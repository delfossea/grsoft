5 PI=3.14159
10 hgr
15 x=0
20 r=50
30 inc=1/r
50 hplot sin(x)*r+70 ,cos(x)*r+70
60 x=x+inc
65 IF x > 2 * PI THEN goto 80
70 goto 50
80 REM fin
