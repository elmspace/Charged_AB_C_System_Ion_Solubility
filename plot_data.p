reset
set key b l

f(x) = 0.0

plot "/Users/ashkandehghan/Dropbox/Research_Projects/Electric_Thin_Films/Computation/NEW/main1_version3/RESULTS/MOD_main_delfE_vs_delV.dat" using 1:($4-$3) title "PA=0.0001" w lp,\
 "/Users/ashkandehghan/Dropbox/Research_Projects/Electric_Thin_Films/Computation/NEW/main1_version3/RESULTS/MOD_main_delfE_vs_delV_PA_0.dat" using 1:($4-$3) title "PA=0.0001" w lp,\
 "/Users/ashkandehghan/Dropbox/Research_Projects/Electric_Thin_Films/Computation/NEW/main1_version3/RESULTS/MOD_main_delfE_vs_delV_PA_001.dat" using 1:($4-$3) title "PA=0.0001" w lp,\
f(x) w l lc -1


pause(-1)


reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"

set xlabel '{/Symbol D}V'  font ",22"
set ylabel '{/Symbol D}fE'  font ",22"
set key t r font ",18" spacing 2.2

set xrange [0.0: 22.5]
set yrange [-0.012:0.008]

set pointsize 2

f(x) = 0.0

plot "/Users/ashkandehghan/Dropbox/Research_Projects/Electric_Thin_Films/Computation/NEW/main1_version3/RESULTS/MOD_main_delfE_vs_delV/B_by_Surface/MOD_main_delfE_vs_delV_PA_0.dat" using 1:($4-$3) title "PA=0.0000" w lp lw 2,\
"/Users/ashkandehghan/Dropbox/Research_Projects/Electric_Thin_Films/Computation/NEW/main1_version3/RESULTS/MOD_main_delfE_vs_delV/B_by_Surface/MOD_main_delfE_vs_delV_PA_0001.dat" using 1:($4-$3) title "PA=0.0001" w lp lw 2,\
"/Users/ashkandehghan/Dropbox/Research_Projects/Electric_Thin_Films/Computation/NEW/main1_version3/RESULTS/MOD_main_delfE_vs_delV/B_by_Surface/MOD_main_delfE_vs_delV_PA_0002.dat" using 1:($4-$3) title "PA=0.0002" w lp lw 2,\
"/Users/ashkandehghan/Dropbox/Research_Projects/Electric_Thin_Films/Computation/NEW/main1_version3/RESULTS/MOD_main_delfE_vs_delV/B_by_Surface/MOD_main_delfE_vs_delV_PA_0003.dat" using 1:($4-$3) title "PA=0.0003" w lp lw 2,\
f(x) w l notitle " " lc -1


pause(-1)


reset
unset key

plot "/Users/ashkandehghan/Dropbox/Research_Projects/Electric_Thin_Films/Computation/NEW/main1_version3/RESULTS/MOD_main_delfE_vs_delV.dat" using 1:3 w lp,\
"/Users/ashkandehghan/Dropbox/Research_Projects/Electric_Thin_Films/Computation/NEW/main1_version3/RESULTS/MOD_main_delfE_vs_delV.dat" using 1:4 w lp


