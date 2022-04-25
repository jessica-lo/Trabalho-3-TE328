#include "calc_functions.h"

/*Função que verifica se os valores ultrapassam o tamanho do vetor de leituras
  se sim, é realizado uma série de condições para retornar o número de valores a serem sobrescritos
*/
int incLoop(int index, int inc, int tam){
  if(inc > tam) inc = inc % tam;
  if(index + inc >= tam) return (index + inc - tam);
  else if(index + inc < 0) return (index + inc + tam);
  else return index + inc;
}

/*Função que armazena os valores lidos no vetor,
  a variável head é incrementada por meio da função incLoop
  realiza o incremento da contagem e faz a soma dos valores lidos
*/
void addToArray(int num, int* arr, int tam, int* head, int* sum, int* count, int* overrides){
  if(*head == tam - 1 || *overrides > 0) (*overrides)++;
  arr[*head] = num;
  *head = incLoop(*head, 1, tam);
  (*count)++;
  (*sum) += num;
}

/*Função que armazena os últimos três valores do vetor lido para outro vetor
*/
void computeReadings(int* arrFrom, int tam, int head, int overrides, int* arrTo){

  int limit;
  if(overrides == 0 && head - 4 < 0) limit = tam - 1;
  else limit = incLoop(head, -4, tam);
  for(int i = incLoop(head, -1, tam), j = 0; i != limit; i = incLoop(i, -1, tam),j++){
    arrTo[j] = arrFrom[i];
  }
}
