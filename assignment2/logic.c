#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "setup.h"
#include "draw.h"
#include "random.h"
#include "main.h"

void logic()
{
    /*Declares the variables needed for the snake updating algorithm*/
    int i, lastX, lastY, last2X, last2Y;

    /*Snake updating system*/
    lastX = tailX[0];
    lastY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;

    for(i = 1; i < tailCount; i++){
        last2X = tailX[i];
        last2Y = tailY[i];
        tailX[i] = lastX;
        tailY[i] = lastY;
        lastX = last2X;
        lastY = last2Y;
    }
    switch(dir) /*Takes the direction from input, and updates coordinates of snake for movement*/
    {
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y++;
            break;
        case 4:
            x--;
            break;
        default:
            break;
    }
    if (score >= win){ /*Ends game if player meets win condition and prints win statement*/
        printf("You won!");
        gameOver = 1;
    }

    /*Allows snake to move through walls and loop around opposite side*/
    if (x >= height) x = 0; else if (x < 0) x = height - 1;
    if (y >= width) y = 0; else if (y < 0) y = width - 1;
    
    /*Ends the game if snake head hits tail*/
    for (i = 0; i < tailCount; i++){
        if(tailX[i] == x && tailY[i] == y){
            gameOver = 1;
        }
    }
    /*Updates score and tail length and respawns food at random location if snake eats food*/
    if (x == foodX && y == foodY){
        score += 1;
        foodX = random(1, width-1);
        foodY = random(1, height-1-1);
        tailCount++;
    }
}