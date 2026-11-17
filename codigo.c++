#include <Ultrasonic.h>

const int led_1_red = 3;
const int led_1_green = 5;
const int led_1_blue= 6;

const int led_2_red = 9;
const int led_2_green = 10;
const int led_2_blue = 11;

const int sensor_1_trig = 2;
const int sensor_1_echo = 4;

const int sensor_2_trig = 7;
const int sensor_2_echo = 8;

const int botao = 12;
const int buzzer = 13;

const int distancia_sensor_maxima = 300; // medir largura da parada medida pelo sensor e inserir aqui
int distancia_sensor_1;
int distancia_sensor_2;

Ultrasonic sensor_1 (sensor_1_trig, sensor_1_echo);
Ultrasonic sensor_2 (sensor_2_trig, sensor_2_echo);

// botão daqui pra baixo

void tocarTom(int freq, int duracaoMs) {
  long meioPeriodo = 500000L / freq;
  long ciclos = (long)freq * duracaoMs / 1000;
  for (long i = 0; i < ciclos; i++) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(meioPeriodo);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(meioPeriodo);
  }
}

void sirene() {
  unsigned long inicio = millis();
  while (millis() - inicio < 3000) { // muda o tempo aq
    tocarTom(800, 300);              // som 1
    tocarTom(1200, 300);             // som 2 se quiser
  }
}
// botão daqui pra cima

void setup() {
  Serial.begin(9600);
    pinMode(led_1_red, OUTPUT);
    pinMode(led_1_green, OUTPUT);
    pinMode(led_1_blue, OUTPUT);

    pinMode(led_2_red, OUTPUT);
    pinMode(led_2_green, OUTPUT);
    pinMode(led_2_blue, OUTPUT); 

    // botão daqui pra baixo
    pinMode(botao, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
    // botão daqui pra cima
}

void funcao_leds_standby() {
  analogWrite(led_1_red, 255);
  analogWrite(led_1_green, 102);
  analogWrite(led_1_blue, 0);

  analogWrite(led_2_red, 255);
  analogWrite(led_2_green, 102);
  analogWrite(led_2_blue, 0);
}

void funcao_leds_ativo(){
  analogWrite(led_1_red, 102);
  analogWrite(led_1_green, 255);
  analogWrite(led_1_blue, 204);

  analogWrite(led_2_red, 102);
  analogWrite(led_2_green, 255);
  analogWrite(led_2_blue, 204);
}

void loop() {
  distancia_sensor_1 = sensor_1.read();
  distancia_sensor_2 = sensor_2.read();

  Serial.print("Sensor 1: ");
  Serial.print(sensor_1.read());
  Serial.println("cm");
  Serial.print("Sensor 2: ");
  Serial.print(sensor_2.read());
  Serial.println("cm");

  // botão dnv daqui pra baixo

  unsigned long t = millis();
  while (millis() - t < 1500) { // coloquei o teu delay do serial aq lippo
    if (digitalRead(botao) == LOW) {
      sirene();
      break;
    }
  }
  // botão dnv daqui pra cima

  if ((distancia_sensor_1 < distancia_sensor_maxima) or (distancia_sensor_2 < distancia_sensor_maxima)){
    funcao_leds_ativo();
  }
  else{
    funcao_leds_standby();
  }
}