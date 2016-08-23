void MOD1( ){

  int i,j;

  SaveData(0);
  
  deltaV = 0.0;
  kA=6.0;
  kB=2.5;
  PA=ChargeDensity;

  omega(w);
  do{

    parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
    FreeEnergy( );
    SaveData(1);
    
    std::cout<<"fE="<<Free_Energy<<"   xAB="<<xAB<<std::endl;
  
    xAB-=0.01;
  }while(xAB>5.0);

};
