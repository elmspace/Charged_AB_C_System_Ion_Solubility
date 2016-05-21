void MOD2( ){

  int i,j;
  double fE_Lam, fE_Hex;
  double fE_LamP, fE_HexP;
  double ml, mh, bl, bh;
  double fAc;
  char phase;

  LAM=1;
  HEX=1;
  SaveData(0);
  
  NA = 40;
  deltaV = 0.0;
  kA=6.0;
  kB=2.5;
  PA=1.0e-20;

  do{
    NA = 40;
    do{
      for(int i=0; i<2; i++){
	if(i==0){LAM=1;HEX=0;phase='L';
	}else{LAM=0;HEX=1;phase='H'; }
	
	omega(w);
	parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);
	FreeEnergy( );
	
	std::cout<<Free_Energy<<" "<<(NA/NAB)<<" "<<phase<<std::endl;

	if(LAM==1){fE_Lam=Free_Energy;}
	if(HEX==1){fE_Hex=Free_Energy;}

	SaveData(1);
	
	if(i==1 && fE_Hex<fE_Lam){
	  ml=(fE_Lam-fE_LamP)/(NA-(NA+1));
	  mh=(fE_Hex-fE_HexP)/(NA-(NA+1));
	  bl=fE_Lam-ml*NA;
	  bh=fE_Hex-mh*NA;
	  fAc=((bh-bl)/(ml-mh))/NAB;
	  std::cout<<xAB<<" "<<fAc<<std::endl;
	}
	fE_LamP = fE_Lam;
	fE_HexP = fE_Hex;
      }
     
      NA--;
    }while(NA>1);
    exit(0);
    xAB-=0.5;
  }while(xAB>10.0);


};
