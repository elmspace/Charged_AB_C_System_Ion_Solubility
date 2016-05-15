void Set_a_arrays(double **diel_cons, double **a0, double **a1 , double **a2, double **a3, double **a4, double *dxy){

  int i,j;

    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){

	if((i==0)&&(j==0)){//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	  a0[i][j]=(1.0/(dxy[0]*dxy[0]))*(diel_cons[i+1][j]+diel_cons[i][j])+(1.0/(dxy[1]*dxy[1]))*(diel_cons[i][j+1]+diel_cons[i][j]);
	  a1[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i+1][j];
	  a2[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j+1];
	  a3[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a4[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	}else if((i==0)&&(j==(Ny-1))){//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	  a0[i][j]=(1.0/(dxy[0]*dxy[0]))*(diel_cons[i+1][j]+diel_cons[i][j])+(1.0/(dxy[1]*dxy[1]))*(diel_cons[i][j]+diel_cons[i][j]);
	  a1[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i+1][j];
	  a2[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	  a3[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a4[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	}else if((i==(Nx-1))&&(j==0)){//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	  a0[i][j]=(1.0/(dxy[0]*dxy[0]))*(diel_cons[i][j]+diel_cons[i][j])+(1.0/(dxy[1]*dxy[1]))*(diel_cons[i][j+1]+diel_cons[i][j]);
	  a1[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a2[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j+1];
	  a3[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a4[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	}else if((i==(Nx-1))&&(j==(Ny-1))){//+++++++++++++++++++++++++++++++++++++++++++++++++++
	  a0[i][j]=(1.0/(dxy[0]*dxy[0]))*(diel_cons[i][j]+diel_cons[i][j])+(1.0/(dxy[1]*dxy[1]))*(diel_cons[i][j]+diel_cons[i][j]);
	  a1[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a2[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	  a3[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a4[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	}else if((i==0)&&(j>0)&&(j<(Ny-1))){//++++++++++++++++++++++++++++++++++++++++++++++++++
	  a0[i][j]=(1.0/(dxy[0]*dxy[0]))*(diel_cons[i+1][j]+diel_cons[i][j])+(1.0/(dxy[1]*dxy[1]))*(diel_cons[i][j+1]+diel_cons[i][j]);
	  a1[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i+1][j];
	  a2[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j+1];
	  a3[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a4[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	}else if((i==(Nx-1))&&(j>0)&&(j<(Ny-1))){//+++++++++++++++++++++++++++++++++++++++++++++
	  a0[i][j]=(1.0/(dxy[0]*dxy[0]))*(diel_cons[i][j]+diel_cons[i][j])+(1.0/(dxy[1]*dxy[1]))*(diel_cons[i][j+1]+diel_cons[i][j]);
	  a1[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a2[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j+1];
	  a3[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a4[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	}else if((j==0)&&(i>0)&&(i<(Nx-1))){//++++++++++++++++++++++++++++++++++++++++++++++++++
	  a0[i][j]=(1.0/(dxy[0]*dxy[0]))*(diel_cons[i+1][j]+diel_cons[i][j])+(1.0/(dxy[1]*dxy[1]))*(diel_cons[i][j+1]+diel_cons[i][j]);
	  a1[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i+1][j];
	  a2[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j+1];
	  a3[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a4[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	}else if((j==(Ny-1))&&(i>0)&&(i<(Nx-1))){//+++++++++++++++++++++++++++++++++++++++++++++
	  a0[i][j]=(1.0/(dxy[0]*dxy[0]))*(diel_cons[i+1][j]+diel_cons[i][j])+(1.0/(dxy[1]*dxy[1]))*(diel_cons[i][j]+diel_cons[i][j]);
	  a1[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i+1][j];
	  a2[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	  a3[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a4[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	}else{
	  a0[i][j]=(1.0/(dxy[0]*dxy[0]))*(diel_cons[i+1][j]+diel_cons[i][j])+(1.0/(dxy[1]*dxy[1]))*(diel_cons[i][j+1]+diel_cons[i][j]);
	  a1[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i+1][j];
	  a2[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j+1];
	  a3[i][j]=(1.0/(dxy[0]*dxy[0]))*diel_cons[i][j];
	  a4[i][j]=(1.0/(dxy[1]*dxy[1]))*diel_cons[i][j];
	}
	
      }
    }
    
};
