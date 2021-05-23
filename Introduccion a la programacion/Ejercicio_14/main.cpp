#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
	string nombre = "";
	int vida = 10;
	int runa1 = 0;
	int runa2 = 0;
	int runa3 = 0;
	string barra = "=========================";
	cout << barra << endl;
	cout << "Ingrese nombre del personaje: ";
	cin >> nombre;
	cout << endl;
	cout << "Su nombre es: " << nombre << endl;
	cout << "Sus puntos de vida son: " << vida << endl;
	
	return 0;
}

