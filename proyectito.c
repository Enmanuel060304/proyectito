#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#define tam 30

typedef struct 
{
    int posx;
    int posy;
    int color;
}robot; 

robot robotcito;

void start_graphics(); /* funcion para iniciar modo grafico */
void pinta_robot();
void mover_robot(int x,int y);
void oculta_robot();

char tecla;  /* alamecena teclas presionada */ 
int seve = 0;

void main ()
{
	start_graphics();
    robotcito.posx = 100;
    robotcito.posy = 200;
    pinta_robot();
    setcolor(2);
    do
    {
        tecla = inport(0x60);
        
        switch (tecla)
        {
        case 80:
            robotcito.posy++;
            mover_robot(robotcito.posx,robotcito.posy);
            break;
        
        case 75:
            robotcito.posx--;
            mover_robot(robotcito.posx,robotcito.posy);
            break;
        case 77:
            robotcito.posx++;
            mover_robot(robotcito.posx,robotcito.posy);
            break;

        case 72:
            robotcito.posy--;
            mover_robot(robotcito.posx,robotcito.posy);
            break;
        case 32: 
            break;
        }

    }
    while(tecla != 32);

    closegraph();
   /* getch(); */
}

void start_graphics()
{
    int adap = DETECT,modo;
    initgraph(&adap,&modo,"c:\\tc20\\bin");
}

void pinta_robot()
{
    setcolor(4);
    circle(robotcito.posx,robotcito.posy,tam);
    seve = 1;

}

void oculta_robot ()
{
    unsigned int guardacolor = getcolor();
    if (seve)
    {
        setcolor(getbkcolor());
        circle(robotcito.posx,robotcito.posy,tam);
        seve = 0;
        setcolor(guardacolor);

    }
}

void mover_robot(int x,int y)
{
    if (seve)
    {
        oculta_robot();
        x = robotcito.posx;
        y = robotcito.posy;
        pinta_robot();
    }
    else
    {
        x = robotcito.posx;
        y = robotcito.posy;
    }
	
}
