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

bin/indexador.o: src/main/indexador.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/indice_invertido.o: src/main/indice_invertido.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/documento.o: src/main/documento.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/busca.o: src/main/busca.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/vetor.o: src/main/vetor.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/leitor.o: src/main/leitor.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/util.o: src/main/util.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/main: bin/documento.o bin/indice_invertido.o bin/indice.o bin/busca.o bin/vetor.o bin/leitor.o src/main/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/teste: bin/util.o src/teste/teste.cpp src/teste/teste_util.cpp
	$(CXX) $(CXX_FLAGS) -I include/ -I src/main/ $^ -o $@
	
