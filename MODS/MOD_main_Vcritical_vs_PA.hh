void MOD_main_Vcritical_vs_PA(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  // Cleaning the .dat file
  std::ofstream outputFile37("./RESULTS/MOD_main_Vcritical_vs_PA.dat");
  outputFile37 << std::endl;
  outputFile37.close();
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  double fE_Par = 0.0;
  double  fE_Per=0.0;
  double delV, delPA;
  double V_critical;
  double PA_limit;
  int j;
 
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);

  // Overwriting the chosen parameters:
  psi_bc_1=0.0;
  PA=0.0;
  //+++++++++++++++++++++++++++++++++++

  // Setting the top limit of PA
  PA_limit=0.001;
  //+++++++++++++++++++++++++++++++++++
  
  // Setting the del parameters (step sizes)
  delV=0.5;
  delPA=5.0e-5; // 20 steps from 0 to PALimit
  //+++++++++++++++++++++++++++++++++++

 


  
  do{ // this do loop will run over PA values
    
    std::cout<<"PA="<<PA<<std::endl;
    
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
      
    }while(fE_Par<fE_Per);
    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    
    // Setting the critical Voltage
    // Using the midpoint between the Vi and Vi+1
    V_critical = psi_bc_1-0.5*delV;
    
    // Set the voltage back for new scan
    // It doesnt have to start from 0 again
    psi_bc_1-=(5.0*delV);

    // Setting the PA
    PA+=delPA;


    std::ofstream outputFile37("./RESULTS/MOD_main_Vcritical_vs_PA.dat" , ios::app);
    outputFile37 <<V_critical<<" "<<PA<<" "<<tau<<std::endl;
    outputFile37.close();
    
  }while(PA<PA_limit);
  
  
  
  Save_Stuff(w,phi,psi,diel_cons);
  
};
