#include <stdio.h>
#include <math.h>

// Defined function to calculate the integral: f(x) <- x^2
double function (double x) {
  return pow(x, 2);
}


// This function calculates the approximation of an 
// integral using Trapezoidal Rule
double trapezoidalRule (double a, double b, unsigned int n) {
  double I = 0, sum = 0, x;

  double h = (b - a) / n;

  int i;

  for (i = 1; i < n; i++) {
    x = a + i * h;
    sum += function(x);
  }

  I = (h / 2) * (function(a) + function(b) + 2 * sum);

  return I;
}


int main () {
  // Integration limits
  double a = 3, b = 2;
  // Subinterval
  unsigned int n = 20;

  double I = trapezoidalRule(a, b, n);

  printf("I = %lf\n", I);

  return 0;
}
