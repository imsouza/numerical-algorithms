// Compilar: gcc gauss-jordan.c -o exec -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define LIN 3
#define COL 4

double 
MyClock () {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec * 1000000) + tv.tv_usec; 
}


void
mostrarConjuntoSolucao (long double A[LIN][COL]) {
	long double S[LIN];

	for (int i = 0; i < LIN; i++) {
		S[i] = floor(A[i][LIN] / A[i][i]);
	}

	for (int i = 0; i < LIN; i++) {
		printf(">> x%i = %6.4Lf\n", i+1, S[i]);
	}
}



void 
gaussSeidel (long double A[LIN][COL]) {
	long double opElementar = 0.00000000f;

	for (int i = 0; i < LIN; i++) {
		if (A[i][i] == 0.00000000f) { 
			printf("\nSolução inviável por este método.\n");
			abort(); 
		}
		for (int j = 0; j < LIN; j++) {
			if (i != j) {
				opElementar = A[j][i] / A[i][i];
				for (int k = 0; k < COL; k++) {
					A[j][k] -= ceil(A[i][k] * opElementar);
				}
			}
		}
	}

	mostrarConjuntoSolucao(A);
}



int 
main () {
	long double A[LIN][COL] = {
		{1.0, 0.0, -1.0, 1.0},
		{2.0, 1.0, 0.0, 1.0},
		{0.0, 1.0, 1.0, 1.0},

	};

	double time = MyClock();
	gaussSeidel(A);
	printf("\n~ Tempo de Execução: %.10lf ms\n\n\n", (MyClock() - time) / CLOCKS_PER_SEC);

	return 0;
}
