void MOD_main_Vcritical_vs_mu_all_Phases(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  // Cleaning the .dat file
  std::ofstream outputFile37("./RESULTS/MOD_main_Vcritical_vs_mu_all_Phases.dat");
  outputFile37 << std::endl;
  outputFile37.close();
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  double fE_Par, fE_Per, fE_Mix;
  double delV, psi_bc_Limit;
  double delmu, mu_Limit;
  double cond,Limit;
  int V_msg, mu_msg;
  int i,j;

  //   ** IMPORTANT**
  // When setting mu (interaction strength between A/B and substrates) it is importnat to
  // check the configuration. If A is attracted to the substrate the the PAR_AS must be 1 and not PAR_BS
  // also, the mu_limit and delmu must be set accordingly, so you dont step in the wrong direction, which
  // will result in wrong results and infinite loop
  
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);

  // Overwriting the chosen parameters:
  psi_bc_1=21.0;
  psi_bc_2=0.0; // This is always set to 0.0
  mu=-3.5; //- for B + for A near substrate
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
  //+++++++++++++++++++++++++++++++++++

  // Setting the del parameters (step sizes)
  delV=1.0;
  psi_bc_Limit=100.0;

  delmu=-0.1;
  mu_Limit=7.0;
  //+++++++++++++++++++++++++++++++++++


  V_msg=0;
  mu_msg=1;
  
  
  
  do{ // this do loop will run over voltages or mu
    
    
    for(j=0;j<2;j++){
      // Setting the structure 1=on 0=off
      if(j==0){
	PER=1;             // perpendicular
	PAR_AS=0;          // parallel A by substrate
	PAR_BS=0;          // parallel B by substrate
	MIX=0;             // mixed
      }else if (j==1){
	PER=0;             // perpendicular
	PAR_AS=0;          // parallel A by substrate
	PAR_BS=0;          // parallel B by substrate
	MIX=1;             // mixed
      }else if (j==2){
	PER=0;             // perpendicular
	PAR_AS=0;          // parallel A by substrate
	PAR_BS=1;          // parallel B by substrate
	MIX=0;             // mixed
      }else{
	std::cout<<"Something went wrong."<<std::endl;
      }
      
      omega(w);
      
      if((PAR_AS==1)||(PAR_BS==1)){
	fE_Par=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
      } else if(PER==1){
	fE_Per=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
      } else if(MIX==1){
	fE_Mix=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
      }
      
      
    }
    
    
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // Initial_Read is if there is already a .read file for the structre
    Initial_Read=1; // 1=yes 0=no
    // 0=read 1=set manually 2=random
    Iomega=0;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    
    std::cout<<"delV="<<psi_bc_1<<"    mu="<<mu<<"   fE_Par="<<fE_Par<<"   fE_Per="<<fE_Per<<"   fE_Mix="<<fE_Mix<<"  tau="<<tau<<std::endl;

    std::ofstream outputFile37("./RESULTS/MOD_main_Vcritical_vs_mu_all_Phases.dat" , ios::app);
    outputFile37 <<psi_bc_1<<" "<<mu<<" "<<fE_Par<<" "<<fE_Per<<" "<<fE_Mix<<" "<<tau<<std::endl;
    outputFile37.close();
    



    if(V_msg==1){
      psi_bc_1+=delV;
      psi_bc_2=0.0;

      cond=psi_bc_1;
      Limit=psi_bc_Limit;
    }else if(mu_msg==1){
       mu+=delmu;
       //__________________
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
       //__________________

       cond=mu;
       Limit=mu_Limit;
    }


      

  }while(abs(cond)<abs(Limit));
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  
   
  
  Save_Stuff(w,phi,psi,diel_cons);
  
};
