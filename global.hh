//#include </opt/sharcnet/fftw/3.3.2/intel/include/fftw3.h> // This is for Sharcnet                                                        
//#include </usr/include/fftw3.h> // This is for use on Landua                                                                           
#include </usr/local/include/fftw3.h> // This is for local use (My MacBookPro)


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <complex>
#include <stdlib.h>  
#include <math.h>


using namespace std;

#define Nx 32
#define Ny 32

#define ChainType 3 // We will add the e type manually


// Set to 1 to minimize box size and 0 to not
int box_min=0;

// 0=read 1=set manually 2=random
int  Iomega=1;

int LAM, HEX;

double tau; // This is the tau from the theory
double mu; // Surface interaction
double NAB,f,pot_diff;
double kA,kB,PA;        
double pAave, pBave, pIave;
double converg;
double psi_bc_1;
double psi_bc_2;
double Free_Energy;
double Lx,Ly;

fftw_plan forward_plan, inverse_plan;
double *input_q, *transformed_q, *final_q;

int i_fftw;
double xAB;
int NA;
double deltaV;
double ***w;
double ***phi;
double **psi;
double **eta;
double **diel_cons;
double *chi;
double **chiMatrix;
double ds;
double *Ns;
double **k_vector;
double *dxy;
double ***x_sub;



// Paramteres defined to calculate tau ****
#define Pi 3.14159
#define Temp 400.0
#define e 1.6e-19
#define eps_0 8.85e-12
#define K_Boltz 1.38e-23
#define Kuhn 1.0e-9
#define rho_0 1.0e28
// ****************************************
