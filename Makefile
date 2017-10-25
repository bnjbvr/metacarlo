RR := $(shell od -An -N2 -i /dev/random | tr -d ' ')
ITER := 1000

all:
	g++ -o meta-constexpr constexpr.cpp -w -O2 -DSEED=$(RR) -DITER=$(ITER) -std=c++14
	g++ -o meta-montecarlo main.cpp -fpermissive -ftemplate-depth=1000000 -w -O2 -DSEED=$(RR) -std=c++14
