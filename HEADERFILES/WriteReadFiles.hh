void Write_Omega(double ***w){
  // Here we are writting some .read fiels for the omega parameter
  // This will be used for the input for later runs
  
  int i, j;


  
  std::ofstream outputFile1("./OMEGA/omega.dat"); // Format: x, y, wA, wB, wI, w_e
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      outputFile1 << i <<" "<< j <<" "<< w[0][i][j] <<" "<< w[1][i][j] <<" "<<w[2][i][j]<<" "<<w[3][i][j]<<std::endl;
    }
  }
  outputFile1.close();


};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Write_Phi(double ***phi, double **psi, double *dxy){
  // Here we writing some .dat files, mostly for plotting and checking the structure

  
  int i,j;

  // Some output for checking the progress
  std::ofstream outputFile17("./PHI/phi2D.dat");
  for(i=0;i<Nx;i++){      
    for(j=0;j<Ny;j++){
      // x, y, phiA, phiB, phiI, pA_charge, total_charge_per_r V
      outputFile17 <<i*dxy[0]<<" "<<j*dxy[1]<<" "<<phi[0][i][j]<<" "<<phi[1][i][j]<<" "<<phi[2][i][j]<<" "<<-PA*phi[0][i][j]<<" "<<phi[3][i][j]<<" "<<psi[i][j]<<std::endl;
    }
  }
  outputFile17.close();
  std::ofstream outputFile27("./PHI/phi1Dx.dat");
  for(i=0;i<Nx;i++){      
    // x, phiA, phiB, phiI, pA_charge, total_charge_per_r V
    outputFile27 <<i*dxy[0]<<" "<<phi[0][i][Ny/2]<<" "<<phi[1][i][Ny/2]<<" "<<phi[2][i][Ny/2]<<" "<<-PA*phi[0][i][Ny/2]<<" "<<phi[3][i][Ny/2]<<" "<<psi[i][Ny/2]<<std::endl;
  }
  outputFile27.close();
  std::ofstream outputFile37("./PHI/phi1Dy.dat");
  for(j=0;j<Ny;j++){      
    // y, phiA, phiB, phiI, pA_charge, total_charge_per_r V
    outputFile37 <<j*dxy[1]<<" "<<phi[0][Nx/2][j]<<" "<<phi[1][Nx/2][j]<<" "<<phi[2][Nx/2][j]<<" "<<-PA*phi[0][Nx/2][j]<<" "<<phi[3][Nx/2][j]<<" "<<psi[Nx/2][j]<<std::endl;
  }
  outputFile37.close();
  
  
};
