// ===== CÓDIGO PARA O ARDUINO MESTRE (MASTER) =====
// Ele envia os comandos '1' e '0' para controlar o LED do escravo.

#include <Wire.h>

// Endereço I2C do escravo que queremos controlar. Deve ser o mesmo do código do escravo.
const byte ENDERECO_ESCRAVO = 0x2A;

void setup() {
  Serial.begin(9600);
  
  // Inicia a comunicação I2C como Mestre.
  Wire.begin(); 
  
  Serial.println("ESP32 Mestre pronto para enviar comandos.");
}

void loop() {
  // --- Envia comando para LIGAR o LED ---
  Wire.beginTransmission(ENDERECO_ESCRAVO); // Inicia a transmissão para o escravo
  Wire.write('1');                           // Envia o byte/caractere '1'
  Wire.endTransmission();                    // Finaliza e envia os dados
  
  // Imprime no serial do Mestre o que ele fez.
  Serial.println("Comando '1' (LIGAR) enviado.");
  
  delay(2000); // Espera 2 segundos
  
  
  // --- Envia comando para DESLIGAR o LED ---
  Wire.beginTransmission(ENDERECO_ESCRAVO); // Inicia a transmissão para o escravo
  Wire.write('0');                           // Envia o byte/caractere '0'
  Wire.endTransmission();                    // Finaliza e envia os dados

  // Imprime no serial do Mestre o que ele fez.
  Serial.println("Comando '0' (DESLIGAR) enviado.");

  delay(2000); // Espera 2 segundos
}
