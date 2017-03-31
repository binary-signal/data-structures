package sourceAsk1;

import java.util.Random;
import java.util.Vector;

public class Bst {
	private BstNode root=null;
	private int nodeCounter=0;
	
	
	public Bst(int rootValue) {
		root=new BstNode(rootValue);
		nodeCounter++;
	}
	public Bst() {
		root=null;
	}
	
	public BstNode getRoot() {
		return root;
	}
	public void setRoot(BstNode root) {
		this.root = root;
	}
	public int getSize() {
		return nodeCounter;
	}
	public void setSize(int size) {
		this.nodeCounter = size;
	}
	
	public void empty() {
		setRoot(null);
	}
	
	public void insert(int value) {
		insert(root, value);
	}
	public void  insert(BstNode node, int value) {
		if(value<node.getValue()) {
			if(node.getLeft()!=null) {
				insert(node.getLeft(), value);
			}
			else {
				node.setLeft(new BstNode(value));
				nodeCounter++;
			}
		}else if(value>=node.getValue()) {
			if(node.getRight()!=null) {
				insert(node.getRight(), value);
			}
			else {
				node.setRight(new BstNode(value));
				nodeCounter++;
			}
		}
		else if(value==node.getValue()) {
			System.err.println("Value already exists !!!");
		}
		
	}
	public int size() {
		return nodeCounter;
	}
	public void printInOrder() {
		printInOrder(root);
	}
	public void printInOrder(BstNode node) {
	    if (node != null) {
	      printInOrder(node.getLeft());
	      System.out.print(node.getValue()+" ");
	      printInOrder(node.getRight());
	    }
	  }
	public BstNode search(int key) {
		return search(root, key);
	}
	public BstNode search(BstNode node, int key) {
		
		if(node==null) {
			return null;
		}
		else {
			if(node.getValue()==key) {
				System.out.println("Value found !!!");
				return node;
			}
			else {
				if(key<node.getValue()) {
					search(node.getLeft(), key);
				}
				else{
					search(node.getRight(), key);
				}
			}
		}		
		return null;
	}
	public boolean isEmpty() {
		if(root==null) {
			return true;
		}
		else {
			return false;
		}
	}
	public Bst makeBst(int size) {
		Random rand= new Random();
		Bst btree= new Bst(rand.nextInt(Main.randLimit));
		for(int i=0;i<size-1;i++) {
			btree.insert(rand.nextInt(Main.randLimit));
		}
		return btree;
	}
	

}