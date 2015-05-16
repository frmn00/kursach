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
	img[0] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\0.jpg");
	img[1] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\1.jpg");
	img[2] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\2.jpg");
	img[3] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\3.jpg");
	img[4] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\4.jpg");
	img[5] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\5.jpg");
	img[6] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\6.jpg");
	img[7] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\7.jpg");
	img[8] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\8.jpg");
	img[9] = loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\9.jpg");
}

pt getc(){
	int x, y;
	if (ismouseclick(WM_LBUTTONUP)){
		//x = 
	}
	return pt(0, 0);
}

void putIMG(){
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
	putimage(0, 0, loadBMP("C:\\Users\\Sony\\Documents\\Visual Studio 2013\\Projects\\kursach\\kursach\\img\\back.jpg"), 0);
	loadIMG();
	putIMG();
	getch();
	return 0;
}