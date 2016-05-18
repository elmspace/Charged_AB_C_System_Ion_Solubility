void MOD1( ){

  int i,j;

  SaveData(0);

  omega(w);
  
  NA = 40;
  deltaV = 0.0;
  kA=6.0;
  kB=2.5;
  PA=1.0e-20;


  do{
    parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
    FreeEnergy( );
    SaveData(1);
    std::cout<<"fE="<<Free_Energy<<"   NA="<<NA<<std::endl;
    NA--;
  }while(abs(Free_Energy)>someSmallNumb);

};
