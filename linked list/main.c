/**********************************************************************************
*                                BINARY TREE                                      *
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
*Version 1                                                                        *
*                                                                                 *
*Description:                                                                     *
*This code implements a single linked list data structure                         *
*It it desing to link integer values by default. Maybe in                         *
*future a more generic approache is made.If you don't know                        *
*what is this just wiki it "Linked List" or "Single Linked                        *
*List"                                                                            *
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//debug
//#define DEBUG

//make boolean logic
#define TRUE 1
#define FALSE 0
#define NO_FOUND -1


//structs for linked list data type

//type node
 struct list_node {
	int data;
	struct list_node *next;
};
 //type linked list
 struct linked_list {
	 struct list_node *head;
	 //struct list_node *tail;
	 struct list_node *cur;
	 int size;
 };

//Function Declaration for linked list operations
 /*******************************************************************
 *                       Insertion operations                       *
 *******************************************************************/



void list_insert_end(struct linked_list *, int);//
void list_insert_start(struct linked_list *, int);//
void list_insert_at(struct linked_list *, int, int);//


//misc operations
void list_print(struct linked_list *);//
void list_free(struct linked_list *);//
void list_init(struct linked_list *);//

//deletion operations
void list_delete_first(struct linked_list *);//
void list_delete_last(struct linked_list *);//
void list_delete_at(struct linked_list *, int);//

//export operations , after use nodes must be manual free
struct list_node* list_export_first(struct linked_list *);
struct list_node* list_export_last(struct linked_list *);
struct list_node* list_export_at(struct linked_list *, int);

//search operations
int list_search(struct linked_list *, int);//search within a list for a key , return TRUE or FALSE
int list_search_index(struct linked_list * , int);//search within a list for a key, returns the index of the key in the list
struct list_node* list_search_node(struct linked_list* , int);//search within a list for a key, returns the node that holds that key





//main.c test the linked list
int main() {
    int i=0;
	struct linked_list myList;

	list_init(&myList);
    //list_print(&myList);
   ///////////////////////////////////////////////////
    fprintf(stdout, "\t\t\tLINKED LIST TESTS\n\n");
    //////////////////////////////////////////////////

    //deletion
    list_init(&myList);
    fprintf(stdout, "Deletion on an empty list:\n");

    fprintf(stdout, "Try delete first ...");
    list_delete_first(&myList);
    fprintf(stdout, "OK\n\n");

    fprintf(stdout, "Try delete last ...");
    list_delete_last(&myList);
    fprintf(stdout, "OK\n\n");

    fprintf(stdout, "Try delete at pos ...");
    list_delete_at(&myList, 5);
    fprintf(stdout, "OK\n\n");

    //deletion non empty list

    //insertion
    list_init(&myList);
    fprintf(stdout, "Deletion on NON empty list:\n");

    for(i=0; i<10; i++) {
        list_insert_start(&myList, i);
        }
    list_print(&myList);
    fprintf(stdout, "Try delete first ...");
    list_delete_first(&myList);
    list_print(&myList);
    fprintf(stdout, "OK\n\n");

    fprintf(stdout, "Try delete last ...");
    list_delete_last(&myList);
    list_print(&myList);
    fprintf(stdout, "OK\n\n");

    fprintf(stdout, "Try delete at pos ...");
    list_delete_at(&myList, 5);
    list_print(&myList);
    fprintf(stdout, "OK\n\n");


     //insertion
    list_init(&myList);
    fprintf(stdout, "Insertion on an empty list:\n");

    fprintf(stdout, "Try insert start ...");
    for(i=0; i<10; i++) {
        list_insert_start(&myList, i);
        }
    list_print(&myList);
    fprintf(stdout, "OK\n\n");

    fprintf(stdout, "Try insert end ...");
    for(i=10; i<20; i++) {
        list_insert_end(&myList, i);
        }
    list_print(&myList);
    fprintf(stdout, "OK\n\n");

    fprintf(stdout, "Try insert at pos (myList.size/2) = %d ...", (int)((myList.size)/2));
    list_insert_at(&myList, (int)((myList.size)/2), myList.size);
    list_print(&myList);
    fprintf(stdout, "OK\n\n");



     //search on existing list

    if(myList.head == NULL || myList.size <= 0) {
        fprintf(stderr, "List empty aborting....\n");
        exit(-1);
        }

    fprintf(stdout, "\n\nSearch results for linked list\n");

    fprintf(stdout, "Try search for existing key on none empty list  ...");
    if(list_search(&myList, 5 == TRUE)) {
        fprintf(stdout, "FOUND, OK\n\n");
        }
    else {
        fprintf(stdout, "NOT FOUND, FAILURE\n\n");
        }

    fprintf(stdout, "Try search for index of existing key on none empty list  ...");
    if(list_search_index(&myList,7) > 0) {
        fprintf(stdout, "INDEX FOUND #%d, OK\n\n", list_search_index(&myList, 7));
        }
    else {
        fprintf(stdout, "INDEX NOT FOUND, FAILURE\n\n");
        }

    fprintf(stdout, "Try search for node of existing key on none empty list  ...");
    if(list_search_node(&myList, 12)  != NULL) {
        fprintf(stdout, "NODE FOUND , OK\n\n");
        }
    else {
        fprintf(stdout, "NODE NOT FOUND, FAILURE\n\n");
        }


    //search on empty list
    list_free(&myList);

     fprintf(stdout, "Try search for  key on  empty list  ...");
    if(list_search(&myList, myList.size) == FALSE) {
        fprintf(stdout, " OK\n\n");
        }
    else {
        fprintf(stdout, "FAILURE\n\n");
        }

    fprintf(stdout, "Try search for index of  key on  empty list  ...");
    if(list_search_index(&myList, myList.size) == NO_FOUND) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAILURE\n\n");
        }

    fprintf(stdout, "Try search for node of  key on  empty list  ...");
    if(list_search_node(&myList, myList.size)  == NULL) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAILURE\n\n");
        }


    //export operations non empty list
    list_init(&myList);
    fprintf(stdout, "Export operations non empty list:\n");

    for(i=0; i<10; i++) {
        list_insert_start(&myList, i);
        }
    list_print(&myList);
    fprintf(stdout, "Try export first ...");
    if( list_export_first(&myList) != NULL) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAIL\n\n");
        }
    list_print(&myList);

    fprintf(stdout, "Try export last ...");
    if( list_export_last(&myList) != NULL) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAIL\n\n");
        }
    list_print(&myList);

    fprintf(stdout, "Try export at pos ...");
    if( list_export_at(&myList, 4) != NULL) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAIL\n\n");
        }
    list_print(&myList);


    //export on empty list

    list_init(&myList);
    list_free(&myList);
    fprintf(stdout, "Export operations  empty list:\n");

    fprintf(stdout, "Try export first ...");
    if( list_export_first(&myList) == NULL) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAIL\n\n");
        }
    list_print(&myList);

    fprintf(stdout, "Try export last ...");
    if( list_export_last(&myList) == NULL) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAIL\n\n");
        }
    list_print(&myList);

    fprintf(stdout, "Try export at pos ...");
    if( list_export_at(&myList, 4) == NULL) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAIL\n\n");
        }




    getchar();


    //////////////////////////////////////////////////
     if(myList.head != NULL || myList.size > 0) {
        list_free(&myList);
         }
    //list_print(&myList);
	fprintf(stdout,"Press Key to exit...\n");
	getchar();
	return 0;
}

//Functions of Linked List

// initialise variables o linked list struct to NULL and zero
void list_init(struct linked_list *l) {
	l->head = NULL;
	//l->tail = NULL;
	l->cur =  NULL;
	l->size = 0;
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_print

 Args: struct linked_list * l
 Return: void

 Description: Prints the content of every node in the linked list
              ,printing operations starts from List head and termi
              nates to List tail
 *******************************************************************/
void list_print(struct linked_list *l) {
    if (l->head == NULL){ //case of empty list just return !
        fprintf(stdout, "\nList is empty !\n");
        return;
    }
    l->cur = l->head; //set cur to point to the start of the list
    fprintf(stdout, "List Elements:");
    while (l->cur!= NULL) { //traverse the list element by element and print in stdout
        fprintf(stdout, "%d ", l->cur->data);
        l->cur = l->cur->next; //go to next element
    }
    fprintf(stdout, "\n");
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_free

 Args: struct linked_list * l
 Return: void

 Description: Deletes all nodes of a non empty list. Operation sta-
              rts from List head and stops at List tail. If list
              is empty returns
 *******************************************************************/
void list_free(struct linked_list *l) {
    if (l->head == NULL) { //list already empty , return
        fprintf(stdout, "List already empty!\n");
        return;
    }
    while(l->head != NULL) {
        l->cur = l->head->next; //set cur to point to the next node after head
        free(l->head); //delete head node
        l->head = NULL;
        l->head = l->cur; //set the new head of the list
        l->size--; //decrease list size
    }
}

 /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_insert_start

 Args: struct linked_list * l, int data
 Return: void

 Description: Inserts variable data to start of given linked list
 *******************************************************************/
void list_insert_start(struct linked_list *l, int data) {
     struct list_node *n = (struct list_node*) malloc( sizeof(struct list_node));
    if (l->head == NULL) {
        n->data = data;
        n->next = NULL;
        l->head = n;
        l->size++;
    }
    else {
        n->data = data;
        n->next = l->head;
        l->head = n;
        l->size++;
    }
}
 /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_insert_end

 Args: struct linked_list * l, int data
 Return: void

 Description: Inserts variable data to the end of a given linked list
 *******************************************************************/
 void list_insert_end(struct linked_list *l, int data) {
    struct list_node *n = (struct list_node*) malloc( sizeof(struct list_node));
    if (l->head == NULL) {
        n->data = data;
        n->next = NULL;
        l->head = n;
        l->size++;
    }
    else {
       l->cur = l->head;
        while (l->cur->next != NULL) {
            l->cur = l->cur->next;
        }
        n->data = data;
        n->next = NULL;
        l->cur->next = n;
        l->size++;
    }
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_insert_at

 Args: struct linked_list * l, int pos, int data
 Return: void

 Description: Inserts variable data to specified possition(pos) into
              linked list. Linked List arithmetics start from 1
              so valid values for pos is >0 & <list size. Example:

              Before List 0 0 0 0
              call list_insert_at(l, 2)
              After List  0 1 0 0 0
 *******************************************************************/
void list_insert_at(struct linked_list *l, int pos, int data) {
    int index;

    if(l->head == NULL && pos ==1) {
        struct list_node *n = (struct list_node*) malloc( sizeof(struct list_node));
        n->data = data;
        n->next = NULL;
        l->head = n;
        l->size++;
        return;
        }

    if(l->head != NULL) {
        if(pos > l->size) {
        fprintf(stderr, "Insertion position #%d > list size #%d\n", pos, l->size);
        return ;
        }
        else {
        struct list_node *n = (struct list_node*) malloc( sizeof(struct list_node));
        l->cur = l->head;
        index =1;
        while (l->cur != NULL && index != pos-1) {
            l->cur = l->cur->next;
            index++;
        }
        n->data = data;
        n->next = l->cur->next;
        l->cur->next = n;
        l->size++;
        }
     }
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_search

 Args: struct linked_list * l, int key
 Return: int flag

 Description: Search every node a linked list until find a node
              containing the key value. If found return TRUE
              else return FALSE (see defines, TRUE = 1, FALSE = 0)
 *******************************************************************/
int list_search(struct linked_list *l, int key) {
    int flag = FALSE; //search status

    if (l->head == NULL) { //empty list, nothing to search for... :(
        return flag;
    }
    l->cur = l->head; //set cur to point to the start of the list
    while(l->cur != NULL) {
        if (l->cur->data == key) { //check if data == key , if so return , key exists!
            flag = TRUE;
            break; //break the while loop to speed up search, no nessesary need to search whole list because we found what we look for
        }
        l->cur = l->cur->next; // set cur to point to next element to check
    }
    return flag; //return search result
}


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_search_index

 Args: struct linked_list * l, int pos, int key
 Return: int index

 Description: search node containts of a linked list for value key
              if search is succefull return the index of the node
              in the list else return NOT_FOUND(defined as -1)
              List indexes starts from 1 which is head node
 *******************************************************************/
int list_search_index(struct linked_list *l, int key) {
    int flag = FALSE; //search status
    int index;

    if (l->head == NULL) { //empty list, nothing to search for... :(
        return NO_FOUND;
    }
    index=0;
    l->cur = l->head; //set cur to point to the start of the list
    while(l->cur != NULL) {
        if (l->cur->data == key) { //check if data == key , if so return , key exists!
            flag = TRUE;
            break; //break the while loop to speed up search, no nessesary need to search whole list because we found what we look for
        }
        l->cur = l->cur->next; // set cur to point to next element to check
        index++;
    }
    if (flag == TRUE) {
        return index;
    }
    else {
        return NO_FOUND; //return search result
    }
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_search_node

 Args: struct linked_list * l, int pos, int key
 Return: struct list_node *res

 Description: Search node containts of a linked list for a key value
              if found return the node of the list else return NULL
 *******************************************************************/
struct list_node* list_search_node(struct linked_list* l, int key) {
    int flag = FALSE; //search status
    struct list_node* res = NULL;

    if (l->head == NULL) { //empty list, nothing to search for... :(
        return NULL;
    }
    l->cur = l->head; //set cur to point to the start of the list
    while(l->cur != NULL) {
        if (l->cur->data == key) { //check if data == key , if so return , key exists!
            flag = TRUE;
            res = l->cur;
            break; //break the while loop to speed up search, no nessesary need to search whole list because we found what we look for
        }
        l->cur = l->cur->next; // set cur to point to next element to check
    }
    if (flag == TRUE) {
        return res;
    }
    else {
        return NULL; //return search result
    }
 }

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_delete_at

 Args: struct linked_list * l, int pos
 Return: void

 Description: Deletes a node from a linked list, specified by pos
              variable. pos >=1 because list arithetics of this
              implementation starts from 1
 *******************************************************************/
void list_delete_at(struct linked_list *l , int pos) {
    int index;
    struct list_node *tmp = NULL;

    if (l->head == NULL) { //list empty nothing to remove
        fprintf(stderr, "List empty, nothing to remove !\n");
        return;
    }
    if(pos <= 0 && pos > l->size) {
        fprintf(stderr, "Invalid removal position #%d, List removal position range #%d-%d\n", pos, 1, l->size);
        return;
    }
    index = 1;
    if (pos == 1 && index ==1) { //remove the head of the list
        l->cur = l->head; //make cur point to head node
        tmp = l->cur->next; //make tmp point to the next node after head
        free(l->cur); //free head of the list
        l->cur = NULL;
        l->head = tmp; //update head of the list
        l->size--;
        if(l->size == 0) {
            l->head = NULL;
        }
        return;
    }
    else if (pos == l->size) { //remove the last element
        l->cur = l->head; //set current to point to the head node
        while(l->cur != NULL) {//traverse until the node before the last node of the list
            if(l->cur->next->next == NULL) { //check if this is the node before the last node of the list
                break;
            }
            l->cur =l->cur->next; //go to next node
        }
        free(l->cur->next); //free the next node after we stoped
        l->cur->next= NULL; //update the new end of the list to point to NULL
        l->size--;
        return;
    }
    else if(pos > 1 && pos < l->size) {
        index = 1;
        l->cur = l->head;
        while(l->cur != NULL && index <= pos-1) {
            l->cur = l->cur->next;
            index ++;
        }
        tmp = l->cur->next->next; // store position of next node after deletion
        free(l->cur->next); //delete the node
        l->cur->next = NULL;
        l->cur->next = tmp; //connect the node before and after deleter node
        l->size--;
    }

}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_delete_first

 Args: struct linked_list * l
 Return: void

 Description: Deletes the first node of a linked list a.k.a head
              node
 *******************************************************************/
void list_delete_first(struct linked_list *l) {
    list_delete_at(l, 1);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_delete_last

 Args: struct linked_list * l, int pos
 Return: void

 Description: Deletes the last node of a linked list a.k.a tail
              node
 *******************************************************************/
void list_delete_last(struct linked_list *l) {
    list_delete_at(l, l->size);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_export_at

 Args: struct linked_list * l, int pos
 Return: struct list_node*

 Description: Exports the specified by the possition(pos) variable
              node from a linked list. WARNING export doesn't
              deallocates the node allocates when inserted it just
              removes the node from  scope of the list
*******************************************************************/
struct list_node* list_export_at(struct linked_list *l, int pos){
    int index;
    struct list_node *tmp = NULL;
    struct list_node *exp_node = NULL;

    if (l->head == NULL) { //list empty nothing to remove
        fprintf(stderr, "List empty, nothing to remove !\n");
        return NULL;
    }
    if(pos <= 0 && pos > l->size) {
        fprintf(stderr, "Invalid removal position #%d, List removal position range #%d-%d\n", pos, 1, l->size);
        return NULL;
    }
    index = 1;
    if (pos == 1 && index ==1) { //remove the head of the list
        l->cur = l->head; //make cur point to head node
        tmp = l->cur->next; //make tmp point to the next node after head
        exp_node = l->cur;
        free(l->cur); //free head of the list
        l->cur = NULL;
        l->head = tmp; //update head of the list
        l->size--;
        if(l->size == 0) {
            l->head = NULL;
        }
    }
    else if (pos == l->size) { //remove the last element
        l->cur = l->head; //set current to point to the head node
        while(l->cur != NULL) {//traverse until the node before the last node of the list
            if(l->cur->next->next == NULL) { //check if this is the node before the last node of the list
                break;
            }
            l->cur =l->cur->next; //go to next node
        }
        exp_node = l->cur->next;
        free(l->cur->next); //free the next node after we stoped
        l->cur->next= NULL; //update the new end of the list to point to NULL
        l->size--;
    }
    else if(pos > 1 && pos < l->size) {
        index = 1;
        l->cur = l->head;
        while(l->cur != NULL && index <= pos-1) {
            l->cur = l->cur->next;
            index ++;
        }
        tmp = l->cur->next->next; // store position of next node after deletion
        exp_node = l->cur->next;
        free(l->cur->next); //delete the node
        l->cur->next = NULL;
        l->cur->next = tmp; //connect the node before and after deleter node
        l->size--;
    }
    return exp_node;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_export_first

 Args: struct linked_list * l
 Return: struct list_node*

 Description: Exports the (first) head node from a linked list.
              WARNING export doesn't deallocates the node
              allocates when inserted it just removes the node
              from  scope of the list.
*******************************************************************/
struct list_node* list_export_first(struct linked_list *l) {
    return list_export_at(l, 1);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_export_last

 Args: struct linked_list * l
 Return: struct list_node*

 Description: Exports the last (tail) node from a linked list.
              WARNING export doesn't deallocates the node
              allocates when inserted it just removes the node
              from  scope of the list.
*******************************************************************/
struct list_node* list_export_last(struct linked_list *l) {
    return list_export_at(l, l->size);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Function: list_export_last

 Args: struct linked_list * l, int key
 Return: struct list_node*

 Description: Exports the node that holds the key value from a
              linked list. If key doesn't exists return NULL.
              WARNING export doesn't deallocates the node
              allocates when inserted it just removes the node
              from  scope of the list.
*******************************************************************/
struct list_node* list_export_key(struct linked_list *l, int key) {
    int exp_index;

    exp_index = list_search_index(l, key);
    if(exp_index <=0) {
        return NULL;
        }
    else {
        return list_export_at(l, exp_index);
        }
}
