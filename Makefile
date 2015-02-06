#***********************************************************************************************
#*										Makefile												*
#*																								*
#*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
#*																								*
#*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
#***********************************************************************************************

my_sh: main.o addhist.o showhist.o execute.o multiexec.o mypipe.o outredir.o inredir.o my_cd.o
	cc main.o addhist.o showhist.o execute.o multiexec.o mypipe.o outredir.o inredir.o my_cd.o -o my_sh
main.o: main.c
	cc -c main.c -o main.o
addhist.o: addhist.c
	cc -c addhist.c -o addhist.o
showhist.o: showhist.c
	cc -c showhist.c -o showhist.o
execute.o: execute.c
	cc -c execute.c -o execute.o
multiexec.o: multiexec.c
	cc -c multiexec.c -o multiexec.o
mypipe.o: mypipe.c
	cc -c mypipe.c -o mypipe.o
outredir.o: outredir.c
	cc -c outredir.c -o outredir.o
inredir.o: inredir.c
	cc -c inredir.c -o inredir.o
my_cd.o: my_cd.c
	cc -c my_cd.c -o my_cd.o
clean:
	rm *.o
