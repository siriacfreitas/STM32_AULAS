
# Projeto STM32 com FATFS (Leitura) e UART

Este projeto utiliza uma placa STM32 (Nucleo-F446RE) com biblioteca FATFS para **ler um arquivo `teste.txt` do cartão microSD via SPI** e transmitir o conteúdo lido por UART (USART2). O projeto também envia mensagens de erro via UART caso a montagem do sistema FAT falhe.

---

## ⚙️ Requisitos

- **STM32CubeIDE** + **STM32CubeMX**
- Periféricos habilitados:
  - `SPI1` configurado como "FULL-DUPLEX MASTER"
  - `FATFS` ativado como "User-defined"
  - `USART2` configurado para transmissão e recepção serial
  - GPIO configurado para CS (ex: PB6) como saída
- Cartão microSD formatado em FAT32 com arquivo `teste.txt` contendo até 30 bytes

---

## 🗂 Estrutura de Pastas

### 📁 `fatfs/`

Contém os arquivos principais da biblioteca FatFs, incluindo:

* `ff.c`, `ff.h`, `ff_gen_drv.c`, `ff_gen_drv.h`, `diskio.c`, `diskio.h` e outros auxiliares.

### 📁 `fatfs/Target/`

Aqui devem ser **adicionados** os arquivos `user_diskio_spi.c` e `user_diskio_spi.h`, e também **modificados** os arquivos `user_diskio.c` e `user_diskio.h` para permitir a comunicação SPI com o cartão SD.

📽️ Para mais detalhes sobre como fazer essas alterações, assista ao vídeo:  
[YouTube - FATFS STM32 SPI](https://youtu.be/PBIm8BCnbyQ?si=l3_k60RtlLptr43m)

---

## 🔧 Modificação no `main.h`

Adicione a seguinte linha para que o FATFS saiba qual SPI usar:

```c
#define SD_SPI_HANDLE hspi1
```

---

## 🚀 Funcionalidade do Código

1. **Montagem do cartão SD:**  
   Verifica se o sistema de arquivos FAT foi montado corretamente.
   - Se a montagem falhar, envia a mensagem `"Erro: Falha no f_mount.
"` via UART2.

2. **Leitura do arquivo `teste.txt`:**  
   - Abre (ou cria) o arquivo `teste.txt` no cartão.
   - Lê até 30 bytes do conteúdo e armazena no buffer `rxdados`.
   - Fecha o arquivo.

3. **Envio do conteúdo via UART2:**  
   - O conteúdo lido (ou a mensagem de erro) é enviado pelo terminal serial usando a função `send_uart(rxdados)`.

---

## 🧠 Explicação do trecho principal

```c
FATFS meuFATFS;
FIL meuArquivo;
UINT testeByte;
```
Declara variáveis do sistema de arquivos e arquivos.

```c
if (f_mount(&meuFATFS, USERPath, 1) == FR_OK)
```
Monta o sistema de arquivos FAT no cartão.

```c
f_open(...);
f_read(...);
f_close(...);
```
Lê até 30 bytes do conteúdo do arquivo `teste.txt` e fecha o arquivo.

```c
send_uart(rxdados);
```
Envia o conteúdo lido (ou mensagem de erro) pela UART2.

---

## ✅ Resultado Esperado

- O conteúdo do arquivo `teste.txt` é lido do cartão microSD (máx. 30 bytes) e transmitido pela USART2.
- Se a montagem do cartão falhar, é enviada a mensagem de erro `"Erro: Falha no f_mount.
"`.

---

## 👨‍💻 Autor

Este projeto foi desenvolvido como estudo de leitura de arquivos do cartão SD com FATFS via SPI e envio de dados via UART no STM32.
