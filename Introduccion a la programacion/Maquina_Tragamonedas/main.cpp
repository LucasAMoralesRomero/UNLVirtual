#include<iostream>
#include<ctime>
#include <conio.h>
#include <windows.h>

using namespace std;


int main (int argc, char *argv[]) {
	int Monedas_En_Maquina = 10;
	int Monedas_Ingresadas = 0;
	int Monedas_Para_Jugar = 0;
	bool Bandera_Monedas_Usuario = true;
	int Tambores[3] = {0,0,0};
	//char Entrada = "a";
	//int i = 0;
	cout<<"Bienvenido a la maquina tragamonedas!"<<endl;
	cout<<"Presione M para ingresar monedas"<<endl;
	cout<<"Presione ENTER para tirar la palanca"<<endl;
	cout<<"Presione Z para retirarse con sus monedas"<<endl;
	while (Bandera_Monedas_Usuario)
		{

		if(kbhit())
			{
			
			int tecla=getch();
			switch(tecla)
				{
				case 13: //enter
					if(Monedas_Para_Jugar > 0)
						{
							cout<<"presionaste enter, SUERTE!!"<<endl;
							Monedas_Para_Jugar = Monedas_Para_Jugar - 1;
							cout<<"Le quedan "<<Monedas_Para_Jugar<<" monedas."<<endl;
						
						for (int i=0; i<3; i++)
							{
								Tambores[i] = rand()%(7-1+1)+1;
								cout<<Tambores[i]<<endl;
								}
						if(Tambores[0] == Tambores[1] & Tambores[1] == Tambores[2])
							{
								Monedas_Para_Jugar = Monedas_Para_Jugar + (Tambores[0]*3);
								cout<<"Usted gano "<<Tambores[0]*3<<" monedas, FELICITACIONES!!"<<endl;
							}
						}
					else 
						{
							cout<<"ERROR!! no dispone de monedas para jugar, ingrese mas monedas"<<endl;
						}
					break;
				case 'm': //ingresa monedas
					cout<<"Cuantas monedas quiere ingresar?"<<endl;
					cin>>Monedas_Ingresadas;
					if(Monedas_Ingresadas <= 0 | Monedas_Ingresadas >= 10)
					{
						while(Monedas_Ingresadas <= 0 | Monedas_Ingresadas >= 10)
						{
							cout<<"ERROR!! solo puede ingresar hasta 9 monedas, reintente"<<endl;
							cin>>Monedas_Ingresadas;
						}
					}
					cout<<"Ingreso " << Monedas_Ingresadas << " monedas."<<endl;
					Monedas_Para_Jugar = Monedas_Para_Jugar + Monedas_Ingresadas;
					cout<<"Usted tiene "<<Monedas_Para_Jugar<<" monedas para jugar, ¡SUERTE!"<<endl;
					
					break;
				case 'z': 
					cout<<"Usted se retira con "<<Monedas_Para_Jugar<<" monedas."<<endl;
					return 1;
				default: cout<<"ERROR!! opcion incorrecta, por favor reintente"<<endl;
				}
			}
		}
	return 0;
}

