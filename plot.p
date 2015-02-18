

reset

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

set xlabel 'Electrode'  font ",22"
set title 'Electrode'  font ",22"
   
   unset key
   unset sur
   set hidden3d
   set view map 
   set autoscale
   set size square
   splot "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi2D.dat" using 2:1:3






pause(-1)

reset
unset key
unset y2tics

# set xr [0.0 : 7.8]
# set yr [-0.001 : 0.0015]

   f(x)=0.0
   
plot f(x) w l lt -1,\
   "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dx.dat" using 1:2 axes x1y2 w lp lw 3 lt 1,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dx.dat" using 1:3 axes x1y2 w lp lw 3 lt 2,\
   "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dx.dat" using 1:4 axes x1y1 w lp lw 3 lt 3,\
  "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dx.dat" using 1:5 axes x1y1 w lp lw 3 lt 4

pause(-1)

reset
unset key


plot "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dx.dat" using 1:4 w lp,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dx.dat" using 1:5 w lp


pause(-1)

reset
unset key
plot "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dx.dat" using 1:7 w lp


