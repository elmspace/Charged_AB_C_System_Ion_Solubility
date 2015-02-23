void MOD_main_Lam_Spacing(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  // Cleaning the .dat file
  std::ofstream outputFile37("./RESULTS/MOD_main_Lam_Spacing.dat");
  outputFile37 << std::endl;
  outputFile37.close();
  
  double FE;
  double PA_Max, delPA;
  int i,j;

  

  // Setting the structure 1=on 0=off
  PER=1;                         // perpendicular
  PAR_AS=0;                     // Parallel configuration, with A attracted to the substrate
  PAR_BS=0;                     // Parallel configuration, with B attrcated to the substrate
  MIX=0;                        // mixed
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
  
  // Charge percentage 1e-10 is 0
  PA=0.00000000001;
  pIave=PA*pAave;

  PA_Max=0.04;
  delPA=0.001;

  do{
    
    omega(w);
    
    FE=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
    
    std::ofstream outputFile37("./RESULTS/MOD_main_Lam_Spacing.dat" , ios::app);
    outputFile37 <<PA<<" "<<Lx<<" "<<Ly<<" "<<tau<<std::endl;
    outputFile37.close();

    std::cout<<" PA="<<PA<<"   Lx="<<Lx<<"   Ly="<<Ly<<"   tau="<<tau<<std::endl;
  
    // Charge percentage 1e-10 is 0
    PA+=delPA;
    pIave=PA*pAave;
    
  }while(PA<PA_Max);

  Save_Stuff(w,phi,psi,diel_cons);
  
  
};
