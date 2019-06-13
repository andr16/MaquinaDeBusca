#define DOCTEST_CONFIG_IMPLEMENT
#include "indiceInvertido.h"
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Teste {
public:
	static map<string, set<string>> mapa_(const BaseDados& c) {
		return c.mapa;
	}
};

TEST_SUITE("BaseDados") {
	TEST_CASE("inserir(string palavra, string documento)") {
		BaseDados x;
		x.inserir("barraca", "arquivo");
		map<string, set<string>>::iterator it = Teste::mapa_(x).begin();
		CHECK(it->first == "barraca");
	}

	TEST_CASE("ler_inserir_Arquivos()") {
		BaseDados x;
		x.ler_inserir_Arquivos();
		map<string, set<string>>::iterator it = Teste::mapa_(x).begin();
		string primeiro = it->first;
		CHECK(primeiro == "quem");		
	}

	TEST_CASE("ocorrenciasArquivo(string palavra, string documento)") {
		BaseDados x;
		CHECK(x.ocorrenciasArquivo("casa", "1") == 4);
		CHECK(x.ocorrenciasArquivo("apartamento", "1") == 1);
		CHECK(x.ocorrenciasArquivo("carcara", "4") == 1);
		CHECK(x.ocorrenciasArquivo("dinossauro", "2") == 0);
	}

	TEST_CASE("pertence(string palavra)") {
		BaseDados x;
		CHECK(x.pertence("casa") == true);
		CHECK(x.pertence("nelson") == false);
		x.inserir("kleide", "10");
		CHECK(x.pertence("kleide") == true);
	}

	TEST_CASE("frequencia(string palavra)") {
		BaseDados x;
		string palavra = "casa";
		REQUIRE(x.pertence(palavra) == true);
		map<string, int> tf = x.frequencia(palavra);
		map<string, int>::iterator it = tf.begin();
		CHECK(it->first == "1");
		CHECK(it->second == 4);
	}

	TEST_CASE("numeroArquivos(string palavra") {
		BaseDados x;
		x.inserir("palavra", "10");
		x.inserir("palavra", "11");
		x.inserir("string", "20");
		x.inserir("valor", "76");
		CHECK(x.numeroArquivos("palavra") == 2);
		CHECK(x.numeroArquivos("string") == 1);
		CHECK(x.numeroArquivos("valor") == 1);
		CHECK(x.numeroArquivos("poltrona") == 0);
	}
}