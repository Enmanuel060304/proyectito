#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<mouse.h>
#include<conio.h>
#include<dos.h>

int dibujoc();
int dibujotri();
int dibujosquare();
int dibujoline();
int entorno1();

void main(){
	int dibujouno, dibujodos, dibujotres, dibujocuatro;
	int entornouno;
	/*Variables para el circulo*/
	int ac=144,bc=135,cc,dc,xc,yc;
	/*Variables para el triangulo*/

	/*Variables para el cudrado*/
	int asquare=305,bsquare=191, csquare=375,dsquare=260,xs,ys;
	char z;
	int adap=DETECT,modo;
	initgraph(&adap, &modo,"C:\\tc20\\bin");
	mver();

	/*Llamamos a las funciones*/
	entornouno=entorno1();

	/*Hacemos las condicionales para poder mostrar los dibujos*/
	while(mclick()!=2){
		z=inport(0x60);
		xc=mxpos(1);
		yc=mypos(1);
		if(mclick()==1 && minlimit(1,550,66,620,133)){
			setcolor(15);
			circle(ac,bc,34);
		}
		else if(mclick()==1 && minlimit(1,549,167,620,235)){
			dibujodos=dibujotri();
		}
		else if(mclick()==1 && minlimit(1,549,279, 619,348)){
			setcolor(15);
			rectangle(asquare,bsquare, csquare,dsquare);
		}
		else if(mclick()==1 && minlimit(1,557,383,616,442)){
			dibujocuatro=dibujoline();
		}


		if(minlimit(1,ac,bc,cc,dc)==1){
			if(mclick()==1){
				setcolor(0);
				circle(ac,bc,34);
				
				ac=xc-5;
				bc=yc-5;
				cc=xc+15;
				dc=yc+15;
				setcolor(15);
				circle(ac,bc,34);
			}
		}
		if(minlimit(1,asquare,bsquare,csquare,dsquare)==1){
			if(mclick()==1){
				setcolor(0);
				rectangle(asquare,bsquare, csquare,dsquare);
				

				asquare=xc-10;
				bsquare=yc-10;
				csquare=xc+20;
				dsquare=yc+20;

				setcolor(15);
				rectangle(asquare,bsquare, csquare,dsquare);
			}
		}

		else if(mclick()==1 && minlimit(1,557,383,616,442)){
			dibujocuatro=dibujoline();
		}

	}

	getch();
	closegraph();

}

/*Se crea el diseno*/
int entorno1(){
	int tri[]={549,235, 584,166, 618,235};
	setcolor(15);
	rectangle(1,1,639,479);
	rectangle(50,45,520,365);
	setlinestyle(3,0,1);
	circle(585,97,34);
	fillpoly(3,tri);
	rectangle(549,279, 619,348);
	line(615,384, 558,441);
}

/*Se crea la funcion del triangulo*/
int dibujotri(){
	int dtri[]={109,309, 144,240, 178,309};
	setcolor(15);
	fillpoly(3,dtri);
}
/*Funcion del cuadrado
int dibujosquare(){
	setcolor(15);
	rectangle(305,191, 375,260);
}*/
/*Funcion de la linia*/
int dibujoline(){
	setcolor(15);
	line(272,93, 215,150);
}
