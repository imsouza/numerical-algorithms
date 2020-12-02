#include <stdio.h>
#include <math.h>

// Defined function to calculate the integral: f(x) <- x^2
double function (double x) {
  return pow(x, 2);
}


// This function calculates the approximation of an 
// integral using Simpson's Rule
double simpsonsRule (double a, double b, unsigned int n) {
  double X0[n], Y0[n], I = 0;

  int i, j;

  double H = (b - a) / n;

  for(i = 0; i <= n; i++) {
    X0[i] = a + H * i;
    Y0[i] = function(X0[i]);
  }

  for(i = 1; i < n; i++) {
    if(i % 2 == 0){
      I += 2 * Y0[i];
    } else {
      I += 4 * Y0[i];
    }
  }

  I += Y0[0] + Y0[n];
  I = (H / 3) * I;

  return I;
}


int main () {
  // Integration limits
  double a = 5, b = 3;
  // Subinterval, only positive values
  unsigned int n = 2;

  double I = simpsonsRule(a, b, n);

  printf("I = %lf\n", I);

  return 0;
}