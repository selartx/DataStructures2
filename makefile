all: derle calistir

derle:
	g++ -c -I "./include/" ./src/Main.cpp -o ./lib/Main.o
	g++ -c -I "./include/" ./src/Linkedlist.cpp -o ./lib/Linkedlist.o 
	g++ -c -I "./include/" ./src/Bst.cpp -o ./lib/Bst.o 
calistir:
	g++    ./lib/Linkedlist.o ./lib/Main.o   ./lib/Bst.o     -o ./bin/program  
	./bin/program
