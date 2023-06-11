#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "random.h"
#include "terminal.h"

int i, j, k, gameOver, score;
int height = 30, width = 30;
int x, y, foodX, foodY, flag;
int tailCount, tailX[100], tailY[100];

/* Function to draw the border */

void draw() 
{
	system("clear");

	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			if (i == 0 || i == width-1 || j == height-1 || j == 0){
				printf("*");
			}
			else if (i == x && j == y){
			       printf(">");
			}
			else if (foodX == i && foodY == j){
			       printf("@");
			}
			else {
				int blank = 0;
				for (k = 0; k < tailCount; k++){
					if (tailX[k] == i && tailY[k] == j){
						printf("-");
						blank = 1;
					}
				}
				if (blank == 0){
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	printf("Score: %d", score);
}

/* Function to spawn food at random point */ 

void setUp()
{
	x = height/2;
	y = width/2;
	score = 0;

	do {
		foodX = random(0, width);
       	 	foodY = random(0, height);
	} while (foodX <= 0 || foodY <= 0 || foodX == x || foodY == y || foodX > height || foodY > width);
}

/* Allows the user to input and move the snake using WASD keys */

void input()
{
	char input;
	disableBuffer();
	scanf("%c", &input);
	enableBuffer();
	switch (input){
		case 'w': 
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'a':
			flag = 3;
			break;
		case 'd':
			flag = 4;
			break;
		case 'x':
			gameOver = 1;
			break;
		}
}

/* Provides the logic and rules for the games and how the game flow is manipulated */

void logic()
{
	int lastX = tailX[0];
	int lastY = tailY[0];
	int last2X, last2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (i = 1; i < tailCount; i++){
		last2X = tailX[i];
		last2Y = tailY[i];
		tailX[i] = lastX;
		tailY[i] = lastY;
		lastX = last2X;
		lastY = last2Y;
	}

	switch(flag){
		case 1:
			x--;
			break;
		case 2:
			x++;
			break;
		case 3:
			y--;
			break;
		case 4:
			y++;
			break;
		default:
			break;
	}
	for (i = 0; i < tailCount; i++){
		if (tailX[i] == x && tailY[i] == y) {
			gameOver = 1;
		}
	}
	if (x > width-1 || y > height-1 || x < 0 || y < 0){
		gameOver = 1;
	}
	if (x == foodX && y == foodY){
		score += 1;
		tailCount++;
		restart:
		foodX = random(0, width);
                foodY = random(0, height);
		if (foodX <= 0 || foodY <= 0 || foodX == x || foodY == y || foodX > height || foodY > width);
		goto restart;
	}
}

/* Driver function that also allows command line arguments */

int main(int argc, char** argv)
{
	width = atoi(argv[0]);
	height = atoi(argv[1]);
	initRandom();
	setUp();
	while (gameOver != 1){
		draw();
		logic();
		input();
	}
	return 0;
}
