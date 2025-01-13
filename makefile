parametrosCompilacao=-Wall -std=gnu++20 
nomePrograma=postinho
all: $(nomePrograma)

$(nomePrograma): main.o OpInvalidoException.o Pessoa.o Profissional.o Usuario.o Ficha.o Gerente.o Medico.o Consulta.o Produto.o Estoque.o Interface.o
	g++ -o $(nomePrograma) main.o OpInvalidoException.o Pessoa.o Profissional.o Usuario.o Ficha.o Gerente.o Medico.o Consulta.o Produto.o Estoque.o Interface.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

OpInvalidoException.o: OpInvalidoException.hpp OpInvalidoException.cpp
	g++ -c OpInvalidoException.cpp $(parametrosCompilacao)
  
Pessoa.o: Pessoa.hpp Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

Profissional.o: Profissional.hpp Profissional.cpp
	g++ -c Profissional.cpp $(parametrosCompilacao)

Usuario.o: Usuario.hpp Usuario.cpp
	g++ -c Usuario.cpp $(parametrosCompilacao)

Ficha.o: Ficha.hpp Ficha.cpp
	g++ -c Ficha.cpp $(parametrosCompilacao)

Gerente.o: Gerente.hpp Gerente.cpp
	g++ -c Gerente.cpp $(parametrosCompilacao)

Medico.o: Medico.hpp Medico.cpp
	g++ -c Medico.cpp $(parametrosCompilacao)

Consulta.o: Consulta.hpp Consulta.cpp
	g++ -c Consulta.cpp $(parametrosCompilacao)

Produto.o: Produto.hpp Produto.cpp
	g++ -c Produto.cpp $(parametrosCompilacao)

Estoque.o: Estoque.hpp Estoque.cpp
	g++ -c Estoque.cpp $(parametrosCompilacao)

Interface.o: Interface.hpp Interface.cpp
	g++ -c Interface.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
	clear
