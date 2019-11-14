CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb


all: bin/main bin/teste

clean:
	rm -rf bin/*

run: bin/main
	clear
	./bin/main

teste: bin/teste
	clear
	./bin/teste

bin/indice.o: src/main/indice.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/busca.o: src/main/busca.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/vetor.o: src/main/vetor.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/leitor.o: src/main/leitor.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/util.o: stc/main/util.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/main: bin/indice.o bin/busca.o bin/vetor.o bin/leitor.o src/main/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/teste: bin/indice.o bin/busca.o bin/vetor.o bin/leitor.o bin/util.o src/test/teste.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@
	
