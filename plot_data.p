reset
set key b l

f(x) = 0.0

plot  "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_fE_vs_delV.dat" using 1:3 title "RUN" w lp lw 2 pt 8


pause(-1)


reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"

set xlabel '{/Symbol D}V'  font ",22"
set ylabel '{/Symbol D}fE'  font ",22"
set key t r font ",18" spacing 2.2

#set xrange [0.0: 22.5]
set yrange [-0.2:0.06]
set ytics 0.04

set pointsize 2

f(x) = 0.0

plot "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV_AS/MOD_main_delfE_vs_delV_PA_000.dat" using 1:($4-$3) title "PA=0.000" w lp lw 2 pt 6,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV_AS/MOD_main_delfE_vs_delV_PA_001.dat" using 1:($4-$3) title "PA=0.001" w lp lw 2 pt 8,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV_AS/MOD_main_delfE_vs_delV_PA_002.dat" using 1:($4-$3) title "PA=0.002" w lp lw 2 pt 4,\
f(x) w l notitle " " lc -1


