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
#include "indiceInvertido.h"

using namespace std;

int main() {
	string h;
	BaseDados objetoGeral;
	cout << "Pesquise: " << endl;
	cin >> h;

	objetoGeral.frequencia(h);
	//objetoGeral.ler_inserir_Arquivos();
	//objetoGeral.imprimirIndice();
	//cout << objetoGeral.numeroArquivos(h);
	return 0;
}
