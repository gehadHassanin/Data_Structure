/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Enhanse_LinkedList.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 * Created on :  DES 6, 2023
 * Author     :  Gehad Hassanin
 *
 */

#ifndef ENHANCE_LINKED_LIST_H_
#define ENHANCE_LINKED_LIST_H_

#include "Global_config.h"


typedef struct node{

	ListEntry entry  ;
	struct node *next;
}Node_t;

typedef struct {

	u32    size ;
	u32    CurrentPosition ; // is index of The last place we went to
	Node_t *head ;
	Node_t *Current ;       // point to The last place we went to
}List_t;
#endif

/*****************************************************************/

/*
 * @brief : This function is used to intilize the List
 *
 * @para  : *pl => pointer to List
 *
 * @ret   : Nothing
 *
 */

void List_vidInit     ( List_t *pl                           ) ;




/*
 * @brief : This function is used to Insert a new element in any position ( 0 <= pos >= size )
 *
 * @para  :
 *               1-   *pl => pointer to List
 *               2-   e   => element that will be insert in the List
 *               3-   pos => is the index of the position where will the element will be inserted
 *
 * @ret   : Nothing
 *
 * @pre   : this List is initialized and not full
 *
 * @Note  : position must be -->  ( pos >= 0 && pos <= size )
 *
 */
void List_vidInsert     ( u32 pos, ListEntry e  , List_t *pl           ) ;




/************************************************************************************************/

/*
 * @brief : This function is used to Insert a new element in any position ( 0 <= pos >= size )
 *          ! and check if the memory has been successfully allocated or not
 *
 * @para  :
 *               1-   *pl => pointer to List
 *               2-   e   => element that will be insert in the List
 *               3-   pos => is the index of the position where will the element will be inserted
 *
 * @ret   : u8, return 1 => if the memory has been successfully allocated
 *         ! otherwise it will return => 0
 *
 * @pre   : this List is initialized and not full
 *
 * @Note  : ! this function used only in linked Implementation
 *          ! position must be -->  ( pos >= 0 && pos <= size )
 *
 */
u8  List_u8Insert    ( u32 pos, ListEntry e  , List_t *pl             ) ;

/**************************************************************************************************/




/*
 * @brief : This function is used to Delete the element from ( 0 <= pos >= size - 1 )
 *
 * @para  :
 *               1-   *pl  => pointer to List
 *               2-   *pe  => pointer to the place where the returned element will be stored
 *               3-   pos => is the index of the position where will the element will be deleted
 *
 * @ret   : Nothing
 *
 * @pre   : this List is initialized and not empty
 *
 * @Note  : position must be -->  ( pos >= 0 && pos <= size - 1 )
 *
 */
void List_vidDelete      ( u32 pos, ListEntry *pe, List_t *pl           ) ;




/*
 * @brief : This function is used to retrieve element from the list
 *
 * @para  :
 *               1-   *pl  => pointer to List
 *               2-   *pe  => pointer to the place where the last element will be stored
 *               3-   pos  => is the index of the position where will the element will be retrieved
 *
 * @ret   : Nothing
 *
 * @pre   : this List is initialized and not empty
 *
 * @Note  : position must be -->  ( pos >= 0 && pos <= size - 1 )
 *
 */
void List_vidRetrieve   ( u32 pos, ListEntry *pe, List_t *pl           ) ;



/*
 * @brief : This function is used to retrieve element from the list
 *
 * @para  :
 *               1-   *pl => pointer to List
 *               2-   e   => The element we will replace the element in the list with it
 *               3-   pos => is the index of the position where will the element will be stored replace the other element
 *
 * @ret   : Nothing
 *
 * @pre   : this List is initialized and not empty
 *
 * @Note  : position must be -->  ( pos >= 0 && pos <= size - 1 )
 *
 */
void List_vidReplace   ( u32 pos, ListEntry e, List_t *pl           ) ;




/*
 * @brief : This function is used to clear the data of the List
 *
 * @para  :
 *               1-   *pl  => pointer to List
 *
 * @ret   : Nothing
 *
 */
void List_vidClear    ( List_t *pl                           ) ;




/*
 * @brief : This function is used to visit each element in the List
 *
 * @para  :
 *               1-   *pl  => pointer to List
 *               2-   *pf  => pointer to function takes element of ListEntry & return Nothing
 *
 * @ret   : Nothing
 *
 * @pre   : the List is initialized
 *
 */
void List_vidTraverse ( List_t *pl, void (*pf) (ListEntry) ) ;




/*
 * @brief : This function is used to check the List full or not
 *
 * @para  :
 *               1-   *pl  => pointer to List
 *
 * @ret   : u8, return 1 => if full & return 0 => if not full
 *
 */
u8  List_IsFull  ( List_t *pl ) ;




/*
 * @brief : This function is used to check the List empty or not
 *
 * @para  :
 *               1-   *pl  => pointer to List
 *
 * @ret   : u8, return 1 => if empty & return 0 => if not empty
 *
 */
u8  List_IsEmpty ( List_t *pl ) ;




/*
 * @brief : This function is used to find size of the List
 *
 * @para  :
 *               1-   *pl  => pointer to List
 *
 * @ret   : u32, return size of the List
 *
 */
u32 List_GetSize ( List_t *pl ) ;





