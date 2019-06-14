#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include "baseDados.h"

using namespace std;

BaseDados::BaseDados() {
	this->ler_inserir_Arquivos();
	coordenadas = this->hash();
}

void BaseDados::inserir(string palavra, string documento) {
	set<string> docs = { documento };
	pair<map<string, set<string>>::iterator, bool> par;
	par = mapa.insert(pair<string, set<string>>(palavra, docs));
	if (!par.second) {
		mapa[palavra].insert(documento);
	}
}

void BaseDados::ler_inserir_Arquivos() {
	ifstream inFile;
	string palavra;

	for (int p = 1; p <= 5; p++) {
	 inFile.open("C:\\Users\\André\\Documents\\UFMG\\PDS II\\" + to_string(p) + ".txt");
	//	inFile.open("C:\\Users\\André\\Documents\\UFMG\\PDS II\\colecao_arquivos\\" + to_string(p));
		if (!inFile) {
			//cerr << "O arquivo" + to_string(p) + "nao foi aberto";
			cout << "pulou\n";
	//		continue;
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
	}
	else {
		while (inFile >> palavra_no_arq) {
			for (int i = 0; palavra_no_arq[i] != '\0'; i++) { // Loop para eliminar simbolos e letras maiusculas das palavras do arquivo
				palavra_no_arq[i] = tolower(palavra_no_arq[i]);
				palavra_no_arq.erase(remove_if(palavra_no_arq.begin(), palavra_no_arq.end(), [](char c) { return !isalpha(c) && !isdigit(c); }), palavra_no_arq.end());
			}
			if (palavra == palavra_no_arq) {
				contador++;
			}
		}
	}
	inFile.close();
	return contador;
}

bool BaseDados::pertence(string palavra) {
	return (mapa.find(palavra) != mapa.end());
}

map<string, int> BaseDados::frequencia(string palavra) {
	set<string> arquivos;
	map<string, int> tf;
	set<string>::iterator it_arqs;
	map<string, int>::iterator it_tf;
	if (this->pertence(palavra)) {
		arquivos = mapa[palavra];
	}

	for (it_arqs = arquivos.begin(); it_arqs != arquivos.end(); it_arqs++) {
		tf[*it_arqs] = this->ocorrenciasArquivo(palavra, *it_arqs);
	}

	for (it_tf = tf.begin(); it_tf != tf.end(); it_tf++) {
		cout << "\nChave: " << it_tf->first;
		cout << "\nValor: " << it_tf->second << endl;
	}

	return tf;
}

int BaseDados::numeroArquivos(string palavra) {
	set<string> arquivos;

	if (this->pertence(palavra)) {
		arquivos = mapa[palavra];
	}
	return arquivos.size();
}



// -------------------------------------------------------------------------------



double BaseDados::calcularIdf(string palavra) {
	return log(NUMERO_DOCUMENTOS / numeroArquivos(palavra));
}

map<int, double> BaseDados::hash() {
	int numeroPalavra = mapa.size();
	map<int, double>aux;
	map<string, set<string>>::iterator it;
	vector<string>::iterator i; // Iterator referente ao vector com nome dos documentos
	int x = 1;
	for (it = mapa.begin(); it != mapa.end(); it++, x++) { // Avanca o map<string,set<string> 
		BaseDados a;
		string palavra = it->first;
		map<string, int> resultado = frequencia(palavra);
		auto passaFrequencia = resultado.begin();
		auto docFrequencia = resultado.begin(); // Mapa (doc,frequencia)
		for (i = nomeDocumentos.begin(); i != nomeDocumentos.end(); i++) {
			int valorVetor = atoi(i->c_str());
			int valorMap = atoi((it->first).c_str());
			if (valorVetor == valorMap) {
				int tf = ocorrenciasArquivo(palavra, *i);
				pair<int, double> a(x * numeroPalavra + valorVetor, calcularIdf(palavra) * ((double)tf));
				passaFrequencia++;
			}
			else {
				pair<int, double> a(x * numeroPalavra + valorVetor, 0);
			}
		}
	}

	return aux;
}

void BaseDados::hash(string pesquisa) {
	int numeroPalavra = mapa.size();
	vector<string> divido;
	vector<string>::iterator vectorI = divido.begin(); //iterator referente ao vector com nome dos documentos
	map<int, double>::iterator coordenadasI;
	string inserir;
	for (int i = 0; pesquisa[i] != '\0'; i++) {
		char aux = pesquisa[i];
		int teste = aux;
		inserir[i] = pesquisa[i];
		if (teste == 32 || aux == '\0') {
			divido.push_back(inserir);
			inserir = "";
		}
	}
	int x = 1;
	for (map<string, set<string>>::iterator iAux = mapa.begin(); iAux != mapa.end(); iAux++, x++) { // Avanca o map<string,set<string> 
		int contem = 0;
		string palavra = iAux->first;
		for (vectorI; vectorI != divido.end(); vectorI++) {
			if (palavra == *vectorI) {
				contem++;
			}
		}
		if (contem > 0) {
			pair < int, double > a(x * numeroPalavra + 1, calcularIdf(palavra) * ((double)contem));
			coordenadas.insert(a);
		}
		else {
			pair < int, double > a(x * numeroPalavra + 1, 0);
			coordenadas.insert(a);
		}
	}
}


// ------------------------ END HASH ----------------------------------------


bool BaseDados::existe(string palavra, string documento) {
	set<string> aux;
	set<string>::iterator it;
	aux = mapa[palavra];
	for (it = aux.begin(); it != aux.end(); it++) {
		if (*it == palavra) {
			return true;
		}
	}
	return false;
}

map<double, int> BaseDados::rankingCoss() {
	map<double, int> SIM;
	int numero_palavras = mapa.size();
	
	vector<string>::iterator i;
	map<int, double>::iterator j;
	for (i = nomeDocumentos.begin(); i != nomeDocumentos.end(); i++) {
		double Somatorio1 = 0, Somatorio2 = 0, Somatorio3 = 0;
		for (int x = 1; x <= numero_palavras; x++) {
			j = coordenadas.find(x * numero_palavras + atoi(i->c_str()));
			double A = j->second;
			j = coordenadas.find(x * numero_palavras + 1);
			double B = j->second;
			Somatorio1 += (A * B);
			Somatorio2 += (A * A);
			Somatorio3 += (B * B);
		}
		double SimDQ = Somatorio1 / (sqrt(Somatorio2) * sqrt(Somatorio3));
		pair<int, double> p(SimDQ, atoi(i->c_str()));
		SIM.insert(p);
	}
	return SIM;
}

void BaseDados::imprimirRanking() {
	map<double, int> aux = this->rankingCoss();
	map<double, int>::reverse_iterator it = aux.rbegin();
	cout << "__________________________________________";
	for (int i = 0; i < 20; i++) {
		cout << " | " << (it->second) << " | " << endl;
	}
	cout << "___________________________________________";
}