prog.exe: main.o utilitaires.o
	g++ -static-libstdc++ -o prog.exe main.o utilitaires.o

main.o: main.cpp
	g++ -c main.cpp

utilitaires.o: utilitaires.cpp
	g++ -c utilitaires.cpp
clean:
	rm *.o