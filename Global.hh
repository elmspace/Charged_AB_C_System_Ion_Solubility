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

// For testing
const int Test = 0;

// Set to 1 to minimize box size and 0 to not
const int box_min = 1;

// Boundy condition for electric field
// 0 = ThinFilm Extran Field, fixed BC
// 1 = External Electric Field in Bulk
// 2 = No External Electric Field
const int Psi_BC = 2;

// 0=read 1=set manually 2=random
const int  Iomega = 0;

int LAM, HEX;

double ChargeDensity = 1.0e-20;
double tau; // This is the tau from the theory
double mu; // Surface interaction
double NAB,f,pot_diff;
double kA,kB,PA;        
double pAave, pBave, pIave;
double converg;
double psi_bc_1;
double psi_bc_2;
double Free_Energy;
double Lx=0.0,Ly=0.0;
double Lx_Lam=0.0, Ly_Lam=0.0;
double Lx_Hex=0.0, Ly_Hex=0.0;

fftw_plan forward_plan, inverse_plan;
double *input_q, *transformed_q, *final_q;

int i_fftw;
double xAB, xAI = 0.0, xBI = 0.0;
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

const double phi_mix = 0.02; // del_phi
const double omega_mix = 0.02; // del_w

// Paramteres defined to calculate tau ****
#define someSmallNumb 1.0e-5
#define Pi 3.14159
#define Temp 400.0
#define e 1.6e-19
#define eps_0 8.85e-12
#define K_Boltz 1.38e-23
#define Kuhn 1.0e-9
#define rho_0 1.0e28
// ****************************************
