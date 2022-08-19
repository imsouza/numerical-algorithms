// Compilar: gcc bissecao.c -o exec -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRECISAO 0.0001
#define LOG10(x) (log(x) / log(10))

typedef long double L128b;

typedef enum {
  false,
  true
} bool;


L128b f 
(L128b x) {
  return pow(x, 3) + 3 * pow(x, 2) + 12 * x + 8;
}


int 
main () {
  L128b x0 = -5;
  L128b x1 = 5;

  L128b iteracoes = (LOG10(x1 - x0) - LOG10(PRECISAO)) / LOG10(2);
  L128b x2 = (x0 + x1) / 2;

  int passos = 0;

  if (f(x0) * f(x1) > 0) {
    printf("\nValores iniciais incorretos.\n");
    abort();
  }

  printf("\nPassos\t\tPonto A\t\tPonto B\t\t  Raiz\t\tf(x2)\n");
  
  do {
    printf("%i\t\t%Lf\t%Lf\t%Lf\t%Lf\n", passos+1, x0, x1, x2, f(x2));
    
    if (f(x2) == 0) { break; }
    if (fabs(f(x2)) <= PRECISAO) { break; }

    if (f(x0) * f(x2) < 0) {
      x0 = x0;
      x1 = x2;
    } else {
      x0 = x2;
      x1 = x1;
    }

    x2 = (x0 + x1) / 2; passos++;
  } while (passos <= iteracoes);

  printf("\n\nRaiz = [%.4Lf] | Num. Iterações: %i\n\n", x2, passos);

  return 0;
}