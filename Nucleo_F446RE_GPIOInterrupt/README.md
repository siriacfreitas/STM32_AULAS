# Projeto STM32 - LED Blink + Interrupção por Botão

Este projeto demonstra o uso de interrupções externas em conjunto com o controle de LED no STM32, utilizando a biblioteca HAL. Um LED pisca periodicamente a cada 500 ms, enquanto um segundo LED alterna seu estado quando o botão `B1` é pressionado (gerando uma interrupção).

## 🧠 Objetivo

* Demonstrar o uso de interrupções externas via `EXTI` para o botão.
* Alternar o estado de um LED (`PB14`) ao pressionar o botão `PC13`.
* Manter um LED (`PA5`) piscando constantemente no laço principal com `HAL_Delay()`.

## 🛠️ Requisitos

* Placa STM32 (ex: Nucleo-F446RE)
* STM32CubeIDE ou STM32CubeMX
* Programador ST-LINK
* LED conectado ao pino `PA5` (Led2)
* LED adicional conectado a `PB14` (LedInterrupt)
* Botão `B1` já presente na maioria das placas, conectado ao pino `PC13`

## 📂 Estrutura

```
/Core
├── Src
│   └── main.c          # Código principal
├── Inc
│   └── main.h          # Cabeçalhos (caso aplicável)
```

## ⚙️ Funcionamento

### Loop principal (`main()`)

* O LED `Led2_Pin` em `PA5` alterna seu estado a cada 500 ms usando:

```c
HAL_GPIO_TogglePin(GPIOA, Led2_Pin);
HAL_Delay(500);
```

### Interrupção externa (`EXTI`)

* O botão `B1` está conectado a `PC13` e configurado com `GPIO_MODE_IT_FALLING` e `PULLUP`.
* Quando pressionado, aciona a interrupção `EXTI15_10_IRQn`.
* O callback `HAL_GPIO_EXTI_Callback()` alterna o LED `LedInterrupt_Pin` (`PB14`):

```c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    if (GPIO_Pin == B1_Pin){
        HAL_GPIO_TogglePin(GPIOB, LedInterrupt_Pin);
    }
}
```

## 📌 Pinos Utilizados

| Componente      | Porta | Pino | Configuração                                           |
| --------------- | ----- | ---- | ------------------------------------------------------ |
| LED Blink       | GPIOA | PA5  | Saída push-pull                                        |
| LED Interrupção | GPIOB | PB14 | Saída push-pull (alta velocidade)                      |
| Botão (B1)      | GPIOC | PC13 | Entrada com pull-up e interrupção por borda de descida |

## 🚨 Interrupção EXTI

* A interrupção `EXTI15_10_IRQn` é ativada com prioridade 0.
* Ideal para aplicações que requerem resposta imediata a eventos externos.

## 📝 Observações

* Pode ser expandido com debounce por software ou filtragem por hardware.
* Exemplo ideal para aprender sobre multitarefa entre loop principal e interrupções.

## 📄 Licença

Este projeto segue os termos da STMicroelectronics, conforme indicado no cabeçalho do arquivo `main.c`. Se nenhum arquivo LICENSE estiver presente, o código é fornecido "AS-IS".
