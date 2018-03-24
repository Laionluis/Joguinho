#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>  /* only for sleep() */

#define LINHAS 22
#define COLUNAS 40
#define EXTREMO 1
#define PAREDE 4
#define TERRA 2
#define PEDRA 3
#define DIAMANTE 5
#define PORTAL 6
#define VAZIO 0
#define DELAY 60000



void iniciar_mapa(int mapa[LINHAS][COLUNAS],int cont, int diamantes, int score);
void pedra(int mapa[LINHAS][COLUNAS],int x,int y,int *morre);
void recebematriz(int aux_matrix[LINHAS][COLUNAS], int mapa[LINHAS][COLUNAS]);
void PROX_FASE(int mapa[LINHAS][COLUNAS], int mapa2[LINHAS][COLUNAS]);
void parabens();
