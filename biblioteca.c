#include "biblioteca.h"



void iniciar_mapa(int mapa[LINHAS][COLUNAS],int cont, int diamantes, int score)
{
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_WHITE);
	init_pair(3, COLOR_GREEN, COLOR_GREEN);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(1, COLOR_RED, COLOR_RED);
	init_pair(9, COLOR_YELLOW, COLOR_YELLOW);
	int i,j;
	for (i=0; i<LINHAS;i++)
	{
		for (j=0; j<COLUNAS;j++)
		{
			if (mapa[i][j]==VAZIO)
				printw("  ");
			if (mapa[i][j]==TERRA){
				attron(COLOR_PAIR(9));
				printw("- ");
				attroff(COLOR_PAIR(9));}
			if (mapa[i][j]==EXTREMO){
				attron(COLOR_PAIR(3));
				printw("# ");
				attroff(COLOR_PAIR(3));
			}
			if (mapa[i][j]==PEDRA){
				attron(COLOR_PAIR(4));
				printw("0 ");
				attroff(COLOR_PAIR(4));
			}
			if (mapa[i][j]==PAREDE){
				attron(COLOR_PAIR(3));
				printw("# ");
				attroff(COLOR_PAIR(3));
			}
			if (mapa[i][j]==DIAMANTE){
				attron(COLOR_PAIR(5));
				printw("VV");
				attroff(COLOR_PAIR(5));}
			if ((mapa[i][j]==PORTAL))
			{
				attron(COLOR_PAIR(1));
				printw("H ");
				attroff(COLOR_PAIR(1));
			}
		}
		printw("\n");
	}
	cont=cont/30; 
	printw("DIAMANTES: %d   SCORE: %d        TEMPO: %d\n", diamantes, score, cont);
	printw("\n(R) -> RESTART \n\nCOMANDOS:\n  (^)\n(<) (>)\n  (v)\n");
}

void pedra(int mapa[LINHAS][COLUNAS],int x,int y,int *morre)
{
	int i,j;
	for (i=LINHAS; i>0;i--)
	{
		for (j=0; j<COLUNAS;j++)
		{
			if ((mapa[i][j] == PEDRA) && (mapa[i+1][j] == VAZIO))
			{				
				mapa[i+1][j]=PEDRA;
				if (mapa[i+1][j] == mapa[y][x/2])
				{
					*morre=1;
				}
				mapa[i][j]=VAZIO;
			}
			if ((mapa[i][j] == PEDRA) && (mapa[i+1][j] == PEDRA) && (mapa[i+1][j+1] == VAZIO) )
			{
				mapa[i+1][j+1]=PEDRA;
				if (mapa[i+1][j+1] == mapa[y][x/2])
				{
					*morre=1;
				}
				mapa[i][j]=VAZIO;
			}
			if ((mapa[i][j] == PEDRA) && (mapa[i+1][j] == PEDRA) && (mapa[i+1][j-1] == VAZIO) )
			{
				mapa[i+1][j-1]=PEDRA;
				if (mapa[i+1][j-1] == mapa[y][x/2])
				{
					*morre=1;
				}
				mapa[i][j]=VAZIO;
			}
		}
	}
}

void recebematriz(int aux_matrix[LINHAS][COLUNAS], int mapa[LINHAS][COLUNAS])
{
	int i,j;
	for (i=0; i<LINHAS;i++)
	{
		for (j=0; j<COLUNAS;j++)
		{
			aux_matrix[i][j] = mapa[i][j];
		}
	}	
}

void parabens()
{
	clear();
	refresh();
	printw ("PARABÉNS");
}

void PROX_FASE(int mapa[LINHAS][COLUNAS], int mapa2[LINHAS][COLUNAS])
{
	clear();
	refresh();
	recebematriz(mapa,mapa2);
}