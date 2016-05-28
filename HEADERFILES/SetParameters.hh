void parametersAB(double *chi, double f, double &ds, double *Ns,double *dxy, double **chiMatrix, double ***x_sub){
  
  int i,j;
  double tt; // This is for convergence of BP solver

  // This is for convering the BP solver
  tt=cos(Pi/Nx)+cos(Pi/Ny);
  converg=(8.0-sqrt(64.0-16.0*tt*tt))/(tt*tt);
 
  // Potential difference *************************
  psi_bc_1=0.0;
  psi_bc_2=deltaV; // Will be kept at zero all the time

  // This is the surface interaction with substrate if - then B is attracted to substrate, if + then A is attracted
  mu=0.0;
 
  // Degree of polymerization
  Ns[0]=NA;       
  Ns[1]=100-Ns[0];              
  Ns[2]=1;
  NAB=Ns[0]+Ns[1];

  // Setting the Tau parameter from theory (relative length)
  tau=(e*e)/(eps_0*K_Boltz*Temp*Kuhn);
  
  // Fraction of A in diblock
  f=double(Ns[0]/NAB);

  // Average concentrations
  pAave=f;
  pBave=1.0-f;
  pIave=PA*pAave;
  
  // Interaction parameters
  chi[0]=xAB;  //xAB
  chi[1]=0.0;  //xAI
  chi[2]=100.0;  //xBI
  
  
  // delta_x delta_y and delta_s *************
  ds=1.0/NAB;
  if(LAM==1){
    if(Lx_Lam<someSmallNumb && Ly_Lam<someSmallNumb){
      dxy[0]=(3.8)/Nx;
      dxy[1]=(3.8)/Ny;
    }else{
      dxy[0]=(Lx_Lam)/Nx;
      dxy[1]=(Ly_Lam)/Ny;
    }
  }else if(HEX==1){
    if(Lx_Hex<someSmallNumb && Ly_Hex<someSmallNumb){
      dxy[0]=(4.0)/Nx;
      dxy[1]=(6.5)/Ny;
    }else{
      dxy[0]=(Lx_Hex)/Nx;
      dxy[1]=(Ly_Hex)/Ny;
    }
  }
  // *****************************************
  
  // Setting up the interaction matrix
  chiMatrix[0][0]=0.0;     // xAA
  chiMatrix[0][1]=chi[0];  // xAB
  chiMatrix[0][2]=chi[1];  // xAI
  
  chiMatrix[1][0]=chi[0];  // xAB
  chiMatrix[1][1]=0.0;     // xBB
  chiMatrix[1][2]=chi[2];  // xBI
  
  chiMatrix[2][0]=chi[1];  // xAI
  chiMatrix[2][1]=chi[2];  // xBI
  chiMatrix[2][2]=0.0;  // xII


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

};
