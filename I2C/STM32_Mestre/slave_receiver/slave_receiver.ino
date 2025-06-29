// ===== CÓDIGO PARA O ARDUINO ESCRAVO (SLAVE) =====
// Ele recebe comandos para ligar/desligar o LED interno.

#include <Wire.h>

// Endereço I2C que este escravo vai usar.
const byte ENDERECO_ESCRAVO = 0x2A; 

// O LED interno na maioria das placas ESP32 DevKit está no pino 2.
const int LED_PIN = 2;

void setup() {
  Serial.begin(9600);
  
  // Configura o pino do LED como saída.
  pinMode(LED_PIN, OUTPUT);
  
  // Inicia a comunicação I2C como um dispositivo escravo.
  Wire.begin(ENDERECO_ESCRAVO); 
  
  // Registra a função que será chamada quando dados forem recebidos.
  Wire.onReceive(receiveEvent); 
  
  Serial.println("ESP32 Escravo pronto para receber comandos!");
}

void loop() {
  // O loop pode ficar vazio. A interrupção do I2C cuida de tudo.
  delay(100);
}

// Esta função é chamada AUTOMATICAMENTE sempre que o Mestre envia dados.
void receiveEvent(int howMany) {
  // Verifica se há pelo menos um byte para ler.
  if (Wire.available()) {
    // Lê o byte recebido como um caractere.
    char comando = Wire.read(); 
    
    // Imprime no serial do escravo o que ele recebeu (para depuração).
    Serial.print("Comando recebido: ");
    Serial.println(comando);
    
    // Liga o LED se o comando for '1'.
    if (comando == '1') {
      digitalWrite(LED_PIN, HIGH);
    } 
    // Desliga o LED se o comando for '0'.
    else if (comando == '0') {
      digitalWrite(LED_PIN, LOW);
    }
  }
}
