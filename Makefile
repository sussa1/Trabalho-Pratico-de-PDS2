CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb


all: bin/main

clean:
	rm -rf bin/*

run: bin/main
	clear
	./bin/main

teste: bin/teste
	clear
	./bin/teste

bin/busca.o: src/busca.cpp
        $(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/indice.o: src/indice.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/vetor.o: src/vetor.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/leitor.o: src/leitor.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/main: bin/indice.o bin/busca.o bin/vetor.o bin/leitor.o src/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/teste: bin/fila.o src/teste.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@
	