5 PI=3.14159
10 hgr
15 a=0:b=0
20 FOR I = 1 TO 20
25 a=RND(1)*180+50:b=RND(1)*92+50
30 GOSUB 100
40 NEXT 
100 REM CIRCLE
115 x=0
120 r=50
130 inc=1/r
150 hplot sin(x)*r+a ,cos(x)*r+b
160 x=x+inc
165 IF x > 2 * PI THEN RETURN 
170 goto 150
