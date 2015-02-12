void SOR(double **psi, double **diel_cons, double ***phi , double converg, double *dxy){

  
  int i,j,s;

  double **a0,**a1,**a2,**a3,**a4;
  double      **charge;
  double avg_psi,avg_psi_old;


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
 
  
  avg_psi_old=1000.0;
  for(s=0;s<1000;s++){

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
      }
      avg_psi+=psi[i][j]/(Nx*Ny);
    }
    
    
    if(abs(avg_psi_old-avg_psi)<1.0e-4){break;}
    avg_psi_old=avg_psi;
  }


  //for(i=0;i<Nx;i++){
  //std::cout<<i<<" "<<psi[i][Ny/2]<<std::endl;
  //}
  //std::cin>>i;

  // Destroying the allocated memory ---------------------
  destroy_2d_double_array(a0);
  destroy_2d_double_array(a1);
  destroy_2d_double_array(a2);
  destroy_2d_double_array(a3);
  destroy_2d_double_array(a4);
  destroy_2d_double_array(charge);
  // -----------------------------------------------------


}
