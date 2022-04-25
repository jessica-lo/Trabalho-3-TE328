#ifndef CALC_FUNCTIONS_H
#define CALC_FUNCTIONS_H

int incLoop(int index, int inc, int tam);
void addToArray(int num, int* arr, int tam, int* head, int* sum, int* count, int* overrides);
void computeReadings(int* arrFrom, int tam, int head, int overrides, int* arrTo);

#endif
