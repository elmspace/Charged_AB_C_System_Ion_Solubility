reset

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/Charged_AB_C_System_Ion_Solubility/PHI/phi2D.dat"

##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#set term postscript enhanced color
#set output "~/Desktop/fE.ps"

set pm3d
set iso 100
set samp 100
set palette model RGB
set dgrid3d 32,32,1
#set size square
unset border
unset xtics
unset ytics
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
   
   splot path_to_file using 2:1:7
