#include <Windows.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
bool Noatravesar, repetirseleccion = 0, errorcolor = false, movimientoinvalido = false;
string blanco = "  ";
string negro = "██";
string ocupado = "██";
string reina = "▒▒";
string bordecuadrado = "════════";
int a = 0, cuadrado = 10, i, j, k, p, longituddenombresunidos, ftemp, ctemp, b, Jugador, turno;
char columna, columna2;
int fila, fila2;
int matriz8original[8][8] = {
	{-1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 1, -1, 1, -1, 1, -1, 1},
	{0, -1, 0, -1, 0, -1, 0, -1},
	{-1, 0, -1, 0, -1, 0, -1, 0},
	{2, -1, 2, -1, 2, -1, 2, -1},
	{-1, 2, -1, 2, -1, 2, -1, 2},
	{2, -1, 2, -1, 2, -1, 2, -1} };
int matriz10original[10][10] = {
	{-1, 1, -1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 1, -1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 0, -1, 0, -1, 0, -1, 0, -1, 0},
	{0, -1, 0, -1, 0, -1, 0, -1, 0, -1},
	{-1, 2, -1, 2, -1, 2, -1, 2, -1, 2},
	{2, -1, 2, -1, 2, -1, 2, -1, 2, -1},
	{-1, 2, -1, 2, -1, 2, -1, 2, -1, 2},
	{2, -1, 2, -1, 2, -1, 2, -1, 2, -1} };
int matriz8[8][8];
int matriz10[10][10];
/*
* int matriz8original[8][8] = {
	{-1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 1, -1, 1, -1, 1, -1, 1},
	{0, -1, 0, -1, 0, -1, 0, -1},
	{-1, 0, -1, 0, -1, 0, -1, 0},
	{2, -1, 2, -1, 2, -1, 2, -1},
	{-1, 2, -1, 2, -1, 2, -1, 2},
	{2, -1, 2, -1, 2, -1, 2, -1} };
int matriz10original[10][10] = {
	{-1, 1, -1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 1, -1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 0, -1, 0, -1, 0, -1, 0, -1, 0},
	{0, -1, 0, -1, 0, -1, 0, -1, 0, -1},
	{-1, 2, -1, 2, -1, 2, -1, 2, -1, 2},
	{2, -1, 2, -1, 2, -1, 2, -1, 2, -1},
	{-1, 2, -1, 2, -1, 2, -1, 2, -1, 2},
	{2, -1, 2, -1, 2, -1, 2, -1, 2, -1} };
-1: Espacios color blanco
0: Espacio Negro
1: Normal Jugador 1
2: Normal Jugador 2
3: Resaltado Jugador 1
4: Resaltado Jugador 2
5: Reina Jugador 1
6: Reina Jugador 2
7: Reina Resaltada Jugador 1
8: Reina Resaltada Jugador 2
*/
short int colordefondo = 14, colordetexto = 0, colorjugador1 = 15, colorjugador2 = 4l;
void color(int x, int y) {
	p = (16 * x) + y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void cronometro() {
	int hora = 0, minuto = 0, segundo = 0;
	while (1) {
		if (segundo == 60) {
			segundo = 0;
			minuto++;
			if (minuto == 60)
			{
				minuto = 0;
				hora++;
			}
		}
		system("cls"); //esto tarda 100 ms en ejecutarse
		cout << "\n\n\n\t╔════════════════════════════════════╗";
		cout << "\n\t║   Tiempo Transcurrido:  ";
		if (hora < 10) cout << "0" << hora;
		else cout << hora;
		cout << ":";
		if (minuto < 10) cout << "0" << minuto;
		else cout << minuto;
		cout << ":";
		if (segundo < 10) cout << "0" << segundo;
		else cout << segundo;
		cout << "   ║";
		cout << "\n\t╚════════════════════════════════════╝";
		Beep(850 + segundo * 10, 300 - segundo * 200 / 60);
		Sleep(600 + segundo * 200 / 60);
		segundo++;
	}
}
void reloj() {
	while (true) {
		cout << "\n\n\n\t";
		system("time /t");
		Sleep(10000);
		system("cls");
	}
}
void transicion(string textodeinicio) {
	int fps = 200;
	for (int pp = 0; pp < (textodeinicio).length(); pp++) {
		cout << textodeinicio[pp];
		if (textodeinicio[pp] == ':' || textodeinicio[pp] == '.') Sleep(1000 / (fps / 6));
		else if (textodeinicio[pp] == ',') Sleep(1000 / (fps / 3));
		else Sleep(1000 / fps);
	}
}
void salir() {
	system("color 0f");
	exit(0);
}
void dibujar(string* jugador1, string* jugador2) {
	longituddenombresunidos = (*jugador1).length() + (*jugador2).length();
	system("cls");
	cout << "\n\n\t   Jugador 1: " << *jugador1;
	for (i = 36 - longituddenombresunidos; i > 0; i--) cout << " ";
	cout << "\t\t\t\tJugador 2: " << *jugador2;
	cout << "\n\n\t     ";
	for (i = cuadrado; i != 0; i--) cout << "    " << char(65 + (cuadrado - i)) << "   ";
	cout << "\n\n\t     ╔";
	for (i = cuadrado; i != 0; i--) cout << bordecuadrado;
	cout << "╗";
	for (i = cuadrado; i != 0; i--) {
		for (k = 4; k != 0; k--) {
			if (k == 2) {
				if (cuadrado - i + 1 >= 10) cout << "\n\t" << cuadrado - i + 1 << "   ║";
				else cout << "\n\t" << cuadrado - i + 1 << "    ║";
			}
			else cout << "\n\t     ║";
			for (j = cuadrado; j != 0; j--) {
				if (cuadrado == 8) 	a = matriz8[(cuadrado - i)][(cuadrado - j)];
				else a = matriz10[(cuadrado - i)][(cuadrado - j)];
				color(colordefondo, colordetexto);
				if (a == -1) cout << blanco << blanco << blanco << blanco;
				else if (a == 0) cout << negro << negro << negro << negro;
				else {
					if (k == 1 || k == 4) {
						cout << negro << negro << negro << negro;
					}
					else {
						cout << negro;
						if (a == 1) color(colordetexto, colorjugador1);
						else if (a == 2) color(colordetexto, colorjugador2);
						else if (a == 3) {
							if (colordefondo != colorjugador1) color(colordetexto, colordefondo);
							else if (colorjugador2 == 4) color(colordetexto, 12);
							else color(colordetexto, 4);
						}
						else if (a == 4) {
							if (colordefondo != colorjugador2) color(colordetexto, colordefondo);
							else if (colorjugador1 == 4) color(colordetexto, 12);
							else color(colordetexto, 4);
						}
						if (a == 5) color(colordetexto, colorjugador1);
						else if (a == 6) color(colordetexto, colorjugador2);
						else if (a == 7) {
							if (colordefondo != colorjugador1) color(colordetexto, colordefondo);
							else if (colorjugador2 == 4) color(colordetexto, 12);
							else color(colordetexto, 4);
						}
						else if (a == 8) {
							if (colordefondo != colorjugador2) color(colordetexto, colordefondo);
							else if (colorjugador1 == 4) color(colordetexto, 12);
							else color(colordetexto, 4);
						}
						if (0 <= a && a <= 4) {
							cout << ocupado;
							cout << ocupado;
						}
						else {
							cout << reina;
							cout << reina;
						}
						color(colordefondo, colordetexto);
						cout << negro;
					}
				}
			}
			cout << "║";
		}
	}
	cout << "\n\t     ╚";
	for (i = cuadrado; i != 0; i--) cout << bordecuadrado;
	cout << "╝";
	color(14, 0);
	return;
}
void comermatriz8(int* f1, char* c1, int* f2, char* c2, int jugador) {
	Noatravesar = false;
	if (matriz8[*f2][*c2] == 0) {
		if (repetirseleccion == false) {
			if (matriz8[*f1][*c1] == 3) {
				if (abs(*f1 - *f2) == 2 && (matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 2 || matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 6) && *f1 < *f2) {
					matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] = 0;
					Noatravesar = true;
					repetirseleccion = true;
				}
				else if (abs(*f1 - *f2) == 1) Noatravesar = true;
				else {
					Noatravesar = false;
					movimientoinvalido = true;
				}
			}
			else if (matriz8[*f1][*c1] == 4) {
				if (abs(*f1 - *f2) == 2 && (matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 1 || matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 5) && *f2 < *f1) {
					matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] = 0;
					Noatravesar = true;
					repetirseleccion = true;
				}
				else if (abs(*f1 - *f2) == 1) Noatravesar = true;
				else {
					Noatravesar = false;
					movimientoinvalido = true;
				}
			}
			else if (matriz8[*f1][*c1] == 7 || matriz8[*f1][*c1] == 8) {
				int cuadrante[2];
				if (*f1 < *f2 && *c1 < *c2) {
					cuadrante[0] = 1;
					cuadrante[1] = 1;
				}
				else if (*f1 < *f2 && *c1 > *c2) {
					cuadrante[0] = 1;
					cuadrante[1] = -1;
				}
				else if (*f1 > *f2 && *c1 > *c2) {
					cuadrante[0] = -1;
					cuadrante[1] = -1;
				}
				else if (*f1 > *f2 && *c1 < *c2) {
					cuadrante[0] = -1;
					cuadrante[1] = 1;
				}
				ftemp = *f1;
				ctemp = *c1;
				for (b = abs(*c1 - *c2); b != 0; b--) {
					ftemp += cuadrante[0];
					ctemp += cuadrante[1];
					if (jugador == 1) {
						if (matriz8[ftemp][ctemp] == 1 || matriz8[ftemp][ctemp] == 5) {
							if (matriz8[ftemp - cuadrante[0]][ctemp - cuadrante[1]] == 0) {
								*f2 = ftemp - cuadrante[0];
								*c2 = ctemp - cuadrante[1];
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								movimientoinvalido = true;
								return;
							}
						}
						else if (matriz8[ftemp][ctemp] == 2 || matriz8[ftemp][ctemp] == 6) {
							if (matriz8[ftemp + cuadrante[0]][ctemp + cuadrante[1]] == 0) {
								matriz8[ftemp][ctemp] = 0;
								*f2 = ftemp + cuadrante[0];
								*c2 = ctemp + cuadrante[1];
								repetirseleccion = true;
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								movimientoinvalido = true;
								return;
							}
						}
						else if (matriz8[ftemp][ctemp] == 0) Noatravesar = true;
					}
					else if (jugador == 2) {
						if (matriz8[ftemp][ctemp] == 2 || matriz8[ftemp][ctemp] == 6) {
							if (matriz8[ftemp - cuadrante[0]][ctemp - cuadrante[1]] == 0) {
								*f2 = ftemp - cuadrante[0];
								*c2 = ctemp - cuadrante[1];
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								movimientoinvalido = true;
								return;
							}
						}
						else if (matriz8[ftemp][ctemp] == 1 || matriz8[ftemp][ctemp] == 5) {
							if (matriz8[ftemp + cuadrante[0]][ctemp + cuadrante[1]] == 0) {
								matriz8[ftemp][ctemp] = 0;
								*f2 = ftemp + cuadrante[0];
								*c2 = ctemp + cuadrante[1];
								repetirseleccion = true;
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								movimientoinvalido = true;
								return;
							}
						}
						else if (matriz8[ftemp][ctemp] == 0) Noatravesar = true;
					}
				}
			}
		}
		else {
			if (matriz8[*f1][*c1] == 3) {
				if (abs(*f1 - *f2) == 2 && (matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 2 || matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 6)) {
					matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] = 0;
					Noatravesar = true;
					repetirseleccion = true;
				}
				else if (abs(*f1 - *f2) != 2) {
					Noatravesar = false;
					repetirseleccion = false;
					turno++;
				}
				else {
					Noatravesar = false;
					repetirseleccion = true;
				}
			}
			else if (matriz8[*f1][*c1] == 4) {
				if (abs(*f1 - *f2) == 2 && (matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 1 || matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 5)) {
					matriz8[(*f1 + *f2) / 2][(*c1 + *c2) / 2] = 0;
					Noatravesar = true;
					repetirseleccion = true;
				}
				else if (abs(*f1 - *f2) != 2) {
					Noatravesar = false;
					repetirseleccion = false;
					turno++;
				}
				else {
					Noatravesar = false;
					repetirseleccion = true;
				}
			}
			else if (matriz8[*f1][*c1] == 7 || matriz8[*f1][*c1] == 8) {
				int cuadrante[2];
				if (*f1 < *f2 && *c1 < *c2) {
					cuadrante[0] = 1;
					cuadrante[1] = 1;
				}
				else if (*f1 < *f2 && *c1 > *c2) {
					cuadrante[0] = 1;
					cuadrante[1] = -1;
				}
				else if (*f1 > *f2 && *c1 > *c2) {
					cuadrante[0] = -1;
					cuadrante[1] = -1;
				}
				else if (*f1 > *f2 && *c1 < *c2) {
					cuadrante[0] = -1;
					cuadrante[1] = 1;
				}
				ftemp = *f1;
				ctemp = *c1;
				for (b = abs(*c1 - *c2); b != 0; b--) {
					ftemp += cuadrante[0];
					ctemp += cuadrante[1];
					if (jugador == 1) {
						if (matriz8[ftemp][ctemp] == 2 || matriz8[ftemp][ctemp] == 6) {
							if (matriz8[ftemp + cuadrante[0]][ctemp + cuadrante[1]] == 0) {
								matriz8[ftemp][ctemp] = 0;
								*f2 = ftemp + cuadrante[0];
								*c2 = ctemp + cuadrante[1];
								repetirseleccion = true;
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								repetirseleccion = false;
								return;
							}
						}
						else if (matriz8[ftemp][ctemp] == 0) {
							Noatravesar = false;
							repetirseleccion = false;
							turno++;
						}
					}
					else if (jugador == 2) {
						if (matriz8[ftemp][ctemp] == 1 || matriz8[ftemp][ctemp] == 5) {
							if (matriz8[ftemp + cuadrante[0]][ctemp + cuadrante[1]] == 0) {
								matriz8[ftemp][ctemp] = 0;
								*f2 = ftemp + cuadrante[0];
								*c2 = ctemp + cuadrante[1];
								repetirseleccion = true;
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								repetirseleccion = false;
								return;
							}
						}
						else if (matriz8[ftemp][ctemp] == 0) {
							Noatravesar = false;
							repetirseleccion = false;
							turno++;
						}
					}
				}
			}
		}
	}
}
void comprobarmatriz8(int* f1, char* c1, int* f2, char* c2, int jugador) {
	comermatriz8(f1, c1, f2, c2, jugador);
	if (Noatravesar) {
		if (!repetirseleccion) {
			if (jugador == 1) {
				if (cuadrado - *f2 < cuadrado - *f1 || matriz8[*f1][*c1] == 7) {
					if (matriz8[*f1][*c1] == 7) {
						matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz8[*f2][*c2] = jugador + 4;
					}
					else if (matriz8[*f1][*c1] == 3) {
						if ((*f2 == cuadrado - 1)) {
							matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
							matriz8[*f2][*c2] = jugador + 4;
						}
						else {
							matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
							matriz8[*f2][*c2] = jugador;
						}
					}
				}
				else {
					if (matriz8[*f1][*c1] == 7) {
						matriz8[*f1][*c1] = jugador + 4;
						turno++;
					}
					else if (matriz8[*f1][*c1] == 3) {
						matriz8[*f1][*c1] = jugador;
						turno++;
					}
				}
			}
			else if (jugador == 2) {
				if (cuadrado - *f2 > cuadrado - *f1 || matriz8[*f1][*c1] == 8) {
					if (matriz8[*f1][*c1] == 8) {
						matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz8[*f2][*c2] = jugador + 4;
					}
					else if (matriz8[*f1][*c1] == 4) {
						if ((*f2 == 0)) {
							matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
							matriz8[*f2][*c2] = jugador + 4;
						}
						else {
							matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
							matriz8[*f2][*c2] = jugador;
						}
					}
				}
				else {
					if (matriz8[*f1][*c1] == 8) {
						matriz8[*f1][*c1] = jugador + 4;
						turno++;
					}
					else if (matriz8[*f1][*c1] == 4) {
						matriz8[*f1][*c1] = jugador;
						turno++;
					}
				}
			}
		}
		else {
			if (jugador == 1) {
				if (matriz8[*f1][*c1] == 7) {
					matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
					matriz8[*f2][*c2] = jugador + 4;
				}
				else if (matriz8[*f1][*c1] == 3) {
					if ((*f2 == cuadrado - 1)) {
						matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz8[*f2][*c2] = jugador + 4;
					}
					else {
						matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz8[*f2][*c2] = jugador;
					}
				}
			}
			else if (jugador == 2) {
				if (matriz8[*f1][*c1] == 8) {
					matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
					matriz8[*f2][*c2] = jugador + 4;
				}
				else if (matriz8[*f1][*c1] == 4) {
					if ((*f2 == 0)) {
						matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz8[*f2][*c2] = jugador + 4;
					}
					else {
						matriz8[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz8[*f2][*c2] = jugador;
					}
				}
			}
		}
	}
	else {
		if (matriz8[*f1][*c1] == 8 || matriz8[*f1][*c1] == 7) {
			matriz8[*f1][*c1] = jugador + 4;
		}
		else if (matriz8[*f1][*c1] == 4 || matriz8[*f1][*c1] == 3) {
			matriz8[*f1][*c1] = jugador;
		}
		turno++;
	}
}
void turnos8(string* j1, string* j2) {
	if (repetirseleccion) {
		turno++;
		fila = fila2;
		columna = columna2;
	}
	if (movimientoinvalido) {
		cout << "\n\n\tEl movimiento insertado anteriormente es inválido\n\n\t\t";
		movimientoinvalido = false;
	}
	if (turno % 2 == 1) { //
		Jugador = 1;
		if (!repetirseleccion) {
			columna = 20;
			columna2 = 20;
			fila = 20;
			fila2 = 20;
			do {
				do {
					cout << "\n\n\tJugador 1, " << *j1 << " , ingrese la columna (Letra) y fila (Número) de la ficha a desplazar:\n\n\t\t";
					cin >> columna;
					columna = toupper(columna);
					if (65 <= columna && columna <= 72) columna = columna - 65;
					else cout << "\n\n\tLa columna " << columna << " está fuera del tablero\n\n\t\t";
					cin >> fila;
					fila = fila - 1;
					if (!(0 <= fila && fila <= cuadrado - 1)) cout << "\n\n\tLa fila " << fila << " está fuera del tablero\n\n\t\t";
				} while (fila > cuadrado || 0 > fila || columna > cuadrado || 0 > columna);
				if (columna % 2 == fila % 2) cout << "\n\n\tNo existen piezas en las casillas blancas";
				else if (!(matriz8[fila][columna] == 1 || matriz8[fila][columna] == 5)) cout << "\n\n\tLa casilla seleccionada no posee una ficha que puedas mover";
			} while (!(matriz8[fila][columna] == 1 || matriz8[fila][columna] == 5));
		}
		if (matriz8[fila][columna] == 1) {
			matriz8[fila][columna] = 3;
		}
		else if (matriz8[fila][columna] == 5) {
			matriz8[fila][columna] = 7;
		}
		system("cls");
		dibujar(j1, j2);
		do {
			do {
				if (!repetirseleccion) cout << "\n\n\tJugador 1, " << *j1 << " , ingrese la columna (Letra) y fila (Número) a la que desea desplazar la ficha seleccionada:\n\n\t\t";
				else cout << "\n\n\tJugador 2, " << *j2 << " , Puede comer otra pieza en este turno. \n\tInserte la columna (Letra) y fila (Número) de la pieza seleccionada para dejar de seguir comiendo\n\n\t\t";
				cin >> columna2;
				columna2 = toupper(columna2);
				if (65 <= columna2 && columna2 <= 72) columna2 = columna2 - 65;
				else cout << "\n\n\tLa columna " << columna2 << " está fuera del tablero\n\n\t\t";
				cin >> fila2;
				fila2 = fila2 - 1;
				if (fila2 == fila && columna2 == columna) {
					if (matriz8[fila][columna] == 8 || matriz8[fila][columna] == 7) {
						matriz8[fila][columna] = Jugador + 4;
					}
					else if (matriz8[fila][columna] == 4 || matriz8[fila][columna] == 3) {
						matriz8[fila][columna] = Jugador;
					}
					if (repetirseleccion != false) repetirseleccion = false;
					return;
				}
				if (!(0 <= fila2 && fila2 <= cuadrado - 1)) cout << "\n\n\tLa fila " << fila2 << " está fuera del tablero\n\n\t\t";
			} while (columna2 > cuadrado || 0 > columna2);
			if (columna2 % 2 == fila2 % 2) cout << "\n\n\tNo se pueden mover las piezas a las casillas blancas";
			else if (matriz8[fila2][columna2] != 0) cout << "\n\n\tNo se pueden mover las piezas a una casilla que esté ocupada";
			else if (!(abs(columna - columna2) == abs(fila - fila2))) cout << "\n\n\tLas fichas solo pueden moverse en diagonal";
		} while (!(matriz8[fila2][columna2] == 0 && abs(columna - columna2) == abs(fila - fila2)));
		Noatravesar = false;
		comprobarmatriz8(&fila, &columna, &fila2, &columna2, 1);
	}
	else if (turno % 2 == 0) { //jugador 2
		Jugador = 2;
		if (!repetirseleccion) {
			columna = 20;
			columna2 = 20;
			fila = 20;
			fila2 = 20;
			do {
				do {
					cout << "\n\n\tJugador 2, " << *j2 << " , ingrese la columna (Letra) y fila (Número) de la ficha a desplazar:\n\n\t\t";
					cin >> columna;
					columna = toupper(columna);
					if (65 <= columna && columna <= 72) columna = columna - 65;
					else cout << "\n\n\tLa columna " << columna << " está fuera del tablero\n\n\t\t";
					cin >> fila;
					fila = fila - 1;
					if (!(0 <= fila && fila <= cuadrado - 1)) cout << "\n\n\tLa fila " << fila << " está fuera del tablero\n\n\t\t";
				} while (fila > cuadrado || 0 > fila || columna > cuadrado || 0 > columna);
				if (columna % 2 == fila % 2) cout << "\n\n\tNo existen piezas en las casillas blancas";
				else if (!(matriz8[fila][columna] == 2 || matriz8[fila][columna] == 6)) cout << "\n\n\tLa casilla seleccionada no posee una ficha que puedas mover";
			} while (!(matriz8[fila][columna] == 2 || matriz8[fila][columna] == 6));
		}
		if (matriz8[fila][columna] == 2) {
			matriz8[fila][columna] = 4;
		}
		else if (matriz8[fila][columna] == 6) {
			matriz8[fila][columna] = 8;
		}
		system("cls");
		dibujar(j1, j2);
		do {
			do {
				if (!repetirseleccion) cout << "\n\n\tJugador 2, " << *j2 << " , ingrese la columna (Letra) y fila (Número) a la que desea desplazar la ficha seleccionada:\n\n\t\t";
				else cout << "\n\n\tJugador 2, " << *j2 << " , Puede comer otra pieza en este turno. \n\tInserte la columna (Letra) y fila (Número) de la pieza seleccionada para dejar de seguir comiendo\n\n\t\t";
				cin >> columna2;
				columna2 = toupper(columna2);
				if (65 <= columna2 && columna2 <= 72) columna2 = columna2 - 65;
				else cout << "\n\n\tLa columna " << columna2 << " está fuera del tablero\n\n\t\t";
				cin >> fila2;
				fila2 = fila2 - 1;
				if (fila2 == fila && columna2 == columna) {
					if (matriz8[fila][columna] == 8 || matriz8[fila][columna] == 7) {
						matriz8[fila][columna] = Jugador + 4;
					}
					else if (matriz8[fila][columna] == 4 || matriz8[fila][columna] == 3) {
						matriz8[fila][columna] = Jugador;
					}
					if (repetirseleccion != false) repetirseleccion = false;
					return;
				}
				if (!(0 <= fila2 && fila2 <= cuadrado - 1)) cout << "\n\n\tLa fila " << fila2 << " está fuera del tablero\n\n\t\t";
			} while (columna2 > cuadrado || columna2 < 0);
			if (columna2 % 2 == fila2 % 2) cout << "\n\n\tNo se pueden mover las piezas a las casillas blancas";
			else if (matriz8[fila2][columna2] != 0) cout << "\n\n\tNo se pueden mover las piezas a una casilla que esté ocupada";
			else if (!(abs(columna - columna2) == abs(fila - fila2))) cout << "\n\n\tLas fichas solo pueden moverse en diagonal";
		} while (!(matriz8[fila2][columna2] == 0 && abs(columna - columna2) == abs(fila - fila2)));
		Noatravesar = false;
		comprobarmatriz8(&fila, &columna, &fila2, &columna2, 2);
	}
	return;
}
void comermatriz10(int* f1, char* c1, int* f2, char* c2, int jugador) {
	Noatravesar = false;
	if (matriz10[*f2][*c2] == 0) {
		if (repetirseleccion == false) {
			if (matriz10[*f1][*c1] == 3) {
				if (abs(*f1 - *f2) == 2 && (matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 2 || matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 6) && *f1 < *f2) {
					matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] = 0;
					Noatravesar = true;
					repetirseleccion = true;
				}
				else if (abs(*f1 - *f2) == 1) Noatravesar = true;
				else {
					Noatravesar = false;
					movimientoinvalido = true;
				}
			}
			else if (matriz10[*f1][*c1] == 4) {
				if (abs(*f1 - *f2) == 2 && (matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 1 || matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 5) && *f2 < *f1) {
					matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] = 0;
					Noatravesar = true;
					repetirseleccion = true;
				}
				else if (abs(*f1 - *f2) == 1) Noatravesar = true;
				else {
					Noatravesar = false;
					movimientoinvalido = true;
				}
			}
			else if (matriz10[*f1][*c1] == 7 || matriz10[*f1][*c1] == 8) {
				int cuadrante[2];
				if (*f1 < *f2 && *c1 < *c2) {
					cuadrante[0] = 1;
					cuadrante[1] = 1;
				}
				else if (*f1 < *f2 && *c1 > *c2) {
					cuadrante[0] = 1;
					cuadrante[1] = -1;
				}
				else if (*f1 > *f2 && *c1 > *c2) {
					cuadrante[0] = -1;
					cuadrante[1] = -1;
				}
				else if (*f1 > *f2 && *c1 < *c2) {
					cuadrante[0] = -1;
					cuadrante[1] = 1;
				}
				ftemp = *f1;
				ctemp = *c1;
				for (b = abs(*c1 - *c2); b != 0; b--) {
					ftemp += cuadrante[0];
					ctemp += cuadrante[1];
					if (jugador == 1) {
						if (matriz10[ftemp][ctemp] == 1 || matriz10[ftemp][ctemp] == 5) {
							if (matriz10[ftemp - cuadrante[0]][ctemp - cuadrante[1]] == 0) {
								*f2 = ftemp - cuadrante[0];
								*c2 = ctemp - cuadrante[1];
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								movimientoinvalido = true;
								return;
							}
						}
						else if (matriz10[ftemp][ctemp] == 2 || matriz10[ftemp][ctemp] == 6) {
							if (matriz10[ftemp + cuadrante[0]][ctemp + cuadrante[1]] == 0) {
								matriz10[ftemp][ctemp] = 0;
								*f2 = ftemp + cuadrante[0];
								*c2 = ctemp + cuadrante[1];
								repetirseleccion = true;
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								movimientoinvalido = true;
								return;
							}
						}
						else if (matriz10[ftemp][ctemp] == 0) Noatravesar = true;
					}
					else if (jugador == 2) {
						if (matriz10[ftemp][ctemp] == 2 || matriz10[ftemp][ctemp] == 6) {
							if (matriz10[ftemp - cuadrante[0]][ctemp - cuadrante[1]] == 0) {
								*f2 = ftemp - cuadrante[0];
								*c2 = ctemp - cuadrante[1];
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								movimientoinvalido = true;
								return;
							}
						}
						else if (matriz10[ftemp][ctemp] == 1 || matriz10[ftemp][ctemp] == 5) {
							if (matriz10[ftemp + cuadrante[0]][ctemp + cuadrante[1]] == 0) {
								matriz10[ftemp][ctemp] = 0;
								*f2 = ftemp + cuadrante[0];
								*c2 = ctemp + cuadrante[1];
								repetirseleccion = true;
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								movimientoinvalido = true;
								return;
							}
						}
						else if (matriz10[ftemp][ctemp] == 0) Noatravesar = true;
					}
				}
			}
		}
		else {
			if (matriz10[*f1][*c1] == 3) {
				if (abs(*f1 - *f2) == 2 && (matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 2 || matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 6)) {
					matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] = 0;
					Noatravesar = true;
					repetirseleccion = true;
				}
				else if (abs(*f1 - *f2) != 2) {
					Noatravesar = false;
					repetirseleccion = false;
					turno++;
				}
				else {
					Noatravesar = false;
					repetirseleccion = true;
				}
			}
			else if (matriz10[*f1][*c1] == 4) {
				if (abs(*f1 - *f2) == 2 && (matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 1 || matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] == 5)) {
					matriz10[(*f1 + *f2) / 2][(*c1 + *c2) / 2] = 0;
					Noatravesar = true;
					repetirseleccion = true;
				}
				else if (abs(*f1 - *f2) != 2) {
					Noatravesar = false;
					repetirseleccion = false;
					turno++;
				}
				else {
					Noatravesar = false;
					repetirseleccion = true;
				}
			}
			else if (matriz10[*f1][*c1] == 7 || matriz10[*f1][*c1] == 8) {
				int cuadrante[2];
				if (*f1 < *f2 && *c1 < *c2) {
					cuadrante[0] = 1;
					cuadrante[1] = 1;
				}
				else if (*f1 < *f2 && *c1 > *c2) {
					cuadrante[0] = 1;
					cuadrante[1] = -1;
				}
				else if (*f1 > *f2 && *c1 > *c2) {
					cuadrante[0] = -1;
					cuadrante[1] = -1;
				}
				else if (*f1 > *f2 && *c1 < *c2) {
					cuadrante[0] = -1;
					cuadrante[1] = 1;
				}
				ftemp = *f1;
				ctemp = *c1;
				for (b = abs(*c1 - *c2); b != 0; b--) {
					ftemp += cuadrante[0];
					ctemp += cuadrante[1];
					if (jugador == 1) {
						if (matriz10[ftemp][ctemp] == 2 || matriz10[ftemp][ctemp] == 6) {
							if (matriz10[ftemp + cuadrante[0]][ctemp + cuadrante[1]] == 0) {
								matriz10[ftemp][ctemp] = 0;
								*f2 = ftemp + cuadrante[0];
								*c2 = ctemp + cuadrante[1];
								repetirseleccion = true;
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								repetirseleccion = false;
								return;
							}
						}
						else if (matriz10[ftemp][ctemp] == 0) {
							Noatravesar = false;
							repetirseleccion = false;
							turno++;
						}
					}
					else if (jugador == 2) {
						if (matriz10[ftemp][ctemp] == 1 || matriz10[ftemp][ctemp] == 5) {
							if (matriz10[ftemp + cuadrante[0]][ctemp + cuadrante[1]] == 0) {
								matriz10[ftemp][ctemp] = 0;
								*f2 = ftemp + cuadrante[0];
								*c2 = ctemp + cuadrante[1];
								repetirseleccion = true;
								Noatravesar = true;
								return;
							}
							else {
								Noatravesar = false;
								repetirseleccion = false;
								return;
							}
						}
						else if (matriz10[ftemp][ctemp] == 0) {
							Noatravesar = false;
							repetirseleccion = false;
							turno++;
						}
					}
				}
			}
		}
	}
}
void comprobarmatriz10(int* f1, char* c1, int* f2, char* c2, int jugador) {
	comermatriz10(f1, c1, f2, c2, jugador);
	if (Noatravesar) {
		if (!repetirseleccion) {
			if (jugador == 1) {
				if (cuadrado - *f2 < cuadrado - *f1 || matriz10[*f1][*c1] == 7) {
					if (matriz10[*f1][*c1] == 7) {
						matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz10[*f2][*c2] = jugador + 4;
					}
					else if (matriz10[*f1][*c1] == 3) {
						if ((*f2 == cuadrado - 1)) {
							matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
							matriz10[*f2][*c2] = jugador + 4;
						}
						else {
							matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
							matriz10[*f2][*c2] = jugador;
						}
					}
				}
				else {
					if (matriz10[*f1][*c1] == 7) {
						matriz10[*f1][*c1] = jugador + 4;
						turno++;
					}
					else if (matriz10[*f1][*c1] == 3) {
						matriz10[*f1][*c1] = jugador;
						turno++;
					}
				}
			}
			else if (jugador == 2) {
				if (cuadrado - *f2 > cuadrado - *f1 || matriz10[*f1][*c1] == 8) {
					if (matriz10[*f1][*c1] == 8) {
						matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz10[*f2][*c2] = jugador + 4;
					}
					else if (matriz10[*f1][*c1] == 4) {
						if ((*f2 == 0)) {
							matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
							matriz10[*f2][*c2] = jugador + 4;
						}
						else {
							matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
							matriz10[*f2][*c2] = jugador;
						}
					}
				}
				else {
					if (matriz10[*f1][*c1] == 8) {
						matriz10[*f1][*c1] = jugador + 4;
						turno++;
					}
					else if (matriz10[*f1][*c1] == 4) {
						matriz10[*f1][*c1] = jugador;
						turno++;
					}
				}
			}
		}
		else {
			if (jugador == 1) {
				if (matriz10[*f1][*c1] == 7) {
					matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
					matriz10[*f2][*c2] = jugador + 4;
				}
				else if (matriz10[*f1][*c1] == 3) {
					if ((*f2 == cuadrado - 1)) {
						matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz10[*f2][*c2] = jugador + 4;
					}
					else {
						matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz10[*f2][*c2] = jugador;
					}
				}
			}
			else if (jugador == 2) {
				if (matriz10[*f1][*c1] == 8) {
					matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
					matriz10[*f2][*c2] = jugador + 4;
				}
				else if (matriz10[*f1][*c1] == 4) {
					if ((*f2 == 0)) {
						matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz10[*f2][*c2] = jugador + 4;
					}
					else {
						matriz10[*f1][*c1] = 0; //3 para el jugador 1, 4 para el jugador 2
						matriz10[*f2][*c2] = jugador;
					}
				}
			}
		}
	}
	else {
		if (matriz10[*f1][*c1] == 8 || matriz10[*f1][*c1] == 7) {
			matriz10[*f1][*c1] = jugador + 4;
		}
		else if (matriz10[*f1][*c1] == 4 || matriz10[*f1][*c1] == 3) {
			matriz10[*f1][*c1] = jugador;
		}
		turno++;
	}
}
void turnos10(string* j1, string* j2) {
	if (repetirseleccion) {
		turno++;
		fila = fila2;
		columna = columna2;
	}
	if (movimientoinvalido) {
		cout << "\n\n\tEl movimiento insertado anteriormente es inválido\n\n\t\t";
		movimientoinvalido = false;
	}
	if (turno % 2 == 1) { //
		Jugador = 1;
		if (!repetirseleccion) {
			columna = 20;
			columna2 = 20;
			fila = 20;
			fila2 = 20;
			do {
				do {
					cout << "\n\n\tJugador 1, " << *j1 << " , ingrese la columna (Letra) y fila (Número) de la ficha a desplazar:\n\n\t\t";
					cin >> columna;
					columna = toupper(columna);
					if (65 <= columna && columna <= 65 + cuadrado - 1) columna = columna - 65;
					else cout << "\n\n\tLa columna " << columna << " está fuera del tablero\n\n\t\t";
					cin >> fila;
					fila = fila - 1;
					if (!(0 <= fila && fila <= cuadrado - 1)) cout << "\n\n\tLa fila " << fila << " está fuera del tablero\n\n\t\t";
				} while (fila > cuadrado || 0 > fila || columna > cuadrado || 0 > columna);
				if (columna % 2 == fila % 2) cout << "\n\n\tNo existen piezas en las casillas blancas";
				else if (!(matriz10[fila][columna] == 1 || matriz10[fila][columna] == 5)) cout << "\n\n\tLa casilla seleccionada no posee una ficha que puedas mover";
			} while (!(matriz10[fila][columna] == 1 || matriz10[fila][columna] == 5));
		}
		if (matriz10[fila][columna] == 1) {
			matriz10[fila][columna] = 3;
		}
		else if (matriz10[fila][columna] == 5) {
			matriz10[fila][columna] = 7;
		}
		system("cls");
		dibujar(j1, j2);
		do {
			do {
				if (!repetirseleccion) cout << "\n\n\tJugador 1, " << *j1 << " , ingrese la columna (Letra) y fila (Número) a la que desea desplazar la ficha seleccionada:\n\n\t\t";
				else cout << "\n\n\tJugador 2, " << *j2 << " , Puede comer otra pieza en este turno. \n\tInserte la columna (Letra) y fila (Número) de la pieza seleccionada para dejar de seguir comiendo\n\n\t\t";
				cin >> columna2;
				columna2 = toupper(columna2);
				if (65 <= columna2 && columna2 <= 65 + cuadrado - 1) columna2 = columna2 - 65;
				else cout << "\n\n\tLa columna " << columna2 << " está fuera del tablero\n\n\t\t";
				cin >> fila2;
				fila2 = fila2 - 1;
				if (fila2 == fila && columna2 == columna) {
					if (matriz10[fila][columna] == 8 || matriz10[fila][columna] == 7) {
						matriz10[fila][columna] = Jugador + 4;
					}
					else if (matriz10[fila][columna] == 4 || matriz10[fila][columna] == 3) {
						matriz10[fila][columna] = Jugador;
					}
					if (repetirseleccion != false) repetirseleccion = false;
					return;
				}
				if (!(0 <= fila2 && fila2 <= cuadrado - 1)) cout << "\n\n\tLa fila " << fila2 << " está fuera del tablero\n\n\t\t";
			} while (columna2 > cuadrado || columna2 < 0);
			if (columna2 % 2 == fila2 % 2) cout << "\n\n\tNo se pueden mover las piezas a las casillas blancas";
			else if (matriz10[fila2][columna2] != 0) cout << "\n\n\tNo se pueden mover las piezas a una casilla que esté ocupada";
			else if (!(abs(columna - columna2) == abs(fila - fila2))) cout << "\n\n\tLas fichas solo pueden moverse en diagonal";
		} while (!(matriz10[fila2][columna2] == 0 && abs(columna - columna2) == abs(fila - fila2)));
		Noatravesar = false;
		comprobarmatriz10(&fila, &columna, &fila2, &columna2, 1);
	}
	else if (turno % 2 == 0) { //jugador 2
		Jugador = 2;
		if (!repetirseleccion) {
			columna = 20;
			columna2 = 20;
			fila = 20;
			fila2 = 20;
			do {
				do {
					cout << "\n\n\tJugador 2, " << *j2 << " , ingrese la columna (Letra) y fila (Número) de la ficha a desplazar:\n\n\t\t";
					cin >> columna;
					columna = toupper(columna);
					if (65 <= columna && columna <= 65 + columna - 1) columna = columna - 65;
					else cout << "\n\n\tLa columna " << columna << " está fuera del tablero\n\n\t\t";
					cin >> fila;
					fila = fila - 1;
					if (!(0 <= fila && fila <= cuadrado - 1)) cout << "\n\n\tLa fila " << fila << " está fuera del tablero\n\n\t\t";
				} while (fila > cuadrado || 0 > fila || columna > cuadrado || 0 > columna);
				if (columna % 2 == fila % 2) cout << "\n\n\tNo existen piezas en las casillas blancas";
				else if (!(matriz10[fila][columna] == 2 || matriz10[fila][columna] == 6)) cout << "\n\n\tLa casilla seleccionada no posee una ficha que puedas mover";
			} while (!(matriz10[fila][columna] == 2 || matriz10[fila][columna] == 6));
		}
		if (matriz10[fila][columna] == 2) {
			matriz10[fila][columna] = 4;
		}
		else if (matriz10[fila][columna] == 6) {
			matriz10[fila][columna] = 8;
		}
		system("cls");
		dibujar(j1, j2);
		do {
			do {
				if (!repetirseleccion) cout << "\n\n\tJugador 2, " << *j2 << " , ingrese la columna (Letra) y fila (Número) a la que desea desplazar la ficha seleccionada:\n\n\t\t";
				else cout << "\n\n\tJugador 2, " << *j2 << " , Puede comer otra pieza en este turno. \n\tInserte la columna (Letra) y fila (Número) de la pieza seleccionada para dejar de seguir comiendo\n\n\t\t";
				cin >> columna2;
				columna2 = toupper(columna2);
				if (65 <= columna2 && columna2 <= 65 + cuadrado - 1) columna2 = columna2 - 65;
				else cout << "\n\n\tLa columna " << columna2 << " está fuera del tablero\n\n\t\t";
				cin >> fila2;
				fila2 = fila2 - 1;
				if (fila2 == fila && columna2 == columna) {
					if (matriz10[fila][columna] == 8 || matriz10[fila][columna] == 7) {
						matriz10[fila][columna] = Jugador + 4;
					}
					else if (matriz10[fila][columna] == 4 || matriz10[fila][columna] == 3) {
						matriz10[fila][columna] = Jugador;
					}
					if (repetirseleccion != false) repetirseleccion = false;
					return;
				}
				if (!(0 <= fila2 && fila2 <= cuadrado - 1)) cout << "\n\n\tLa fila " << fila2 << " está fuera del tablero\n\n\t\t";
			} while (columna2 > cuadrado || columna2 < 0);
			if (columna2 % 2 == fila2 % 2) cout << "\n\n\tNo se pueden mover las piezas a las casillas blancas";
			else if (matriz10[fila2][columna2] != 0) cout << "\n\n\tNo se pueden mover las piezas a una casilla que esté ocupada";
			else if (!(abs(columna - columna2) == abs(fila - fila2))) cout << "\n\n\tLas fichas solo pueden moverse en diagonal";
		} while (!(matriz10[fila2][columna2] == 0 && abs(columna - columna2) == abs(fila - fila2)));
		Noatravesar = false;
		comprobarmatriz10(&fila, &columna, &fila2, &columna2, 2);
	}
	return;
}
void registrarjugador(int n, string* i) {
	cout << "\n\t╔════════════════════════════════════════════════════════════════╗";
	cout << "\n\t║                Ingrese el nombre del jugador " << n << ":                ║";
	cout << "\n\t╚════════════════════════════════════════════════════════════════╝\n\n\t\t";
	cin >> *i;
	system("cls");
}
void registrarcolor(int n) {
	char lector;
	errorcolor = true;
	cout << "\n\t╔═════════════════════════════════════════════════════════════════════════════════════════════════╗";
	cout << "\n\t║                         Ingrese el color de ficha del jugador " << n << ":                                ║";
	cout << "\n\t║                                                                                                 ║";
	cout << "\n\t║   [1] Azul                [2] Verde              [3] Aguamarina         [4] Rojo                ║";
	cout << "\n\t║   [5] Púrpura             [6] Amarillo           [7] Blanco             [8] Gris                ║";
	cout << "\n\t║   [9] Azul claro          [A] Verde claro        [B] Aguamarina claro   [C] Rojo claro          ║";
	cout << "\n\t║                           [D] Púrpura claro      [E] Blanco brillante                           ║";
	cout << "\n\t║                                                                                                 ║";
	cout << "\n\t╚═════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n\t\t";
	cin >> lector;
	if (97 <= lector && lector <= 102) lector = toupper(lector);
	//Convertir a lector en mayuscula si es una minúscula entre a y f
	if (lector == 'F') lector = 'Z'; //-> Internamente E se codifica como F, así que hay que eliminar las f, y cambiar las e por f
	if (lector == 'E') lector = 'F';
	if ('A' <= lector && lector <= 'D' || lector == 'F') lector = lector - 65 + 10;
	//+10 porque A, B, C, D, y E se cuentan en hexadecimales, es decir, a partir del 10
	//Se excluyó el negro de la lista de colores a seleccionar, porque las casillas por las que
	//las damas se mueven son negras, las piezas se volverían invisibles
	else if (49 <= lector && lector <= 57) lector = lector - 48;
	else {
		if (lector == 'Z') lector = 'F';
		system("cls");
		cout << "\n\t╔════════════════════════════════════════════════════════════════════════╗";
		cout << "\n\t║                                                                        ║";
		cout << "\n\t║                   El caracter " << lector << " está fuera del rango                   ║";
		cout << "\n\t║                     (Presione Enter para Regresar)                     ║";
		cout << "\n\t║                                                                        ║";
		cout << "\n\t╚════════════════════════════════════════════════════════════════════════╝";
		system("pause>nul");
		system("cls");
		return;
	}
	if (n == 1) {
		system("cls");
		errorcolor = false;
		colorjugador1 = lector;
		return;
	}
	else if (n == 2) {
		if (colorjugador1 == lector) {
			system("cls");
			cout << "\n\t╔════════════════════════════════════════════════════════════════════════╗";
			cout << "\n\t║                                                                        ║";
			cout << "\n\t║                        Elija un color diferente                        ║";
			cout << "\n\t║                     (Presione Enter para Regresar)                     ║";
			cout << "\n\t║                                                                        ║";
			cout << "\n\t╚════════════════════════════════════════════════════════════════════════╝";
			system("pause>nul");
			system("cls");
			return;
		}
		else {
			system("cls");
			errorcolor = false;
			colorjugador2 = lector;
			return;
		}
	}
	system("cls");
	return;
}
void gano(int ganador, string* i) {
	system("cls");
	for (int i = 8 - 1; i >= 0; i--) for (j = 8 - 1; j >= 0; j--) matriz8[i][j] = matriz8original[i][j];
	for (int i = 10 - 1; i >= 0; i--) for (j = 10 - 1; j >= 0; j--) matriz10[i][j] = matriz10original[i][j];
	repetirseleccion = 0;
	cout << "\n\t╔";
	for (int w = 70 + (*i).length() * 2 - ((*i).length() % 2); w != 0; w--) {
		cout << "═";
	}
	cout << "╗";
	cout << "\n\t║";
	for (int w = 70 + (*i).length() * 2 - ((*i).length() % 2); w != 0; w--) {
		cout << " ";
	}
	cout << "║";
	cout << "\n\t║";
	for (int w = ((70 + (*i).length() * 2) / 2) - (27 + (*i).length()) / 2; w != 0; w--) {
		cout << " ";
	}
	cout << "¡El jugador " << ganador << ", " << *i << " ha ganado!";
	for (int w = ((70 + (*i).length() * 2) / 2) - (27 + (*i).length()) / 2; w != 0; w--) {
		cout << " ";
	}
	cout << "║";
	cout << "\n\t║";
	for (int w = 70 + (*i).length() * 2 - ((*i).length() % 2); w != 0; w--) {
		cout << " ";
	}
	cout << "║";
	cout << "\n\t╚";
	for (int w = 70 + (*i).length() * 2 - ((*i).length() % 2); w != 0; w--) {
		cout << "═";
	}
	cout << "╝";
	system("pause>nul");
	system("cls");
	return;
}
void principal(string* jugador1, string* jugador2) {
	int fichasj1 = 0, fichasj2 = 0, cont, cont1;
	while (true) {
		fichasj1 = 0;
		fichasj2 = 0;
		for (cont = cuadrado - 1; cont >= 0; cont--) {
			for (cont1 = cuadrado - 1; cont1 >= 0; cont1--) {
				if (cuadrado == 10) {
					if (matriz10[cont][cont1] == 1 || matriz10[cont][cont1] == 5) fichasj1++;
					else if (matriz10[cont][cont1] == 2 || matriz10[cont][cont1] == 6) fichasj2++;
				}
				else if (cuadrado == 8) {
					if (matriz8[cont][cont1] == 1 || matriz8[cont][cont1] == 5) fichasj1++;
					else if (matriz8[cont][cont1] == 2 || matriz8[cont][cont1] == 6) fichasj2++;
				}
			}
		}
		if (fichasj1 == 0) {
			gano(2, jugador2);
			break;
		}
		else if (fichasj2 == 0) {
			gano(1, jugador1);
			break;
		}
		else {
			if (!repetirseleccion) dibujar(jugador1, jugador2);
			if (cuadrado == 10) turnos10(jugador1, jugador2);
			else if (cuadrado == 8) turnos8(jugador1, jugador2);
			system("cls");
			turno++;
		}
	}
}
void personalizado() {
	string jugador1, jugador2;
	registrarjugador(1, &jugador1);
	do registrarcolor(1); while (errorcolor);
	registrarjugador(2, &jugador2);
	do registrarcolor(2); while (errorcolor);
	principal(&jugador1, &jugador2);
}
void normal() {
	string jugador1, jugador2;
	registrarjugador(1, &jugador1);
	registrarjugador(2, &jugador2);
	principal(&jugador1, &jugador2);
}
void dibujarejemplo(int lado, int* matriz) {
	int ejemplo;
	cout << "\n\t║                      ╔";
	for (i = lado; i != 0; i--) cout << bordecuadrado;
	cout << "╗";
	for (int w = ((10 - lado) * 8); w != 0; w--) cout << " ";
	cout << "    ║";
	for (i = lado; i != 0; i--) {
		for (k = 4; k != 0; k--) {
			cout << "\n\t║                      ║";
			for (j = lado; j != 0; j--) {
				ejemplo = matriz[(lado * lado) - 1 - ((i - 1) * lado + (j - 1))];
				color(colordefondo, colordetexto);
				if (ejemplo == -1) cout << blanco << blanco << blanco << blanco;
				else if (ejemplo == 0) cout << negro << negro << negro << negro;
				else if (ejemplo == 9) {
					color(colordetexto, colorjugador1);
					if (k == 1 || k == 4)  cout << blanco << ocupado << ocupado << blanco;
					else if (k == 2 || k == 3) cout << ocupado << blanco << blanco << ocupado;
					color(colordefondo, colordetexto);
				}
				else {
					if (k == 1 || k == 4) {
						cout << negro << negro << negro << negro;
					}
					else {
						cout << negro;
						if (ejemplo == 1) color(colordetexto, colorjugador1);
						else if (ejemplo == 2) color(colordetexto, colorjugador2);
						else if (ejemplo == 3) {
							if (colordefondo != colorjugador1) color(colordetexto, colordefondo);
							else if (colorjugador2 == 4) color(colordetexto, 12);
							else color(colordetexto, 4);
						}
						else if (ejemplo == 4) {
							if (colordefondo != colorjugador2) color(colordetexto, colordefondo);
							else if (colorjugador1 == 4) color(colordetexto, 12);
							else color(colordetexto, 4);
						}
						if (ejemplo == 5) color(colordetexto, colorjugador1);
						else if (ejemplo == 6) color(colordetexto, colorjugador2);
						else if (ejemplo == 7) {
							if (colordefondo != colorjugador1) color(colordetexto, colordefondo);
							else if (colorjugador2 == 4) color(colordetexto, 12);
							else color(colordetexto, 4);
						}
						else if (ejemplo == 8) {
							if (colordefondo != colorjugador2) color(colordetexto, colordefondo);
							else if (colorjugador1 == 4) color(colordetexto, 12);
							else color(colordetexto, 4);
						}
						if (0 <= ejemplo && ejemplo <= 4) {
							cout << ocupado;
							cout << ocupado;
						}
						else {
							cout << reina;
							cout << reina;
						}
						color(colordefondo, colordetexto);
						cout << negro;
					}
				}
			}
			cout << "║";
			for (int w = ((10 - lado) * 8); w != 0; w--) cout << " ";
			cout << "    ║";
		}
	}
	cout << "\n\t║                      ╚";
	for (i = lado; i != 0; i--) cout << bordecuadrado;
	cout << "╝";
	for (int w = ((10 - lado) * 8); w != 0; w--) cout << " ";
	cout << "    ║";
	color(14, 0);
}
void instrucciones() {
	int lado = 3;
	int* matrizejemplo = new int[lado * lado];
	system("cls");
	cout << "\n\t╔════════════════════════════════════════════════════════════════════════════════════════════════════════════╗";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║                                             [ Juego de Damas ]                                             ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║                                         [ Instrucciones de juego ]                                         ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║   [1] Elegir la opción Iniciar una Partida, o Iniciar una Partida Personalizada                            ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║   [2] Insertar el nombre del Jugador 1, y el nombre del Jugador 2                                          ║";
	cout << "\n\t║       [2.1] Si escogió la opción partida personalizada, también elija el color de los jugadores)           ║";
	cout << "\n\t║       [2.2] El jugador 1 tiene el primer turno, independientemente de su color en pantalla. Las fichas del ║";
	cout << "\n\t║             jugador 1 se encuentran en la parte superior del tablero al inicio del juego.                  ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║   [3] Para seleccionar una pieza de su equipo, ingrese la letra correspondiente a la columna, y el número  ║";
	cout << "\n\t║       correspondiente a la fila en la que se encuentra la pieza a desplazar. La pieza seleccionada se      ║";
	cout << "\n\t║       pintará de amarillo para mostrar que ha sido seleccionada.                                           ║";
	cout << "\n\t║       [3.1] Si ha insertado una posición invalida, el juego se lo resaltará, y le brindará la razón por la ║";
	cout << "\n\t║             cual la posición brindada es incorrecta.                                                       ║";
	cout << "\n\t║       [3.2] Si desea deseleccionar una pieza seleccionada, en el siguiente paso escriba la posición de la  ║";
	cout << "\n\t║             pieza actualmente seleccionada. La pieza volverá a su color natural para mostrar que ha sido   ║";
	cout << "\n\t║             deseleccionada. El turno de cualquiera de los dos jugadores no terminará hasta que el estado   ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║             del tablero sea diferente al que tenía al iniciar el turno, por tanto, el turno se repetirá.   ║";
	cout << "\n\t║   [4] Tras seleccionar una pieza, debe indicar a que posición desea desplazarla, insertando la letra       ║";
	cout << "\n\t║       correspondiente a la fila y el número correspondiente a la columna.                                  ║";
	cout << "\n\t║       [4.1] Debe tener en cuenta que las piezas solo pueden moverse en diagonal, en un ángulo de 45 grados,║";
	cout << "\n\t║             y que deben moverse a casillas negras vacías                                                   ║";
	cout << "\n\t║       [4.2] Las piezas normales [██] solo pueden desplazarse una casilla por turno al moverse, excepto     ║";
	cout << "\n\t║             cuando estan comiendo a otros jugadores (Deben avanzar dos casillas), o cuando se repite el    ║";
	cout << "\n\t║             turno, bajo circunstancias que se explicarán más adelante. Adicionalmente, este tipo de pieza  ║";
	cout << "\n\t║             solo puede avanzar verticalmente en una dirección. Si la pieza empezó abajo, solo puede        ║";
	cout << "\n\t║             ascender, y si empezó arriba, solo puede descender.                                            ║";
	cout << "\n\t║             [4.2.1] Para comer una pieza, una región del tablero debe presentar la siguiente disposición:  ║";
	int matrizadibujar[9] = { 1,-1,0,-1,2,-1,0,-1,0 };
	for (int x = (lado * lado) - 1; x >= 0; x--) matrizejemplo[x] = matrizadibujar[x];
	dibujarejemplo(lado, matrizejemplo);
	cout << "\n\t║                     Si el turno fuera del jugador blanco, para comer la pieza roja, el jugador tendría que ║";
	cout << "\n\t║                     moverse a la posición indicada a continuación:                                         ║";
	matrizadibujar[8] = 9;
	for (int x = (lado * lado) - 1; x >= 0; x--) matrizejemplo[x] = matrizadibujar[x];
	dibujarejemplo(lado, matrizejemplo);
	cout << "\n\t║                     Tras el movimiento indicado, el tablero quedaría de la siguiente manera:               ║";
	matrizadibujar[0] = 0;
	matrizadibujar[4] = 0;
	matrizadibujar[8] = 1;
	for (int x = (lado * lado) - 1; x >= 0; x--) matrizejemplo[x] = matrizadibujar[x];
	dibujarejemplo(lado, matrizejemplo);
	cout << "\n\t║       [4.3] Las piezas de tipo reina [▒▒] pueden desplazarse cuantas casillas deseen en horizontal, sin    ║";
	cout << "\n\t║             embargo, no pueden atravesar a otras piezas de su equipo, y se deben detener inmediatamente    ║";
	cout << "\n\t║             después de comer a una pieza del jugador contrario, sea esta una dama o no. Adicionalmente,    ║";
	cout << "\n\t║             este tipo de pieza puede ir en cualquier dirección.                                            ║";
	cout << "\n\t║             [4.3.1] Si una dama detecta que hay una pieza de su equipo en una parte de su recorrido, se    ║";
	cout << "\n\t║                     detendrá una casilla antes de la posición de la ficha que detectó en su camino.        ║";
	cout << "\n\t║             [4.3.2] Si una dama detecta que hay una pieza del jugador contrario en su recorrido, se        ║";
	cout << "\n\t║                     detendrá una casilla después de la posición de la ficha que detectó en su camino.      ║";
	cout << "\n\t║       [4.4] Al comer una pieza, se entrará en un modo especial, que permite seguir comiendo más piezas     ║";
	cout << "\n\t║             usando solamente la pieza actualmente seleccionada. Para salir de este modo, ingrese las       ║";
	cout << "\n\t║             coordenadas de la pieza resaltada. Al terminar el modo especial, el turno pasará a ser del     ║";
	cout << "\n\t║             jugador opuesto, y la pieza será deseleccionada.                                               ║";
	cout << "\n\t║             [4.4.1] El modo especial solo permite comer piezas, no permite realizar un desplazamiento en   ║";
	cout << "\n\t║                     el que no se coma una pieza del jugador contrario. Adicionalmente, solo al comer       ║";
	cout << "\n\t║                     multiples piezas (Contando solo a partir de la segunda pieza a comer), se puede usar   ║";
	cout << "\n\t║                     una pieza ordinaria para comer hacia la dirección opuesta a la normalmente permitida.  ║";
	cout << "\n\t║                     (En el caso de que sea una dama, sigue manteniendo sus propiedades de movimiento sin   ║";
	cout << "\n\t║                     alteración alguna)                                                                     ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║   [5] Al realizar un movimiento, el turno pasará a ser del jugador contrario.                              ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║   [6] Si una pieza normal llega al extremo opuesto del tablero, se convertirá en reina.                    ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║   [7] La partida terminará cuando uno de los dos jugadores se queden sin piezas.                           ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║                                        Presione Enter para Regresar                                        ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝";
	cout << "\n\n\t\t";
	delete matrizejemplo;
	system("pause>nul");
}
void creditos() {
	cout << "\n\t╔════════════════════════════════════════════════════════════════════════════════════════════════════════════╗";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║                                             [ Juego de Damas ]                                             ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣";
	cout << "\n\t║                                             ╔════════════════╗                                             ║";
	cout << "\n\t║                                             ║██  ██  ██  ██  ║                                             ║";
	cout << "\n\t║                                             ║  ██  ██  ██  ██║                                             ║";
	cout << "\n\t║                                             ║██  ██  ██  ██  ║                                             ║";
	cout << "\n\t║                                             ║  ██  ██  ██  ██║                                             ║";
	cout << "\n\t║                                             ║██  ██  ██  ██  ║                                             ║";
	cout << "\n\t║                                             ║  ██  ██  ██  ██║                                             ║";
	cout << "\n\t║                                             ║██  ██  ██  ██  ║                                             ║";
	cout << "\n\t║                                             ║  ██  ██  ██  ██║                                             ║";
	cout << "\n\t║                                             ╚════════════════╝                                             ║";
	cout << "\n\t╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║   Programación y codificación:                                                                             ║";
	cout << "\n\t║       Marcelo Alejandro Scerpella Zarkovic                                                                 ║";
	cout << "\n\t║       Fernando Josué Díaz Silva                                                                            ║";
	cout << "\n\t║       Joaquin Marcelo Cortés Casas                                                                         ║";
	cout << "\n\t║   Curso:                                                                                                   ║";
	cout << "\n\t║       Programación I                                                                                       ║";
	cout << "\n\t║   Profesor:                                                                                                ║";
	cout << "\n\t║       Juan Orlando Salazar Campos                                                                          ║";
	cout << "\n\t║   Versión del Proyecto:                                                                                    ║";
	cout << "\n\t║       1.7.2                                                                                                ║";
	cout << "\n\t║      (Primera versión, seis cambios importantes en el código, dos bugs solucionado desde el último cambio) ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║                                        Presione Enter para Regresar                                        ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝";
	cout << "\n\n\n\n";
	system("pause > nul");
	system("cls");
	return;
}
void menu() {
	int ops;
	system("cls");
	cout << "\n\t╔════════════════════════════════════════════════════════════════════════════════════════════════════════════╗";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║                                             [ Juego de Damas ]                                             ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║                                         █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█                                         ║";
	cout << "\n\t║                                         █  ╭──────────────────╮  █                                         ║";
	cout << "\n\t║                                         █  │   ██  ██  ██  ██ │  █                                         ║";
	cout << "\n\t║                                         █  │ ██  ██  ██  ██   │  █                                         ║";
	cout << "\n\t║                                         █  │   ██  ██  ██  ██ │  █                                         ║";
	cout << "\n\t║                                         █  │ ██  ██  ██  ██   │  █                                         ║";
	cout << "\n\t║                                         █  │   ██  ██  ██  ██ │  █                                         ║";
	cout << "\n\t║                                         █  │ ██  ██  ██  ██   │  █                                         ║";
	cout << "\n\t║                                         █  │   ██  ██  ██  ██ │  █                                         ║";
	cout << "\n\t║                                         █  │ ██  ██  ██  ██   │  █                                         ║";
	cout << "\n\t║                                         █  ╰──────────────────╯  █                                         ║";
	cout << "\n\t║                                         █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█                                         ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t║   [1] Iniciar una partida                                                                                  ║";
	cout << "\n\t║   [2] Iniciar una partida personalizada                                                                    ║";
	cout << "\n\t║   [3] Abrir Instrucciones                                                                                  ║";
	if (cuadrado == 8) cout << "\n\t║   [4] Cambiar tamaño de tablero (Tamaño actual: " << cuadrado << ")                                                         ║";
	else cout << "\n\t║   [4] Cambiar tamaño de tablero (Tamaño actual: " << cuadrado << ")                                                        ║";
	cout << "\n\t║   [5] Créditos                                                                                             ║";
	cout << "\n\t║   [6] Salir                                                                                                ║";
	cout << "\n\t║                                                                                                            ║";
	cout << "\n\t╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝";
	cout << "\n\n\t\t";
	cin >> ops;
	turno = 1;
	system("cls");
	switch (ops) {
	case 1:
		normal();
		break;
	case 2:
		personalizado();
		break;
	case 3:
		instrucciones();
		break;
	case 4:
		if (cuadrado == 8) cuadrado = 10;
		else if (cuadrado == 10) cuadrado = 8;
		break;
	case 5:
		creditos();
		break;
	case 6:
		salir();
		break;
	case 43:
		reloj();
		break;
	case 64:
		cout << "\n\n";
		while (true) transicion("\n\tIs the final countdown!\n\tWe're living together\n\tThe final countdown!\n\tOoooooooh");
		break;
	case 2147483647:
		cronometro();
		break;
	default:
		cout << "\n\t╔════════════════════════════════════════════════════════════════════════════════════════════════════════════╗";
		cout << "\n\t║                                                                                                            ║";
		cout << "\n\t║                                    [ La opción ingresada no es Válida ]                                    ║";
		cout << "\n\t║                                                                                                            ║";
		cout << "\n\t╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣";
		cout << "\n\t║                                      [ Presione Enter para Regresar ]                                      ║";
		cout << "\n\t╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝";
		system("pause > nul");
		system("cls");
	}
}
int main() {
	//setlocale(LC_ALL, "");
	for (i = 8 - 1; i >= 0; i--) for (j = 8 - 1; j >= 0; j--) matriz8[i][j] = matriz8original[i][j];
	for (i = 10 - 1; i >= 0; i--) for (j = 10 - 1; j >= 0; j--) matriz10[i][j] = matriz10original[i][j];
	SetConsoleOutputCP(CP_UTF8);
	system("title Damas");
	system("color e0");
	color(colordefondo, colordetexto);
	while (true) menu();
	return 1;
}