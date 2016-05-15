void omega(double ***w){
  // Here we are initializing the omega fields

  
  int i,j;
  int ii,jj;

  
  // Initializing the omeg fields to zero
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      w[0][i][j]=0.0;
      w[1][i][j]=0.0;
      w[2][i][j]=0.0;
      w[3][i][j]=0.0;
    }
  }
  // +++++++++++++++++++++++++++++++++++++

  
  if(Iomega==0){

    std::ifstream infile;

    if(LAM==1){infile.open("./OMEGA/Initial/LAM.read");}
    if(HEX==1){infile.open("./OMEGA/Initial/HEX.read");}
 
      
    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	infile >> ii >> jj >> w[0][i][j] >> w[1][i][j] >> w[2][i][j] >> w[3][i][j]; 
      }
    }
    infile.close();
    
  }else if(Iomega==1){

    if(LAM==1){
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  w[0][i][j]=-1.0*cos(2.0*Pi*i/Nx);
	}
      }
    }else if(HEX==1){
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  w[0][i][j]=-1.0*cos(2.0*Pi*i/Nx)*cos(2.0*Pi*j/Ny);
	}
      }
    }

  }


};
