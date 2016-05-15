void Slope_Calc2(double **f_func , int direc ,double  *dxy, double **slope){

  int i,j;

 
  if(direc==0){

    for(i=1;i<(Nx-1);i++){
      for(j=0;j<Ny;j++){
	slope[i][j]=(f_func[i+1][j]-f_func[i-1][j])/(2.0*dxy[0]);
      }
    }
    for(j=0;j<Ny;j++){
      slope[0][j]=(f_func[1][j]-f_func[0][j])/dxy[0];
      slope[Nx-1][j]=(f_func[Nx-1][j]-f_func[Nx-2][j])/dxy[0];
    }

  }else if(direc==1){

    for(i=0;i<Nx;i++){
      for(j=1;j<(Ny-1);j++){
	slope[i][j]=(f_func[i][j+1]-f_func[i][j-1])/(2.0*dxy[1]);
      }
    }
    for(i=0;i<Nx;i++){
      slope[i][0]=(f_func[i][1]-f_func[i][0])/dxy[1];
      slope[i][Ny-1]=(f_func[i][Ny-1]-f_func[i][Ny-2])/dxy[1];
    }

  }else{
    std::cout<<"There is something wrong in Slope_Clac.hh";
  }




};
