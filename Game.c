#include <stdio.h>
#include "Game.h"

void zero_board( char grid[3][3] )
{
    
    for( int i = 0; i < 3; i++ )
    {
        for( int j = 0; j < 3; j++ )
        {
            grid[i][j] = ' ';
        }
    }
}

void print_board( char grid[3][3] )
{

    printf("\n%7c C%-4c %4cC%-5c%4cC%-5c\n",' ','0',' ','1',' ','2');
    printf("-----------------------------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("R%d ", i);
        printf("%2s", "|");
        
        for (int j = 0; j < 3; j++)
        {
            printf("%5c", grid[i][j]);   // 5 spaces, then |
            printf("%5s", "|");
        }
        printf("\n-----------------------------------\n");
    }
}

void start_game( char grid[3][3] )
{
    int row, col, C = 0;

    do
    {
        C++;

        if( C % 2 ) // Player 1 move
        {
            printf("Player X Turn ---> Enter row and col: ");
            scanf("%d", &row);
            getchar();
            scanf("%d", &col);
            getchar();

            if( valid_move( row, col, grid) )
            {
                grid[row][col] = 'X';
                print_board( grid );
            }
            else
            {
                C--;
                printf("\nInvalid Move, Please try again\n\n");
            }

            if( Win_check( grid ) )
            {
                printf("Player X won, Wohooo!\n");
                break;
            }
        }

        else // Player 2 move
        {
            printf("Player O Turn ---> Enter row and col: ");
            scanf("%d %d", &row, &col);
            getchar();

            if( valid_move( row, col, grid) )
            {
                grid[row][col] = 'O';
                print_board( grid );
            }
            else
            {
                C--;
                printf("\nInvalid Move, Please try again\n\n");
            }

            if( Win_check( grid ) )
            {
                printf("Player O won, Wohoo!\n");
                break;
            }
        }

        if( C == 9 )
        {
            printf("Oh noo, It's a draw\n");
            break;
        }

    } while(1);
}

int valid_move( int row, int col, char grid[3][3] )
{
    if( row < 0 || col < 0 || row > 2 || col > 2 ) // If outof bound
    {
        return 0;
    }
    else if( grid[row][col] != ' ' ) // If already entered row
    {
        return 0;
    }
    else
        return 1; // Valid move
}

int Win_check( char grid[3][3] )
{
    // Row wise check
    for( int i = 0; i < 3; i++ )
    {
        if( ( grid[i][0] != ' ' ) && ( grid[i][0] == grid[i][1]) && (grid[i][0] == grid[i][2] ) )
            return 1;
    }

    // Coloumn wise check
    for( int j = 0; j < 3; j++ )
    {
        if( ( grid[0][j] != ' ' ) && ( grid[0][j] == grid[1][j]) && (grid[0][j] == grid[2][j] ) )
            return 1;
    }

    // Primary Diagonal check ( top left to bottom right )
    if(( grid[0][0] != ' ' ) && ( grid[0][0] == grid[1][1]) && (grid[0][0] == grid[2][2] ) )
        return 1;

    // Anti Diagonal check ( Top right to bottom left )
    else if(( grid[0][2] != ' ' ) && ( grid[0][2] == grid[1][1]) && (grid[0][2] == grid[2][0] ) )
        return 1;
    
    // If no matches
    return 0;
}