reset
unset key
set autoscale

p0 = "./RESULTS/MOD_Lam_PA0.dat"
p1 = "./RESULTS/MOD_Lam.dat"


#set xr [10.0 : 12.0]

f(x) = 0.0

plot f(x) with l lc -1,\
   p0 using 4:1 w lp lw 3 lt 3,\
   p1 using 4:1 w lp lw 3 lt 1

pause(-1)

