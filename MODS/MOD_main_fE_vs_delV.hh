void MOD_main_fE_vs_delV(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  // Cleaning the .dat file
  std::ofstream outputFile37("./RESULTS/MOD_main_fE_vs_delV.dat");
  outputFile37 << std::endl;
  outputFile37.close();
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  double fE_Phase;
  
  int i, j, Iter;
  double delV, MaxVolt;
  

  MaxVolt = 100.0;
  delV = 1.0;

  Iter = int(MaxVolt/delV);
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);

  // Charge percentage 1e-10 is 0
  PA=0.00000000001;
  pIave=PA*pAave;
  
  // Overwriting the chosen parameters:
  // Potential difference *************************
  psi_bc_1=20.0;
  psi_bc_2=0.0; // Will be kept at zero all the time
  //+++++++++++++++++++++++++++++++++++

  
  mu=-5.0; // set to - for B_Sub and set to + for A_Sub
  //||||||||||||||||||||||||||||||||||||||||||||||
  // This is where we define the h(r) only nonzero at surfaces
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      if(i==0){
	x_sub[0][i][j]=-mu;
	x_sub[1][i][j]=mu;
      }else if(i==(Nx-1)){
	x_sub[0][i][j]=-mu;
	x_sub[1][i][j]=mu;
      }else{
	x_sub[0][i][j]=0.0;
	x_sub[1][i][j]=0.0;
      }
    }
  }
  //||||||||||||||||||||||||||||||||||||||||||||||

  
  PER=1;             // perpendicular
  PAR_AS=0;          // parallel A by substrate
  PAR_BS=0;          // parallel B by substrate
  MIX=0;             // mixed

  omega(w);
  
  do{
     
    fE_Phase=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
     
    
    std::cout<<"delV="<<psi_bc_1<<" "<<"  PA="<<PA<<" "<<"  fE_Phase="<<fE_Phase<<" "<<"  tau="<<tau<<std::endl;
    
    std::ofstream outputFile37("./RESULTS/MOD_main_fE_vs_delV.dat" , ios::app);
    outputFile37 <<psi_bc_1<<" "<<PA<<" "<<fE_Phase<<std::endl;
    outputFile37.close(); 


    // Overwriting the chosen parameters:
    // Potential difference *************************
    psi_bc_1+=delV;
    psi_bc_2=0.0; // Will be kept at zero all the time
    //+++++++++++++++++++++++++++++++++++
    
    
  }while(psi_bc_1<MaxVolt);
  
  
  Save_Stuff(w,phi,psi,diel_cons);
  
};
