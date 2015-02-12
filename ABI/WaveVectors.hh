void WaveVectors(double **k_vector, double *dxy){

  int             i,j;
  double          lx,ly;
  double          *Kx,*Ky;

  Kx=create_1d_double_array(Nx,"Kx");
  Ky=create_1d_double_array(Ny,"Ky");
 
  lx=dxy[0]*Nx;
  ly=dxy[1]*Ny;
 
  for(i=0;i<Nx;i++){Kx[i]=(Pi*i)/(lx);}
  for(i=0;i<Nx;i++){Kx[i]*=Kx[i];}

  for(i=0;i<Ny;i++){Ky[i]=(Pi*i)/(ly);}
  for(i=0;i<Ny;i++){Ky[i]*=Ky[i];}

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      k_vector[i][j]=Kx[i]+Ky[j];
    }
  }

  // Destroying the allocated memory ---------------
  destroy_1d_double_array(Kx);
  destroy_1d_double_array(Ky);
  // -----------------------------------------------

  
};
