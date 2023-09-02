/*
 * Make sure to set TAB size in spaces by 4
 * File: task1_1.c
 * Author: Mohamed Ali
 * Description: Just print "GRU".
 * Date: [8/12/2023]
 */

#include <stdio.h>
#include <stdlib.h>

void print_GRU(void);

int main()
{
    printf("\'GRU\' \n");
    printf("\n\n=======================================\n\n\n\n");
    print_GRU();
    return 0;
}

void print_GRU(void)
{
    int rows_count;
    int colmns_count;

    for(rows_count = 0; rows_count < 5; rows_count++)
    {
        for(colmns_count = 0; colmns_count < 22; colmns_count++)
        {
            if(0 == rows_count)
            {
                printf("*****   ****     *     *");
                break;
            }
            else if(1 == rows_count)
            {
                printf("*       *   *    *     *");
                break;
            }
            else if(2 == rows_count)
            {
                printf("*  **   ****     *     *");
                break;
            }
            else if(3 == rows_count)
            {
                printf("*   *   *   *    *     *");
                break;
            }
            else if(4 == rows_count)
            {
                printf("*****   *    *   *******");
                break;
            }

        }
        printf("\n");

    }
    printf("\n");
}

