# Projeto STM32 - Botão com Debounce + Toggle LED

Este projeto demonstra como usar um botão para alternar o estado de um LED utilizando STM32 e a HAL, com controle de debounce simples baseado em tempo com `HAL_GetTick()`.

## 🧠 Objetivo

* Detectar o pressionamento de um botão (`PC13`) com verificação de *debounce* por tempo.
* Alternar o estado de um LED (`PA5`) a cada pressionamento.
* Utilizar temporização com `HAL_GetTick()` para evitar múltiplos toggles por *bouncing* mecânico.

## 🛠️ Requisitos

* Placa STM32 (ex: Nucleo-F446RE)
* STM32CubeIDE ou STM32CubeMX
* Programador ST-LINK
* Botão conectado a `PC13` (já presente em muitas placas)
* LED conectado a `PA5` (ou LED onboard)

## 📂 Estrutura

```
/Core
├── Src
│   └── main.c          # Código principal
├── Inc
│   └── main.h          # Cabeçalhos (caso aplicável)
```

## ⚙️ Funcionamento

1. O botão em `PC13` é monitorado constantemente.
2. Quando pressionado (nível lógico `0`), o sistema registra o tempo atual com `HAL_GetTick()`.
3. Se o tempo desde o último acionamento (`ut`) for maior que 10 ms, alterna o estado do LED.
4. Armazena o tempo da última ação para evitar múltiplas detecções indevidas por ruído de contato (*bouncing*).

```c
if (!HAL_GPIO_ReadPin(GPIOC, B1_Pin)) {
    t = HAL_GetTick();
    if (t - ut > 10) {
        HAL_GPIO_TogglePin(GPIOA, led2_Pin);
    }
    ut = t;
}
```

## 📌 Pinos Utilizados

| Componente | Porta | Pino | Configuração        |
| ---------- | ----- | ---- | ------------------- |
| Botão      | GPIOC | PC13 | Entrada com pull-up |
| LED        | GPIOA | PA5  | Saída push-pull     |

## ⏱️ Debounce por Software

* Utiliza a função `HAL_GetTick()` para ler o tempo atual em milissegundos desde a inicialização.
* Um delay mínimo de 10 ms entre leituras é usado para evitar múltiplos toggles devido ao bouncing.

## 📝 Observações

* Pode ser aprimorado com debounce por interrupção ou técnicas mais robustas se necessário.
* Ideal para aprendizado de entrada digital com temporização.

## 📄 Licença

Este projeto segue os termos da STMicroelectronics, conforme indicado no cabeçalho do arquivo `main.c`. Se nenhum arquivo LICENSE estiver presente, o código é fornecido "AS-IS".
