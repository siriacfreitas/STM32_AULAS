# Projeto STM32 - Botão + LED com HAL

Este projeto é um exemplo simples de controle digital com STM32, utilizando a biblioteca HAL. O programa lê o estado de um botão conectado ao pino `PC13` (B1\_Pin) e controla o estado de um LED no pino `PA5` (Led2\_Pin). Quando o botão é pressionado, o LED acende; quando solto, o LED apaga.

## 🧠 Objetivo

Demonstrar:

* Leitura de um botão digital (entrada com pull-up);
* Controle de um LED (saída push-pull);
* Uso de `HAL_GPIO_ReadPin()` e `HAL_GPIO_WritePin()` com GPIOs.

## 🛠️ Requisitos

* Placa STM32 (ex: Nucleo-F446RE)
* STM32CubeIDE ou STM32CubeMX
* Programador ST-LINK (ou similar)
* Botão físico conectado a `PC13` (normalmente presente na placa)
* LED conectado a `PA5` (ou o LED onboard LD2)

## 📂 Estrutura

```
/Core
├── Src
│   └── main.c          # Código principal
├── Inc
│   └── main.h          # Cabeçalhos (caso aplicável)
```

## ⚙️ Funcionamento

No `main.c`, o programa:

1. Inicializa o sistema e os periféricos;
2. Lê o estado lógico do botão em `PC13` com pull-up ativado (`0` = pressionado);
3. Liga o LED (`PA5`) quando o botão é pressionado, e o desliga caso contrário.

```c
if(HAL_GPIO_ReadPin(GPIOC, B1_Pin) == 0) {
    HAL_GPIO_WritePin(GPIOA, Led2_Pin, GPIO_PIN_SET);
} else {
    HAL_GPIO_WritePin(GPIOA, Led2_Pin, GPIO_PIN_RESET);
}
```

## 📌 Pinos Utilizados

| Componente | Porta | Pino | Configuração        |
| ---------- | ----- | ---- | ------------------- |
| Botão      | GPIOC | PC13 | Entrada com pull-up |
| LED        | GPIOA | PA5  | Saída push-pull     |

## 🔍 Detalhes Técnicos

* O botão usa lógica invertida (pressionado = `0`) por estar com pull-up interno ativado.
* O LED é controlado por escrita direta no pino digital usando `HAL_GPIO_WritePin()`.

## 📝 Observações

* O código segue estrutura padrão gerada pelo STM32CubeIDE.
* Pode ser expandido para interrupções ou debounce via software/hardware.

## 📄 Licença

Este projeto segue os termos da STMicroelectronics, conforme indicado no cabeçalho do arquivo `main.c`. Se nenhum arquivo LICENSE estiver presente, o código é fornecido "AS-IS".
