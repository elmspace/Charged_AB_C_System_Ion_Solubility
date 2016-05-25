reset
unset key
set autoscale

p1 = "./RESULTS/MOD_Lam_PA_1em2.dat"
p2 = "./RESULTS/MOD_Lam_PA_1em20.dat"
p3 = "./RESULTS/MOD_Lam_PA_1p5em2.dat"
p4 = "./RESULTS/MOD_Lam.dat"

set xr [10.0 : 12.0]

f(x) = 0.0

plot f(x) with l lc -1,\
p1 using 4:1 w lp lw 3 lt 1,\
 p2 using 4:1 w lp lw 3 lt 2,\
 p3 using 4:1 w lp lw 3 lt 3,\
 p4 using 4:1 w lp lw 3 lt 4


pause(-1)

