package sourceAsk1;

import java.util.Vector;

public class Main {
	
	public static int randLimit=10;
	public static int N=20;
	
	public static void main(String[] args) {

		Bst bst=new Bst();
		bst=bst.makeBst(N);
		bst.printInOrder();
		System.out.println();
		
	
		
		
		System.out.println("Bst Size : "+bst.getSize());	
		}
	}
	
	


