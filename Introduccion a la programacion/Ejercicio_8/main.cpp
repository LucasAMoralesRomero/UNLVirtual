#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
	//ejercicio 8: sin usar un fot, hacer un programa que cuente
	//de 1 a 10 en una variable y salga
	
	:agregar1
	{
		cout << " " << numero << " "<<;
		numero ++;
		goto :volver;
	};
	int numero = 1;
	string linea = "=========================";
	cout << linea << endl;
	:volver;
	if (numero < 10) goto :agregar1;
	cout << endl;
	cout << linea << endl;
	return 0;
}
	

