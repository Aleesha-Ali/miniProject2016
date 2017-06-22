#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "classOnOff.h"
#include "luckyNumber.h"

// Function declaration
void clearBuffer();


// main function is the entry point of the program
int main ( int argc, char *argv[] ){
	int example_to_run;
	char runAgainStatus;

    if ( argc != 3 ) /* argc should be 3 for correct execution */
    {
        printf("You did not specify the filename correctly. Correct usage should be as follows");
        printf( "\nusage: %s filename1 filename2", argv[0] );
    }
    else
    {
        printf("Welcome to ***** Project \n");
        do{
            printf("\nPlease select your choice: \n");
            printf("\n[1] - ClassOnOffExample \n[2] - ChutikiLuckyNumberExample. \n");
            scanf("%d", &example_to_run);
            switch(example_to_run){
                case 1:
                    system ("clear");
                    printf("\nOutput is :\n");
                    determineClassOnOff(argv[1]);
                    break;
                case 2:
                    system ("clear");
                    printf("\nOutput is :\n");
                    findLuckyNumber(argv[2]);
                    break;
                default:
                    printf("You did not enter a valid choice \n");
                    break;
            }

            printf("\n \nDo you want to continue? If yes than enter 'Y || y' else enter any other value to exit \n");
            clearBuffer();
            scanf(" %c", &runAgainStatus);
            system ("clear");
        }while(runAgainStatus == 'Y' || runAgainStatus == 'y' );
    }

	return 0;

} // End of main function

//This function is used for flushing-stdin-after-every-input
void clearBuffer(){
	int ch;
    while ((ch=getchar()) != EOF && ch != '\n');
}

void go_to_end_of_line(FILE *ip)
{ 	int c;
	while ((c = getc(ip)) != '\n' && c != EOF);
}
