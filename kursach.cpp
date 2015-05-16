#include "graphics\graphics.h"
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void *img[10];
int curr[18];
const int SIZE_C = 18;

struct pt{
	int x, y;
	pt(int x, int y){
		this->x = x;
		this->y = y;
	};
	pt(){};
};

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
	return;
}

void shuffle(){
	srand(time(NULL));
	int k = 1;
	for (int i = 0; i < SIZE_C; i += 2){
		curr[i] = k;
		curr[i + 1] = k;
		k++;
	}
	for (int i = 0; i < SIZE_C; i++)
		swap(&curr[i], &curr[rand() % SIZE_C]);
}

void loadIMG(){
	img[0] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\0.jpg");
	img[1] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\1.jpg");
	img[2] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\2.jpg");
	img[3] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\3.jpg");
	img[4] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\4.jpg");
	img[5] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\5.jpg");
	img[6] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\6.jpg");
	img[7] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\7.jpg");
	img[8] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\8.jpg");
	img[9] = loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\9.jpg");
}

pt getc(){
	int x, y;
	for (int i = 72; i < 506; i += 148)
	for (int j = 83; j < 900; j += 161){
		x = mousex(), y = mousey();
		if (y >= i && y <= i + 127 && x >= j && x <= j + 100)
			return pt((j-83)/161 + 1, (i - 72)/148 + 1);
	}
	return pt(-1, -1);
}

void putRub(){
	for (int i = 72; i < 506; i+= 148)
	for (int j = 83; j < 900; j += 161)
		putimage(j, i, img[0], 0);
}

void showIMG(int n, int x, int y){
	putimage(83 + (x - 1) * 161, 72 + (y - 1) * 148, img[n], 0);
	return;
}

int main(){
	shuffle();
	initwindow(1056, 595, "Найди пару");
	putimage(0, 0, loadBMP("C:\\Users\\Freeman\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\back.jpg"), 0);
	loadIMG();
	putRub();
	int st = 0, lst = 0;
	pt lpos;
	while (1){
		switch (st)
		{
		case 0:
			if (ismouseclick(WM_LBUTTONUP)){
				pt tm = getc();
				if (tm.x != -1 && tm.y != -1){
					showIMG(curr[(6 * (tm.y - 1)) + tm.x - 1], tm.x, tm.y);
					lst = curr[(6 * (tm.y - 1)) + tm.x - 1];
					lpos = tm;
								st = 1;
				}
				clearmouseclick(WM_LBUTTONUP);
				clearmouseclick(WM_LBUTTONDOWN);
			}
			break;
		case 1:
			if (ismouseclick(WM_LBUTTONUP)){
				pt tm = getc();
				if (tm.x != -1 && tm.y != -1){
					showIMG(curr[(6 * (tm.y - 1)) + tm.x - 1], tm.x, tm.y);
					if (curr[(6 * (tm.y - 1)) + tm.x - 1] != lst){
						Sleep(2000);
						showIMG(0, tm.x, tm.y);
						showIMG(0, lpos.x, lpos.y);
						st = 0;
					}
					else st = 0;
				}
				clearmouseclick(WM_LBUTTONUP);
				clearmouseclick(WM_LBUTTONDOWN);
			}
			break;
		default:
			break;
		}
	}
	getch();
	return 0;
}