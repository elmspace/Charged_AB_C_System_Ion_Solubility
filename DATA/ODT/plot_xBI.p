reset
set key t l
set autoscale

set term postscript enhanced color
set output "~/Desktop/fE.ps"

set ylabel 'ODT'  font ",25"
set xlabel 'PA'  font ",25"

p0 = "./DATA/ODT/xBI/ODT_xBI_0.dat"
p1 = "./DATA/ODT/xBI/ODT_xBI_25.dat"
p2 = "./DATA/ODT/xBI/ODT_xBI_50.dat"
p3 = "./DATA/ODT/xBI/ODT_xBI_75.dat"
p4 = "./DATA/ODT/xBI/ODT_xBI_100.dat"

set pointsize 2

f(x) = 0.0

plot p0 using 1:2 w lp title "xBI = 0" lw 4 lt 3 ,\
p1 using 1:2 w lp  title "xBI = 25" lw 4 lt 1,\
p2 using 1:2 w lp  title "xBI = 50" lw 4 lt 2,\
p3 using 1:2 w lp  title "xBI = 75" lw 4 lt 4,\
p4 using 1:2 w lp  title "xBI = 100" lw 4 lt 5

pause(-1)

