#include <stdio.h>
#include "Game.h"

int main()
{
    char grid[3][3]; int choice;

    printf("\n<----Welcome to Tic-Tac-Toe Game---->\n\n");
    
    zero_board( grid );
    print_board( grid );

    printf("Player 1: X\n");
    printf("Player 2: O\n");

    start_game( grid );

    do
    {
        printf("\nDo You Wish to Play Again\n"
                "1. Yes\n"
                "2. No\n"
                "Enter Choice( 1 or 2 ): ");
        scanf("%d", &choice);
        getchar();

        if( choice == 1 )
        {
            printf("\n<----Starting New Game---->\n\n");
            zero_board( grid );
            print_board( grid );
            start_game( grid );
        }
        else if(choice != 2)
        {
            printf("\nInvalid choice. Please enter 1 or 2.\n");
        }

    } while( choice != 2 );

    printf("\n<----Thank you for Playing! See you soon---->\n\n");
        return 0;
}