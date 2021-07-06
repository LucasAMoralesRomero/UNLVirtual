#include<iostream>
#include<ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

int main (int argc, char *argv[]) {
	//defino un arreglo multidimensional por cada palo(basto espada copa y oro)en el cual contengo el numero de naipe y un numero adiional que usare como bandera
	int Basto [2][10] {{1,2,3,4,5,6,7,10,11,12},{0,0,0,0,0,0,0,0,0,0}};
	int Espada [2][10] {{1,2,3,4,5,6,7,10,11,12},{0,0,0,0,0,0,0,0,0,0}};
	int Copa [2][10] {{1,2,3,4,5,6,7,10,11,12},{0,0,0,0,0,0,0,0,0,0}};
	int Oro [2][10] {{1,2,3,4,5,6,7,10,11,12},{0,0,0,0,0,0,0,0,0,0}};
	bool QuieroJugar = true; //bandera para indicar si quiero jugar o no 
	cout << "Bienvenido al juego de 7 ½" << endl;
	cout << "Soy Sherman, el crupier de esta noche" << endl;
	cout << "En este juego, le ire tirando cartas, el objetivo es no pasarse de 7 ½" << endl;
	cout << "El mazo con el que jugaremos cuenta con 40 cartas, del 1 al 7 suman su valor: el 1 de basto vale 1, el 5 de oro vale 5" << endl;
	cout << "Y el 10, 11 y 12 valen ½" << endl;
	
	return 0;
}

