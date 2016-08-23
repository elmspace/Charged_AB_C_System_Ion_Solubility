

reset
unset key
set autoscale

set yr [0.0 : 1.0]

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
path_to_file = "./DATA/Density/xBI/phi1Dy.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   
   f(x)=0.0
   
plot path_to_file using 1:2 w lp lw 3 lt 1,\
   path_to_file using 1:3 w lp lw 3 lt 2

pause(-1)

reset
unset key
set autoscale

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
path_to_file = "./DATA/Density/xBI/phi1Dy.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
plot path_to_file using 1:7 w lp lw 3 lt 1



pause(-1)

reset
unset key
set autoscale

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
path_to_file = "./DATA/Density/xBI/phi1Dy.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
plot path_to_file using 1:6 w lp lw 3 lt 1

pause(-1)

reset
unset key
set autoscale

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
path_to_file = "./DATA/Density/xBI/phi1Dy.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   
   f(x)=0.0
   
plot f(x) w l lt -1,\
   path_to_file using 1:2 axes x1y2 w lp lw 3 lt 1,\
   path_to_file using 1:3 axes x1y2 w lp lw 3 lt 2,\
   path_to_file using 1:4 axes x1y1 w lp lw 3 lt 3,\
   path_to_file using 1:5 axes x1y1 w lp lw 3 lt 4

pause(-1)
