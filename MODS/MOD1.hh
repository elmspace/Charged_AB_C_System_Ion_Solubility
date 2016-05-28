void MOD1( ){

  int i,j;

  SaveData(0);
  
  NA = 50;
  deltaV = 0.0;
  kA=6.0;
  kB=2.5;
  PA=1.0e-2;

  omega(w);
  do{

    parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
    FreeEnergy( );
    SaveData(1);
    
    std::cout<<"fE="<<Free_Energy<<"   xAB="<<xAB<<std::endl;
    
    xAB-=0.05;
  }while(xAB>10.0);

};
