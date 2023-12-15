/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Global_config.h   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *
 * Created on :  DES 6, 2023
 * Author     :  Gehad Hassanin
 *
 */

#ifndef GLOBAL_CONFIG_H_
#define GLOBAL_CONFIG_H_

#define ARRAY_BASED  0
#define LINKED_BASED 1

/*
 *  options:-
 *
 *            1- ARRAY_BASED
 *            2- LINKED_BASED
 */

#define TYPE_BASED LINKED_BASED

/*****************************************************************/

/*       This line used to specify the maximum the stack, Queue, List size        */
#define MAX_ELEMENTS   50

#define MAX_STACK      MAX_ELEMENTS
#define MAX_QUEUE      MAX_ELEMENTS
#define MAX_LIST       MAX_ELEMENTS

/*****************************************************************/

/*
 *  ELEMENT_TYPE : is Data type of the data
 *  This line used to specify the Data type of the data that will be pushed in the stack or Queue or List
 */
typedef u32        ELEMENT_TYPE ;

typedef ELEMENT_TYPE StackEntry ;
typedef ELEMENT_TYPE QueueEntry ;
typedef ELEMENT_TYPE ListEntry  ;

/*****************************************************************/
#endif /* GLOBAL_CONFIG_H_ */
