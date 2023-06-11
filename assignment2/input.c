#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
#include "setup.h"

int dir; /*Declares variable for input direction*/

void input()
{
    /*Inputs a char from the user pressing a key*/
    char input;
    disableBuffer();
    scanf("%c", &input);
    enableBuffer();
    switch(input)
    {
        /*WASD key inputs controls direction of movement*/
        case 'a':
            dir = 1;
            break;
        case 's':
            dir = 2;
            break;
        case 'd':
            dir = 3;
            break;
        case 'w':
            dir = 4;
            break;
        case 'x':
            gameOver = 1;
            break;
    }
}