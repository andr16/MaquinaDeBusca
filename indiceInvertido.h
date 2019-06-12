#ifndef INDICEINVERTIDO_H
#define INDICEINVERTIDO_H

#include <string>
#include <map>
#include <set>

using namespace std;

class BaseDados {
public:
	// Cria um indice invertido vazio
	BaseDados();

	// Insere a palavra e o documento no map de acordo com o indice invertido
	void inserir(string palavra, string documento);

	// Imprime o indice invertido
	void imprimirIndice();

	// Le o documento e retorna o numero de vezes que a palavra ocorre nele
	int ocorrenciasArquivo(string palavra, string documento);

	// Le cada arquivo, trata as palavras e as insere no indice
	void ler_inserir_Arquivos();

	// Retorna se a palavra pertence a algum arquivo
	bool pertence(string palavra);

	// Recebe uma palavra e retorna um mapa com os documentos
	// onde ela aparece e o numero de vezes que ela se repete.
	// Pre-condicao: a palavra deve pertencer a algum arquivo
	map<string, int> frequencia(string palavra);

private:
	map<string, set<string>> mapa; // Mapa que representa o indice invertido
	string palavra; // Palavras dos arquivos 
};

#endif  // INDICEINVERTIDO_H