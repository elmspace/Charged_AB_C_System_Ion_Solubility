void MOD_main( ){

  double FE;
  int i,j;

  // Length of A block
  NA = 50;
  // Potential Difference
  deltaV = 0.0;
  // Dielectric constants
  kA=1.0; //6.0
  kB=1.0; //2.5
  // Charge percentage 1e-10 is 0
  PA=1.0e-2;
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
  
  omega(w);
  
  FE=FreeEnergy( );
  
  std::cout<<"fE="<<FE<<"   Lx="<<Lx<<"    Ly="<<Ly<<std::endl;
  

  SaveData( );
  
};
