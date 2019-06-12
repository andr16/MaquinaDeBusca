#include <iostream>
#include <fstream>
#include <algorithm>
#include "indiceInvertido.h"
using namespace std;

BaseDados::BaseDados() {}

void BaseDados::inserir(string palavra, string documento) {
	set<string> docs = { documento };
	pair<map<string, set<string>>::iterator, bool> par;
	par = mapa.insert(pair<string, set<string>>(palavra, docs));
	if (!par.second) {
		mapa[palavra].insert(documento);
	}
}

void BaseDados::imprimirIndice() {
	for (auto it1 = mapa.begin(); it1 != mapa.end(); ++it1) {
		cout << "\nPalavra: " << it1->first;
		cout << "\nValores:";
		for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
			cout << *it2 << endl;
		}
	}
}

int BaseDados::ocorrenciasArquivo(string palavra, string documento) {
	ifstream inFile;
	string palavra_no_arq;
	int contador = 0;

	inFile.open("C:\\Users\\André\\Documents\\UFMG\\PDS II\\" + documento + ".txt");
	if (!inFile) {
		cerr << "O arquivo" + documento + "nao foi aberto";
		exit(1);
	}

	while (inFile >> palavra_no_arq) {
		for (int i = 0; palavra_no_arq[i] != '\0'; i++) { // Loop para eliminar simbolos e letras maiusculas das palavras do arquivo
			palavra_no_arq[i] = tolower(palavra_no_arq[i]);
			palavra_no_arq.erase(remove_if(palavra_no_arq.begin(), palavra_no_arq.end(), [](char c) { return !isalpha(c) && !isdigit(c); }), palavra_no_arq.end());
		}
		if (palavra == palavra_no_arq) {
			contador++;
		}
	}
	inFile.close();
	return contador;
}

void BaseDados::ler_inserir_Arquivos() {
	ifstream inFile;
	string palavra;

	for (int p = 1; p <= 5; p++) {
		inFile.open("C:\\Users\\André\\Documents\\UFMG\\PDS II\\" + to_string(p) + ".txt");
		if (!inFile) {
			cerr << "O arquivo" + to_string(p) + "nao foi aberto";
			exit(1);
		}

		while (inFile >> palavra) { 
			for (int i = 0; palavra[i] != '\0'; i++) { // Loop para eliminar simbolos e letras maiusculas das palavras do arquivo
				palavra[i] = tolower(palavra[i]);
				palavra.erase(remove_if(palavra.begin(), palavra.end(), [](char c) { return !isalpha(c) && !isdigit(c); }), palavra.end());
			}
	        inserir(palavra, to_string(p));
		}
		inFile.close();
	}
}

bool BaseDados::pertence(string palavra) {
	return (mapa.find(palavra) != mapa.end());
}

map<string, int> BaseDados::frequencia(string palavra) {
	BaseDados objeto;
	set<string> arquivos;
	
	if (objeto.pertence(palavra)); {
		arquivos = mapa[palavra];
	}

	map<string, int> tf;
	set<string>::iterator it_arqs;
	map<string, int>::iterator it_tf;

	for (it_arqs = arquivos.begin(); it_arqs != arquivos.end(); it_arqs++) {
		tf[*it_arqs] = objeto.ocorrenciasArquivo(palavra, *it_arqs);
	}

	return tf;
}