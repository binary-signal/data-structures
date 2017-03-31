public class node {

    public int data;
    public node left;
    public node right;
    public node parent;

    public node(int data, node parent) {
        this.data = data;
        left = right = null;
        this.parent = parent;
    }


    public boolean isLeaf() {
        if ((this != null && left == null) && (this != null && right == null)) {
            return true;
        }
        return false;
    }

    public boolean hasLeftChild() {
        if(left != null) {
            return true;
        }
        return false;
    }

    public boolean hasRightChild() {
        if(right != null) {
            return true;
        }
        return false;
    }

     //check if this node is the root node
    public boolean isRoot() {
        if(parent == null) {
            return true;
        }
        return false;
    }

    public boolean isLeftChild() {
        if(parent != null && parent.left == this) {
            return true;
        }
        return false;
    }

    public boolean isRightChild() {
        if(parent != null && parent.right == this) {
            return true;
        }
        return false;
    }

    //print node
    public void print() {
        System.out.print(" "+data+" ");
    }
    
    public void print2() {
    	System.out.println(data);
    }

    public void print(boolean verbose) {
        if (verbose == false) {
            System.out.print(" " + data + " ");
        } else {
            System.out.println("****************************");
            System.out.println("Node id:" + this.toString());
            System.out.println("Node data: " + data);
            if (left != null) {
                System.out.print("Left Child: " + left.data);
            } else {
                System.out.print(" Left Child: null");
            }
            if (right != null) {
                System.out.print(" Right Child: " + right.data);
            } else {
                System.out.print(" Right Child: null");
            }
            System.out.println();
            if (parent != null) {
                System.out.println("Parent Node: " + parent.data);
            } else {
                System.out.println("Parent Node: null (root)");
            }
            System.out.println("****************************");
        }

    }

}
