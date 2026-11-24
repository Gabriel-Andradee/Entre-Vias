#include <Ultrasonic.h>

const int led_1_red = 2;
const int led_1_green = 3;
const int led_1_blue= 4;

const int led_2_red = 5;
const int led_2_green = 6;
const int led_2_blue = 7;

const int sensor_1_trig = 8;
const int sensor_1_echo = 9;

const int botao = 10;
const int buzzer = 11;

const int led_A = 12;
const int led_B = 13;

const int distancia_sensor_maxima = 10; // medir largura da parada medida pelo sensor e inserir aqui
int distancia_sensor_1;

Ultrasonic sensor_1 (sensor_1_trig, sensor_1_echo);

void tocarTom(int freq, int duracaoMs) {
  
  long meioPeriodo = 500000 / freq;
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
    tocarTom(800, 300);
    digitalWrite(led_1_red, 255);
    digitalWrite(led_1_green, 0);
    digitalWrite(led_1_blue, 0);
    digitalWrite(led_2_red, 255);
    digitalWrite(led_2_green, 0);
    digitalWrite(led_2_blue, 0);
    digitalWrite(led_A, HIGH);
    digitalWrite(led_B, HIGH);
    tocarTom(1200, 300);
    digitalWrite(led_1_red, 0);
    digitalWrite(led_1_green, 0);
    digitalWrite(led_1_blue, 0);
    digitalWrite(led_2_red, 0);
    digitalWrite(led_2_green, 0);
    digitalWrite(led_2_blue, 0);
    digitalWrite(led_A, LOW);
    digitalWrite(led_B, LOW);
  }
}

void setup() {
  Serial.begin(9600);
    pinMode(led_1_red, OUTPUT);
    pinMode(led_1_green, OUTPUT);
    pinMode(led_1_blue, OUTPUT);

    pinMode(led_2_red, OUTPUT);
    pinMode(led_2_green, OUTPUT);
    pinMode(led_2_blue, OUTPUT); 

    pinMode(botao, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
}

void funcao_leds_standby() {
  digitalWrite(led_1_red, 255);
  digitalWrite(led_1_green, 0);
  digitalWrite(led_1_blue, 0);

  digitalWrite(led_2_red, 255);
  digitalWrite(led_2_green, 0);
  digitalWrite(led_2_blue, 0);

  digitalWrite(led_A, LOW);
  digitalWrite(led_B, LOW);
}

void funcao_leds_ativo(){
  digitalWrite(led_1_red, 255);
  digitalWrite(led_1_green, 255);
  digitalWrite(led_1_blue, 255);

  digitalWrite(led_2_red, 255);
  digitalWrite(led_2_green, 255);
  digitalWrite(led_2_blue, 255);

  digitalWrite(led_A, HIGH);
  digitalWrite(led_B, HIGH);
}

void loop() {
  unsigned long min_tempo;
  Serial.print("millis: ");
  Serial.print(millis());
  Serial.print("   ");
  Serial.print("tempo: ");
  Serial.print(min_tempo);
  Serial.print("   ");
  distancia_sensor_1 = sensor_1.read();

  Serial.print("Sensor 1: ");
  Serial.print(sensor_1.read());
  Serial.println("cm");

  if (digitalRead(botao) == LOW) {
    sirene();
    }
  if (distancia_sensor_1 < distancia_sensor_maxima){
    funcao_leds_ativo();
    min_tempo = millis();
  }
  if (min_tempo < (millis() - 5000)){
    funcao_leds_standby();
  }
}
