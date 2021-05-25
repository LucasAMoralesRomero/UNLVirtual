#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
	string nombre = "";
	double vida = 10;
	double runa1 = 0;
	double runa2 = 0;
	double runa3 = 0;
	double total = 0;
	string barra = "=========================";
	bool estaVivo;
	cout << barra << endl;
	cout << "Ingrese nombre del personaje: ";
	cin >> nombre;
	cout << endl;
	cout << "Su nombre es: " << nombre << endl;
	cout << "Sus puntos de vida son: " << vida << endl;
	cout << "ngresar primera runa: ";
	cin >> runa1;
	cout << endl;
	cout << "Ingrese segunda runa: ";
	cin >> runa2;
	cout << endl;
	cout << "Ingrese tercer runa: ";
	cin >> runa3;
	cout << endl;
	total = (runa1 - ((runa2/2) + (runa3/2)));
	vida = vida - total;
	cout << "Sus puntos de vida son: " << vida;
	cout << endl;
	vida = vida - total;
	cout << "Sus puntos de vida son: " << vida;
	estaVivo = vida > 0;
	cout << endl;
	cout <<"El personaje sigue vivo?: " << estaVivo;
	return 0;
}

