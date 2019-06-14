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
#include "baseDados.h"

using namespace std;

string entrada() {
	string pesquisa;
	cout << "Consulta: ";
	cin >> pesquisa;
	return pesquisa;
}

int main() {
	BaseDados* Db = new BaseDados();
	char verificador = 's';
	while (verificador == 's') {
		string p = entrada();
		Db->hash(p);
		Db->rankingCoss();
		Db->imprimirRanking();
	}
	/*string pesquisa;
	entrada();*/
	
	//x.imprimirIndice();
	return 0;
}
