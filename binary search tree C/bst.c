#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE  0
#define IN 2
#define PRE 3
#define POST 4

struct binary_tree_node {
	int data;
	struct binary_tree_node *ch_left;
	struct binary_tree_node *ch_right;
};

struct binary_search_tree {
	struct binary_tree_node *root;
	int node_num;
};


void bst_init(struct binary_search_tree *bst) {
	bst->root = NULL;
	bst->node_num = 0;
}


void bst_insert_rec(struct binary_tree_node *node, int data) {
	if (data < node->data) {
		if (node->ch_left != NULL) {
			bst_insert_rec(node->ch_left, data);
			}
			else {
				node->ch_left = (struct binary_tree_node*) malloc(sizeof(struct binary_tree_node));
				node->ch_left->data = data;
				node->ch_left->ch_left = NULL;
				node->ch_left->ch_right = NULL;
			}
	}else if (data >= node->data) {
		if (node->ch_right != NULL) {
			bst_insert_rec(node->ch_right, data);
			}
			else {
				node->ch_right = (struct binary_tree_node*) malloc(sizeof(struct binary_tree_node));
				node->ch_right->data = data;
				node->ch_right->ch_left = NULL;
				node->ch_right->ch_right = NULL;
			}
		}
}

void bst_insert(struct binary_search_tree *bst, int data) {
	if (bst->root == NULL) {
		bst->root = (struct binary_tree_node *) malloc(sizeof(struct binary_tree_node));
		bst->root->data = data;
		bst->root->ch_left = NULL;
		bst->root->ch_right = NULL;
		bst->node_num++;
	}
	else {
		bst_insert_rec(bst->root, data);
		bst->node_num++;
	}
}

int bst_search_rec2(struct binary_tree_node *node, int key) {
	int res = FALSE;
	if(node == NULL) {
			return FALSE;
		}
	else {
		if (node->data == key) {
			fprintf(stdout, "Value found !!!\n");
			return TRUE;
		}
		else {
			if(key < node->data) {
				res = bst_search_rec(node->ch_left, key);
			}
			else{
				res = bst_search_rec(node->ch_right, key);
			}
		}
	}
	return res;
}
int bst_search_rec(struct binary_tree_node *node, int key) {
	int res = FALSE;
	if(node!= NULL) {
		if (node->data == key) {
			fprintf(stdout, "Value found !!!\n");
			return TRUE;
		}
		else {
			if(key < node->data) {
				res = bst_search_rec(node->ch_left, key);
			}
			else{
				res = bst_search_rec(node->ch_right, key);
			}
		}
	}
	return res;
}
int bst_search(struct binary_search_tree *bst, int key) {
	if (bst->root == NULL) {
		return FALSE;
	}
	else {
		return bst_search_rec(bst->root, key);
	}
}

struct binary_tree_node*  bst_free_rec(struct binary_tree_node *node) {
	if (node != NULL ) {
        bst_free_rec(node->ch_left);
        bst_free_rec(node->ch_right);
        free(node);
    }
    return NULL;
}

void bst_free(struct binary_search_tree * bst) {
	if (bst->root == NULL) {
		fprintf(stdout, "Tree is already empty!\n");
	}
	else {
		bst_free_rec(bst->root);
        bst->root = NULL;
        bst->node_num = 0;
	}
}

void bst_print_preorder(struct binary_tree_node *node) {

	if (node == NULL) {
	    return ;
    }
	else {
	    printf("%d\t",node->data);
        bst_print_preorder(node->ch_left);
        bst_print_preorder(node->ch_right);
	}
}

void bst_print_postorder(struct binary_tree_node *node) {
	if (node == NULL) {
	    return ;
    }
	else {
	    bst_print_postorder(node->ch_left);
        bst_print_postorder(node->ch_right);
	    printf("%d\t",node->data);
	}
}



void bst_print_inorder(struct binary_tree_node *node) {
    if (node == NULL) {
	    return ;
    }
	else {
	    bst_print_inorder(node->ch_left);
	    printf("%d\t",node->data);
        bst_print_inorder(node->ch_right);
	}
}
