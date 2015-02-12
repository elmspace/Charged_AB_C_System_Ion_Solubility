void Incomp(double **eta, double ***phi, double **delphi){

  int     i,j; 
  double  ptot;

  ptot=0.0;

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      
      ptot=0.0;
      delphi[i][j]=0.0;
      
      ptot=phi[0][i][j]+phi[1][i][j];	
      
      delphi[i][j]=1.0-ptot;
      eta[i][j]-=delphi[i][j];
      
    }
  }
 
};
