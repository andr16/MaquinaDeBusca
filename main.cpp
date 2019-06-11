#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <cctype>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int main() {
	set<string> s;

	map<string, set<string>> data;
	set<string> rak;
	string a;

	for (int p = 1; p <= 5; p++) {
		ifstream inFile;
		
		inFile.open("C:\\Users\\André\\Documents\\UFMG\\PDS II\\" + to_string(p) + ".txt");
		if (!inFile) {
			cerr << "O arquivo" + to_string(p) + " nao foi aberto";
			exit(1);
		}

		while (inFile >> a) { // loop para eliminar simbolos e letras maiusculas das palavras do arquivo

			for (int i = 0; a[i] != '\0'; i++) {
				a[i] = tolower(a[i]);
				a.erase(remove_if(a.begin(), a.end(), [](char c) { return !isalpha(c) && !isdigit(c); }), a.end());
				rak.insert(to_string(p));
			}
			//cout << a << ' ';
			data[a] = rak;
		}
		inFile.close();
	}

	for (map<string, set<string> >::iterator it = data.begin(); it != data.end(); it++) {
		cout << "\n\nchave: " << it->first << endl;
	}

	for (set<string>::iterator o = rak.begin(); o != rak.end(); o++) {
		cout << "\n\nvalor: " << *o << endl;
	}


}
