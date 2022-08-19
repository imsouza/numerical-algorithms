#include <stdio.h>

#define DATAPOINTS 3

typedef long double L128b;

int 
main () {
  L128b pontoDeInterpolacao = 5;
  
  L128b X[DATAPOINTS] = { 0, 
                          1, 
                          4 };

  L128b Y[DATAPOINTS] = {-1, 
                          1, 
                          1 };

  L128b operacao;
  L128b somatorio = 0;

  int i, j;

  for (j = 0; j < DATAPOINTS - 1; j++) {
    for (i = DATAPOINTS - 1; i > j; i--) {
      Y[i] = (Y[i] - Y[i - 1]) / (X[i] - X[i-j-1]);
      
    }
  }

  for (i = DATAPOINTS - 1; i >= 0; i--) {
    operacao = 1;

    for (j = 0; j < i; j++) {
      operacao *= (pontoDeInterpolacao - X[j]);
    }

    operacao *= Y[j];
    somatorio += operacao;
  }

  printf("Pontos de Interpolação resultante: X:%.4Lf => Y:%.4Lf\n", 
  pontoDeInterpolacao, somatorio);

  return 0;
}