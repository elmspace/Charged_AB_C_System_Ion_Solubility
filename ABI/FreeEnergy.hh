double FreeEnergy(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub){

  
  double  currentfE, oldfE, deltafE;  
  int     i,j,iter,chain,ii,jj; 
  double  precision=1.0e-3; 
  double  QAB,QI; 
  double  fEW, fEchi, fES, fE_charge, fESurf, fE_homogenous; 
  double  epsilon, gamma;
  double  **delphi;
  double  ***delW;
  double  ***newW;
  double  **slope_x;
  double  **slope_y;
  double  deltaW;
  double  msg;

 
  delW=create_3d_double_array(ChainType+1,Nx,Ny,"delW");
  delphi=create_2d_double_array(Nx,Ny,"delphi");
  newW=create_3d_double_array(ChainType+1,Nx,Ny,"newW");
  slope_x=create_2d_double_array(Nx,Ny,"slope_x");
  slope_y=create_2d_double_array(Nx,Ny,"slope_y");

  msg=1.0;
  oldfE=1.0e2;
  std::ofstream outputFile("./fE.dat");
  do{
  
    WaveVectors(k_vector,dxy);   //
    currentfE=0.0;
    deltafE=0.0;
  
    epsilon=0.01; // del_phi
    gamma=0.01; // del_w
  
    iter=0;  
    
    do{
      iter++;

      // Setting all the free energy components to zero
      fEW=0.0;
      fEchi=0.0;
      fES=0.0;
      fESurf=0.0;
      deltaW=0.0;
       
      QAB=ConcAB(phi,w,Ns,ds,k_vector,dxy,psi); // Solving for QAB and phiA and phiB
      QI=ConcI(phi,w,Ns,dxy,psi); // Solving for QI and phiI
      SOR(psi,diel_cons,phi,converg,dxy); // Solving the BP equation in here
      Incomp(eta,phi,delphi); // Calcuating the incompressibility
  


      // Writting some Phi and Omega Files on the go +++++++++++++++++++++++++++++++++++++++
      Write_Omega(w);
      Write_Phi(phi,psi,dxy);
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

      // Calculating the gradient in the x and y direction
      Slope_Calc2(psi,0,dxy,slope_x);
      Slope_Calc2(psi,1,dxy,slope_y);
   
      // Initializing to zero the new fields
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(ii=0;ii<ChainType+1;ii++){
	    newW[ii][i][j]=0.0;  
	  }
	}
      }
     
      // Calculating (kappa(r)/2)|delta V(r)|^2      ++++++++++++++++++++++++++++++++++++++++++++++
      fE_charge=0.0;
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  fE_charge-=(((12.0*Pi)/tau)*diel_cons[i][j]*(pow(slope_x[i][j],2)+pow(slope_y[i][j],2))*dxy[0]*dxy[1]);
	  fE_charge+=(NAB*phi[3][i][j]*psi[i][j])*dxy[0]*dxy[1];
	}
      }
      fE_charge/=((Nx*dxy[0])*(Ny*dxy[1]));
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      


      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  
	  for(ii=0;ii<ChainType;ii++){
	    for(jj=0;jj<ChainType;jj++){
	      
	      newW[ii][i][j]+=((chiMatrix[ii][jj]*phi[jj][i][j]));
	      fEchi+=phi[ii][i][j]*chiMatrix[ii][jj]*phi[jj][i][j]*dxy[0]*dxy[1];
	      
	    }
	    
	   
	    if(ii==0){newW[ii][i][j]+=x_sub[0][i][j]+eta[i][j]-((12.0*Pi*kA)/tau)*(pow(slope_x[i][j],2)+pow(slope_y[i][j],2));}  //A
	    if(ii==1){newW[ii][i][j]+=x_sub[1][i][j]+eta[i][j]-((12.0*Pi*kB)/tau)*(pow(slope_x[i][j],2)+pow(slope_y[i][j],2));}  //B
	    if(ii==2){newW[ii][i][j]+=0.0;}  //I

	    fEW+=(newW[ii][i][j]*phi[ii][i][j]*dxy[0]*dxy[1]);
	    
	    delW[ii][i][j]=newW[ii][i][j]-w[ii][i][j];
	    deltaW+=fabs(delW[ii][i][j]);
	    
	  }
	  newW[3][i][j]=NAB*psi[i][j];
	  delW[3][i][j]=newW[3][i][j]-w[3][i][j];
	  
	  fESurf+=(x_sub[0][i][j]*phi[0][i][j]+x_sub[1][i][j]*phi[1][i][j])*dxy[0]*dxy[1];
	  fEW+=(newW[3][i][j]*phi[3][i][j]*dxy[0]*dxy[1]); // here we add w_e * phi_e where w_e is psi
	}
      }

      // This is the average deltaW for checking
      deltaW/=(Nx*Ny);
      // Dividing by volume
      fESurf/=((Nx*dxy[0])*(Ny*dxy[1]));
      fEchi/=(2.0*((Nx*dxy[0])*(Ny*dxy[1])));
      fEW/=((Nx*dxy[0])*(Ny*dxy[1]));

      // Calculating the homogenous free energy
      fE_homogenous=homogenousfE(chiMatrix);
      
      fES=((pAave+pBave))*log(QAB/(pAave+pBave))+NAB*pIave*log(QI/pIave);
      
      currentfE=-fES-fEW+fEchi+fE_charge+fESurf;

      // Calculating the difference in free energy (now-previous)
      deltafE=fabs(currentfE-oldfE);

      // Print out some results
      //std::cout<<iter<<" "<<(currentfE-fE_homogenous)<< " " << deltaW<<" "<<delphi[Nx/2][Ny/2]<<std::endl;
      
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(chain=0;chain<ChainType+1;chain++){
	    w[chain][i][j]+=(gamma*delW[chain][i][j]-epsilon*delphi[i][j]);
	  }
	}
      }
   
    }while((deltaW>precision)||(iter<200));

   
    outputFile <<dxy[0]*Nx<<" "<<dxy[1]*Ny<<" "<<currentfE<<" "<<fE_homogenous<<std::endl;    

    Free_Energy=oldfE;
    
    size_adjust_1D_x(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
    //size_adjust_2D_xy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);

    if((oldfE<currentfE)||(abs(oldfE-currentfE)<0.00001)){
      msg=0.0;
    }
    if(msg>0.5){
      oldfE=currentfE;
    }
    if(box_min==0){
      msg=0.0;
    }

 
  }while(msg>0.5);

  outputFile <<"END"<<std::endl;    
  outputFile.close();


  // Destroying the allocated memory ----------------
  destroy_2d_double_array(slope_x);
  destroy_2d_double_array(slope_y);
  destroy_2d_double_array(delphi);
  destroy_3d_double_array(delW);
  destroy_3d_double_array(newW);
  // ------------------------------------------------


  return oldfE;
  
  
};
