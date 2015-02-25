reset
set key b l
#set xr [0.0 : 5.0]
set yr [3.5 : 30.0]

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_mu.dat"
# Landau
#path_to_file = "/1/home/dehgha2/Desktop/Electric_Thin_Film_Project/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_mu.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

plot path_to_file using (abs($2)):1 title " " w lp,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/points.dat" using (abs($2)):1 w p pt 6,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/points.dat" using (abs($3)):1 w p pt 7
