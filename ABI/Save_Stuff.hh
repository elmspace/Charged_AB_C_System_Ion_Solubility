void Save_Stuff(double ***w, double ***phi, double **psi, double **diel_cons){

  int i,j;


  std::ofstream outputFile37("./Free_Energy_Tot.dat" , ios::app);
  outputFile37 <<psi_bc_1<<" "<<PA<<" "<<Free_Energy<<std::endl;
  outputFile37.close(); 


};
