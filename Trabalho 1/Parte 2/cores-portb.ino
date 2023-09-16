const int RED_PIN = 3;   // Pino para o LED vermelho
const int GREEN_PIN = 5; // Pino para o LED verde
const int BLUE_PIN = 6;  // Pino para o LED azul

void setup() {
  DDRB |= (1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN); // Define os pinos como saída
}

void setColor(int redValue, int greenValue, int blueValue) {
  for(int i = 0; i < 256; i++) {
    if(i < redValue) PORTB |= (1 << RED_PIN);
    else PORTB &= ~(1 << RED_PIN);
    
    if(i < greenValue) PORTB |= (1 << GREEN_PIN);
    else PORTB &= ~(1 << GREEN_PIN);
    
    if(i < blueValue) PORTB |= (1 << BLUE_PIN);
    else PORTB &= ~(1 << BLUE_PIN);
    
    delayMicroseconds(50); // Ajuste este valor para controlar a intensidade
  }
}

void loop() {
  setColor(255, 0, 0);   // Vermelho
  setColor(0, 255, 0);   // Verde
  setColor(0, 0, 255);   // Azul
  setColor(255, 255, 0); // Amarelo
  setColor(0, 255, 255); // Ciano
  setColor(255, 0, 255); // Magenta
  setColor(255, 255, 255); // Branco
  setColor(0, 0, 0);     // Desligado
}
