void MOD_main( ){

  int i,j;

  // Length of A block
  NA = 30;
  // Potential Difference
  deltaV = 20.0;
  // Dielectric constants
  kA=6.0; //6.0
  kB=2.5; //2.5
  // Charge percentage 1e-10 is 0
  PA=1.0e-20;
  
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
  
  omega(w);
  
  FreeEnergy( );
  
  std::cout<<"fE="<<Free_Energy<<"   Lx="<<Lx<<"    Ly="<<Ly<<std::endl;
  
  
};
