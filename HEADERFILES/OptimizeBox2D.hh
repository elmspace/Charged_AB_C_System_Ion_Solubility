void size_adjust_2D_xy(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub){

  int     i,j,k,l,ii,jj,ll,kk;
  double  dely,delx;
  double  box, *dxy_temp;
  double  *box_x,*box_y,*box_fE;
  double  ***w_temp,**psi_temp;

  w_temp=create_3d_double_array(ChainType+1,Nx,Ny,"w_temp");
  psi_temp=create_2d_double_array(Nx,Ny,"psi_temp");
  box_y=create_1d_double_array(8,"box_y");
  box_x=create_1d_double_array(8,"box_x");	  
  box_fE=create_1d_double_array(8,"box_fE");
  dxy_temp=create_1d_double_array(3,"dxy_temp");

  dely=0.01/Nx;
  delx=0.01/Ny;
 
  l=0;
  for(i=-1;i<2;i++){
    for(j=-1;j<2;j++){
    
      if((i==0)&&(j==0)){
	
      }else{

	box_x[l]=i*delx;
	box_y[l]=j*dely;
	
	dxy_temp[0]=dxy[0];
	dxy_temp[1]=dxy[1];
    	
	for(ii=0;ii<Nx;ii++){
	  for(jj=0;jj<Ny;jj++){
	    psi_temp[ii][jj]=psi[ii][jj];
	    for(ll=0;ll<ChainType+1;ll++){
	      w_temp[ll][ii][jj]=w[ll][ii][jj];
	    }
	  }
	}
      
	dxy_temp[0]+=box_x[l];
	dxy_temp[1]+=box_y[l];
	
	box_fE[l]=FreeEnergy_Box_Edition(w_temp,phi,psi_temp,eta,diel_cons,Ns,ds,k_vector,chi,dxy_temp,chiMatrix,x_sub);
		
	l=l+1;
	
      }
    }
  }
  //std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  
  for(i=0;i<7;i++){
    ii=0;
    for(j=i+1;j<8;j++){
      if(box_fE[i]<box_fE[j]){
	ii=ii+1;
      }
    }
    if(ii==(8-(i+1))){
      break;
    }
  }
  
  dxy[0]=dxy[0]+box_x[i];
  dxy[1]=dxy[1]+box_y[i];


  // Destroying the allocated memory -------------------- 
  destroy_2d_double_array(psi_temp);
  destroy_3d_double_array(w_temp);
  destroy_1d_double_array(dxy_temp);
  destroy_1d_double_array(box_y);
  destroy_1d_double_array(box_x);
  destroy_1d_double_array(box_fE);
  // ----------------------------------------------------
 
  
};
