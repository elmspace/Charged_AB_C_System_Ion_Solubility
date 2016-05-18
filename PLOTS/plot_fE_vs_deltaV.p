reset
unset key
set autoscale

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/Charged_AB_C_System_Ion_Solubility/RESULTS/"

##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   
   f(x)=0.0
   
plot path_to_file."MOD_Lam.dat" using 2:1 w lp lw 3 lt 1,\
path_to_file."MOD_Hex.dat" using 2:1 w lp lw 3 lt 3

pause(-1)

