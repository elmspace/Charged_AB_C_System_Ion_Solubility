void InputArguments(int numb_of_args, char* arg_input[]){


  // Set all phase type to 0
  LAM = 0;
  HEX = 0;
 
  
  if(strcmp( arg_input[1], "LAM") == 0){
    LAM=1;
  }else if(strcmp( arg_input[1], "HEX") == 0){
    HEX=1;
  }else{
    std::cout<<"The phase you have chosen does not exists!"<<std::endl;
    exit(1);
  }


  xAB=atoi(arg_input[2]);

  

};
