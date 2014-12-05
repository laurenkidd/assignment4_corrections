#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef N
#define N 3
#endif



int main(int argc, char **argv)
{
  srandom(time(NULL));
  /*double *pi_approx = (double*) malloc(N * sizeof( double ));
  if (pi_approx == NULL ) { puts("Cannot Allocate Result Array.");exit(1);}
   double *percent_err = (double*) malloc(N * sizeof( double ));
  if (percent_err == NULL ) { puts("Cannot Allocate Result Array.");exit(1);}*/
  int NUM;
  
  double pi_approx[3];
  double percent_err[3];
  double px, py;
  int n_cir = 0 ;   

  for (int i = 0; i < N ; i++){
    switch ( i ) {
      case 0:
        NUM = 100;
        break;
      case 1:
        NUM = 10000;
        break;
      case 2:
        NUM = 1000000;
      break;
    }
    

//  set p to pointer
    /*points *p = (points*) malloc(NUM * sizeof(points));
    if (p == NULL ) { puts("Cannot Allocate points.");exit(1);}*/

// Populate plane with points and write locations of points.
    
    for (int j = 0 ; j < NUM ; j++){
      px = (rand()/(double)RAND_MAX) ;
      py = (rand()/(double)RAND_MAX) ;
    

    // Determine whether points fall within circle or not.
    //  If they fall within the circle, x^y+y^2 <= 1
   
        if ((px*px + py*py) <= (double)1 ) {
          n_cir += 1 ;
        }
    }
// Take the ratio n_cir/n_sq * 4 to find pi
    double nc = n_cir;
    pi_approx[i] = (nc/(double) NUM) * (double)4;
// Calculate percent error compared to actual value of pi
    double pi_actual = 3.14159265359;
    percent_err[i] = fabs(pi_actual - pi_approx[i])/pi_actual * (double)100;
// Write result to screen
    printf("%s %f %s %f\n","estimate for pi: ", pi_approx[i], ", percent error:", percent_err[i]);
     int n_cir = 0 ;   
  }
//Calculate percent error as a function of NUM (assume linear in a log-log plot)
// Percent error(N) will be the slope of a plot of log(error) versus  log(NUM)
   double err_N = (log(percent_err[0])-log(percent_err[2]))/(log((double)100)-log((double)1000000));
    printf("%s %f %s\n","percent_error(N)", err_N, " * log(NUMBER_OF_POINTS)");
 
  return 0;
}


