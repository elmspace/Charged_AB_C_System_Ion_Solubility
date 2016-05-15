void MOD_main( ){

  double FE;
  int i,j;

  NA = 50;
  deltaV = 0.0;
  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
  
  omega(w);
  
  FE=FreeEnergy( );
  
  std::cout<<"fE="<<FE<<"   Lx="<<Lx<<"    Ly="<<Ly<<std::endl;
  

  SaveData( );
  
};
