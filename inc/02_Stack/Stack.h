/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Stack.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 * Created on :  DES 4, 2023
 * Author     :  Gehad Hassanin
 *
 */

#ifndef STACK_H_
#define STACK_H_

#include "Global_config.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Array based Implementation  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#if TYPE_BASED ==  ARRAY_BASED

/*
 *   $ Stack_t members :
 *                       1- top               ==> is the index of the first available place
 *                       2- entry [MAX_STACK] ==> array of the data in the stack
 *
 */
typedef struct {

	u32 top ;
	StackEntry entry [MAX_STACK];

}Stack_t;

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Linked based Implementation  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#elif  TYPE_BASED ==  LINKED_BASED

typedef struct node {

	StackEntry entry ;
	struct node *next ;

}Node_t;

typedef struct {

	Node_t *top ;
	u32 size ;
}Stack_t;


#endif

/*****************************************************************/

/*
 * @brief : This function is used to intilize the Stack
 *
 * @para  : *ps => pointer to Stack
 *
 * @ret   : Nothing
 *
 */

void Stack_vidInit     ( Stack_t *ps                           ) ;




/*
 * @brief : This function is used to push a new element on the top of the Stack
 *
 * @para  :
 *               1-   *ps => pointer to Stack
 *               2-   e   => element that will be pushed in the Stack
 *
 * @ret   : Nothing
 *
 * @pre   : this Stack is initialized and not full
 *
 * @post  : the element e has been stored at the top of the Stack
 *
 */
void Stack_vidPush     ( StackEntry e  , Stack_t *ps           ) ;




/************************************************************************************************/

/*
 * @brief : This function is used to push a new element at the top of the Stack
 *          ! and check if the memory has been successfully allocated or not
 *
 * @para  :
 *               1-   *ps => pointer to Stack
 *               2-   e   => element that will be push in the Stack
 *
 * @ret   : u8, return 1 => if the memory has been successfully allocated
 *         ! otherwise it will return => 0
 *
 * @pre   : this Stack is initialized and not full
 *
 * @Note  : this function used only in linked Implementation
 *
 */
u8  Stack_u8Push    ( StackEntry e  , Stack_t *ps             ) ;

/**************************************************************************************************/




/*
 * @brief : This function is used to pop the last element from the top of the Stack
 *
 * @para  :
 *               1-   *ps  => pointer to Stack
 *               2-   *pe  => pointer to the place where the last element will be stored
 *
 * @ret   : Nothing
 *
 * @pre   : this Stack is initialized and not empty
 *
 * @post  : the last element entered is returned
 *
 */
void Stack_vidPop      ( StackEntry *pe, Stack_t *ps           ) ;




/*
 * @brief : This function is used to retrieve the top entry off the Stack
 *
 * @para  :
 *               1-   *ps  => pointer to Stack
 *               2-   *pe  => pointer to the place where the last element will be stored
 *
 * @ret   : Nothing
 *
 * @pre   : this Stack is initialized and not empty
 *
 * @post  : the last element entered is returned
 *
 */
void Stack_vidGetTop   ( StackEntry *pe, Stack_t *ps           ) ;




/*
 * @brief : This function is used to clear the data of the Stack
 *
 * @para  :
 *               1-   *ps  => pointer to Stack
 *
 * @ret   : Nothing
 *
 */
void Stack_vidClear    ( Stack_t *ps                           ) ;




/*
 * @brief : This function is used to visit each element in the Stack
 *
 * @para  :
 *               1-   *ps  => pointer to Stack
 *               2-   *pf  => pointer to function takes element of StackEntry & return Nothing
 *
 * @ret   : Nothing
 *
 * @pre   : the Stack is initialized
 *
 */
void Stack_vidTraverse ( Stack_t *ps, void (*pf) (StackEntry) ) ;




/*
 * @brief : This function is used to check the Stack full or not
 *
 * @para  :
 *               1-   *ps  => pointer to Stack
 *
 * @ret   : u8, return 1 => if full & return 0 => if not full
 *
 */
u8  Stack_IsFull  ( Stack_t *ps ) ;




/*
 * @brief : This function is used to check the Stack empty or not
 *
 * @para  :
 *               1-   *ps  => pointer to Stack
 *
 * @ret   : u8, return 1 => if empty & return 0 => if not empty
 *
 */
u8  Stack_IsEmpty ( Stack_t *ps ) ;




/*
 * @brief : This function is used to find size of the Stack
 *
 * @para  :
 *               1-   *ps  => pointer to Stack
 *
 * @ret   : u32, return size of the Stack
 *
 */
u32 Stack_GetSize ( Stack_t *ps ) ;
#endif // STACK_H_




