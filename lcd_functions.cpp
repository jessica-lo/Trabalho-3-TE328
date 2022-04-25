#include "lcd_functions.h"

/*Função que recebe todos os parâmetros necessários para imprimir no lcd
*/
void printReadings(LiquidCrystal* lcd, int sum, int overrides, int count, int* arr){
  (*lcd).setCursor(0, 0);
  (*lcd).clear();
  for(int i = 2; i >= 0; i--){
    if(arr[i] > 0) (*lcd).print(arr[i]);
    (*lcd).print(" ");
    (*lcd).setCursor((3 - i)*5, 0);
  }
  
  (*lcd).setCursor(0, 1);
  (*lcd).print(sum);
  (*lcd).setCursor(5, 1);
  (*lcd).print((float)sum/count);
  (*lcd).setCursor(10, 1);
  (*lcd).print(" ");
  (*lcd).setCursor(11, 1);
  (*lcd).print(overrides);
  (*lcd).setCursor(14, 1);
  (*lcd).print(count);
}
