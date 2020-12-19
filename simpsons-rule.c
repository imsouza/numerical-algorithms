/**
 * @file simpsons-rule.c
 * @brief A program that calculates the approximation of an integral using Simpson's rule
 * integral using Simpson's Rule
 * @author Mateus Almeida
 * @version 1.0
 */

#include <stdio.h>
#include <math.h>

/**
 * Defined function to calculate the integral: f(x) <- x^2
 * @param x: value for calculating the function
 */
double function (double x) {
  return pow(x, 2);
}


/**
 * This function calculates the approximation of an 
 * integral using Simpson's Rule
 * @param a: integration limit A
 * @param b: integration limit B
 * @param n: number of subintervals
 */
double simpsonsRule (double a, double b, unsigned int n) {
  double x0[n], y0[n], I = 0;

  int i, j;

  double h = (b - a) / n;

  for(i = 0; i <= n; i++) {
    x0[i] = a + h * i;
    y0[i] = function(x0[i]);
  }

  for(i = 1; i < n; i++) {
    if(i % 2 == 0){
      I += 2 * y0[i];
    } else {
      I += 4 * y0[i];
    }
  }

  I += y0[0] + y0[n];
  I = (h / 3) * I;

  return I;
}


int main () {
  //! Integration limits
  double a = 5, b = 3;
  //! Subinterval
  unsigned int n = 2;

  double I = simpsonsRule(a, b, n);

  printf("I = %lf\n", I);

  return 0;
}
