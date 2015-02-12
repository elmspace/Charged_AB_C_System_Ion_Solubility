/*

This program solve the modified diffusion equations and Boltmann-Poisson equation in 2D
For a AB diblock copolymers with a negatively charged A-block and neutral B-block
There are also positive ions in the system, so the system is globally charge neutral


Written By:   Ashkan Dehghan [McMaster University]

*/
#include "./global.hh"
#include "./ABI/parametersABI.hh"
#include "./ABI/WaveVectors.hh"
#include "./ABI/omega.hh"
#include "./ABI/Slope_Calc.hh"
#include "./ABI/Slope_Calc2.hh"
#include "./ABI/solvediffeq.hh"
#include "./ABI/A_Arrays.hh"
#include "./ABI/SolvePsi.hh"
#include "./ABI/ConcAB.hh"
#include "./ABI/ConcI.hh"
#include "./ABI/fEhomo.hh"
#include "./ABI/Incomp.hh"
#include "./ABI/write_readFiles.hh"
#include "./ABI/FreeEnergy_Box_Edition.hh"
#include "./ABI/size_adjust_1D_x.hh"
#include "./ABI/size_adjust_2D_xy.hh"
#include "./ABI/FreeEnergy.hh"
#include "./ABI/Save_Stuff.hh"

#include "./MODS/MOD_main.hh"
#include "./MODS/MOD_main_delfE_vs_delV.hh"

using namespace std;


int main(){

  int i,ii;
  double ***w;
  double ***phi;
  double **psi;
  double **eta;
  double **diel_cons;
  double *chi;
  double **chiMatrix;
  double f;
  double ds;
  double *Ns;
  double **k_vector;
  double *dxy;
  double ***x_sub;


  // The ChainType+1 corresponds to 0=A, 1=B, 2=I and 3=e
  w=create_3d_double_array(ChainType+1,Nx,Ny,"w"); // w[3] is the suxilary field for total charge
  phi=create_3d_double_array(ChainType+1,Nx,Ny,"phi"); // phi[3] is the total charge at i,j
  psi=create_2d_double_array(Nx,Ny,"psi");
  eta=create_2d_double_array(Nx,Ny,"eta");
  diel_cons=create_2d_double_array(Nx,Ny,"diel_cons");
  chi=create_1d_double_array(ChainType,"chi");
  Ns=create_1d_double_array(ChainType,"Ns");
  k_vector=create_2d_double_array(Nx,Ny,"k_vector");
  dxy=create_1d_double_array(2,"dxyz");
  chiMatrix=create_2d_double_array(ChainType,ChainType,"chiMatrix");
  x_sub=create_3d_double_array(ChainType,Nx,Ny,"x_sub");


  long iseed;
  time_t t;
  iseed=time(&t);
  srand48(iseed);
  
  // Setting up the FFTW for MDE +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  input_q=(double*)fftw_malloc(sizeof(double)*Nx*Ny);
  transformed_q=(double*)fftw_malloc(sizeof(double)*Nx*Ny);
  final_q=(double*)fftw_malloc(sizeof(double)*Nx*Ny);
  forward_plan=fftw_plan_r2r_2d(Nx,Ny,input_q,transformed_q,FFTW_REDFT10,FFTW_REDFT10,i);
  inverse_plan=fftw_plan_r2r_2d(Nx,Ny,transformed_q,final_q,FFTW_REDFT01,FFTW_REDFT01,i);
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 
  // Mods are customized main.cpps, which will run a specific calculation
  // I made it this way to keep main clean
  // For description of what each mod, look at the end of this file

  

  //MOD_main(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub,f);
  MOD_main_delfE_vs_delV(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub,f);
  //MOD_main_Vcritical_vs_PA(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub,f);
  //MOD_main_Vcritical_vs_mu(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub,f);
  
  //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



  //Destroy memory allocations------------
  fftw_free(input_q);
  fftw_free(transformed_q);
  fftw_free(final_q);
  fftw_destroy_plan(forward_plan);
  fftw_destroy_plan(inverse_plan);

  destroy_3d_double_array(w);
  destroy_2d_double_array(psi);
  destroy_2d_double_array(eta);
  destroy_2d_double_array(diel_cons);
  destroy_3d_double_array(phi);
  destroy_1d_double_array(chi);
  destroy_1d_double_array(Ns);
  destroy_2d_double_array(k_vector);
  destroy_1d_double_array(dxy);
  destroy_2d_double_array(chiMatrix);
  destroy_3d_double_array(x_sub);
  //-------------------------------------
  

  return 0;
}


// INFO ++++++++++++++++++++
/*

MOD_main ---> This is a simple mod, which will use the parameters in the parameters.hh to run one calculation


MOD_main_delfE_vs_delV ---> This mod will compare the free energy of the parallel to the perpendicular for a given parameter set as a function of voltage.
                            The final output would be a plot of delF vs delV


MOD_main_Vcritical_vs_PA ---> This mod will run over different configuration for a set of parameters and compare their free energy for a given voltage. At the critical voltage where the 
                              perpendicular configuration is more favarable, it will terminate and starts scanning for Vcritical for a different PA value. The final product would be a 
                              a function of Vcritical vs PA

MOD_main_Vcritical_vs_mu ---> This mod will run over different configuration for a set of parameters and compare their free energy for a given voltage. At the critical voltage where the 
                              perpendicular configuration is more favarable, it will terminate and starts scanning for Vcritical for a different mu value. The final product would be a 
                              a function of Vcritical vs mu (here mu is the interaction strength between the A/B and substrates)


 */
