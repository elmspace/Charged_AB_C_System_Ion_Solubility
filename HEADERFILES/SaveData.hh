void SaveData(int action){

  if(action==0){
    if(LAM==1){
      // Cleaning Generic output file
      std::ofstream outputFile37("./RESULTS/MOD_Lam.dat");
      outputFile37 << std::endl;
      outputFile37.close();
      //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    }else if(HEX==1){
      // Cleaning Generic output file
      std::ofstream outputFile37("./RESULTS/MOD_Hex.dat");
      outputFile37 << std::endl;
      outputFile37.close();
      //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    }
  }else{
    if(LAM==1){
      // *********************************************
      // Writing data to a generic file
      std::ofstream outputFile37("./RESULTS/MOD_Lam.dat" , ios::app);
      outputFile37 <<Free_Energy<<" "<<deltaV<<" "<<PA<<" "<<xAB<<" "<<NA/NAB<<" "<<deltaV<<" "<<Lx<<" "<<Ly<<std::endl;
      outputFile37.close();
      // *********************************************
    }else if(HEX==1){
      // *********************************************
      // Writing data to a generic file
      std::ofstream outputFile37("./RESULTS/MOD_Hex.dat" , ios::app);
      outputFile37 <<Free_Energy<<" "<<deltaV<<" "<<PA<<" "<<xAB<<" "<<NA/NAB<<" "<<deltaV<<" "<<Lx<<" "<<Ly<<std::endl;
      outputFile37.close();
      // *********************************************
    }
  }

};
