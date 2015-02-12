void MOD_main(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  double FE;


  // Setting the structure 1=on 0=off
  PER=0;                         // perpendicular
  PAR_AS=1;                     // Parallel configuration, with A attracted to the substrate
  PAR_BS=0;                     // Parallel configuration, with B attrcated to the substrate
  MIX=0;                        // mixed
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
  omega(w);
  
  FE=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
  
  Save_Stuff(w,phi,psi,diel_cons);
  
};
