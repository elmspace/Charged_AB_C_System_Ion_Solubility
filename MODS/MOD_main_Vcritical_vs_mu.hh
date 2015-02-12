void MOD_main_Vcritical_vs_mu(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  // Cleaning the .dat file
  std::ofstream outputFile37("./RESULTS/MOD_main_Vcritical_vs_mu.dat");
  outputFile37 << std::endl;
  outputFile37.close();
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  double fE_Par, fE_Per;
  double delV, delmu;
  double V_critical;
  double mu_limit;
  int j;

  //   ** IMPORTANT**
  // When setting mu (interaction strength between A/B and substrates) it is importnat to
  // check the configuration. If A is attracted to the substrate the the PAR_AS must be 1 and not PAR_BS
  // also, the mu_limit and delmu must be set accordingly, so you dont step in the wrong direction, which
  // will result in wrong results and infinite loop
  
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);

  // Overwriting the chosen parameters:
  psi_bc_1=0.0;
  mu=0.0;
  //+++++++++++++++++++++++++++++++++++

  // Setting the top limit of mu
  mu_limit=5.0;
  //+++++++++++++++++++++++++++++++++++
  
  // Setting the del parameters (step sizes)
  delV=2.5;
  delmu=1.0e-1; 
  //+++++++++++++++++++++++++++++++++++

 


  
  do{ // this do loop will run over mu values
    
    std::cout<<"mu="<<mu<<std::endl;
    
    do{ // this do loop will run over voltages
      
      // Overwriting the chosen parameters:
      // Potential difference *************************
      psi_bc_1+=delV;
      psi_bc_2=0.0; // Will be kept at zero all the time
      //+++++++++++++++++++++++++++++++++++
      
      for(j=0;j<2;j++){
	// Setting the structure 1=on 0=off
	if(j==0){
	  PER=0;             // perpendicular
	  PAR_AS=0;          // parallel A by substrate
	  PAR_BS=1;          // parallel B by substrate
	  MIX=0;             // mixed
	}else{
	  PER=1;             // perpendicular
	  PAR_AS=0;          // parallel A by substrate
	  PAR_BS=0;          // parallel B by substrate
	  MIX=0;             // mixed
	}
	
	omega(w);
	
	if((PAR_AS==1)||(PAR_BS==1)){
	  fE_Par=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
	} else if(PER==1){
	  fE_Per=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
	}
	
	
      }
      
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      // Initial_Read is if there is already a .read file for the structre
      Initial_Read=0; // 1=yes 0=no
      // 0=read 1=set manually 2=random
      Iomega=0;
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

      std::cout<<"delV="<<psi_bc_1<<" "<<"  delfE="<<fE_Par-fE_Per<<" "<<"  tau="<<tau<<std::endl;
      
    }while(fE_par<fE_per);
    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    
    // Setting the critical Voltage
    // Using the midpoint between the Vi and Vi+1
    V_critical = psi_bc_1-0.5*delV;
    
    // Set the voltage back for new scan
    // It doesnt have to start from 0 again
    psi_bc_1-=(5.0*delV);

    // Setting the PA
    mu+=delmu;


    std::ofstream outputFile37("./RESULTS/MOD_main_Vcritical_vs_mu.dat" , ios::app);
    outputFile37 <<V_critical<<" "<<mu<<" "<<tau<<std::endl;
    outputFile37.close();

    // This will check for the correct combination of mu and configuration
    if((mu<0.0)&&(PAR_AS==1)){std::cout<<"Your initial condition and this parameter dont match."<<std::endl;}
    if((mu>0.0)&&(PAR_BS==1)){std::cout<<"Your initial condition and this parameter dont match."<<std::endl;}
    
  }while(mu<mu_limit);
  
  
  
  Save_Stuff(w,phi,psi,diel_cons);
  
};
