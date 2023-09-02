#include <stdio.h>
#include <stdlib.h>

#include "package.h"

/**
  * @brief create object from struct package_t and return it's address
  *
  * @param  Ret_Status, pointer point to status of function to know it's performance.
  * @retval address for created object
  */

package_t *CreatePackage(unsigned short *Ret_Status)
{
    package_t *my_obje;

    my_obje = (package_t *)malloc(sizeof(package_t));
    if(NULL == my_obje)
    {
        printf("Error!!, memory did not allocate \n");
        *Ret_Status = NULL_Pointer;
    }
    else
    {
        /*I assumed that max number of tasks is 30 task for simplification
          but it can be an input take from user */
        my_obje->Pack_Array = (char **)calloc(30, sizeof(void *));
        if(NULL == my_obje->Pack_Array)
        {
            free(my_obje);
            *Ret_Status = R_NOK;
        }
        else
        {
            my_obje->Elem_Num = 0;
            my_obje->index = -1; //index = -1 means that package is empty
            *Ret_Status = R_OK;
        }
    }
    return(my_obje);
}

/**
  * @brief add data to package
  *
  * @param  package, pointer point to object created from package_t struct.
  * @retval status of function to declare it's performance.
  */

unsigned short Push_data(package_t *package)
{
    unsigned short Ret_Status = 0;

    if(NULL == package)
    {
        printf("Error!!, memory did not allocate, exist Null pointer as a parameter \n");
        Ret_Status = NULL_Pointer;
    }
    else
    {
        if(30 == package->Elem_Num)
        {
            printf("Max number of tasks!, please remove task first to add new one \n");
            Ret_Status = Pack_Full;
        }
        else
        {
            (package->Elem_Num)++;
            (package->index)++;
            printf("Enter task description: ");
            package->Pack_Array[package->index] = fgets(calloc(50, sizeof(char)), 50, stdin);
            /*I did not use normal array because I need to allocate different memory each time
              user choose pushing a data, so calloc will do this for me, also I assumed that make
              size for one task is just 50 character */
            Ret_Status = R_OK;
            printf("Task added successfully! \n\n");
        }
    }
    return(Ret_Status);
}

/**
  * @brief remove Tasks from package
  *
  * @param  package, pointer point to object created from package_t struct.
  * @param  Task_index, Task index desired to be removed.
  * @retval status of function to declare it's performance.
  */

unsigned short Remove_data(package_t *package, signed char Task_index)
{
    unsigned short Ret_Status = 0;

    if(NULL == package)
    {
        printf("Error!!, memory did not allocate, exist Null pointer as a parameter \n");
        Ret_Status = NULL_Pointer;
    }
    else
    {
        if(0 == package->Elem_Num)
        {
            printf("Empty!!, there is no tasks to remove \n");
            Ret_Status = Pack_Empty;

        }
        else
        {
            free(package->Pack_Array[Task_index-1]);
            (package->Elem_Num)--;
            package->index--;
            Ret_Status = R_OK;
            printf("Task removed successfully!\n\n");
        }
    }
    return(Ret_Status);
}

/**
  * @brief View data added to package
  *
  * @param  package, pointer point to object created from package_t struct.
  * @retval status of function to declare it's performance
  */

unsigned short View_data(package_t *package)
{
    unsigned short Ret_Status = 0;

    if(NULL == package)
    {
        printf("Error!!, memory did not allocate, exist Null pointer as a parameter \n");
        Ret_Status = NULL_Pointer;
    }
    else
    {
        if(0 == package->Elem_Num)
        {
            printf("Empty!!, there is no tasks to show \n");
            Ret_Status = Pack_Empty;
        }
        else
        {
            printf("\nCurrent Tasks = %i \n\n", package->Elem_Num);
            for(int counter = 0; counter < package->Elem_Num; counter++)
            {
                printf("Task ID: %i \n", counter+1);
                printf("Description: %s \n\n", package->Pack_Array[counter]);
            }
            Ret_Status = R_OK;
        }
    }

    return(Ret_Status);
}
