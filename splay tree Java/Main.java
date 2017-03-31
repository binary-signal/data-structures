import java.util.Random;

public class Main {


	 
	public static void main(String[] args) {
		splaytree tree = new splaytree();
		
		tree.insert(5);
		tree.printPostOrder(tree.root);
		System.out.println();
		tree.insert(3);
		tree.printPostOrder(tree.root);
		System.out.println();
		tree.insert(10);
		tree.printPostOrder(tree.root);
		System.out.println();
		tree.insert(1);
		tree.printPostOrder(tree.root);
		System.out.println();
		tree.insert(4);
		tree.printPostOrder(tree.root);
		System.out.println();
		tree.insert(7);
		tree.printPostOrder(tree.root);
		System.out.println();
		tree.insert(12);
		
		tree.printPostOrder(tree.root);
		System.out.println();
		
		//check tree for 9 nodes
		if(tree.countR(tree.root) == 7) {
			System.out.println("OK");
		}
		
		System.out.println("Search");
		tree.search(tree.root, 7);
		
		tree.printPostOrder(tree.root);
		
		System.out.println("Depth check :");
		System.out.println(tree.node_depth(tree.root, tree.root.left.left));
	
	}

}
