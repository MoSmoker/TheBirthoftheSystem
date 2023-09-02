#ifndef _PACKAGE_H
#define _PACKAGE_H

#define R_NOK 0
#define R_OK  1
#define Pack_Full  2
#define Pack_Empty 3
#define NULL_Pointer 4

typedef struct
{
    char **Pack_Array;
    signed short index;
    unsigned short Elem_Num; //number of elements in package

}package_t;


/**
  * @brief create object from struct package_t and return it's address
  *
  * @param  Ret_Status, pointer point to status of function to know it's performance.
  * @retval address for created object
  */
package_t *CreatePackage(unsigned short *Ret_Status);

/**
  * @brief add data to package
  *
  * @param  package, pointer point to object created from package_t struct.
  * @retval status of function to declare it's performance.
  */
unsigned short Push_data(package_t *package);

/**
  * @brief remove Tasks from package
  *
  * @param  package, pointer point to object created from package_t struct.
  * @param  Task_index, Task index desired to be removed.
  * @retval status of function to declare it's performance.
  */
unsigned short Remove_data(package_t *package, signed char Task_index);

/**
  * @brief View data added to package
  *
  * @param  package, pointer point to object created from package_t struct.
  * @retval status of function to declare it's performance
  */
unsigned short View_data(package_t *package);


#endif // _PACKAGE_H
