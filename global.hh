#include <stdio.h>     //Include the standard input/output libraries
#include <iostream>  //Cout and Cin etc.
#include <fstream>
#include <complex>
#include <stdlib.h>    //Include standard fucntion libraries
#include <math.h>      //Use the math function libraries
#include <time.h>      //Call system time libraries to define the integer seed for random numbers
#include "./include/smemory.hh"  //Use my custom memory handling class
//#include </opt/sharcnet/fftw/3.3.2/intel/include/fftw3.h> // This is for Sharcnet                                                        
#include </usr/include/fftw3.h> // This is for use on Landua                                                                           
//#include </usr/local/include/fftw3.h> // This is for local use (My MacBookPro)
using namespace std;

#define Nx 32
#define Ny 32

#define ChainType 3 // We will add the e type manually
#define Pi 3.14159
#define Temp 400.0
#define e 1.6e-19
#define eps_0 8.85e-12
#define K_Boltz 1.38e-23
#define Kuhn 1.0e-9
#define rho_0 1.0e28


int box_min;
int Iomega;
int PAR_AS;                     // Parallel configuration, with A attracted to the substrate
int PAR_BS;                     // Parallel configuration, with B attrcated to the substrate
int PER;                        // Perpendicular configuration
int MIX;                        // Mixed confuration, with parrallel and perpendicular
int Initial_Read;

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
