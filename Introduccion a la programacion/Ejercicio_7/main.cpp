#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
	//ejercicio 7: mostrar edad y con bool ver si es mayor que 50
	int edad = 28;
	bool mayor = edad > 50;
	string linea = "=========================";
	cout << linea << endl;
	cout << "Mi edad es: " << edad << endl;
	cout << "Es mi edad mayor a 50?: " << mayor << endl;
	cout << linea;
	return 0;
}

