#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "random.h"
#include "main.h"

/*Declares variables needed for the set up of the game*/
int gameOver, x, y, score, foodX, foodY;

void setup()
{	
	gameOver = 0;
	x = snakeX[7];
	y = snakeY[7];
	score = 0;

	/*Spawns food at random coordinates on the map, within boundary*/
	foodX = random(1, width-1);
	foodY = random(1, height);
}
