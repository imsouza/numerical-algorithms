#include <stdio.h>

#define DATAPOINTS 5

typedef long double L128b;

int 
main () {
  L128b pontoDeInterpolacaoX = 9;
  L128b pontoDeInterpolacaoY = 0.0000f;

  
  L128b X[DATAPOINTS] = { 5, 
                          7, 
                          11, 
                          13, 
                          17 };

  L128b Y[DATAPOINTS] = { 150, 
                          392, 
                          1452, 
                          2366, 
                          5202 };

  L128b operacao;

  for(int i = 1; i < DATAPOINTS; i++) {
    operacao = 1;

    for(int j = 1; j < DATAPOINTS; j++) {
      if(i != j) {
        operacao *= (pontoDeInterpolacaoX - X[j]) / (X[i] - X[j]);
      }
    }

    pontoDeInterpolacaoY += operacao * Y[i];
  }

  printf("Pontos de Interpoção em X: %.4Lf => Y:%.4Lf\n", 
  pontoDeInterpolacaoX, pontoDeInterpolacaoY);

  return 0;
}
