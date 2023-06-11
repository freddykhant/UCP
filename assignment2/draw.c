#include <stdio.h>
#include <stdlib.h>
#include "setup.h"
#include "input.h"
#include "main.h"

int tailCount;
int tailX[100], tailY[100];

/*Function to draw the map*/
void draw()
{
	int i, j, k;
	system("clear"); /*Clears the terminal*/

	for (i = 0; i < width + 2; i++){ /*Draws boundary*/
		printf("*");
	}
	printf("\n");

	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){

			if (j == 0){ 
				printf("*");
			}
			else if(i == x && j == y){ /*Draws the head of the snake, according to direction of movement*/
					switch(dir){
						case 1:
							printf("<");
							break;
						case 2:
							printf("v");
							break;
						case 3:  
							printf(">");
							break;
						case 4:
							printf("^");
							break;
						default:
							printf("%c", body[7]);
							break;
					}
			}
			else if(i == foodX && j == foodY){ /*Draws the food*/
				printf("@");
			}
			else
			{
				int print = 0;
				int tprint = 0;
				
				for (k = 0; k < tailCount; k++){ /*Draws the body of the snake according to direction of movement*/
					if(tailX[k] == i && tailY[k] == j){
						switch(dir){
							case 1:
								printf("-");
								break;
							case 2:
								printf("|");
								break;
							case 3:  
								printf("-");
								break;
							case 4:
								printf("|");
								break;
							default:
								printf("-");
								break;
							print = 1;
						}
					}
				}
				if(tailX[tailCount-1] == i && tailY[tailCount-1] == j){ /*Draws the tail fo the snake*/
						printf("#");
						tprint = 1;
				}
				if(print == 0 && tprint == 0){ /*Draws blank space for the map*/
					printf(" ");
				}
			}
			if(j == width-1){
				printf("*");
			}
		}
		printf("\n");
	}
	for (i = 0; i < width+2; i++){
		printf("*");
	}
	printf("\n");
	printf("food eaten: %d/%d", score, win); /*Displays the score count out of amount needed to win*/
	printf("\n");
}