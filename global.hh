#include <stdio.h>     //Include the standard input/output libraries
#include <iostream>  //Cout and Cin etc.
#include <fstream>
#include <complex>
#include <stdlib.h>    //Include standard fucntion libraries
#include <math.h>      //Use the math function libraries
#include <time.h>      //Call system time libraries to define the integer seed for random numbers
#include "./include/smemory.hh"  //Use my custom memory handling class
#include </usr/local/include/fftw3.h>
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
int PAR, PER, MIX;
int Initial_Read;

double tau; // This is the tau from the theory
double NAB,f,pot_diff;
double kA,kB,PA;        
double pAave, pBave, pIave;
double converg;
double psi_bc_1;
double psi_bc_2;
double Free_Energy;

fftw_plan forward_plan, inverse_plan;
double *input_q, *transformed_q, *final_q;
