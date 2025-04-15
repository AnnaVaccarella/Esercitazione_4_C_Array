#include <iostream>
#include <fstream> //per leggere e scrivere file
#include <iomanip> //per formattare l'output numerico
#include <string> //per usare oggetti stringa 
#include <sstream> //per dividere le stringhe in parti

using namespace std;

int main() {
	ifstream inputFile("data.txt");
	
	if (!inputFile) {
		cerr<< "Errore nell'apertura del file" ;
		return 1;
	}
string line;
float S;
int n;

//Leggi la prima riga: S
getline(inputFile, line);
S = stof(line.substr(line.find(';') + 1)); //line.find(';') + 1 trova la posizione dopo il ; per estrarre solo il valore, stof() converte da stringa a float

//Seconda riga: n
getline(inputFile, line);
n = stoi(line.substr(line.find(';')+ 1));

//Terza riga: intestazione; la ignoriamo
getline(inputFile, line);



	
	