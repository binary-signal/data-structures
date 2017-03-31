/*
 * Copyright (c) 2011, Euaggelos Mouroutsos a.k.a Nauagos , mvaggelis@gmail.com
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
 * Neither the name of the <organization> nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


public class linkedList {

    //Linked list variables
    private linkedListNode head;   //points to the head of the linked list
    private linkedListNode current;//points to the current node of the linked list 
    private linkedListNode tail;   //not used in this implementation
    int size;              //number of nodes inserted at linked list

    //Linked list constructor
    public linkedList() {
        head = current = tail = null;
        size = 0;
    }

    //getters and setters for accessing class variables from other classes
    public linkedListNode getHead() {
        return head;
    }

    public void setHead(linkedListNode head) {
        this.head = head;
    }

    public linkedListNode getCurrent() {
        return current;
    }

    public void setCurrent(linkedListNode current) {
        this.current = current;
    }

    public linkedListNode getTail() {
        return tail;
    }

    public void setTail(linkedListNode tail) {
        this.tail = tail;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    //insert new node at the head of the linked list
    public void insert(int text) {
        //first make a new node to insert to the linked list
        linkedListNode ln = new linkedListNode(text);

        //check if the linked list is empty, if so insert node at head
        if (head == null) {
            head = ln;
            size++;
            return;
        }

        current = head;
        head = ln;
        head.setNext(current);
        size++;
    }

    //search for a key into the linked list, it is implemented but not used so far... :P
    public boolean search(int key) {
        if (head == null) { //means we are searching an empty list
            return false;
        }
        current = head; // make current = head and start traversing the linked list
        while (current != null) {
            if (current.getText() == key) { //means we found what are looking for return true
                return true;
            }
        }
        return false; // means key linked list doesn't contains key .... to bad return false

    }
    //check if a linked list is empty, if so return true , else false.

    public boolean isEmpty() {
        if (head == null) {
            return true;
        }
        return false;

    }
    //delete a node from list, not implemented not used so far

    //print the data that nodes of a linked list holds, from head to tail, i mean print node as they were inserted
    public void print() {
        if (head == null) { // we got an empty list , print msg and return
            System.out.println("List is empty !");
            return;
        }
        current = head; //make current = head and start traversing the list stop when find tail a.k.a null node.
        System.out.println("Linked List: list of elements");
        while (current != null) {
            System.out.print(" "+current.getText()+" ");
            current = current.getNext(); //go to next node
        }
        System.out.println();
    }

    public void free() {
        if (head == null) { //empty list, nothing to free, return
            return;
        }
        while (head != null) { //make head next point to current
            current = head.getNext();
            head = null; // delete head
            head = current; //make new head point to current
            size--; //decrease size
        }
        //Just for debugging print list size, if size is 0 , we are good ! :)
        //System.out.println("List size afrer clean is: " + size);
    }

    public linkedListNode nodeAt(int index) {
        int count;
        current = head;
        count = 0;
        while (count < index) {
            current = current.getNext();
            count++;
        }
        return current;
    }
    
    public linkedListNode list_min() {
    	linkedListNode min = null;
    	
    	min = head;
    	current = head;
    	
    	while(current != null) {
    		if(current.getText() < min.getText()) {
    			min = current;
    		}
    		current = current.getNext();
    	}
    	//System.out.println("Min node is: "+min.getText());
    	return min;
    }
    public void remove(linkedListNode node) {
    	int index = 0;
    	current = head;
    	
    	while(current != null) {
    		if(current.getText() == node.getText()) {
    			break;
    		}
    		index++;
    	}
    	int i =0;
    	while(i<index) {
    		current = current.getNext();
    	}
    	linkedListNode tmp = current.getNext();
    	current = current.getNext().getNext();
    	
    }
    
    public linkedListNode delete(int key) // delete link with given key
    { 
    	
    	linkedListNode current = head; // search for link
    	linkedListNode previous = head;
    while(current.getText() != key)
    {
    if(current.getNext() == null)
    return null; // didn’t find it
    else
    {
    previous = current; // go to next link
    current = current.getNext();
    }
    } // found it
    size--;
    if(current == head) // if first link,
    head = head.getNext(); // change first
    else // otherwise,
    previous.setNext( current.getNext() ); // bypass it
    return current;
    }
    
    public void sort() {
    	linkedList sort = new linkedList();
    	
    	while(this.getSize() > 0) {
    		linkedListNode tmp = list_min();
    		tmp = delete(tmp.getText());
    		sort.insert(tmp.getText());
    	}
    	head = sort.getHead();
    	current = head;
    	
    }
    
    
}
