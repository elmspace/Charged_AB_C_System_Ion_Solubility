reset
unset key
set autoscale

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
#path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/Charged_AB_C_System_Ion_Solubility/RESULTS/"
path_to_file = "/home/elmspace/Desktop/SCFT_CODES/ION_SOLUBILITY/FARM/main1/RESULTS/"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   
   f(x)=0.0
   
plot path_to_file."fE.dat" using 1:2 w lp lw 3 lt 1

pause(-1)

