void MOD_main(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  double FE;
  int i,j;

  // Setting the structure 1=on 0=off
  PER=0;                         // perpendicular
  PAR_AS=0;                     // Parallel configuration, with A attracted to the substrate
  PAR_BS=0;                     // Parallel configuration, with B attrcated to the substrate
  MIX=1;                        // mixed
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);

  // 0=read 1=set manually 2=random
  Iomega=1;

  // Charge percentage 1e-10 is 0
  PA=0.00000000001;
  pIave=PA*pAave;
  
  // Potential difference *************************
  psi_bc_1=25.0;
  psi_bc_2=0.0; // Will be kept at zero all the time
  
  mu=-7.0; // set to - for B_Sub and set to + for A_Sub
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

  
  omega(w);
  
  FE=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
  
  std::cout<<"fE="<<FE<<"   PA="<<PA<<"    mu="<<mu<<std::endl;
  

  Save_Stuff(w,phi,psi,diel_cons);
  
};
