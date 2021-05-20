#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
	//ejercicio 6: mi edad y mi edad en 10 años
	int edad = 28;
	string linea = "========================";
	cout << linea << endl;
	cout << "Tengo " << edad << " anios." << endl;
	edad += 10;
	cout << "En 10 anios voy a tener: " << edad << " anios" << endl;
	cout << linea;
	return 0;
}

