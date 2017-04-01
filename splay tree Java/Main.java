import splaytree.splaytree;
import splaytree.node;

public class Main {
    public static void main(String[] args) {
        splaytree tree = new splaytree();

        System.out.println("Insert 5");
        tree.insert(5);
        System.out.println("Print tree:");
        tree.printPostOrder(tree.root);
        System.out.println();

        System.out.println("Insert 3");
        tree.insert(3);
        System.out.println("Print tree:");
        tree.printPostOrder(tree.root);
        System.out.println();

        System.out.println("Insert 10");
        tree.insert(10);
        System.out.println("Print tree:");
        tree.printPostOrder(tree.root);
        System.out.println();

        System.out.println("Insert 1");
        tree.insert(1);
        System.out.println("Print tree:");
        tree.printPostOrder(tree.root);
        System.out.println();

        System.out.println("Insert 4");
        tree.insert(4);
        System.out.println("Print tree:");
        tree.printPostOrder(tree.root);
        System.out.println();

        System.out.println("Insert 7");
        tree.insert(7);
        System.out.println("Print tree:");
        tree.printPostOrder(tree.root);
        System.out.println();

        System.out.println("Insert 12");
        tree.insert(12);
        System.out.println("Print tree:");
        tree.printPostOrder(tree.root);
        System.out.println();

        //check tree for 7 nodes
        System.out.print("Check number of nodes in tree: ");
        if (tree.countR(tree.root) == 7) {
            System.out.println("OK");
        }


        System.out.println("Search key 7 in tree: ");
        node res = tree.search(tree.root, 7);
        if (res != null) {
            System.out.println("Key 7 found in the tree");
            res.print(true);

        }
        System.out.print("\n");


        System.out.print("\nDepth of tree:");
        System.out.println(tree.node_depth(tree.root, tree.root.left.left));

    }

}
