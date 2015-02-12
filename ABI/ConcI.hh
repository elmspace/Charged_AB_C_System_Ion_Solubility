double ConcI(double ***phi, double ***w, double *Ns,double *dxy, double **psi){

  int         i,j,s;
  double      Q;
  double      **qI;
  double      **wI_eff;
  
  qI=create_2d_double_array(Nx,Ny,"qI");
  wI_eff=create_2d_double_array(Nx,Ny,"wI_eff"); // Allocating memory for wI_eff

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      wI_eff[i][j]=w[2][i][j]+w[3][i][j];
    }
  }
  
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      qI[i][j]=exp(-wI_eff[i][j]/NAB);
    }
  }
  
  // Here we are doing the sum to get the single chain partition function
  Q=0.0;
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      Q+=qI[i][j]*dxy[0]*dxy[1];
    }
  }
  // Normalizing with respect to the volume of the box
  Q/=((dxy[0]*Nx)*(dxy[1]*Ny));
  
  // Here we do the concentration calculation
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){	
      phi[2][i][j]=(pIave/Q)*qI[i][j];
    }
  }
  
  //clearing the memory
  destroy_2d_double_array(qI);  
  destroy_2d_double_array(wI_eff);
  
  return Q;


};
