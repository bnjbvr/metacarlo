RR := $(shell od -An -N2 -i /dev/random | tr -d ' ')

all:
	g++ -o meta-montecarlo main.cpp -fpermissive -ftemplate-depth=1000000 -w -O2 -DSEED=$(RR)
