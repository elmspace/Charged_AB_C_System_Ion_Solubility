void MOD1( ){

  int i,j;

  SaveData(0);
  
  NA = 50;
  deltaV = 5.0;
  kA=6.0;
  kB=2.5;
  PA=1.0e-3;


  do{
    omega(w);
    parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
    FreeEnergy( );
    SaveData(1);
    std::cout<<"fE="<<Free_Energy<<"   NA="<<NA<<std::endl;
    NA--;
  }while(NA>25);

};
