CXXFLAGS=-std=c++20 -g

prog.exe: main.o utilitaires.o lit_ecrit.o operations.o
	g++ -static-libstdc++ -o prog.exe main.o utilitaires.o lit_ecrit.o operations.o

main.o: main.cpp
	g++ -c $(CXXFLAGS) main.cpp

utilitaires.o: utilitaires.cpp
	g++ -c $(CXXFLAGS) utilitaires.cpp

lit_ecrit.o: lit_ecrit.cpp
	g++ -c $(CXXFLAGS) lit_ecrit.cpp

operations.o: operations.cpp
	g++ -c $(CXXFLAGS) operations.cpp

clean:
	rm *.o