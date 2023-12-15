/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Circular_Queue.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 * Created on :  DES 5, 2023
 * Author     :  Gehad Hassanin
 *
 */

#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_

#include "Global_config.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Array based Implementation  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#if TYPE_BASED == ARRAY_BASED

/*
 *   $ Queue_t members : 
 *                       1- Front            ==> is the index of the first place to be served
 *                       2- Rear             ==> is the index of The last place we append the data 
 *                       3- entry[MAX_QUEUE] ==> array of the data in the Queue
 *                     
 */
typedef struct  {
	
	u32 Front ;
	u32 Rear  ;
	u32 Size  ;
	QueueEntry entry[MAX_QUEUE] ;
}Queue_t;

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Linked based Implementation  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#elif TYPE_BASED == LINKED_BASED

typedef struct node {
	
	QueueEntry  entry ;
	struct node *next ;
}Node_t;

typedef struct {
	
	Node_t *Front ;
	Node_t *Rear  ;
	u32    Size   ;
}Queue_t;
#endif

/*****************************************************************/

/*
 * @brief : This function is used to intilize the Queue
 *
 * @para  : *pq => pointer to Queue
 *
 * @ret   : Nothing
 *
 */

void CircularQueue_vidInit     ( Queue_t *pq                           ) ;



/*
 * @brief : This function is used to append a new element at the top of the Queue
 *
 * @para  :
 *               1-   *pq => pointer to Queue
 *               2-   e   => element that will be append in the Queue
 *
 * @ret   : Nothing
 *
 * @pre   : this Queue is initialized and not full
 *
 */
void CircularQueue_vidAppend    ( QueueEntry e  , Queue_t *pq           ) ;




/************************************************************************************************/                                                                                             

/*
 * @brief : This function is used to append a new element at the top of the Queue
 *          ! and check if the memory has been successfully allocated or not 
 *          
 * @para  :
 *               1-   *pq => pointer to Queue
 *               2-   e   => element that will be append in the Queue
 *
 * @ret   : u8, return 1 => if the memory has been successfully allocated
 *         ! otherwise it will return => 0
 *
 * @pre   : this Queue is initialized and not full
 *
 * @Note  : this function used only in linked Implementation
 */
u8  CircularQueue_u8Append    ( QueueEntry e  , Queue_t *pq             ) ;

/**************************************************************************************************/




/*
 * @brief : This function used to retrieve the front entry in the Queue 
 *
 * @para  :
 *               1-   *pq  => pointer to Queue
 *               2-   *pe  => pointer to the place where the front entry in the Queue will be stored
 *
 * @ret   : Nothing
 *
 * @pre   : this Queue is initialized and not empty
 *
 */
void CircularQueue_vidServe      ( QueueEntry *pe, Queue_t *pq           ) ;




/*
 * @brief : This function is used to clear the data of the  Queue
 *
 * @para  :
 *               1-   *pq  => pointer to Queue
 *
 * @ret   : Nothing
 *
 */
void CircularQueue_vidClear    ( Queue_t *pq                           ) ;




/*
 * @brief : This function is used to visit each element in the Queue
 *
 * @para  :
 *               1-   *pq  => pointer to Queue
 *               2-   *pf  => pointer to function takes element of QueueEntry & return Nothing
 *
 * @ret   : Nothing
 *
 * @pre   : the Queue is initialized
 *
 */
void CircularQueue_vidTraverse ( Queue_t *pq, void (*pf) (QueueEntry) ) ;




/*
 * @brief : This function is used to check the Queue full or not
 *
 * @para  :
 *               1-   *pq  => pointer to Queue
 *
 * @ret   : u8, return 1 => if full & return 0 => if not full
 *
 */
u8  CircularQueue_IsFull  ( Queue_t *pq ) ;




/*
 * @brief : This function is used to check the Queue empty or not
 *
 * @para  :
 *               1-   *pq  => pointer to Queue
 *
 * @ret   : u8, return 1 => if empty & return 0 => if not empty
 *
 */
u8  CircularQueue_IsEmpty ( Queue_t *pq ) ;




/*
 * @brief : This function is used to find size of the Queue
 *
 * @para  :
 *               1-   *pq  => pointer to Queue
 *
 * @ret   : u32, return size of the Queue
 *
 */
u32 CircularQueue_GetSize ( Queue_t *pq ) ;

#endif /* QUEUE_H_ */