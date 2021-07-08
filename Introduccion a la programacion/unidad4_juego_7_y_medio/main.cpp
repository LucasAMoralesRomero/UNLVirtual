#include<iostream>
#include<ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

int main (int argc, char *argv[]) {
	//defino un arreglo multidimensional por cada palo(basto espada copa y oro)en el cual contengo el numero de naipe y un numero adiional que usare como bandera
	string Palos[4]{"Espada","Basto","Copa","Oro"};//array que contiene los palos de las cartas
	int Mazo[8][10]{
			{1,2,3,4,5,6,7,10,11,12},//espada
			{1,2,3,4,5,6,7,10,11,12},//basto
			{1,2,3,4,5,6,7,10,11,12},//copa
			{1,2,3,4,5,6,7,10,11,12},//oro
			{0,0,0,0,0,0,0,0,0,0},//bandera espada
			{0,0,0,0,0,0,0,0,0,0},//bandera basto
			{0,0,0,0,0,0,0,0,0,0},//bandera copa
			{0,0,0,0,0,0,0,0,0,0}//bandera oro	
		};
	int JugadasJugador [2][14]{{0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0}};//array que contiene las jugadas del jugador
	int ContadorJugador = 0;//contador de jugadas,sirve como indice de JugadasJugador
	float SumaJugador = 0;//acumula los resultados del jugador
	int JugadasComputadora [2][14]{{0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0}};//array que contiene las jugadas de la computadora
	int ContadorComputadora = 0;//contador de jugadas, sirve como indice deJugadasComputadora
	string Jugador = "";
	bool QuieroJugar = true; //bandera para indicar si quiero jugar o no
	int NumeroAleatorio = 0;//variable para almacenar el numero aleatorio
	int Palo = 0;//almaceno el palo de la baraja (basto copa oro o espada)
	cout << "Bienvenido al juego de 7 y medio" << endl;
	cout << "Soy Sherman, el crupier de esta noche" << endl;
	cout << "En este juego, le ire tirando cartas, el objetivo es no pasarse de 7 y medio" << endl;
	cout << "El mazo con el que jugaremos cuenta con 40 cartas, del 1 al 7 suman su valor: el 1 de basto vale 1, el 5 de oro vale 5" << endl;
	cout << "Y el 10, 11 y 12 valen medio" << endl;
	cout << "Por favor, digame su nombre" << endl;
	cin >> Jugador;
	cout << "Un gusto, " << Jugador << " dejeme barajar y comencemos!" << endl;
	cout << Jugador << " , le tiro una carta? (S = si / N = no)" << endl; 
	while (QuieroJugar)
		{
		if(kbhit())
			{
			int tecla=getch();
			switch (tecla)
				{
				case 83 | 115://83 es S y 115 es s en ascii
					if(SumaJugador < 7.6)
					{
						do {
							Palo = rand () % 3 + 0;//genero un numero aleatorio enre 0 y 3 
							NumeroAleatorio = rand() % 9 + 0; //genero un numero aleatorio entre 1 y 10
						} while(Mazo[Palo+4][NumeroAleatorio] ==1);
						cout << "Te salio el " << Mazo[1][NumeroAleatorio] << " de " << Palos[Palo] << endl;
						Mazo[Palo+4][NumeroAleatorio]=1;//cambio la bandera para indicar que ya salio
						JugadasJugador[0][ContadorJugador] = Mazo[1][NumeroAleatorio];//asigno numero que salio en indice de jugada|
						JugadasJugador[1][ContadorJugador] = Palo;//asigno palo que salio en indice de jugada
						ContadorJugador ++;
						if(NumeroAleatorio < 7 )//si el numero aleatorio es < 7 significa que esta entre 1 y 7
						{
							SumaJugador = SumaJugador + (NumeroAleatorio + 1);//suma a suma jugador el valor de la carta que salio
						}
						else // si no es menor que 7 significa que es 10 11 o 12
						{
							SumaJugador = SumaJugador + 0.5;
						}
					}
					else 
					{
						cout <<Jugador << " Te pasaste de 7.5, perdiste."<<endl;
					}
					break;
				}
			}
		}

	return 0;
}

