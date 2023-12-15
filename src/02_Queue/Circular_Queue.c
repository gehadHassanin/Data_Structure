/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Circular_Queue.c  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 * Created on :  DES 5, 2023
 * Author     :  Gehad Hassanin
 *
 */


#include <stdlib.h>

#include "STD_TYPES.h"
#include "Global_config.h"
#include "Circular_Queue.h"


/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Array based Implementation  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#if TYPE_BASED == ARRAY_BASED

void CircularQueue_vidInit     ( Queue_t *pq                           )  {

	pq -> Front = 0 ;
	pq -> Rear = -1 ;
	pq -> Size =  0 ;
}

void CircularQueue_vidAppend    ( QueueEntry e  , Queue_t *pq           )  {

	pq -> Rear = ( pq -> Rear + 1 ) % MAX_QUEUE ;
	pq -> entry[pq -> Rear] = e ;
	pq -> Size++ ;
}

void CircularQueue_vidServe     ( QueueEntry *pe, Queue_t *pq           )  {

	*pe = pq -> entry[pq -> Front] ;
	pq -> Front = ( pq -> Front + 1 ) % MAX_QUEUE ;
	pq -> Size-- ;
}

void CircularQueue_vidGetTop   ( QueueEntry *pe, Queue_t *pq           ) {

   *pe = pq -> entry[pq -> Front] ;
}

void CircularQueue_vidClear    ( Queue_t *pq                           )  {

	pq -> Front = 0 ;
	pq -> Rear = -1 ;
	pq -> Size =  0 ;
}

void CircularQueue_vidTraverse ( Queue_t *pq, void (*pf) (QueueEntry) )  {

	u32 LOC_u32Size ;
	u32 LOC_u32Pos = pq -> Front ;
	for ( LOC_u32Pos; LOC_u32Size < pq -> Size; LOC_u32Size++ )  {

		(*pf) (pq -> entry[LOC_u32Pos]) ;
		LOC_u32Pos = ( LOC_u32Pos + 1) % MAX_QUEUE ;
	}
}

u8  CircularQueue_IsFull  ( Queue_t *pq ) {

	return ( pq -> Size == MAX_QUEUE ) ;
}

u8  CircularQueue_IsEmpty ( Queue_t *pq ) {

	return !pq -> Size ;
}

u32 CircularQueue_GetSize ( Queue_t *pq ) {

	return pq -> Size ;
}

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Linked based Implementation  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#elif TYPE_BASED == LINKED_BASED

void CircularQueue_vidInit     ( Queue_t *pq                           ) {

	pq -> Front = NULL ;
	pq -> Rear  = NULL ;
	pq -> Size  = 0 ;
}

void CircularQueue_vidAppend    ( QueueEntry e  , Queue_t *pq           ) {

	Node_t *pn = ( Node_t* )malloc( sizeof(Node_t) ) ;
	pn -> next = NULL ;
	pn -> entry = e ;

	if ( !pq -> Rear ) {
		pq -> Front = pn ;
	}

	else {
		pq -> Rear -> next = pn ;
	}

	pq -> Rear = pn ;
	pq -> Size++ ;
}

u8  CircularQueue_u8Append    ( QueueEntry e  , Queue_t *pq             ) {

	Node_t *pn = ( Node_t* )malloc( sizeof(Node_t) ) ;

	if ( !pn ) {
		return 0 ;
	}

	else {
		pn -> next = NULL ;
		pn -> entry = e ;

		if ( !pq -> Rear ) {
			pq -> Front = pn ;
		}

		else {
			pq -> Rear -> next = pn ;
		}

		pq -> Rear = pn ;
		pq -> Size++ ;
		return 1 ;
	}
}

void CircularQueue_vidServe     ( QueueEntry *pe, Queue_t *pq           ) {

	Node_t *pn = pq -> Front ;
	*pe = pn -> entry ;
	pq -> Front = pn -> next ;
	free( pn ) ;

	if ( ! pq -> Front ) {
		pq -> Rear = NULL ;
	}

	pq -> Size-- ;
}

void CircularQueue_vidGetTop   ( QueueEntry *pe, Queue_t *pq           ) {

    *pe = pq -> Front -> entry ;
}

void CircularQueue_vidClear    ( Queue_t *pq                           ) {

	while ( pq -> Front ) {

		pq -> Rear = pq -> Front -> next ;
		free ( pq -> Front ) ;
		pq -> Front = pq -> Rear ;
	}

	pq -> Size = 0 ;
}

void CircularQueue_vidTraverse ( Queue_t *pq, void (*pf) (QueueEntry) ) {

	Node_t *pn = pq -> Front ;

	while ( pn ) {

		(*pf) ( pn -> entry ) ;
		pn = pn -> next ;
	}
}

u8  CircularQueue_IsFull  ( Queue_t *pq ) {

	return 0 ;
}

u8  CircularQueue_IsEmpty ( Queue_t *pq ) {

	return !pq -> Front ;
}

u32 CircularQueue_GetSize ( Queue_t *pq ) {

	return pq -> Size ;
}
#endif