SEED := $(shell od -An -N2 -i /dev/random | tr -d ' ')
ITER := 1000

all: constexpr templates

constexpr:
	g++ -o meta-constexpr constexpr.cpp -w -O2 -DSEED=$(SEED) -DITER=$(ITER) -std=c++14

templates:
	g++ -o meta-montecarlo main.cpp -fpermissive -ftemplate-depth=1000000 -w -O2 -DSEED=$(SEED) -std=c++14
