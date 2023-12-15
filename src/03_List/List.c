/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  List.c   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 * Created on :  DES 6, 2023
 * Author     :  Gehad Hassanin
 *
 */

#include "STD_TYPES.h"
#include "Global_config.h"
#include "List.h"

#include "stdlib.h"

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Array based Implementation   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#if TYPE_BASED ==  ARRAY_BASED

void List_vidInit     ( List_t *pl                                     )  {

	pl -> size = 0 ;
}

void List_vidInsert     ( s32 pos, ListEntry e  , List_t *pl           )  {

	s32 LOC_u32Iterator = ( pl -> size ) - 1;

	for ( LOC_u32Iterator; LOC_u32Iterator >= pos; LOC_u32Iterator-- ) {

		pl -> entry[LOC_u32Iterator + 1] = pl -> entry[LOC_u32Iterator] ;
	}

	pl -> entry[pos] = e ;
	pl -> size++ ;
}

void List_vidDelete      ( u32 pos, ListEntry *pe, List_t *pl           )  {

	u32 LOC_u32Iterator = pos + 1;
	*pe = pl -> entry[pos] ;

	for ( LOC_u32Iterator; LOC_u32Iterator < pl -> size; LOC_u32Iterator++ ) {

		pl -> entry[LOC_u32Iterator - 1] = pl -> entry[LOC_u32Iterator] ;
	}

	pl -> size--;
}

void List_vidRetrieve   ( u32 pos, ListEntry *pe, List_t *pl           )  {

	*pe = pl -> entry[pos] ;
}

void List_vidReplace   ( u32 pos, ListEntry e, List_t *pl              )  {

	pl -> entry[pos] = e ;
}

void List_vidClear    ( List_t *pl                                     )  {

	pl -> size = 0 ;
}

void List_vidTraverse ( List_t *pl, void (*pf) (ListEntry)            )  {

	u32 LOC_u32Iterator ;

	for ( LOC_u32Iterator = 0; LOC_u32Iterator < pl -> size; LOC_u32Iterator++ ) {

		(*pf) ( pl -> entry[LOC_u32Iterator] ) ;
	}
}

u8  List_IsFull  ( List_t *pl ) {

	return ( pl -> size == MAX_LIST ) ;
}

u8  List_IsEmpty ( List_t *pl ) {

	return !pl -> size ;
}

u32 List_GetSize ( List_t *pl ) {

	return pl -> size ;
}
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Linked based Implementation  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#elif  TYPE_BASED ==  LINKED_BASED

void List_vidInit     ( List_t *pl                                     ) {

	pl -> head = NULL ;
	pl -> size = 0 ;
}

void List_vidInsert   ( u32 pos, ListEntry e  , List_t *pl             ) {

	Node_t *q = pl -> head ;
	u32    LOC_u32Iterator ;
	Node_t *pn = ( Node_t* )malloc( sizeof(Node_t) ) ;
	pn -> entry = e ;

	if ( pos == 0 ) {

		pn -> next = pl -> head ;
		pl -> head = pn ;
	}

	else {

		for ( LOC_u32Iterator = 0; LOC_u32Iterator < pos - 1;  LOC_u32Iterator++ ) {

			q = q -> next ;
		}

		pn -> next = q -> next ;
		q -> next = pn ;
	}

	pl -> size++ ;
}

u8  List_u8Insert        ( u32 pos, ListEntry e  , List_t *pl          )  {

	Node_t *q = pl -> head ;
	u32    LOC_u32Iterator ;
	Node_t *pn = ( Node_t* )malloc( sizeof(Node_t) ) ;

	if ( !pn ) {

		return 0 ;
	}

	else {

		pn -> entry = e ;

		if ( pos == 0 ) {

			pn -> next = pl -> head ;
			pl -> head = pn ;
		}

		else {

			for ( LOC_u32Iterator = 0; LOC_u32Iterator < pos - 1;  LOC_u32Iterator++ ) {

				q = q -> next ;
			}

			pn -> next = q -> next ;
			q -> next = pn ;
		}

		pl -> size++ ;
		return 1 ;
	}
}
void List_vidDelete      ( u32 pos, ListEntry *pe, List_t *pl           )  {

	Node_t *temp, *q = pl -> head ;
	u32    LOC_u32Iterator ;

	if ( pos == 0 ) {

		*pe = pl -> head -> entry ;
		temp = pl -> head -> next ;
		free( pl -> head ) ;
		pl -> head = temp ;
	}

	else {

		for ( LOC_u32Iterator = 0; LOC_u32Iterator < pos - 1;  LOC_u32Iterator++ ) {

			q = q -> next ;
		}

		*pe = q -> next -> entry ;
		temp = q -> next -> next ;
		free( q -> next ) ;
		q -> next = temp ;
	}

	pl -> size-- ;
}

void List_vidRetrieve   ( u32 pos, ListEntry *pe, List_t *pl           )  {

	u32    LOC_u32Iterator ;
	Node_t *q = pl -> head ;

	for ( LOC_u32Iterator = 0; LOC_u32Iterator < pos;  LOC_u32Iterator++ ) {

		q = q -> next ;
	}

	*pe = q -> entry ;
}

void List_vidReplace   ( u32 pos, ListEntry e, List_t *pl              )  {

	u32    LOC_u32Iterator ;
	Node_t *q = pl -> head ;

	for ( LOC_u32Iterator = 0; LOC_u32Iterator < pos;  LOC_u32Iterator++ ) {

		q = q -> next ;
	}

	q -> entry = e ;
}

void List_vidClear    ( List_t *pl                                     )  {

	Node_t *pn = pl -> head -> next;

	while ( pl -> head ) {

		pn = pl -> head -> next ;
		free ( pl -> head ) ;
		pl -> head = pn ;
	}

	pl -> size = 0 ;
}

void List_vidTraverse ( List_t *pl, void (*pf) (ListEntry)            )  {

	Node_t *pn = pl -> head ;

	while ( pn ) {

		(*pf) ( pn -> entry) ;
		pn = pn -> next ;
	}
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
#endif

