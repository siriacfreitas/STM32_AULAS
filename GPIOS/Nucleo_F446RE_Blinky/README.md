# Projeto STM32 - Blink com HAL

Este projeto é um exemplo básico de firmware para microcontroladores STM32 utilizando a HAL (Hardware Abstraction Layer) da STMicroelectronics. O código realiza o **toggle do pino PA5** a cada segundo, criando um efeito de piscar em um LED conectado a esse pino (como o LED LD2 em placas Nucleo).

## 🧠 Objetivo

Demonstrar a configuração mínima necessária para:

* Inicialização do sistema com `HAL_Init()` e configuração do clock;
* Configuração de um pino GPIO como saída (`PA5`);
* Alternância de estado do pino com `HAL_GPIO_TogglePin()`;
* Delay com `HAL_Delay()`.

## 🛠️ Requisitos

* Placa STM32 (ex: Nucleo-F446RE)
* STM32CubeIDE ou STM32CubeMX + compilador GCC/ARM
* ST-LINK ou outro programador/debugger compatível

## 📂 Estrutura

```
/Core
├── Src
│   └── main.c          # Código principal
├── Inc
│   └── main.h          # Cabeçalhos (caso aplicável)
```

## ⚙️ Funcionalidade

O `main.c` inicializa o microcontrolador, configura o clock e o GPIO, e entra em um laço infinito onde alterna o estado do pino `PA5` a cada 1000 ms.

```c
while (1)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    HAL_Delay(1000);
}
```

Esse comportamento gera um piscar periódico no LED.

## 🔧 Inicialização de Hardware

* **Clock**: Configurado com HSI + PLL (frequência definida no CubeMX).
* **GPIOA Clock**: Ativado via `__HAL_RCC_GPIOA_CLK_ENABLE();`
* **PA5**: Configurado como saída push-pull, sem pull-up/down, velocidade baixa.


## 📄 Licença

Este projeto segue os termos da STMicroelectronics, conforme indicado no cabeçalho do arquivo `main.c`. Se nenhum arquivo LICENSE estiver presente, o código é fornecido "AS-IS".




