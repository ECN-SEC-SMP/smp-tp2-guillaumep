prog.exe: main.o utilitaires.o lit_ecrit.o
	g++ -static-libstdc++ -o prog.exe main.o utilitaires.o lit_ecrit.o

main.o: main.cpp
	g++ -c main.cpp

utilitaires.o: utilitaires.cpp
	g++ -c utilitaires.cpp

lit_ecrit.o: lit_ecrit.cpp
	g++ -c lit_ecrit.cpp

clean:
	rm *.o