set term postscript enhanced color
set output "~/Desktop/fE.ps"

set xlabel '{/Symbol D}V'  font "Times,32"
set ylabel 'f_{/Symbol \136}-f_{||}'  font "Times,32"

set key at 1.5,-0.09font "Times,22" spacing 2.2



set xrange [0.0: 15.0]
set yrange [-0.10:0.07]
set ytics 0.04

set pointsize 2

f(x) = 0.0

plot f(x) w l notitle " " lc -1 lw 5,\
"/1/home/dehgha2/Desktop/Electric_Thin_Film_Project/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV_AS/MOD_main_delfE_vs_delV_PA_000.dat" using 1:($4-$3) title "PA=0.000" w lp lw 5 pt 6 lc -1,\
"/1/home/dehgha2/Desktop/Electric_Thin_Film_Project/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV_AS/MOD_main_delfE_vs_delV_PA_001.dat" using 1:($4-$3) title "PA=0.001" w lp lw 5 pt 8 lc -1,\
"/1/home/dehgha2/Desktop/Electric_Thin_Film_Project/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV_AS/MOD_main_delfE_vs_delV_PA_002.dat" using 1:($4-$3) title "PA=0.002" w lp lw 5 pt 4 lc -1



