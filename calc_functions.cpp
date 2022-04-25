#include "calc_functions.h"

/*Fun��o que verifica se os valores ultrapassam o tamanho do vetor de leituras
  se sim, � realizado uma s�rie de condi��es para retornar o n�mero de valores a serem sobrescritos
*/
int incLoop(int index, int inc, int tam){
  if(inc > tam) inc = inc % tam;
  if(index + inc >= tam) return (index + inc - tam);
  else if(index + inc < 0) return (index + inc + tam);
  else return index + inc;
}

/*Fun��o que armazena os valores lidos no vetor,
  a vari�vel head � incrementada por meio da fun��o incLoop
  realiza o incremento da contagem e faz a soma dos valores lidos
*/
void addToArray(int num, int* arr, int tam, int* head, int* sum, int* count, int* overrides){
  if(*head == tam - 1 || *overrides > 0) (*overrides)++;
  arr[*head] = num;
  *head = incLoop(*head, 1, tam);
  (*count)++;
  (*sum) += num;
}

/*Fun��o que armazena os �ltimos tr�s valores do vetor lido para outro vetor
*/
void computeReadings(int* arrFrom, int tam, int head, int overrides, int* arrTo){

  int limit;
  if(overrides == 0 && head - 4 < 0) limit = tam - 1;
  else limit = incLoop(head, -4, tam);
  for(int i = incLoop(head, -1, tam), j = 0; i != limit; i = incLoop(i, -1, tam),j++){
    arrTo[j] = arrFrom[i];
  }
}
