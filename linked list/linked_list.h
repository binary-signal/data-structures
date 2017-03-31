/**********************************************************************************
*                             SINLGE LINKED LIST                                  *
*                               IMPLEMENTATION                                    *
*Copyright (c) 2011                                                               *
*All rights reserved.                                                             *
*                                                                                 *
*Redistribution and use in source and binary forms, with or without               *
*modification, are permitted provided that the following conditions are met:      *
*1. Redistributions of source code must retain the above copyright                *
*   notice, this list of conditions and the following disclaimer.                 *
*2. Redistributions in binary form must reproduce the above copyright             *
*   notice, this list of conditions and the following disclaimer in the           *
*   documentation and/or other materials provided with the distribution.          *
*3. All advertising materials mentioning features or use of this software         *
*   must display the following acknowledgement:                                   *
*   This product includes software developed by the <organization>.               *
*4. Neither the name of the <organization> nor the                                *
*   names of its contributors may be used to endorse or promote products          *
*   derived from this software without specific prior written permission.         *
*                                                                                 *
*THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> ''AS IS'' AND ANY                *
*EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED        *
*WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE           *
*DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY               *
*DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES       *
*(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;     *
*LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND      *
*ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       *
*(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS    *
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                     *
*                                                                                 *
*                                                                                 *
*Author: Vaggelis Mouroutsos                                                      *
*Email: mvaggelis@gmail.com                                                       *
*Version 2.1                                                                      *
*Last Update: 24/11/2011														  *
*																				  *
*Latest changes:                                                                  *
*	.Improved Documentation for functions and function definitions                *
*	.Fixed 2 bugs. While exporting nodes,the nodes deallocated the exporting      *
*    value causing segmentation fault if used. While performing iterations on the *
*	 full length of the linked list, length checks for iteration where wrong      *
*                                                                                 *
*                                                                                 *
*Description:                                                                     *
*This code implements a single linked list data structure                         *
*It it desing to link void* values by default. Maybe in                           *
*future a more generic approache is made.If you don't know                        *
*what is this just wiki it "Linked List" or "Single Linked                        *
*List"                                                                            *
**********************************************************************************/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//enable debug messages
#define LIST_DEBUG_ENABLE 0

 /*******************************************************************
 *                            # Definitions                         *
 *******************************************************************/
 /*******************************************************************/

#ifdef LIST_DEBUG_ENABLE //1
	#define LIST_DEBUG 1
#endif

//make boolean logic
#ifndef LIST_TRUE
	#define LIST_TRUE 1
#endif
#ifndef LIST_FALSE
	#define LIST_FALSE 0
#endif
#ifndef LIST_NOT_FOUND
	#define LIST_NOT_FOUND -1
#endif

/*******************************************************************
*                Structs for Linked List Data Type                 *
*******************************************************************/
/*******************************************************************/

//type definition for linked list node
 typedef struct list_node {
	void* data;
	struct list_node *next;
}lNode;
//type definition for linked list
 typedef struct linked_list {
	 struct list_node *head;
	 struct list_node *cur;
	 long size;
 }lList;


/*******************************************************************
*        Function Declaration for Linked List Operations           *
*******************************************************************/
/*******************************************************************/

/*******************************************************************
*                         Insert Operations                         *
/*******************************************************************/
//insert new value at the end the linked list
void list_insert_end(struct linked_list *, void*);
//insert new value as the first node the linked list
void list_insert_start(struct linked_list *, void*);
//insert new value at linked list specified by the range 1:length(list)
void list_insert_at(struct linked_list *, int, void*);


 /*******************************************************************
 *                           Misc Operations                        *
 *******************************************************************/
//prints the contents of the list in string represantation not suitable for every data type !!!
void list_print(struct linked_list *);
//removes all the nodes from the list and frees any resorses allocated
void list_free(struct linked_list *);
//initiliase the list, use this function before attemping any operations in a linked list !!!
void list_init(struct linked_list *);
//returns the size of the linked list
long list_size(struct linked_list *);
//returns a copy of the linked list from the arguments
struct linked_list* douplicate(struct linked_list *);

/*******************************************************************
 *                          Peak Operations                        *
 *******************************************************************/
//returns the value of first element without extracting it from the list
void* list_peak_first(struct linked_list *);
//returns the value of last element without extracting it from the list
void* list_peak_last(struct linked_list *);
//returns the value of element specified from int argumets valid aguments is in range 1:length(list) without extracting it from the list
void* list_peak_at(struct linked_list *, int );

/*******************************************************************
 *                        Delete Operations                        *
 *******************************************************************/
//delete first elemet of the linked list , function DOESN'T return the node neither the value of the node
void list_delete_first(struct linked_list *);
//delete last elemet of the linked list , function DOESN'T return the node neither the value of the node
void list_delete_last(struct linked_list *);
//delete elemet of the linked list specifies in range 1:length(list), function DOESN'T return the node neither the value of the node
void list_delete_at(struct linked_list *, int);//

/*******************************************************************
 *                       Export Pperations                       *
 *******************************************************************/

//deletes the first node end returns it's value to the caller function
void* list_export_first(struct linked_list *);
//deletes the last node end returns it's value to the caller function
void* list_export_last(struct linked_list *);
//deletes the  node specified by the int in range 1:length(list) end returns is value to the caller function
void* list_export_at(struct linked_list *, int);

/*******************************************************************
 *                         Search Operation                        *
 *******************************************************************/
//search within a list for a key , return LIST_TRUE or LIST_FALSE
int list_search(struct linked_list *, void*);
//search within a list for a key, returns the index of the key in the list
int list_search_index(struct linked_list * , void*);
//search within a list for a key, returns the node that holds that key
struct list_node* list_search_node(struct linked_list* , void*);

#endif