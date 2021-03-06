reset

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
path_to_file = "./PHI/phi2D.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#set term postscript enhanced color
#set output "~/Desktop/fE.ps"

set pm3d
set iso 100
set samp 100
set palette model RGB
set dgrid3d 32,32,1
set size square
unset border
#unset xtics
#unset ytics
#unset colorbox
set pm3d flush begin ftriangles scansforward interpolate 10,5

#set xlabel 'Electrode +'  font ",22"
#set title 'Electrode -'  font ",22"
   
   unset key
   unset sur
   set hidden3d
   set view map 
   set autoscale
#set size square
   
#x, y, phiA, phiB, phiI, pA_charge, total_charge_per_r V

   splot path_to_file using 2:1:3

pause(-1)


reset

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
path_to_file = "./PHI/phi2D.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#set term postscript enhanced color
#set output "~/Desktop/fE.ps"

set pm3d
set iso 100
set samp 100
set palette model RGB
set dgrid3d 32,32,1
set size square
unset border
#unset xtics
#unset ytics
#unset colorbox
set pm3d flush begin ftriangles scansforward interpolate 10,5

#set xlabel 'Electrode +'  font ",22"
#set title 'Electrode -'  font ",22"
   
   unset key
   unset sur
   set hidden3d
   set view map 
   set autoscale
#set size square
   
#x, y, phiA, phiB, phiI, pA_charge, total_charge_per_r V

   splot path_to_file using 2:1:3
