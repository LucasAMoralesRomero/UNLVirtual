#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

//void evaluarDados(int dados[], int auxDados[], bool jugadas[]);

//void darResultados(jugadas[], dadoAuxiliar[]);//me dice lo que saque
// primer parametro: arreglo a ordenar
// segundo parametro: elementos del arreglo 

void sort(int a[],int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}
void tirarDados (int dado[]){
	//tira los Dados
	//srand(time(NULL));
	int i;
	for (int i = 0; i < 5; i++) {
		
		dado[i] = (rand()%6 + 1);
		
	}	
}
	void evaluarDados(int dados[], int auxDados[], bool jugadas[]){
		//jugadas[0]=generala -- jugadas[1]=full -- jugadas [2]=poker -- jugadas[3]=escalera
		int i = 0;
		int j = 0;//contador para la salida de los numeros en dados(cuantas veces salen)
		int k = 0;//contador para las todos al 
		int aux = 0;
		//cuento cuantas veces salio un dados para los todo al...
		for (j = 0; j < 5; j++)
		{
			switch(dados[j])
			{
			case 1://en caso de ser 1, sumo 1 a auxdados
				auxDados[0] = auxDados[0]+1;
				break;
			case 2://en caso de ser 2 suno 1 a auxdados
				auxDados[1] =auxDados[1]+1;
				break;
			case 3://en caso de ser 3 sumo 1 a auxDados
				auxDados[2] =auxDados[2]+1;
				break;
			case 4://en caso de ser 4 sumo 1 a auxDados
				auxDados[3] =auxDados[3]+1;
				break;
			case 5://en caso de ser 5 sumo 1 a auxDados
				auxDados[4] =auxDados[4]+1;
				break;
			case 6://en caso de ser 6 sumo 1 a auxDados
				auxDados[5] =auxDados[5]+1;
				break;
			}
		}
		
		
		//evaluacion de Generala
		if (dados[0] == dados[1] && dados[1] == dados[2] && dados[2] == dados[3] && dados[3] == dados[4])
		{
			jugadas[0] = 1;
		}
		//veo si es escalera
		if(dados[0]+1 == dados[1] && dados[1]+1 == dados[2] && dados[2]+1 == dados[3] && dados[3]+1 == dados[4] ){
			jugadas[3] = 1;
		}
		//veo si salio full (3 iguales y 2 iguales)
		if((auxDados[0] == 2 || auxDados[1] == 2 || auxDados[2] == 2  || auxDados[3] == 2 || auxDados[4] == 2) && (auxDados[0] == 3 || auxDados[1] == 3 || auxDados[2] == 3 || auxDados[3] == 3 || auxDados[4] == 3)){
			jugadas[1] = 1;
		}
		//veo si salio poker(4 dados iguales)
		if(auxDados[0] == 4 || auxDados[1] == 4 || auxDados[2] == 4 || auxDados[3] == 4 || auxDados[4] == 4){
			jugadas[2] = 1;
		}
		cout<<"----------------------------------------------------------------------------------------"<<endl;
		//mostramos los dados obtenidos
		cout<<"Dados obtenidos:"<<endl;
		cout<<dados[0]<<" "<<dados[1]<<" "<<dados[2]<<" "<<dados[3]<<" "<<dados[4]<<endl;
		
		cout<<"----------------------------------------------------------------------------------------"<<endl;
		
		//damos el resultado de los todos al....
		
		for (k=1; k<7; k++)
		{
			cout<<"Todos al: "<<k<<" "<<auxDados[k-1]*k<<endl; 
		}
		
		if (jugadas[1] == 1)
		{
			cout<<"Full: 30"<<endl;
		}
		else
		{
			cout<<"Full: 0"<<endl;	
		}
		
		if (jugadas[2] == 1)
		{
			cout<<"Poker: 40"<<endl;
		}
		else
		{
			cout<<"Poker: 0"<<endl;	
		}
		
		if (jugadas[3] == 1)
		{
			cout<<"Escalera: 50"<<endl;
		}
		else
		{
			cout<<"Escalera: 0"<<endl;	
		}
		if (jugadas[0] == 1)
		{
			cout<<"Generala: 60"<<endl;
		}
		else
		{
			cout<<"Generala: 0"<<endl;	
		}
		cout<<"----------------------------------------------------------------------------------------"<<endl;
	}

		
void evaluarResultados(bool jugadas[],bool jugadasPC[],int resultados[])//tomo las jugadas y comuinco quien gano
	{
	if(jugadas[0] == 1)//veo si es generala y lo asigno en el resultado de jugador
		{
		resultados[0] = 60;
		}
	if (jugadas[1] == 1)//veo si es full y lo asigno en el resultado de jugador
		{
		resultados[0] = 30;
		}
	if (jugadas[2] == 1)//veo si es poker y lo asigno en el resultado de jugador
		{
		resultados[0] = 40;
		}
	if (jugadas[3] == 1)//veo si es escalera y lo asigno en el resultado de jugador
		{
		resultados[0] = 50;
		}
	
	if(jugadasPC[0] == 1)//veo si es generala y lo asigno en el resultado de jugador
	{
		resultados[1] = 60;
	}
	if (jugadasPC[1] == 1)//veo si es full y lo asigno en el resultado de jugador
	{
		resultados[1] = 30;
	}
	if (jugadasPC[2] == 1)//veo si es poker y lo asigno en el resultado de jugador
	{
		resultados[1] = 40;
	}
	if (jugadasPC[3] == 1)//veo si es escalera y lo asigno en el resultado de jugador
	{
		resultados[1] = 50;
	}
	if (resultados[0] > resultados[1])
		{
		cout<<"Gana esta mano el jugador"<<endl;
		}
	if (resultados[0] < resultados[1])
		{
		cout<<"Gana esta mano la PC"<<endl;
		}
	if (resultados[0] == resultados[1])
		{
		cout<<"Esta mano es un empate"<<endl;
		}
	cout<<"¿Quieres volver  jugar?"<<endl;
	}
void limpiarVariables(int dado[], int dadoPC[], int auxDados[], int auxDadosPC[], bool jugadas[], bool jugadasPC[], int resultados[])
	{
	int i;
	int j;
	int k;
	//limpio los dados
	for (i = 0; i < 5; i++)
		{
		dado[i]= 0;
		dadoPC[i] = 0;
		}
	//limpio los auxiliares
	for (j = 0; j < 6; j++)
		{
		auxDados[j] = 0;
		auxDadosPC[j] = 0;
		}
	//limpio los resultados
	for (k = 0; k < 4; k++)
		{
		jugadas[k] = 0;
		jugadasPC[k] = 0;
		}
	resultados[0] = 0;
	resultados[1] = 0;
	}
int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int dado[5] {0,0,0,0,0};
	int dadoAuxiliar[6] {0,0,0,0,0,0};
	bool jugadas[4]{0,0,0,0};//jugadas[0]=generala -- jugadas[1]=full -- jugadas [2]=poker -- jugadas[3]=escalera
	
	int dadoPC[5] {0,0,0,0,0};
	int dadoAuxiliarPC[6] {0,0,0,0,0,0};
	bool jugadasPC[4] {0,0,0,0};//jugadas[0]=generala -- jugadas[1]=full -- jugadas [2]=poker -- jugadas[3]=escalera
	
	int resultados[2]{0,0};//posicion1 jugador posicion 2 pc
	
	bool QuieroJugar = 1;//QuieroJugar es una bandera que indica si el juego sigue
	
	cout<<"Bienvenido al juego de la generala!"<<endl;
	cout<<"Presione ENTER para tirar los dados"<<endl;
	cout<<"Presione Z para terminar el juego"<<endl;
	
	while (QuieroJugar)
	{
		if (kbhit)
		{
			int tecla=getch();
			switch(tecla)
			{
				case 13: //enter
				tirarDados(dado);
				tirarDados(dadoPC);
				
				sort(dado,5);
				sort(dadoPC, 5);
				
				cout<<"Jugadas del Jugador:"<<endl;
				evaluarDados(dado,dadoAuxiliar,jugadas);
				cout<<"Jugadas de la computadora:"<<endl;
				evaluarDados(dadoPC,dadoAuxiliarPC,jugadasPC);
				
				evaluarResultados(jugadas,jugadasPC,resultados);
				
				//limpio las variables
				limpiarVariables(dado, dadoPC, dadoAuxiliar, dadoAuxiliarPC, jugadas, jugadasPC, resultados);
				break;
			}
		}
	}
	
	return 0;
}


