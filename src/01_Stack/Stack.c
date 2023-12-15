/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Stack.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 * Created on :  DES 4, 2023
 * Author     :  Gehad Hassanin
 *
 */

#include "STD_TYPES.h"
#include "Global_config.h"
#include "Stack.h"

#include "stdlib.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Array based Implementation   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#if TYPE_BASED ==  ARRAY_BASED

void Stack_vidInit     ( Stack_t *ps                           )  {

	ps -> top = 0 ;
}

void Stack_vidPush     ( StackEntry e  , Stack_t *ps           )  {

	ps -> entry[ps -> top++] = e ;
}

void Stack_vidPop      ( StackEntry *pe, Stack_t *ps           )  {

	*pe = ps -> entry[--ps -> top] ;
}

void Stack_vidGetTop   ( StackEntry *pe, Stack_t *ps           )  {

	*pe = ps -> entry[ps -> top - 1] ;
}

void Stack_vidClear    ( Stack_t *ps                           )  {

	ps -> top = 0 ;
}

void Stack_vidTraverse ( Stack_t *ps, void (*pf) (StackEntry) )  {

	u32 LOC_u32Iterator = ps -> top ;
	for ( LOC_u32Iterator; LOC_u32Iterator > 0; LOC_u32Iterator-- ) {

		(*pf) ( ps -> entry[LOC_u32Iterator - 1]) ;
	}
}

u8  Stack_IsFull  ( Stack_t *ps                                )  {

	return ps -> top == MAX_STACK ;
}

u8  Stack_IsEmpty ( Stack_t *ps                                )  {

	return !ps -> top ;
}

u32 Stack_GetSize ( Stack_t *ps                                )  {

	return ps -> top ;
}

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Linked based Implementation  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#elif  TYPE_BASED ==  LINKED_BASED

void Stack_vidInit     ( Stack_t *ps                           ) {

	ps -> top = NULL ;
	ps -> size = 0 ;
}

void Stack_vidPush     ( StackEntry e  , Stack_t *ps           ) {

	Node_t *pn = ( Node_t* )malloc( sizeof(Node_t) ) ;
	pn -> entry = e ;
	pn -> next = ps -> top ;
	ps -> top = pn ;
	ps -> size++ ;
}

u8  Stack_u8Push    ( StackEntry e  , Queue_t *ps             )  {
	
	Node_t *pn = ( Node_t* )malloc( sizeof(Node_t) ) ;
	
	if ( !pn ) {
		 return 0 ;
	}
	
	else {
		pn -> entry = e ;
		pn -> next = ps -> top ;
		ps -> top = pn ;
		ps -> size++ ;
		return 1 ;
	}
}

void Stack_vidPop      ( StackEntry *pe, Stack_t *ps           ) {

	Node_t *pn ;
	*pe = ps -> top -> entry ;
	pn = ps -> top ;
	ps -> top = pn -> next ;
	free ( pn ) ;
	ps -> size--;
}

void Stack_vidGetTop   ( StackEntry *pe, Stack_t *ps           ) {

	*pe = ps -> top -> entry ;
}

void Stack_vidClear    ( Stack_t *ps                           ) {

	Node_t *pn = ps -> top ;
	while ( pn ) {

		pn = pn -> next ;
		free ( ps -> top ) ;
		ps -> top = pn ;
	}

	ps -> size = 0 ;
}

void Stack_vidTraverse ( Stack_t *ps, void (*pf) (StackEntry) ) {

	Node_t *pn = ps -> top ;
	while ( pn ) {

		(*pf) ( pn -> entry ) ;
		pn = pn -> next ;
	}
}

u8  Stack_IsFull  ( Stack_t *ps                                ) {

	return 0;
}

u8  Stack_IsEmpty ( Stack_t *ps                                ) {

	return !ps -> top ;
}

u32 Stack_GetSize ( Stack_t *ps                                ) {

	return ps -> size ;
}
#endif

