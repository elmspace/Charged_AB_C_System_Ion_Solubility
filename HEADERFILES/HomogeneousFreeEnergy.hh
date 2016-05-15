double homogenousfE(double **chiMatrix){

  int     i,j;
  double  *avphi;
  double  fE_homo;

  avphi=create_1d_double_array(ChainType,"avphi");

  avphi[0]=pAave; // A average
  avphi[1]=pBave; // B average
  avphi[2]=pIave; // I average
  
  fE_homo=0.0;

  for(i=0;i<ChainType;i++){
    for(j=i;j<ChainType;j++){
      fE_homo+=avphi[i]*avphi[j]*chiMatrix[i][j];
    }
  }

  fE_homo+=((pAave+pBave)/NAB)*log(pAave+pBave)+pIave*log(pIave);
    
  destroy_1d_double_array(avphi);

  return fE_homo;

};
