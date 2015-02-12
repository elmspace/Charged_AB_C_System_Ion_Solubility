void Slope_Calc(double **f_func , int direc ,double  *dxy, double **slope){

  int i,j;
  double m,b;
  double **g_func;
  

  if(direc==0){
    g_func=create_2d_double_array(Nx,Ny,"g_func");
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    for(i=0;i<(Nx-1);i++){
      for(j=0;j<Ny;j++){
	m=(f_func[i+1][j]-f_func[i][j])/dxy[0];
	b=f_func[i][j]-(m*dxy[0]*i);
	g_func[i][j]=(m*dxy[0]*i)+b;
      }
    }
    for(i=0;i<(Nx-1);i++){
      for(j=0;j<Ny;j++){
	slope[i+1][j]=(g_func[i+1][j]-g_func[i][j])/dxy[0];
      }
    }
    for(j=0;j<Ny;j++){
      slope[0][j]=(g_func[0][j]-f_func[0][j])/(dxy[0]*0.5);
    }
    for(j=0;j<Ny;j++){
      slope[Nx-1][j]=(f_func[Nx-1][j]-g_func[Nx-2][j])/(dxy[0]*0.5);
    }
    destroy_2d_double_array(g_func);
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  }else if(direc==1){
    g_func=create_2d_double_array(Nx,Ny,"g_func");
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    for(i=0;i<Nx;i++){
      for(j=0;j<(Ny-1);j++){
	m=(f_func[i][j+1]-f_func[i][j])/dxy[1];
	b=f_func[i][j]-(m*dxy[1]*j);
	g_func[i][j]=(m*dxy[1]*j)+b;
      }
    }
    for(i=0;i<Nx;i++){
      for(j=0;j<(Ny-1);j++){
	slope[i][j+1]=(g_func[i][j+1]-g_func[i][j])/dxy[1];
      }
    }
    for(i=0;i<Nx;i++){
      slope[i][0]=(g_func[i][0]-f_func[i][0])/(dxy[1]*0.5);
    }
    for(i=0;i<Nx;i++){
      slope[i][Ny-1]=(f_func[i][Ny-1]-g_func[i][Ny-2])/(dxy[1]*0.5);
    }
    destroy_2d_double_array(g_func);
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  }else{
    std::cout<<"There is something wrong in Slope_Clac.hh";
  }




};
