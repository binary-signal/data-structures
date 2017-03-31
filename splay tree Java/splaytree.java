public class splaytree {

    public node root;
    public int records;

    public splaytree() {
        root = null;
        records = 0;
    }
    
    //calculate the depth of a node
    public int node_depth(node node, node target) {
        int left_depth = 0;
        int right_depth = 0; 
        if (node == null || node == target) {
            return 0;
        }
        left_depth = node_depth(node.left, target);
        right_depth = node_depth(node.right, target);

        if (left_depth < right_depth) {
            return right_depth + 1;
        } else {
            return left_depth + 1;
        }
    }

    //print nodes post order
    public void printPostOrder(node n) {
        if (n != null) {
            n.print();
            printPostOrder(n.left);
            printPostOrder(n.right);
        }
    }

    //search for a key
    public node search(node n, int key) {
        node result = null;
        if (n != null) {
            if (key < n.data) {
                result = search(n.left, key);
            } else if (key > n.data) {
                result = search(n.right, key);
            } else if (key == n.data) {
                return n;
            }
        }
        return result;
    }

    //insert
    public void insert(int key) {
        insert(root, key);
    }

    public void insert(node n, int key) {
        if (root == null) {
            root = new node(key, null);
            records++;
            return;
        }
        if (key == n.data) {
            System.err.println("Try to insert duplicate value: " + key);
            //splay(n.parent); //because of duplicate node splay the last accesed node e.g the father of node n
            return;
        }
        if (key < n.data) {
            if (n.left == null) {
                n.left = new node(key, n);
                splay(n.left);
                records++;
            } else {
                insert(n.left, key);
            }
        } else if (key > n.data) {
            if (n.right == null) {
                n.right = new node(key, n);
                splay(n.right);
                records++;
            } else {
                insert(n.right, key);
            }
        }
    }

    //count nodes
    public int countR(node h) {
        if (h == null) {
            return 0;
        }
        return 1 + countR(h.left) + countR(h.right);
    }

    public void rotate(node T) {	
		node p = T.parent;
		node gp = null;		
		if (p != null) {  gp = p.parent; }				
		if (!T.isRoot()) {
			// Remember whether T is originally left child or right child
			final boolean wasLeft = T.isLeftChild();
			// T has grandparent		
			if (gp != null) {
				// Replace subtree of grandparent with T for Double rotations					
				if (gp.left == p) {
					gp.left = T;
					T.parent = gp;
				}
				else {
					gp.right = T;
					T.parent = gp;
				}
			}
			else {
				// T has no grandparent, set T to the new root.
				root = T;
				T.parent = null;
			}
			// Rotate from left
			if (wasLeft) {
				// Attach T's right child to its parent's left child
				p.left = T.right;
				if (T.right != null) {						
					T.right.parent = p;  // update the parent of T's subtree					
				}
				// Now rotate T, so T's parent becomes T's right child					
				T.right = p;
				if (p != null) {
					p.parent = T;
				}										
			}
			else { // Rotate from right
				// Attach T's left child to its parent's right child
				p.right = T.left;					
				if (T.left != null) {
					T.left.parent = p; // update the parent of T's subtree
				}
				// Now rotate T, so T's parent becomes T's left child
				T.left = p;
				if (p != null) {
					p.parent = T;						
				}					
			}
		}
	}	
    
    //splay
    public void splay(node n) {
    	while(!n.isRoot()) { //splay until node n becomes the root
    		node p = n.parent;
    		node gp = p.parent;
    		
    		//n has a parent but no grandparent
    		if(gp == null) {
    			rotate(n); //zig rotation
    			//rotations++;
    		}
    		else {
    			//n has both parent and grandparent
    			//zig zig
    			if(n.isLeftChild() == p.isLeftChild()) {
    				rotate(p);
    				rotate(n);
    				//rotations++;
    			}
    			else {
    				//node n and its parent are not in the same direction 
    				//zig zag 
    				rotate(n);
    				rotate(n);
    				//rotations++;
    			}
    		}
    	}
    }
    //perform rotationa depending the node
    public void rotate_backup(node n) {
        node p = n.parent;
        node gp = null;

        if (p != null) {
            gp = p.parent;
        }
        if (!n.isRoot()) {
            //mark the position of n, if it is a right or left child
            final boolean wasLeft = n.isLeftChild();

            //n has a grandparent
            if (gp != null) {
                //replace subtree of gp with n for double rotation
                if (gp.left == p) {
                    gp.left = n;
                    n.parent = gp;
                } else {
                    gp.right = n;
                    n.parent = gp;
                }
            } else {
                //n has no grandparent , set n as the new "root"
                root = n;
                n.parent = null;

                //rotate from left
                if (wasLeft) {
                    //attach n right child to parent's left child
                    p.left = n.right;
                    if (n.right != null) {
                        n.right.parent = p; //update the parent of n
                    }

                    //rotate n, so n parent becomes n's right child
                    n.right = p;
                    if (p != null) {
                        p.parent = n;
                    }
                } else {
                    //rotate from right
                    p.right = n.left;
                    if (n.left != null) {
                        n.left.parent = p;// update the parent on n's subtree
                    }

                    //rotate n, so n's parent becomes n's left child
                    n.left = p;
                    if (p != null) {
                        p.parent = n;
                    }
                }
            }
        }
    }
}
