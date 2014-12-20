#!/usr/bin/gnuplot
set title "memory usage"
set xlabel "time"
set ylabel "memory"
unset xtics
unset ytics
set key off
plot "gnuplot.data" title "" with lines
pause -1 "Hit any key to continue"

