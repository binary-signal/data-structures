#include <stdio.h>
#include <stdlib.h>



enum print_filter{inorder = 1, postorder = 2, preorder = 3}prn_filter;


struct binary_tree_node {
	int data;
	struct binary_tree_node *ch_left;
	struct binary_tree_node *ch_right;
};

struct binary_search_tree {
	struct binary_tree_node *root;
	int node_num;
};


void bst_init(struct binary_search_tree *);

void bst_insert_rec(struct binary_tree_node *, int);
void bst_insert(struct binary_search_tree *, int);
void bst_print_in_order_rec(struct binary_tree_node *);
void bst_print_in_order(struct binary_search_tree *);
void bst_free(struct binary_search_tree *);
struct binary_tree_node * bst_free_rec(struct binary_tree_node *);
int bst_search_rec(struct binary_tree_node *, int);
int bst_search(struct binary_search_tree *, int);
void bst_delete(struct binary_search_tree *);
struct binary_tree_node* bst_remove(struct binary_search_tree*, int);

void bst_print_inorder(struct binary_tree_node *);
void bst_print_preorder(struct binary_tree_node *);
void bst_print_postorder(struct binary_tree_node *);
