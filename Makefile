all:
	g++ -o meta-montecarlo main.cpp -fpermissive -ftemplate-depth=100000 -w -O2
