#ifndef INDICEINVERTIDO_H
#define INDICEINVERTIDO_H

#include <string>
#include <map>
#include <set>
#include <vector>
#include <math.h>
const int NUMERO_DOCUMENTOS = 5;

using namespace std;

class BaseDados {
public:
	// Construtor da classe
	BaseDados();

	// Insere a palavra e o documento no map de acordo com o indice invertido
	void inserir(string palavra, string documento);

	// Le os arquivos e insere as palavras no indice invertido
	void ler_inserir_Arquivos();

	// Imprime o indice invertido
	void imprimirIndice();

	// Le o documento e retorna o numero de vezes que a palavra ocorre nele
	int ocorrenciasArquivo(string palavra, string documento);

	// Retorna se a palavra pertence a algum arquivo
	bool pertence(string palavra);

	// Recebe uma palavra e retorna um mapa com os documentos
	// onde ela aparece e o numero de vezes que ela se repete.
	// Pre-condicao: a palavra deve pertencer a algum arquivo
	map<string, int> frequencia(string palavra);
	
	// Retorna o numero de arquivos em que a palavra aparece
	int numeroArquivos(string palavra);


	// ------------------------------------------------------


	// Calcula idf de apenas uma palavra
	double calcularIdf(string palavra);

	// Cria sistema de coordenada por funcao hash
    //map<int, double> hash();

	// Funcao de entrada
	string entrada();

	// Testa se palavra pertence a documento
	bool existe(string palavra, string documento);

private:
	map<string, set<string>> mapa; // Mapa que representa o indice invertido
	vector<string> nomeDocumentos;
	map<int, double> coordenadas;
	friend class Teste;
};

#endif  // INDICEINVERTIDO_H