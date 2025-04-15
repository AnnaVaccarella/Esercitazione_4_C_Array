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

//Lettura dei pesi e rendimenti
float w[100], r[100]; 
for (int i = 0; i < n; ++i) {
	getline(inputFile, line);
	stringstream ss(line);
	string w_str, r_str;
	
	getline(ss, w_str, ';');
	getline(ss, r_str, ';');
	
	w[i] = stof(w_str);
	r[i] = stof(r_str);
	
}

inputFile.close();
//Calcolo del rendimento e del valore finale
float r_tot = 0.0;
for (int i = 0; i < n; ++i)
	r_tot += w[i] * r[i];

float V = (1+r_tot) * S;
//Scrittura su file result.txt e su schermo
ofstream outputFile("result.txt");
if (!outputFile) {
	cerr << "Errore nell'apertura del file" ;
	return 1;
}
//Formattazione dell'output
outputFile<< fixed << setprecision(2);
cout << fixed << setprecision(2);

	
	

	
	