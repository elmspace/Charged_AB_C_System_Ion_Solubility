void SOR(double **psi, double **diel_cons, double ***phi , double converg, double *dxy){

  
  int i,j,s;

  double **a0,**a1,**a2,**a3,**a4;
  double      **charge;
  double avg_psi,avg_psi_old=10000.0;
  double conv1=10000.0,conv2=10000.0;


  a0=create_2d_double_array(Nx,Ny,"a0");
  a1=create_2d_double_array(Nx,Ny,"a1");
  a2=create_2d_double_array(Nx,Ny,"a2");
  a3=create_2d_double_array(Nx,Ny,"a3");
  a4=create_2d_double_array(Nx,Ny,"a4");
  charge=create_2d_double_array(Nx,Ny,"charge"); // total charge multiplied by lB

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      phi[3][i][j]=phi[2][i][j]-PA*phi[0][i][j]; // Charge density
      
      charge[i][j]=((tau*NAB)/(24.0*Pi))*phi[3][i][j];
      
      diel_cons[i][j]=kA*phi[0][i][j]+kB*phi[1][i][j];
      
      psi[i][j]=0.0;
    }
  }
  Set_a_arrays(diel_cons,a0,a1,a2,a3,a4,dxy);
  
 
  for(s=0;s<100000;s++){
    
    if(Psi_BC==0){
      avg_psi=0.0;
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  if(i==0){
	    psi[i][j]=psi_bc_1;
	  }else if(i==(Nx-1)){
	    psi[i][j]=psi_bc_2;
	  }else{
	    if(j==0){
	      psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j]+charge[i][j])-(converg*psi[i][j]);
	    }else if(j==(Ny-1)){
	      psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	    }else{
	      psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	    }
	  }	  
	  avg_psi+=psi[i][j]/(Nx*Ny);
	}
      }
    }else if(Psi_BC==1){
      avg_psi=0.0;
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  if((i==0)&&(j==0)){//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i][j]+a4[i][j]*psi[i][j]+charge[i][j])-(converg*psi[i][j]);
	    psi[i][j]+=psi_bc_1;
	  }else if((i==0)&&(j==(Ny-1))){//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j]+a3[i][j]*psi[i][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	    psi[i][j]+=psi_bc_1;
	  }else if((i==(Nx-1))&&(j==0)){//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j]+charge[i][j])-(converg*psi[i][j]);
	    psi[i][j]+=psi_bc_2;
	  }else if((i==(Nx-1))&&(j==(Ny-1))){//+++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i][j]+a2[i][j]*psi[i][j]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	    psi[i][j]+=psi_bc_2;
	  }else if((i==0)&&(j>0)&&(j<(Ny-1))){//++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	    psi[i][j]+=psi_bc_1;
	  }else if((i==(Nx-1))&&(j>0)&&(j<(Ny-1))){//+++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	    psi[i][j]+=psi_bc_2;
	  }else if((j==0)&&(i>0)&&(i<(Nx-1))){//++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j]+charge[i][j])-(converg*psi[i][j]);
	  }else if((j==(Ny-1))&&(i>0)&&(i<(Nx-1))){//+++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	  }else{
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	  }
	  avg_psi+=psi[i][j]/(Nx*Ny);
	}
      }
    }else if(Psi_BC==2){
      avg_psi=0.0;
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  if((i==0)&&(j==0)){//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i][j]+a4[i][j]*psi[i][j]+charge[i][j])-(converg*psi[i][j]);
	  }else if((i==0)&&(j==(Ny-1))){//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j]+a3[i][j]*psi[i][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	  }else if((i==(Nx-1))&&(j==0)){//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j]+charge[i][j])-(converg*psi[i][j]);
	  }else if((i==(Nx-1))&&(j==(Ny-1))){//+++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i][j]+a2[i][j]*psi[i][j]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	  }else if((i==0)&&(j>0)&&(j<(Ny-1))){//++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	  }else if((i==(Nx-1))&&(j>0)&&(j<(Ny-1))){//+++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	  }else if((j==0)&&(i>0)&&(i<(Nx-1))){//++++++++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j]+charge[i][j])-(converg*psi[i][j]);
	  }else if((j==(Ny-1))&&(i>0)&&(i<(Nx-1))){//+++++++++++++++++++++++++++++++++++++++++++++
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	  }else{
	    psi[i][j]=psi[i][j]+(converg/a0[i][j])*(a1[i][j]*psi[i+1][j]+a2[i][j]*psi[i][j+1]+a3[i][j]*psi[i-1][j]+a4[i][j]*psi[i][j-1]+charge[i][j])-(converg*psi[i][j]);
	  }
	  avg_psi+=psi[i][j]/(Nx*Ny);
	}
      }
    }else{
      std::cout<<"The boundary condition chosen for the electric field is not valid!"<<std::endl;
      exit(0);
    }

    // **************************************************************************************************
    conv1=abs(avg_psi_old-avg_psi);
    //std::cout<<s<<" "<<abs(avg_psi_old-avg_psi)<<" "<<abs(conv1-conv2)<<std::endl;
    if((abs(conv1-conv2)<1.0e-10) && s>1000){break;}
    avg_psi_old=avg_psi;
    conv2=conv1;
    // **************************************************************************************************
  }
  
  
  if((abs(conv1-conv2)>1.0e-10)){
    std::cout<<"the PB did not converege!"<<std::endl;
    exit(0);
  }
  
  // Destroying the allocated memory ---------------------
  destroy_2d_double_array(a0);
  destroy_2d_double_array(a1);
  destroy_2d_double_array(a2);
  destroy_2d_double_array(a3);
  destroy_2d_double_array(a4);
  destroy_2d_double_array(charge);
  // -----------------------------------------------------


}
