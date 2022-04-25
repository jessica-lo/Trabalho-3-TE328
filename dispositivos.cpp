#include "dispositivos.h"

/*Fun��o para realizar a leitura dos valores de entrada do sensor e converte para cent�metros
*/
int getDist(int echo, int trig){
  float duration = 0;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  return (duration*0.034)/2;
}

/*Fun��o que converte o valor em cent�metros para valores de sa�da do PWM
*/
void lightLed(int val, const int* led){
  int bright = map(val, 2, 335, 0, 255);
  analogWrite(*led, bright);
}
