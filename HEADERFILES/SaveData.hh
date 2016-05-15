void SaveData( ){

  std::ofstream outputFile37("./Free_Energy_Tot.dat" , ios::app);
  outputFile37 <<Free_Energy<<" "<<psi_bc_1<<" "<<PA<<" "<<xAB<<" "<<NA<<" "<<deltaV<<" "<<Lx<<" "<<Ly<<std::endl;
  outputFile37.close(); 


};
