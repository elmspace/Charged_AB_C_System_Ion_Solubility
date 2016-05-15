#reset
#set key b l

#plot "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_PA.dat" using 2:1 title " " w lp

#pause(-1)


reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"

set xlabel 'P_A'  font ",22"
set ylabel '{/Symbol D}V_c'  font ",22"

set key at 0.001,7.5 font ",18" spacing 2.2

#set xrange [0.0: 22.5]
#set yrange [-0.2:0.06]
#set ytics 0.04

set pointsize 2

f(x) = 0.0

plot "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_PA/B_Sub/MOD_main_Vcritical_vs_PA_BSub_xBI_0.dat" using 2:1 title "{/Symbol c}_{BI}=0" w lp lw 3 pt 2,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_PA/B_Sub/MOD_main_Vcritical_vs_PA_BSub_xBI_50.dat" using 2:1 title "{/Symbol c}_{BI}=50" w lp lw 3 pt 4,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_PA/B_Sub/MOD_main_Vcritical_vs_PA_BSub_xBI_100.dat" using 2:1 title "{/Symbol c}_{BI}=100" w lp lw 3 pt 6,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_PA/B_Sub/MOD_main_Vcritical_vs_PA_BSub_xBI_150.dat" using 2:1 title "{/Symbol c}_{BI}=150" w lp lw 3 pt 8,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_PA/B_Sub/MOD_main_Vcritical_vs_PA_BSub_xBI_200.dat" using 2:1 title "{/Symbol c}_{BI}=200" w lp lw 3 pt 10




