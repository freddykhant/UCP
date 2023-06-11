#include <stdio.h>
#include <stdlib.h>
#include "setup.h"
#include "draw.h"
#include "input.h"
#include "logic.h"
#include "random.h"

/*Declares variables to store data from file*/
int win, height, width;
int snakeX[8], snakeY[8];
char body[8];

/*Attempted* Declares linked list*/

/*struct node{
    int snakeX;
    int snakeY;
    char body;
    struct node *next;
};
typedef struct node node_s;*/

/*Attempted* function to create new nodes*/

/*node_s *new_node(int snakeX, int snakeY, char body){
    node_s *result1 = malloc(sizeof(node_s));
    node_s *result2 = malloc(sizeof(node_s));
    node_s *result3 = malloc(sizeof(node_s));
    result1->snakeX = snakeX;
    result2->snakeY = snakeX;
    result3->body = body;
}*/

int main(int argc, char *argv[]) 
{
    FILE* file;
    win = atoi(argv[2]); /*Win condition stored in win*/
    char lines[9];
    int cur_line = 0;

    /*Abort program with error message if less/more than 2 command line arguments*/
	if(argc < 3 || argc > 3){
        printf("Error: Invalid Number of Arguments\n");
        return 1;
	}
    /*Abort program with error message if entered win amount < 2*/
    else if(win < 2){
		printf("Error: Invalid Win Amount, Minimum is 2\n");
		return 1;
	}
    else
    {
        file = fopen(argv[1], "r"); /*Opens file in read mode*/
        if(file == NULL){ /*Aborts program with error message if given file does not exist*/
            printf("Error: Could not open file\n");
            return 1;
        }
        else{
            fscanf(file, "%d %d", &height, &width); /*Scans first line and stores them as height and width respectively*/

            /*Iterates through the file and scans the data storing them in arrays as elements*/
            while(fgets(lines, sizeof(lines), file) != NULL){
                if(fscanf(file, "%d %d %c", &snakeX[cur_line], &snakeY[cur_line], &body[cur_line]) == 4){
                    cur_line++;
                }
            }
            fclose(file);

            /*Attempted creates new nodes with appropriate data and links them*/ 

            /*node_s *head;
            node_s *tmp;
            tmp = new_node(snakeX[0], snakeY[0], body[0]);
            head = tmp;
            for(int i = 1; i < 8; i++){
                tmp = new_node(snakeX[i], snakeY[i], body[i]);
                tmp->next = head;
                head = tmp;    
            }*/
        
            /*Sets the game up*/
		    initRandom(); 
		    setup(); 
		    while (gameOver != 1) 
            {
                draw();
			    input();
			    logic();
		    }
        }
	}
	return 0;
}