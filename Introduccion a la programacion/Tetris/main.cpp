#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
//definicion de ontroles
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
//definicion de colores
void gotoxy(int x, int y)//funcion que emula gotoxy de biblioteca borlandC
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD xyPos;
	xyPos.X = x;
	xyPos.Y = y;
	SetConsoleCursorPosition(hCon, xyPos);
}

void OcultarCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon, &cci);
}

void PintarLimites() {
	
	for(int i = 2; i < 78; i++)
	{
		//limite superior
		gotoxy(i,3); 
		printf("%c",205);
		
		//limite inferior
		gotoxy(i,33);
		printf("%c",205);
	}
	for(int i = 4; i < 33; i++)
	{
		//limite izquierda
		gotoxy(2,i); 
		printf("%c",186);
		
		//limite derecha
		gotoxy(77,i); 
		printf("%c",186);
		
	}
	//pintar las esquinas
	gotoxy(2,3);
	printf("%c",201);
	
	gotoxy(2,33);
	printf("%c",200);
	
	gotoxy(77,3);
	printf("%c",187);
	
	gotoxy(77,33);
	printf("%c",188);
	
}

using namespace std;

int main (int argc, char *argv[]) {
	
	OcultarCursor();
	PintarLimites();
	gotoxy(15,10);printf("*");
	int x = 10;
	int y = 10;
	bool game_over = false;
	while(!game_over)
	{
		
		
		if(kbhit())
		{
			char tecla = getch();
			gotoxy(x,y);
			printf(" ");
			if(tecla == IZQUIERDA && x > 3)
			{
				x--;
			}
			if(tecla == DERECHA && x < 76)
			{
				x++;
			}
			if(tecla == ABAJO && y < 32)
			{
				y++;
			}
			gotoxy(x,y);
			printf("*");
		}
		Sleep(30);
	}
	
	
	return 0;
}
