void Allocate(int action){
  
  // action=1 allocate, =0 deallocate

  if(action==1){
    
    // The ChainType+1 corresponds to 0=A, 1=B, 2=I and 3=e
    w=create_3d_double_array(ChainType+1,Nx,Ny,"w"); // w[3] is the suxilary field for total charge
    phi=create_3d_double_array(ChainType+1,Nx,Ny,"phi"); // phi[3] is the total charge at i,j
    psi=create_2d_double_array(Nx,Ny,"psi");
    eta=create_2d_double_array(Nx,Ny,"eta");
    diel_cons=create_2d_double_array(Nx,Ny,"diel_cons");
    chi=create_1d_double_array(ChainType,"chi");
    Ns=create_1d_double_array(ChainType,"Ns");
    k_vector=create_2d_double_array(Nx,Ny,"k_vector");
    dxy=create_1d_double_array(2,"dxyz");
    chiMatrix=create_2d_double_array(ChainType,ChainType,"chiMatrix");
    x_sub=create_3d_double_array(ChainType,Nx,Ny,"x_sub");
    // Setting up the FFTW for MDE +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    input_q=(double*)fftw_malloc(sizeof(double)*Nx*Ny);
    transformed_q=(double*)fftw_malloc(sizeof(double)*Nx*Ny);
    final_q=(double*)fftw_malloc(sizeof(double)*Nx*Ny);
    forward_plan=fftw_plan_r2r_2d(Nx,Ny,input_q,transformed_q,FFTW_REDFT10,FFTW_REDFT10,i_fftw);
    inverse_plan=fftw_plan_r2r_2d(Nx,Ny,transformed_q,final_q,FFTW_REDFT01,FFTW_REDFT01,i_fftw);
    //-------------------------------------
    
  }else{
    
    //DeAllocate------------
    fftw_free(input_q);
    fftw_free(transformed_q);
    fftw_free(final_q);
    fftw_destroy_plan(forward_plan);
    fftw_destroy_plan(inverse_plan);
    destroy_3d_double_array(w);
    destroy_2d_double_array(psi);
    destroy_2d_double_array(eta);
    destroy_2d_double_array(diel_cons);
    destroy_3d_double_array(phi);
    destroy_1d_double_array(chi);
    destroy_1d_double_array(Ns);
    destroy_2d_double_array(k_vector);
    destroy_1d_double_array(dxy);
    destroy_2d_double_array(chiMatrix);
    destroy_3d_double_array(x_sub);
    //-------------------------------------
    
  }
  
};
