/*Programa que realiza a entrada de dados do sensor ultrassônico HC-SR04,
  manipula-se este valor de entrada para encontrar a distância respectiva,
  e regula, por meio do PWM, a luminosidade de um LED de acordo com o valor desta distância.
  O vetor que armazena estes valores é alocado dinÇamicamente com tamanho incial aleatório,
  toda vez que os valores ultrapassam do tamanho máximo, estes sobrescrevem os valores iniciais.
  O LCD mostra os últimos 3 valores, a soma, a média, a quantidade de valores lidos e a quantidade de valores sobrescritos.
*/

/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include "lcd_functions.h"
#include "calc_functions.h"
#include "dispositivos.h"
#include <TimerOne.h>
//Beginning of Auto generated function prototypes by Atmel Studio
void teste(void );
//End of Auto generated function prototypes by Atmel Studio


//definição dos pinos do sensor
#define echoPin 12
#define trigPin 13

//dsfinição do pino do LED
const int led = 11;

const int rs = 7, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int* data = (int*) calloc(3, sizeof(int));  //vetor utilizado para armazenar os últimos três valores
int* readings;    //vetor que armazena todos os valores
int sum = 0;      //variável para soma
int count = 0;        //variável para armazenar a quantidade de valores lidos
int head = 0;     //variável que define em qual posição do vetor o primeiro dos últimos três valores se encontram
int tam;          //variável para o tamanho do vetor
int overrides = 0;  //variável para armazenar a quantidade de valores sobrescritos

void setup()
{  
  /*iniclializa o timer após 3 segundos
    após isso a interrupção executa a função interruptTimer
  */
  Timer1.initialize(2000000);
  Timer1.attachInterrupt(teste);
  
  /*randomSeed retorna um valor aleatório para cada execução do programa
    tam é definido aleatoriamente entre 30 e 50
	o vetor readings é alocado dinâmicamente com o tamanho aleatório
  */
  randomSeed(analogRead(0));
  tam = random(30,51);
  readings = (int*) malloc(tam*sizeof(int));
  
  //declara o pino 11 como saída
  pinMode(led, OUTPUT);

  //inicializa o display lcd
  lcd.begin(16, 2);
  
  //delcara o pino 12 como saída e o 13 como entrada
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

/*Função executada pela interrupção
*/
void teste(void){
  Serial.println("sla");
  int num = getDist(echoPin, trigPin);
  lightLed(num, &led);
  addToArray(num, readings, tam, &head, &sum, &count, &overrides);
  computeReadings(readings, tam, head, overrides, data);
  printReadings(&lcd, sum, overrides, count, data);
}

void loop() {
  // put your main code here, to run repeatedly:
}
