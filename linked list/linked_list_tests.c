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
*Version 2                                                                        *
*                                                                                 *
*Description:                                                                     *
*This code implements a single linked list data structure                         *
*It it desing to link integer values by default. Maybe in                         *
*future a more generic approache is made.If you don't know                        *
*what is this just wiki it "Linked List" or "Single Linked                        *
*List"                                                                            *
**********************************************************************************/

#include <stdio.h>
#include "linked_list.h"
#include <string.h>
#include <stdlib.h>

void list_test();
void list_test2();
void list_test3();
void list_test4();
void list_test5();


int main(int argc, char** argv) {
	//list_test();
	list_test2();
    list_test3();
	list_test4();
        list_test5();
	fprintf(stdout,"\nPress Key to exit...\n");
	getchar();
	fflush(stdin);
	return 0;
}

void list_test() {
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
        list_insert_start(&myList, (void*)i);
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
        list_insert_start(&myList, (void*)i);
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
    list_insert_at(&myList, (int)((myList.size)/2), (void*)myList.size);
    list_print(&myList);
    fprintf(stdout, "OK\n\n");



     //search on existing list

    if(myList.head == NULL || myList.size <= 0) {
        fprintf(stderr, "List empty aborting....\n");
        exit(-1);
        }

    fprintf(stdout, "\n\nSearch results for linked list\n");

    fprintf(stdout, "Try search for existing key on none empty list  ...");
    if(list_search(&myList, (void*)5) == LIST_TRUE) {
        fprintf(stdout, "FOUND, OK\n\n");
        }
    else {
        fprintf(stdout, "NOT FOUND, FAILURE\n\n");
        }

    fprintf(stdout, "Try search for index of existing key on none empty list  ...");
    if(list_search_index(&myList,(void*)7) > 0) {
        fprintf(stdout, "INDEX FOUND #%d, OK\n\n", list_search_index(&myList, (void*)7));
        }
    else {
        fprintf(stdout, "INDEX NOT FOUND, FAILURE\n\n");
        }

    fprintf(stdout, "Try search for node of existing key on none empty list  ...");
    if(list_search_node(&myList, (void*)12)  != NULL) {
        fprintf(stdout, "NODE FOUND , OK\n\n");
        }
    else {
        fprintf(stdout, "NODE NOT FOUND, FAILURE\n\n");
        }


    //search on empty list
    list_free(&myList);

     fprintf(stdout, "Try search for  key on  empty list  ...");
    if(list_search(&myList, (void*)myList.size) == LIST_FALSE) {
        fprintf(stdout, " OK\n\n");
        }
    else {
        fprintf(stdout, "FAILURE\n\n");
        }

    fprintf(stdout, "Try search for index of  key on  empty list  ...");
    if(list_search_index(&myList, (void*)myList.size) == LIST_NOT_FOUND) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAILURE\n\n");
        }

    fprintf(stdout, "Try search for node of  key on  empty list  ...");
    if(list_search_node(&myList, (void*)myList.size)  == NULL) {
        fprintf(stdout, "OK\n\n");
        }
    else {
        fprintf(stdout, "FAILURE\n\n");
        }


    //export operations non empty list
    list_init(&myList);
    fprintf(stdout, "Export operations non empty list:\n");

    for(i=0; i<10; i++) {
        list_insert_start(&myList, (void*)i);
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

     if(myList.head != NULL || myList.size > 0) {
        list_free(&myList);
         }
    //list_print(&myList);
}

void list_test2() {
	int rt = 0;
	lList list;

	list_init(&list);

	//insert to list at head
	fprintf(stdout, "Inserting at list...\n");
	list_insert_start(&list, (void*)"test");
	list_insert_start(&list, (void*)"abc");
	list_insert_start(&list, (void*)"vaggelis");
	list_insert_start(&list, (void*)"Hello");
	list_insert_start(&list, (void*)"World");
	list_print(&list);

	//remove from list head
	fprintf(stdout, "Removing element from list head...\n");
	list_delete_first(&list);
	list_print(&list);

	list_delete_first(&list);
	list_delete_first(&list);
	list_delete_first(&list);
	list_delete_first(&list);
	list_delete_first(&list);
	list_delete_first(&list);
	list_delete_first(&list);
	list_delete_first(&list);
	list_delete_first(&list);
	list_delete_first(&list);
	list_delete_first(&list);

	//make a succesful search
	fprintf(stdout, "Search List for existing element...");
	rt =list_search(&list, (void*)"vaggelis");
	if(rt == LIST_TRUE) {
		fprintf(stdout, "Status: FOUND\n");
	}
	else {
		fprintf(stdout, "Status: NOT FOUND\n");
	}

	//make a not succesful search
	fprintf(stdout, "Search List for non existing element...");
	rt =list_search(&list, (void*)"vedouza");
	if(rt == LIST_TRUE) {
		fprintf(stdout, "Status: FOUND\n");
	}
	else {
		fprintf(stdout, "Status: NOT FOUND\n");
	}


	list_free(&list);
}

void list_test3() {
	int rt = 0;
	lList list;
	struct sample {
		int sample1;
		int sample2;
		char buf1;
	};

	struct sample s;
	struct sample* a;
	lNode* node;
	s.sample1 = 10;
	s.sample2 = 50;
	s.buf1 = 'a';


	list_init(&list);

	list_insert_start(&list, (void*)&s);
	a = (struct sample*)malloc(sizeof(struct sample));
	a = (struct sample*)list_export_first(&list);


	//a = (struct sample*)node->data;

	fprintf(stdout, "%d %d %c\n", a->sample1, a->sample2, a->buf1);
}

void list_test4() {
	lList list;
	char* sample;

	list_init(&list);

	sample = (char*)malloc(sizeof(char));
	if(sample == NULL) {
		fprintf(stderr,"Cant mallocn\n");
	}


	//insert
	list_insert_end(&list, (void*)"a");
	list_insert_end(&list, (void*)"b");
	list_insert_end(&list, (void*)"c");
	list_insert_end(&list, (void*)"d");
	list_insert_end(&list, (void*)"e");

	list_print(&list);

	sample = (char*)list_peak_first(&list);
	fprintf(stdout, "Peak first: %c\n", *sample);
	//*sample ='z';

	sample = (char*)list_peak_last(&list);
	fprintf(stdout, "Peak last: %c\n", *sample);
	//*sample ='z';

	sample = (char*)list_peak_at(&list,1);
	fprintf(stdout, "Peak 1: %c\n", *sample);
	//*sample ='z';

	sample = (char*)list_peak_at(&list,2);
	fprintf(stdout, "Peak 2: %c\n", *sample);
	//*sample ='z';

	sample = (char*)list_peak_at(&list,3);
	fprintf(stdout, "Peak 3: %c\n", *sample);
	//*sample ='z';

	sample = (char*)list_peak_at(&list,4);
	fprintf(stdout, "Peak 4: %c\n", *sample);
	//*sample ='z';

	sample = (char*)list_peak_at(&list,5);
	fprintf(stdout, "Peak 5: %c\n", *sample);
	//*sample ='z';

	sample = (char*)list_peak_at(&list,6);
	//fprintf(stdout, "Peak 6: %c\n", *sample);
	//*sample ='z';

	free(sample);

}

void list_test5() {
    lList l ;
    lList* clone = NULL;

    list_init(&l);

    list_insert_start(&l, (void*) 6);
    list_insert_start(&l, (void*) "test");
    list_insert_start(&l, (void*) "yoooo");

    //printf the original list
    puts("print original list\n");
    list_print(&l);

    //duplicate list
    puts("douplicating list\n");
    clone = douplicate(&l);

    //print the clone list
    puts("printing the clone list\n");
    list_print(clone);

    //free the lists
    puts("freeing the lists...\n");
    list_free(&l);
    list_free(clone);
    free(clone);
}

