void parametersAB(double *chi, double f, double &ds, double *Ns,double *dxy, double **chiMatrix, double ***x_sub){
  
  int i,j;
  double tt; // This is for convergence of BP solver

  // Set to 1 to minimize box size and 0 to not
  box_min=1;

  // 0=read 1=set manually 2=random
  Iomega=1;
 
  // Initial_Read is if there is already a .read file for the structre
  Initial_Read=0; // 1=yes 0=no

  // Dielectric constants
  kA=6.0;
  kB=2.5;
  
  // Charge percentage 1e-10 is 0
  PA=0.001;

  // This is for convering the BP solver
  tt=cos(Pi/Nx)+cos(Pi/Ny);
  converg=(8.0-sqrt(64.0-16.0*tt*tt))/(tt*tt);
  
  // Potential difference *************************
  psi_bc_1=0.0;
  psi_bc_2=0.0; // Will be kept at zero all the time

  // This is the surface interaction with substrate if - then B is attracted to substrate, if + then A is attracted
  mu=-1.0;

  if((mu<0.0)&&(PAR_AS==1)){std::cout<<"Your initial condition and this parameter dont match."<<std::endl;}
  if((mu>0.0)&&(PAR_BS==1)){std::cout<<"Your initial condition and this parameter dont match."<<std::endl;}
  
  
  // Degree of polymerization
  Ns[0]=50;               // A
  Ns[1]=50;               // B
  Ns[2]=1;
  NAB=Ns[0]+Ns[1];

  // Setting the Bjerrum lenth
  //tau=(e*e*Kuhn*Kuhn*4.0*Pi*rho_0)/(eps_0*K_Boltz*Temp);  // This is Michael's definition of the tau parameter
  //std::cout<<"tau= "<<tau<<std::endl;
  tau=(e*e)/(eps_0*K_Boltz*Temp*Kuhn); // This is according to An-Chang's paper
  //std::cout<<"tau= "<<tau<<std::endl;
 


  // Fraction of A in diblock
  f=double(Ns[0]/NAB);

  // Average concentrations
  pAave=f;
  pBave=1.0-f;
  pIave=PA*pAave;

  // Interaction parameters
  chi[0]=20.0;  //xAB
  chi[1]=0.0;  //xAI
  chi[2]=0.0;  //xBI
  
  
  // delta_x delta_y and delta_s
  ds=1.0/NAB;
  dxy[0]=(8.075)/Nx;
  dxy[1]=(8.075)/Ny;

  
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
