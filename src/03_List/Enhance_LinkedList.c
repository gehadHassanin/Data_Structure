/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Enhance_LinkedList.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 * Created on :  DES 6, 2023
 * Author     :  Gehad Hassanin
 *
 */

#include "STD_TYPES.h"
#include "Global_config.h"
#include "Enhance_LinkedList.h"

#include "stdlib.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Linked based Implementation  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */

void List_vidInit     ( List_t *pl                                     ) {

	pl -> head = NULL ;
	pl -> Current = NULL ;
	pl -> size = 0 ;
	pl -> CurrentPosition = 0 ;
}

void List_vidInsert   ( u32 pos, ListEntry e  , List_t *pl             ) {

	Node_t *pn = ( Node_t* )malloc( sizeof(Node_t) ) ;
	pn -> entry = e ;

	if ( pos == 0 ) {

		pn -> next = pl -> head ;
		pl -> head = pn ;
		pl -> CurrentPosition = 0 ;
		pl -> Current = pl -> head ;
	}

	else {

		if ( pos <= pl -> CurrentPosition ) {

			pl -> Current = pl -> head ;
			pl -> CurrentPosition = 0 ;
		}

		for ( pl -> CurrentPosition; pl -> CurrentPosition < pos - 1;  pl -> CurrentPosition++ ) {

			pl -> Current = pl -> Current -> next ;
		}

		pn -> next = pl -> Current -> next ;
		pl -> Current -> next = pn ;
	}

	pl -> size++ ;
}

u8  List_u8Insert        ( u32 pos, ListEntry e  , List_t *pl          )  {

	Node_t *pn = ( Node_t* )malloc( sizeof(Node_t) ) ;

	if ( !pn ) {

		return 0 ;
	}

	else {

		pn -> entry = e ;

		if ( pos == 0 ) {

			pn -> next = pl -> head ;
			pl -> head = pn ;
			pl -> CurrentPosition = 0 ;
			pl -> Current = pl -> head ;
		}

		else {

			if ( pos <= pl -> CurrentPosition ) {

				pl -> Current = pl -> head ;
				pl -> CurrentPosition = 0 ;
			}

			for ( pl -> CurrentPosition; pl -> CurrentPosition < pos - 1;  pl -> CurrentPosition++ ) {

				pl -> Current = pl -> Current -> next ;
			}

			pn -> next = pl -> Current -> next ;
			pl -> Current -> next = pn ;
		}

		pl -> size++ ;
		return 1 ;
	}
}
void List_vidDelete      ( u32 pos, ListEntry *pe, List_t *pl           )  {

	Node_t *temp ;

	if ( pos == 0 ) {

		*pe = pl -> head -> entry ;
		pl -> Current = pl -> Current -> next ;
		free( pl -> head ) ;
		pl -> head = pl -> Current ;
		pl -> CurrentPosition = 0 ;
	}

	else {

		if ( pos <= pl -> CurrentPosition ) {

			pl -> Current = pl -> head ;
			pl -> CurrentPosition = 0 ;
		}

		for ( pl -> CurrentPosition; pl -> CurrentPosition < pos - 1;  pl -> CurrentPosition++ ) {

			pl -> Current = pl -> Current -> next ;
		}

		*pe = pl -> Current -> next -> entry ;
		temp = pl -> Current -> next -> next ;
		free( pl -> Current -> next ) ;
		pl -> Current -> next = temp ;
	}

	pl -> size-- ;
}

void List_vidRetrieve   ( u32 pos, ListEntry *pe, List_t *pl           )  {

	if ( pos < pl -> CurrentPosition ) {

		pl -> Current = pl -> head ;
		pl -> CurrentPosition = 0 ;
	}

	for ( pl -> CurrentPosition; pl -> CurrentPosition < pos;  pl -> CurrentPosition++ ) {

		pl -> Current = pl -> Current -> next ;
	}

	*pe = pl -> Current -> entry ;
}

void List_vidReplace   ( u32 pos, ListEntry e, List_t *pl              )  {

	if ( pos < pl -> CurrentPosition ) {

		pl -> Current = pl -> head ;
		pl -> CurrentPosition = 0 ;
	}

	for ( pl -> CurrentPosition; pl -> CurrentPosition < pos;  pl -> CurrentPosition++ ) {

		pl -> Current = pl -> Current -> next ;
	}

	pl -> Current -> entry = e ;
}

void List_vidClear    ( List_t *pl                                     )  {

	while ( pl -> head ) {

		pl -> Current = pl -> head -> next ;
		free ( pl -> head ) ;
		pl -> head = pl -> Current ;
	}

	pl -> size = 0 ;
	pl -> CurrentPosition = 0 ;
}

void List_vidTraverse ( List_t *pl, void (*pf) (ListEntry)            )  {

	pl -> Current = pl -> head ;

	while ( pl -> Current ) {

		(*pf) ( pl -> Current -> entry) ;
		pl -> Current = pl -> Current -> next ;
	}

	pl -> CurrentPosition = ( pl -> size ) - 1 ;
}

u8  List_IsFull  ( List_t *pl ) {

	return 0 ;
}

u8  List_IsEmpty ( List_t *pl ) {

	return !pl -> size ;
}

u32 List_GetSize ( List_t *pl ) {

	return pl -> size ;
}


