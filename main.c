/*
 * Make sure to set TAB size in spaces by 4
 * File: task3_3.c
 * Author: Mohamed Ali
 * Description: simple to-do list.
 * Date: [8/12/2023]
 */

 /* ========= VI ==========
  * This mechanism just works as a stack used in data structure mechanism so you can only remove the last added data
  * If any other data removed, View_data() function will not perform as desired.
  */

#include <stdio.h>
#include <stdlib.h>

#include "package.h"

package_t *Package1 = NULL; /*Hint: there is a problem faced me, if this pointer moved inside main function
                              let's say under Fun_Status for example
                              then it will always transfer to NULL pointer inside switch
                            */

int main()
{
    signed char TaskManger_index = 0;
    signed short RemovedTask_index = 0;
    unsigned short Fun_Status = 0;
    //
    printf("1. Add Task \n");printf("2. View Task \n");printf("3. Remove Task \n");printf("4. Exit\n");
    Package1 = CreatePackage(&Fun_Status); //allocate memory for package
                              //Fun_Status check if function performed as desired


    while(4 != TaskManger_index)
    {
        printf("\nSelect an option : ");
        scanf("%d", &TaskManger_index);
        getchar();//I spent around 2 hours to figure out that usage of scanf() before fgets()
                   //make series issues, and getchar() solve this issue (*__*).
        while( (TaskManger_index <= 0) || (TaskManger_index > 4) )
        {
                printf("Error !!, Re-Enter number from 1~4 : ");
                scanf("%d", &TaskManger_index);
        }
        switch (TaskManger_index)
        {
            case 1:
                Fun_Status = Push_data(Package1); //Fun_Status just a variable help me to debug code
                                                  //if any problem appeared
                break;

            case 2:
                Fun_Status = View_data(Package1);
                break;

            case 3:
                printf("Enter task ID to remove: ");
                scanf("%i", &RemovedTask_index);
                getchar();
                while((RemovedTask_index > Package1->Elem_Num) || (RemovedTask_index < 1))
                {
                    printf("UnKnown ID, re-try to enroll valid one : ");
                    scanf("%i", &RemovedTask_index);
                    getchar();
                }
                Fun_Status = Remove_data(Package1, RemovedTask_index);
                break;
        }

    }
    printf("\nExiting Minions Task Manager. Have a great day! \n");

    return 0;
}
