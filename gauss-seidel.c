// Compilar: gcc gauss-seidel.c -o exec -lm

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
mostrarConjuntoSolucao (int iteracao, L128b xi[LIN][1], L128b xe[LIN][1]) {
	putchar('\n');

	printf("ITERACAO %i:\n", iteracao);
	for (int i = 0; i < LIN; i++) {
		printf(">> x%i = %6.4Lf\t|Er| = %6.4Lf\n", 
		i+1, xi[i][0], xe[i][0]);
	}
}


void 
gaussSeidel (L128b A[LIN][LIN], L128b b[LIN][1]) {
	L128b xinicial[LIN][1]  = {{0},{0},{0}};
	L128b xanterior[LIN][1] = {{0},{0},{0}};
	L128b xerror[LIN][1]    = {{0},{0},{0}};
	bool parada = false;
	int iteracao = 0;

	do {
		if (iteracao >= MAXITER) { break; }

		for (int i = 0; i < LIN; i++) {
			L128b somatorio = 0.000f;
			for (int j = 0; j < LIN; j++) {
				if (i != j) {
					somatorio += (A[i][j] * xinicial[j][0]);
				}

				xinicial[i][0] = ((b[i][0] - somatorio) / A[i][i]);
			}
		}

		for (int i = 0; i < LIN; i++) {
			xerror[i][0] = fabs(
				(xinicial[i][0] - xanterior[i][0]) / xinicial[i][0]
			);
			if (xerror[i][0] >= PRECISAO) {
				parada = true;
			} else {
				parada = false;
			}

			xanterior[i][0] = xinicial[i][0];
		}

		mostrarConjuntoSolucao(++iteracao, xinicial, xerror);
	} while (parada != false);
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
	gaussSeidel(A, b);
	printf("\n~ Tempo de Execução: %.10lf ms\n\n\n", (MyClock() - time) / CLOCKS_PER_SEC);

	return 0;
}
