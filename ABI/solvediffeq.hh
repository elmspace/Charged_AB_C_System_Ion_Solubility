//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                                Solving The Modified Diffusion Equation
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void solveModDiffEqn_FFT(double ***q, double **w, double **qint, double ds, int Ns, int sign, double **k, double *dxy){
  
  int            i,j,s,ss;  // some counters
  unsigned long  ij; // This is used for the Fourier Transform
  double         **wds, **kds;

 

  wds=create_2d_double_array(Nx,Ny,"wds");
  kds=create_2d_double_array(Nx,Ny,"kds");

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      kds[i][j]=exp(-ds*k[i][j]);
      wds[i][j]=exp(-0.5*ds*w[i][j]);
    }
  }
  
  if(sign==1){
   
    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	q[i][j][0]=qint[i][j];
      }
    }
    
    for(s=0;s<((int)Ns);s++){
      
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  ss=j+Ny*i;
	  input_q[ss]=q[i][j][s]*wds[i][j];
	}
      }
      fftw_execute(forward_plan);


      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  ss=j+Ny*i;
	  transformed_q[ss]*=kds[i][j];
	}
      }
      fftw_execute(inverse_plan);
      
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  ss=j+Ny*i;
	  q[i][j][s+1]=((final_q[ss]*wds[i][j])/(4.0*Nx*Ny));
	}
      }
    }

  }else{

    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	q[i][j][0]=qint[i][j];
      }
    }

    for(s=0;s<(Ns);s++){       
      
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  ss=j+Ny*i;
	  input_q[ss]=q[i][j][s]*wds[i][j];
	}
      }
      fftw_execute(forward_plan);

      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  ss=j+Ny*i;
	  transformed_q[ss]*=kds[i][j];
	}
      }
      fftw_execute(inverse_plan);
      
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  ss=j+Ny*i;
	  q[i][j][s+1]=((final_q[ss]*wds[i][j])/(4.0*Nx*Ny));
	}
      }
    }
  }


  destroy_2d_double_array(wds);
  destroy_2d_double_array(kds);

};
