/*

28 abr. 2018/22:41:09
*/

#include "libEuler.h"

#define WIDTH 260
#define HEIGHT 210
#define X WIDTH/2
#define Y HEIGHT/2
#define XMAX WIDTH-X-1
#define XMIN -(WIDTH-X)
#define YMAX HEIGHT-Y
#define YMIN -(HEIGHT-Y)+1

char grid[HEIGHT][WIDTH];

int plot(int x, int y);
void init_grid(void);
void show_grid(void);

// Set "pixel" at specific coordinates
int plot(int x, int y){
    if( x > XMAX || x < XMIN || y > YMAX || y < YMIN ) return(-1);
    grid[Y-y][X+x] = '*';
    return(1);
}

// Initialize grid
void init_grid(void){
    int x,y;
    for(y=0;y<HEIGHT;y++){
        for(x=0;x<WIDTH;x++){
        	grid[y][x] = ' ';
        }
    }
    // draw the axis
    for(y=0;y<HEIGHT;y++) grid[y][X] = '|';
    for(x=0;x<WIDTH;x++) grid[Y][x] = '-';
    grid[Y][X] = '+';
}

// display grid
void show_grid(void){
    int x,y;
    for(y=0;y<HEIGHT;y++){
        for(x=0;x<WIDTH;x++) putchar(grid[y][x]);
        putchar('\n');
    }
}

void P0137_TODO(void){
	float t, t1,x,y,h1,h, Ho=100,Vo=20,g=9.81,ang=90, Vy, Vx, hmax, ttotal,dmax=0;
	init_grid();
	for(float i=ang;i>=0;i-=0.0001){
		Vx=Vo*cos((PI*i/180));
		Vy=Vo*sin(PI*i/180);
		t1=Vy*-1/g*-1;
		h1=Vy*t1-0.5*g*t1*t1;
		hmax=h1+100;
		ttotal= sqrt(hmax/(0.5*g)) + t1;
		if(dmax<Vx*ttotal) dmax=Vx*ttotal;
		for(t=ttotal;t>=0;t-=0.01){
			x=Vx*t;
			h=Ho+Vy*t-0.5*g*t*t;
			y=h;
			//plot(rintf(x),rintf(y));
		}
	}
	double lastY=0.0;
	double add = Vo * Vo / (2 * g) + Ho;
	double factor = -g / (2 * Vo * Vo);
	for(double x=0;y>=0;x+=0.001){
		y = factor * x * x + add;
		printf("y=%f\n",y);
		//getchar();

		double sliceHeight = lastY - y;
		double sliceVolume = PI * x * x * sliceHeight;
		lastY=y;
		plot(rintf(x),rintf(y));
	}
	show_grid();
    return;
}
