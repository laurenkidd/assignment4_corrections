#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef N_SCATTER
#define N_SCATTER 1000000
#endif


int main(int argc, char **argv)
{
 
  srand(time(NULL));
  
  double pi = 3.14159;
  double Na = 6.022e23; //Avogadro's number
  double k = 0.1 ; //define something for beam spread
  double Z, A, rho ;
  int material;
  printf("Enter a material (gold = 1 or silicon = 2), or other for new material = 3)");
  scanf( "%d", &material ); 
  switch ( material ) {
    case 1:
      //gold
      Z = 79; //charge of nucleus  
      A = 196.9665; //atomic weight g/mol
      rho = 19.30; //density g/cm^3
      break;
    case 2:
      Z = 14; //charge of nucleus  
      A = 28.085; //atomic weight g/mol
      rho = 2.3290; //density g/cm^3
      break;
    case 3:
      printf("enter nucleus charge");
      scanf( "%le", &Z ); 
      getchar();
      printf("eneter atomic weight (g/mol)");
      scanf( "%le", &A ); 
      getchar();
      printf("enter density (g/cm^3)");
      scanf( "%le", &rho ); 
      getchar();
      break;
  }
//
  double J = (9.76 * Z + 58.5/pow(Z,0.19)) * pow(10.0,-3);
  double energy;
  printf("Enter a center energy (in kev)");
  scanf( "%le", &energy ); 
  getchar();
  double E_c = energy ; //center energy 
 
  for ( int i = 0; i < N_SCATTER; i++){
  // Random number between 0 and 1
    //double RND1= rand()/(double)RAND_MAX ;
    ///double RND2 = rand()/(double)RAND_MAX ;
// Gaussian deviate
    double z1 = sqrt(-2 * log((double) rand()/(double) RAND_MAX)) * cos(2 * pi * (double) rand()/(double) RAND_MAX);
// Electron beam energy
    double E = E_c * ((double)1 + k * z1);
// Screening parameter
    double alpha = 3.4e-3 * pow(Z,0.67)/E;
// phi
    double phi = acos(1e0 - (2e0 * alpha * (double) rand()/(double) RAND_MAX/(1e0+alpha - (double) rand()/(double) RAND_MAX)));
// psi
    double psi = 2.0 * pi * (double) rand()/(double) RAND_MAX;
//sigma_e
    double sigma_e = 5.21e-21 * pow(Z,2)/pow(E,2) * 4 * pi/(alpha*(1.0 + alpha)) * pow((E+511),2)/pow((E+1024),2); //cm
//mean free path
    double lambda = A/(Na * rho * sigma_e); //cm
//step = scattering position
    double step = -lambda * log((double) rand()/(double) RAND_MAX);
//dE/dS
    double dE_dS = -(double) 78500 * (rho * Z)/(A * E) * log(1.166 * E/J + 1.0); //keV
//delta E
    double delta_E = dE_dS*step;
// energy as electron exits target
    double e_target = E - delta_E;
    printf("%le %le %le %le %le\n", step, E, e_target, psi, phi);
  }
   


  return 0;
}

