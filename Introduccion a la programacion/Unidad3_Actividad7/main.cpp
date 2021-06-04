#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
	//pedir año mes dia indicar cuando naciste y los años que tenes
	//defino un array con los nombres de los meses
	string meses [12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
	//defio un array con los dias maximos por cada mes
	int dias [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	string borde = "==============================";
	int anio = 0;
	int dia = 0;
	int mes = 0;
	//bandera que sirve para saber si ya cumpli años este año
	bool bandera_De_Anio = 0;
	//fecha contra la que comparo (la comparacion es anio-(anio_A_Comparar-1), si bandera es verdadero sumo 1
	int anio_A_Comparar = 2021;
	int mes_A_Comparar = 6;
	int dia_A_Comparar = 9;
	int anios_Que_Tiene = 0;
	cout << borde << endl;
	cout << "Ingresa tu año de nacimiento:" << endl;
	cin >> anio;
	if (anio > anio_A_Comparar)
		{
		cout << "ERROR!! Su anio de nacimento no puede ser mayor que el anio actual, reintente por favor" << endl;
		cin >> anio;
		}
	cout << "Ingresa tu mes de nacimiento:" << endl;
	cin >> mes;
	if (mes > 12 || mes < 1)
		{
			cout << "ERROR!! Mes no puede sem mayor que 12 ni menor que 1, reintente por favor" << endl;
			cin >> mes;
		}
	cout << "Ingresa tu dia de nacimiento:" << endl;
	cin >> dia;
	if (dia > dias[mes-1]|| dia < 1)
		{
			cout << "ERROR!! Dia para el mes " << meses [mes-1] << " no puede ser mayor a " << dias[mes-1] << " ni ser menor que uno, reintente por favor" << endl;
			cin >> dia;
		}
	cout << "Usted nacio el " << dia << " de " << meses[mes-1] << " de " << anio << endl;
	//seteo la bandera verdadera solo si el mes y dia de nacimiento es menor o igual que la fecha de comparacion (la  fecha de entrega de la tarea)
	if (mes <= mes_A_Comparar && dia <= dia_A_Comparar)
		{
		bandera_De_Anio = 1;
		}
	anios_Que_Tiene = (anio_A_Comparar - 1) - anio;
	if (bandera_De_Anio)
		{
		anios_Que_Tiene = anios_Que_Tiene + 1;
		}
	cout << "Usted tiene " << anios_Que_Tiene << " anios.";
	return 0;
}

