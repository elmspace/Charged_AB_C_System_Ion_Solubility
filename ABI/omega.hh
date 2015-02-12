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

  
  if(Iomega==0){// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Reading omega.read fiels

    std::ifstream infile;
    if(Initial_Read==1){
      if(PAR_AS==1){infile.open("./OMEGA/Initial/PAR_AS.read");}
      if(PAR_BS==1){infile.open("./OMEGA/Initial/PAR_BS.read");}
      if(PER==1){infile.open("./OMEGA/Initial/PER.read");}
      if(MIX==1){infile.open("./OMEGA/Initial/MIX.read");}
    }else{
      if(PAR_AS==1){infile.open("./OMEGA/PAR_AS.read");}
      if(PAR_BS==1){infile.open("./OMEGA/PAR_BS.read");}
      if(PER==1){infile.open("./OMEGA/PER.read");}
      if(MIX==1){infile.open("./OMEGA/MIX.read");}
    }
      
    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	infile >> ii >> jj >> w[0][i][j] >> w[1][i][j] >> w[2][i][j] >> w[3][i][j]; 
      }
    }
    infile.close();
    
  }else if(Iomega==1){//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Manually setting the fields

    if(PAR_AS==1){
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  w[0][i][j]=-10.0*cos(4.0*Pi*i/Nx);
	  w[1][i][j]=10.0*cos(4.0*Pi*i/Nx);
	}
      }
    }else if(PAR_BS==1){
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  w[1][i][j]=-10.0*cos(4.0*Pi*i/Nx);
	  w[0][i][j]=10.0*cos(4.0*Pi*i/Nx);
	}
      }
    }else if(PER==1){
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  w[0][i][j]=-10.0*cos(4.0*Pi*j/Ny);
	  w[1][i][j]=10.0*cos(4.0*Pi*j/Ny);
	}
      }
    }else{
      std::cout<<"No structure was chosen."<<std::endl;
    }

  }else if(Iomega==2){//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Random Fields

    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	w[0][i][j]=-0.01*(drand48()-0.50);
	w[1][i][j]=-0.01*(drand48()-0.50);
	w[2][i][j]=-0.01*(drand48()-0.50);
      }
    }

  }

};
