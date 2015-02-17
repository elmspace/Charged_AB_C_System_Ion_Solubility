void MOD_main_Vcritical_vs_PA(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  // Cleaning the .dat file
  std::ofstream outputFile37("./RESULTS/MOD_main_Vcritical_vs_PA.dat");
  outputFile37 << std::endl;
  outputFile37.close();

  std::ofstream outputFile47("./RESULTS/MOD_main_delfE_vs_delV.dat");
  outputFile47 << std::endl;
  outputFile47.close();
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  double fE_Par;
  double  fE_Per;
  double delV, delPA;
  double V_critical;
  double PA_limit;
  double del_fE_now, del_fE_old;
  int j;
 
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);

  // Overwriting the chosen parameters:
  psi_bc_1=0.0;
  psi_bc_2=0.0; // Will be kept at zero all the time
  PA=0.00000000001;
  // Average concentrations (Because pIave depends on PA)
  pIave=PA*pAave;
  //+++++++++++++++++++++++++++++++++++

  // Setting the top limit of PA
  PA_limit=0.005;
  //+++++++++++++++++++++++++++++++++++
  
  // Setting the del parameters (step sizes)
  delV=1.0;
  delPA=0.0005; // 20 steps from 0 to PALimit
  //+++++++++++++++++++++++++++++++++++

   
  do{ // this do loop will run over PA values
    
    std::cout<<"PA="<<PA<<std::endl;
    
    do{ // this do loop will run over voltages
      
      
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
      
      del_fE_now=fE_Par-fE_Per;
      if(fE_Par<fE_Per){del_fE_old=del_fE_now;}
      
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      // Initial_Read is if there is already a .read file for the structre
      Initial_Read=0; // 1=yes 0=no
      // 0=read 1=set manually 2=random
      Iomega=0;
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

      std::cout<<"delV="<<psi_bc_1<<" "<<"  delfE="<<fE_Par-fE_Per<<" "<<"  tau="<<tau<<" "<<" PA="<<PA<<std::endl;
      
      std::ofstream outputFile47("./RESULTS/MOD_main_delfE_vs_delV.dat" , ios::app);
      outputFile47 <<psi_bc_1<<" "<<PA<<" "<<fE_Par<<" "<<fE_Per<<std::endl;
      outputFile47.close();

      // Overwriting the chosen parameters:
      // Potential difference *************************
      psi_bc_1+=delV;
      psi_bc_2=0.0; // Will be kept at zero all the time
      //+++++++++++++++++++++++++++++++++++
      
    }while(fE_Par<fE_Per);
    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    
    // Setting the critical Voltage
    V_critical = FindIntersect (psi_bc_1-2.0*delV, del_fE_old, psi_bc_1-delV, del_fE_now, 0.0, 0.0, 1.0, 0.0);
    

    std::ofstream outputFile37("./RESULTS/MOD_main_Vcritical_vs_PA.dat" , ios::app);
    outputFile37 <<V_critical<<" "<<PA<<" "<<tau<<std::endl;
    outputFile37.close();

    std::ofstream outputFile47("./RESULTS/MOD_main_delfE_vs_delV.dat" , ios::app);
    outputFile47 <<" "<<std::endl;
    outputFile47 <<" "<<std::endl;
    outputFile47.close();

    
    // Set the voltage back for new scan
    // It doesnt have to start from 0 again
    //psi_bc_1-=(5.0*delV);
    psi_bc_1-=5.0*delV;
    psi_bc_2=0.0; // Will be kept at zero all the time

    // Setting the PA
    PA+=delPA;
    // Average concentrations (Because pIave depends on PA)
    pIave=PA*pAave;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // Initial_Read is if there is already a .read file for the structre
    Initial_Read=0; // 1=yes 0=no
    // 0=read 1=set manually 2=random
    Iomega=1;
    // delta_x delta_y and delta_s
    ds=1.0/NAB;
    dxy[0]=(8.075)/Nx;
    dxy[1]=(8.075)/Ny;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    
  }while(PA<PA_limit);
  
  
  
  Save_Stuff(w,phi,psi,diel_cons);
  
};
