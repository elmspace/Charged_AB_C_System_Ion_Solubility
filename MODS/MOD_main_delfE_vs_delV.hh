void MOD_main_delfE_vs_delV(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  // Cleaning the .dat file
  std::ofstream outputFile37("./RESULTS/MOD_main_delfE_vs_delV.dat");
  outputFile37 << std::endl;
  outputFile37.close();
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  double fE_Par, fE_Per;
  
  int i, j, Iter;
  double delV, MaxVolt;
  

  MaxVolt = 30.0;
  delV = 2.5;

  Iter = int(MaxVolt/delV);
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
  
  for(i=0;i<Iter;i++){
  
    
    // Overwriting the chosen parameters:
    // Potential difference *************************
    psi_bc_1=i*delV;
    psi_bc_2=0.0; // Will be kept at zero all the time
    //+++++++++++++++++++++++++++++++++++
    
    for(j=0;j<2;j++){
      // Setting the structure 1=on 0=off
      if(j==0){
	PER=0;             // perpendicular
	PAR_AS=1;          // parallel A by substrate
	PAR_BS=0;          // parallel B by substrate
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

    // Initial_Read is if there is already a .read file for the structre
    Initial_Read=0; // 1=yes 0=no
    // 0=read 1=set manually 2=random
    Iomega=0;
    
    std::cout<<"delV="<<psi_bc_1<<" "<<"  PA="<<PA<<" "<<"  fE_Par="<<fE_Par<<" "<<"  fE_Per="<<fE_Per<<" "<<"  tau="<<tau<<std::endl;
    
    std::ofstream outputFile37("./RESULTS/MOD_main_delfE_vs_delV.dat" , ios::app);
    outputFile37 <<psi_bc_1<<" "<<PA<<" "<<fE_Par<<" "<<fE_Per<<std::endl;
    outputFile37.close(); 
    
    
  }
  
  
  Save_Stuff(w,phi,psi,diel_cons);
  
};
