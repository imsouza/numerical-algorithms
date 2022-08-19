// Compilar: gcc gauss-jacobi.c -o exec -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define LIN 3
#define COL 4

#define PRECISAO 0.00001
#define MAXITER 5

typedef long double L128b;

typedef enum {
	false,
	true
} bool;


double 
MyClock () {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec * 1000000) + tv.tv_usec; 
}


void
mostrarConjuntoSolucao (int it, L128b xi[LIN][1]) {
	putchar('\n');

	printf("ITERACAO %i:\n", it+1);
	for (int i = 0; i < LIN; i++) {
		printf(">> x%i = %6.4Lf\n", 
		i+1, xi[i][0]);
	}
}


void 
gaussJacobi (L128b A[LIN][LIN], L128b b[LIN][1]) {
	L128b x1[LIN][1] = {0,0,0};
	L128b x2[LIN][1] = {0,0,0};

	int iteracao = 0;

	while (iteracao < MAXITER) {
		for (int i = 0; i < LIN; i++) {
			L128b somatorio = 0.000f;

			for (int j = 0; j < LIN; j++) {
				if (j != i) {
					somatorio += A[i][j] * x1[j][0];
				}
			}

			x1[i][0] = fabs((b[i][0] - somatorio) / A[i][i]);
		}

		for (int i = 0; i < LIN; i++) {
			x2[i][0] = x1[i][0];
		}

		mostrarConjuntoSolucao(iteracao++, x2);
	}
}


int 
main () {
	L128b A[LIN][LIN] = {
		{2.0, 3.0, -5.0},
		{2.0, 3.0, 1.0},
		{6.0, 9.0, -7.0},

	};

	L128b b[LIN][1] = {{2.0},{8.0},{18.0}};

	double time = MyClock();
	gaussJacobi(A, b);
	printf("\n~ Tempo de Execução: %.10lf ms\n\n\n", (MyClock() - time) / CLOCKS_PER_SEC);

	return 0;
}
