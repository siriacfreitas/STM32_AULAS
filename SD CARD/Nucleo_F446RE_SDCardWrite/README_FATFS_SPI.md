
# Projeto STM32 com FATFS e Cartão SD via SPI

Este projeto utiliza uma placa STM32 (Nucleo-F446RE) com biblioteca FATFS para criar e escrever arquivos em um cartão microSD através da interface SPI. Ele exemplifica a criação de arquivos, diretórios e o uso do LED como sinalização.

---

## ⚙️ Requisitos

- **STM32CubeIDE** + **STM32CubeMX**
- Periféricos habilitados:
  - `SPI1` configurado como "FULL-DUPLEX MASTER"
  - `FATFS` ativado como "User-defined"
  - GPIO configurado para LED (PB5) e CS(PB6) ambos como saída
- Cartão microSD formatado em FAT32

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

2. **Sinalização com LED:**  
   LED da placa pisca ao montar e ao finalizar operações com sucesso.

3. **Criação de arquivo na raiz:**  
   Cria o arquivo `Arquivo.csv` e escreve duas linhas nele.

4. **Criação de diretório:**  
   Cria uma pasta chamada `PASTA`.

5. **Criação de arquivo dentro da pasta:**  
   Cria `File.txt` dentro de `PASTA` com uma frase de teste.

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
HAL_GPIO_TogglePin(GPIOB, led_Pin);
```
Pisca LED como sinal de sucesso.

```c
f_open(...);
f_write(...);
f_close(...);
```
Cria arquivos e escreve conteúdo neles.

```c
f_mkdir("PASTA");
```
Cria diretório chamado `PASTA`.

```c
HAL_Delay(500);
HAL_GPIO_TogglePin(GPIOB, led_Pin);
```
Pisca o LED novamente após todas as operações.

---

## ✅ Resultado Esperado

- LED pisca duas vezes.
- Criado `Arquivo.csv` na raiz do cartão.
- Criada pasta `PASTA` com arquivo `File.txt`.

---

## 👨‍💻 Autor

Este projeto foi desenvolvido como estudo de integração entre microcontroladores STM32, biblioteca FATFS e cartões SD via SPI.
