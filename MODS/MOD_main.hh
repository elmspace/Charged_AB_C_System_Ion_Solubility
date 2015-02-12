void MOD_main(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  double FE;


  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
  omega(w);
  
  FE=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
  
  Save_Stuff(w,phi,psi,diel_cons);
  
};
