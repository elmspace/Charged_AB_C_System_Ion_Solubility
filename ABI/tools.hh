double FindIntersect (double x1f, double y1f, double x2f, double y2f, double x1g, double y1g, double x2g, double y2g){
  // This function will find the point of intersection between two lines, given from the 4 points above
  // The two functions are called f(x) and g(x)


  double af, ag, bf, bg;
  double X_point;


  af=(y2f - y1f)/(x2f - x1f);
  bf=y1f-af*x1f;

  ag=(y2g - y1g)/(x2g - x1g);
  bg=y1g-ag*x1g;


  X_point=(bg - bf)/(af - ag);
  
  return X_point;


};
