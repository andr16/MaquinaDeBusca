#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <cctype>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {
	map<string, set<string>> data;
	set<string> s;

	/*for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}
	
	set<string>::iterator itSet;
	map<string, set<string>>::iterator t;

	for (t = data.begin(); t != data.end(); t++) {
		cout << "chave: " << t->first << endl << endl;
	}

	for (itSet = s.begin(); itSet != s.end(); itSet++) {
		cout << "valor:" << *itSet << endl;
	}*/

	ifstream inFile1, inFile2;
	inFile1.open("C:\\Users\\André\\Documents\\UFMG\\PDS II\\doc1.txt");
	inFile2.open("C:\\Users\\André\\Documents\\UFMG\\PDS II\\doc2.txt");
	if (!inFile1) {
		cerr << "O arquivo 1 nao foi aberto";
		exit(1);
	}
	if (!inFile2) {
		cerr << "O arquivo 2 nao foi aberto";
		exit(1);
	}

	string a, b;
	while (inFile1 >> a) { // loop para eliminar simbolos e letras maiusculas das palavras do arquivo
		for (int i = 0; a[i] != '\0'; i++) {
			a[i] = tolower(a[i]);
			a.erase(remove_if(a.begin(), a.end(), [](char c) { return !isalpha(c) && !isdigit(c); }), a.end());
		}
		cout << a << ' ';
	}
	inFile1.close();

	/*map<string, set<string>>::iterator itMapa;
	set<string>::iterator itSet;

	for (itMapa = data.begin(), itSet = s.begin(); itMapa != data.end(); itMapa++, itSet++) {
		cout << itMapa->first << "->" << *itSet << endl;
	}*/


	/*cout << endl << endl;
	while (inFile2 >> b) {
		for (int i = 0; b[i] != '\0'; i++) {
			b[i] = tolower(b[i]);
			b.erase(remove_if(b.begin(), b.end(), [](char c) { return !isalpha(c); }), b.end());
			cout << b[i];
		}
		cout << ' ';
	}
	inFile2.close();
	cout << endl;*/
}
