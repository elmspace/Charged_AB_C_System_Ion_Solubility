double ConcAB(double ***phi,double ***w,double *Ns,double ds,double **k_vector,double *dxy, double **psi){

  int         i,j,s;
  double      Q;
  double      ***qA,***qB,***qdagA,***qdagB;
  double      **qint,**qintA,**qintB;
  double      **wA_eff,**wB_eff;
  
 


  qA=create_3d_double_array(Nx,Ny,((int)Ns[0]+1),"qA");
  qB=create_3d_double_array(Nx,Ny,((int)Ns[1]+1),"qB");
  qdagA=create_3d_double_array(Nx,Ny,((int)Ns[0]+1),"qdagA");
  qdagB=create_3d_double_array(Nx,Ny,((int)Ns[1]+1),"qdagB");
  qint=create_2d_double_array(Nx,Ny,"qint");
  qintA=create_2d_double_array(Nx,Ny,"qintA");
  qintB=create_2d_double_array(Nx,Ny,"qintB");
  wA_eff=create_2d_double_array(Nx,Ny,"wA_eff"); // Allocating memory for wA_eff
  wB_eff=create_2d_double_array(Nx,Ny,"wB_eff"); // Allocating memory for wB_eff
  
  // Here is the for loop for doing the qint, setting it to 1.0
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      qint[i][j]=1.0;
      wA_eff[i][j]=(w[0][i][j]-PA*w[3][i][j]); // Setting up wA_eff
      wB_eff[i][j]=w[1][i][j]; // Setting up wB_eff
    }
  }
  
  // Here we will solve the diffusion question
  solveModDiffEqn_FFT(qA,wA_eff,qint,ds,(int)Ns[0],1,k_vector,dxy);
  solveModDiffEqn_FFT(qB,wB_eff,qint,ds,(int)Ns[1],1,k_vector,dxy);

  // The result from the above calculation becomes qdags initial cond
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      qintA[i][j]=qB[i][j][(int)Ns[1]];
      qintB[i][j]=qA[i][j][(int)Ns[0]];
    }
  }

  // Here we will solve the diffusion equation for the complementory qs
  solveModDiffEqn_FFT(qdagA,wA_eff,qintA,ds,(int)Ns[0],-1,k_vector,dxy);
  solveModDiffEqn_FFT(qdagB,wB_eff,qintB,ds,(int)Ns[1],-1,k_vector,dxy);


  // Here we are doing the sum to get the single chain partition function
  Q=0.0;
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      Q+=qdagB[i][j][(int)Ns[1]]*dxy[0]*dxy[1];
    }
  }
  // Normalizing with respect to the volume of the box
  Q/=((dxy[0]*Nx)*(dxy[1]*Ny));
  
  
  // Here we do the concentration calculation
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      
      phi[0][i][j]=0.0;
      phi[1][i][j]=0.0;
      
      for(s=0;s<(Ns[0]+1);s++){
	if(s==0 || s==(int)Ns[0]){
	  phi[0][i][j]+=0.5*qA[i][j][s]*qdagA[i][j][(int)Ns[0]-s]*ds;
	}else{
	  phi[0][i][j]+=qA[i][j][s]*qdagA[i][j][(int)Ns[0]-s]*ds;
	}
      }
      for(s=0;s<(Ns[1]+1);s++){
	if(s==0 || s==(int)Ns[1]){
	  phi[1][i][j]+=0.5*qB[i][j][s]*qdagB[i][j][(int)Ns[1]-s]*ds;
	}else{
	  phi[1][i][j]+=qB[i][j][s]*qdagB[i][j][(int)Ns[1]-s]*ds;
	}
      }
      
      phi[0][i][j]*=((pAave+pBave)/Q);
      phi[1][i][j]*=((pAave+pBave)/Q);

      
    }
  }

  

  //clearing the memory -----------------------------
  destroy_3d_double_array(qA);
  destroy_3d_double_array(qB);
  destroy_3d_double_array(qdagA);
  destroy_3d_double_array(qdagB);  
  destroy_2d_double_array(qint);
  destroy_2d_double_array(qintA);
  destroy_2d_double_array(qintB);
  destroy_2d_double_array(wA_eff);
  destroy_2d_double_array(wB_eff);
  //-------------------------------------------------
  

  return Q;


};
