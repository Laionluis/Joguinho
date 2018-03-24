#include "biblioteca.h"

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


int main()
{	
	int morre=0;
	int variavel=0;
	int aux_fim=0;
	int aux_cont=1;
	int cont_diamante=0;
	int cont_score=0;
	int cont=(50*60),ch;
	int x=0,y=0;
	int aux_matrix[LINHAS][COLUNAS];
	int aux_matrix2[LINHAS][COLUNAS];

    int mapa[LINHAS][COLUNAS] =
    { 
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,3,2,2,3,2,2,4,2,3,2,2,2,5,2,4,2,2,2,0,2,3,2,4,3,2,2,2,2,2,2,4,2,2,3,3,2,2,1},
		{1,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,4,2,2,2,3,2,2,2,4,2,2,2,2,2,2,2,4,2,2,2,2,2,2,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,1},
		{1,5,2,2,2,2,2,2,4,2,3,2,2,2,2,3,4,2,3,2,0,2,2,2,4,2,2,3,2,2,5,2,4,2,2,3,2,3,2,1},
		{1,2,2,2,2,2,2,2,4,2,3,2,2,2,2,3,4,2,3,2,0,2,2,2,4,2,2,2,2,2,3,2,4,2,2,2,2,2,2,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1},
		{1,2,2,2,2,3,3,2,4,2,2,3,2,2,2,2,4,2,2,2,0,2,2,3,4,2,2,2,2,3,2,2,4,2,2,2,2,2,3,1},
		{1,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,4,2,2,2,0,2,2,2,4,2,2,2,2,2,2,2,4,2,2,2,2,2,2,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,3,2,2,3,2,2,2,4,2,2,2,2,3,2,2,4,2,2,3,0,2,2,2,4,2,2,2,2,2,2,5,4,3,2,2,2,2,2,1},
		{1,3,2,2,2,2,3,2,4,2,2,3,2,2,3,2,4,2,2,2,0,2,3,3,4,2,2,2,2,2,2,2,4,2,2,2,2,3,2,1},
		{1,2,3,2,2,2,2,2,4,2,2,2,3,2,2,2,4,2,2,2,0,2,2,2,4,2,2,2,2,2,2,2,4,3,3,2,2,3,2,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1},
		{1,3,2,3,3,3,2,2,4,2,2,2,2,3,2,3,4,2,2,2,0,2,2,2,4,2,3,5,2,2,3,2,4,2,2,2,2,2,2,1},
		{1,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,4,2,2,2,0,2,2,2,4,2,2,2,2,2,2,2,4,2,2,2,2,2,2,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,5,2,2,2,2,3,2,4,3,2,2,2,2,3,2,4,2,3,2,0,2,2,3,4,2,3,2,3,2,2,2,4,2,2,5,2,2,2,1},
		{1,2,2,2,2,2,3,2,4,3,2,2,5,2,2,2,4,2,2,2,0,2,2,2,4,2,2,3,2,2,2,2,4,2,2,2,3,3,3,1},
		{1,2,5,2,2,2,3,3,4,2,2,3,2,2,2,2,4,2,2,2,0,3,2,2,4,2,2,2,2,2,2,2,4,2,2,2,2,2,2,1},
		{1,2,3,2,2,2,2,2,4,2,2,2,2,2,3,2,4,2,1,2,3,2,2,2,4,2,2,2,2,3,2,3,4,2,2,2,2,3,2,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int mapa2[LINHAS][COLUNAS] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,3,0,0,2,2,4,5,2,2,0,0,0,2,2,3,2,2,2,2,2,2,2,2,3,3,3,2,2,2,2,2,5,2,2,2,2,2,2,1},
		{1,2,2,2,2,2,4,2,0,2,2,2,5,3,2,2,2,2,5,3,3,2,2,2,2,2,0,0,2,0,3,3,0,2,3,2,2,2,2,1},
		{1,0,0,3,2,2,4,2,3,0,0,0,0,3,2,2,3,2,2,2,2,0,5,2,2,2,2,3,5,3,3,3,0,2,3,2,0,0,0,1},
		{1,0,0,2,2,2,4,2,3,2,0,0,0,2,2,2,3,3,3,2,5,3,2,2,0,0,5,3,0,2,3,2,2,3,2,0,0,2,2,1},
		{1,2,2,3,5,0,5,0,3,3,0,2,2,5,2,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,5,2,2,2,0,1},
		{1,2,5,2,2,2,2,2,2,2,0,2,2,3,2,2,2,2,2,5,2,2,5,2,2,2,2,2,2,2,2,0,0,0,0,5,2,2,2,1},
		{1,0,2,2,3,2,4,2,2,2,2,2,2,2,0,0,0,0,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,0,2,2,2,2,2,1},
		{1,2,2,2,2,2,4,4,4,4,4,4,4,4,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1},
		{1,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,3,2,5,0,0,0,0,3,3,2,2,2,2,2,2,2,2,2,3,2,1},
		{1,2,3,2,2,2,4,2,2,2,2,3,3,0,0,0,0,0,2,0,2,2,3,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,1},
		{1,0,3,2,3,3,4,2,2,2,2,2,2,2,0,0,0,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,1},
		{1,0,2,2,3,2,4,0,0,0,0,0,0,0,0,2,2,2,2,0,3,3,2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,2,1},
		{1,2,2,2,2,2,4,3,2,2,2,2,3,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,5,2,2,2,2,2,2,1},
		{1,5,2,2,2,0,4,2,0,0,0,0,2,2,0,0,0,0,2,0,0,2,2,0,2,2,2,2,2,2,2,2,2,0,0,2,0,2,0,1},
		{1,2,2,3,2,2,4,2,2,2,2,2,2,2,2,2,2,0,0,0,0,2,2,2,2,2,2,2,2,3,3,0,4,4,4,4,4,4,4,1},
		{1,2,0,3,2,5,4,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,2,2,3,4,0,0,0,0,0,0,1},
		{1,0,0,0,0,3,4,2,3,3,3,2,2,2,2,2,2,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,5,2,0,3,0,1},
		{1,2,2,2,0,2,4,0,2,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,4,2,2,0,0,2,0,1},
		{1,0,3,2,2,2,4,2,5,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,0,0,2,2,0,0,3,2,4,0,2,0,0,0,0,1},
		{1,5,2,0,0,0,4,2,3,2,2,2,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,4,2,2,0,0,0,5,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};	
	recebematriz(aux_matrix,mapa);
	recebematriz(aux_matrix2,mapa2);
	initscr();			/* Start curses mode 		  */
	keypad(stdscr, TRUE);
	noecho();	
	raw();
	nodelay(stdscr, TRUE);
	start_color();
	iniciar_mapa(mapa,cont,cont_diamante,cont_score);
	attroff(COLOR_PAIR(2));	
	x = 36;y = 19;
	curs_set(FALSE);
	do{	
		if ((cont) && (morre == 0) && (variavel == 0) )
		{
			ch = getch();
			clear();
			attron(COLOR_PAIR(2));	
			if ((ch=='r') || (ch=='R')) 
			{
				
				recebematriz(mapa,aux_matrix);
				x = 36;y = 19;
				cont_diamante=0;
				cont_score=0;
				cont=(50*60);
				aux_cont=1;
			}
			if (cont_diamante==aux_cont)
			{
				mapa[18][30]=PORTAL;
			}	
			if (ch == KEY_RIGHT)
			{
				if ((mapa[y][(x/2)+1] == VAZIO) || (mapa[y][(x/2)+1] == TERRA) || (mapa[y][(x/2)+1] == DIAMANTE) || (mapa[y][(x/2)+1] == PORTAL))
				{
					if (mapa[y][(x/2)] == TERRA)
						mapa[y][(x/2)]=VAZIO;
					if (mapa[y][(x/2)+1] == DIAMANTE)
					{
						cont_score = cont_score + 20;
						cont_diamante++;
						mapa[y][(x/2)+1]=VAZIO;						
					}
					if (mapa[y][(x/2)+1] == PORTAL)
					{
						if (aux_fim!=0)
						{
							variavel = 5;
							if ((cont_diamante == 11) || (cont_diamante == 5))
								cont_score = cont_score*2;
							cont_score= (cont_score*(cont/50));
						}
						
						PROX_FASE(mapa,mapa2);
						cont_diamante=0;
						if ((cont_diamante == 11) || (cont_diamante == 5))
							cont_score = cont_score*2;
						cont_score= (cont_score*(cont/50));
						cont=(50*60);
						aux_cont=5;
						x = 8;y = 2;
						aux_fim= 1;
					}
					x+=2;
					pedra(mapa,x,y,&morre);//trata o movimento das pedras
				}
			}
			if (ch == KEY_UP)
			{
				if ((mapa[(y-1)][x/2]==VAZIO) || (mapa[(y-1)][x/2]==TERRA) || (mapa[(y-1)][x/2] == DIAMANTE) || (mapa[(y-1)][x/2] == PORTAL))
				{	
					if (mapa[(y)][x/2]==TERRA)
						mapa[(y)][x/2]=VAZIO;
					if (mapa[(y-1)][x/2]==DIAMANTE)
					{
						cont_score = cont_score + 20;
						cont_diamante++;
						mapa[(y-1)][x/2]=VAZIO;
					}
					if (mapa[(y-1)][x/2] == PORTAL)
					{
						if (aux_fim!=0)
						{
							variavel = 5;
							if ((cont_diamante == 11) || (cont_diamante == 5))
								cont_score = cont_score*2;
							cont_score= (cont_score*(cont/50));
						}
					
						PROX_FASE(mapa,mapa2);
						cont_diamante=0;
						if ((cont_diamante == 11) || (cont_diamante == 5))
							cont_score = cont_score*2;
						cont_score= (cont_score*(cont/50));
						cont=(50*60);
						aux_cont=5;
						x = 8;y = 2;
						aux_fim= 1;
					}
					y--;
					pedra(mapa,x,y,&morre);//trata o movimento das pedras
				}
			}
			if (ch == KEY_DOWN)
			{
				if ((mapa[(y+1)][x/2]==VAZIO) || (mapa[(y+1)][x/2]==TERRA) || (mapa[(y+1)][x/2]==DIAMANTE) || (mapa[(y+1)][x/2]==PORTAL))
				{
					if (mapa[(y)][x/2]==TERRA)
						mapa[y][(x/2)]=VAZIO;
					if (mapa[(y+1)][x/2]==DIAMANTE)
					{
						cont_score = cont_score + 20;
						cont_diamante++;
						mapa[y+1][(x/2)]=VAZIO;						
					}
					if (mapa[(y+1)][x/2] == PORTAL)
					{
						if (aux_fim!=0)
						{
							variavel = 5;
							if ((cont_diamante == 11) || (cont_diamante == 5))
								cont_score = cont_score*2;
							cont_score= (cont_score*(cont/50));
						}
					
						PROX_FASE(mapa,mapa2);
						cont_diamante=0;
						if ((cont_diamante == 11) || (cont_diamante == 5))
							cont_score = cont_score*2;
						cont_score= (cont_score*(cont/50));
						cont=(50*60);
						aux_cont=5;
						x = 8;y = 2;
						aux_fim= 1;
					}
					y++;
					pedra(mapa,x,y,&morre);//trata o movimento das pedras
				}
			}
			if (ch == KEY_LEFT)
			{
				if ((mapa[y][(x/2)-1] == VAZIO) || (mapa[y][(x/2)-1] == TERRA) || (mapa[y][(x/2)-1] == DIAMANTE) || (mapa[y][(x/2)-1] == PORTAL) )
				{
					if (mapa[y][(x/2)] == TERRA)
						mapa[y][(x/2)]=VAZIO;
					if (mapa[y][(x/2)-1] == DIAMANTE)
					{
						cont_score = cont_score + 20;
						cont_diamante++;
						mapa[y][(x/2)-1]=VAZIO;
					}
					if (mapa[y][(x/2)-1] == PORTAL)
					{
						if (aux_fim!=0)
						{
							variavel = 5;
							if ((cont_diamante == 11) || (cont_diamante == 5))
								cont_score = cont_score*2;
							cont_score= (cont_score*(cont/50));
						}
					
						PROX_FASE(mapa,mapa2);
						cont_diamante=0;
						if ((cont_diamante == 11) || (cont_diamante == 5))
							cont_score = cont_score*2;
						cont_score= (cont_score*(cont/50));
						cont=(50*60);
						aux_cont=5;
						x = 8;y = 2;
						aux_fim= 1;
					}
					x-=2;
					pedra(mapa,x,y,&morre);//trata o movimento das pedras
				}
			}
			//trata o movimento das pedras
			pedra(mapa,x,y,&morre);				
			iniciar_mapa(mapa,cont,cont_diamante,cont_score);
			init_pair(2, COLOR_BLACK, COLOR_CYAN);
			attron(COLOR_PAIR(2));
			mvprintw(y, x, "oo");
			attroff(COLOR_PAIR(2));
			refresh();
			usleep(DELAY);
			cont--;
		}
		else
		{
			if (variavel != 5)
			{
				ch = getch();
				clear();		
				printw("DIGITE R PARA TENTAR NOVAMENTE duwan gay \n");		
				printw("\n\n");
				printw("GGGGGGGG AAAAAAAAA MM     MM EEEEEEEEE   OOOOOOOOO VVV   VVV EEEEEEEEE RRRRRRRR  \n");
				printw("GGG      AAA   AAA MMM   MMM EEEEEEEEE   OOO   OOO VVV   VVV EEEEEEEEE RRR   RRR \n");
				printw("GGG      AAA   AAA MMMM MMMM EEE         OOO   OOO VVV   VVV EEE       RRR   RRR \n");
				printw("GGG  GGG AAAAAAAAA MM MMM MM EEEEEE      OOO   OOO VVV   VVV EEEEEEE   RRRRRRR   \n");
				printw("GGG   GG AAAAAAAAA MM  M  MM EEE         OOO   OOO  VVVVVVV  EEE       RRR  RR   \n");
				printw("GGGGGGGG AAA   AAA MM     MM EEEEEEEEE   OOO   OOO   VVVVV   EEEEEEEEE RRR  RRR  \n");
				printw("GGGGGGGG AAA   AAA MM     MM EEEEEEEEE   000000000    VVV    EEEEEEEEE RRR  RRRR \n");
				printw("\n\n");
				refresh();
				usleep(4000);

			}
			else
			{
				ch = getch();
				clear();
				printw("PARABENS, seu score foi de : %d \n", cont_score);
				refresh();
				usleep(4000);
			}
		}
		if ((ch=='r') || (ch=='R')) 
		{
				
			recebematriz(mapa,aux_matrix);
			x = 36;y = 19;
			cont_diamante=0;
			cont_score=0;
			cont=(50*60);
			aux_cont=1;
			morre = 0;
			variavel = 0;
		}
	} while (ch!=KEY_BACKSPACE);
	endwin();	
	return 0;
}