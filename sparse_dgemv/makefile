gcc_options = -std=c++17 -Wall --pedantic-errors
l_b = -llapacke -lblas

program : InputData.o sdgemv.o vec_Initialize.o
	g++ -o $@ $^ $(l_b)

main.o : sdgemv.cpp
	g++ -c $< $(l_b)

printmat.o : InputData.cpp
	g++ -c $< $(l_b)

power.o : vec_Initialize.cpp
	g++ -c $< $(l-b)


run : program
	./program

clean:
	rm -f ./program

.PHONY : run clean