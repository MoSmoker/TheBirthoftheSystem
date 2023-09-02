/*
 * Make sure to set TAB size in spaces by 4
 * File: task2_2.c
 * Author: Mohamed Ali
 * Description: takes number from user as an input and starts
                countdown and prints the sequence of numbers starting
                from that entered number.
 * Date: [8/12/2023]
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    signed int value = 0; //variable that the number from the user will set in
    //
    printf("Enter any positive number : ");
    scanf("%d", &value);
    printf("\n\n");

    while(value<0)
    {
        printf("Error!, re-enter the number [Remember positive number] : ");
        scanf("%d", &value);
    }
    if(0 == value)
    {
        printf("Blast off to the moon! \n"); //no positive number == no sequence
    }
    else
    {
        while(value > 0)
        {
            printf(" %d \n", value);
            value--; //VI: if this line eliminated, program will crash [infinite loop]
            Sleep(1000);
        }
        printf(" Blast off to the moon! \n");
    }
    return 0;
}
