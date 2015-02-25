reset
set key b l

f(x) = 0.0

plot "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_mu_all_Phases.dat" using 2:4 title "Per" w lp lw 2 pt 8,\
 "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_mu_all_Phases.dat" using 2:5 title "Mix" w lp lw 2 pt 8


pause(-1)


reset
set key b l

f(x) = 0.0

plot "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_mu_all_Phases.dat" using 2:($4-$5) title "Per" w lp lw 2 pt 8

