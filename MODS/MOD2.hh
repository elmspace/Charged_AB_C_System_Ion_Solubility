void MOD2( ){

  int i,j;

  SaveData(0);

  omega(w);
  
  NA = 30;
  deltaV = 0.0;
  kA=6.0;
  kB=2.5;
  PA=1.0e-3;

  do{
    parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
    FreeEnergy( );
    SaveData(1);
    std::cout<<"fE="<<Free_Energy<<"   deltaV="<<deltaV<<std::endl;
    deltaV+=0.1;
  }while(abs(deltaV)<3.0);

};
