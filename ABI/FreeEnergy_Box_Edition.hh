double FreeEnergy_Box_Edition(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub){

  
  double  currentfE;  
  int     i,j,chain,ii,jj; 
  double  QAB,QI; 
  double  fES; 
 
  
  WaveVectors(k_vector,dxy);   //
  currentfE=0.0;

  fES=0.0;
  
  QAB=ConcAB(phi,w,Ns,ds,k_vector,dxy,psi);
  QI=ConcI(phi,w,Ns,dxy,psi);

  fES=((pAave+pBave))*log(QAB/(pAave+pBave))+NAB*pIave*log(QI/pIave);
  
  currentfE=-fES;
  

  return currentfE;
  
};
