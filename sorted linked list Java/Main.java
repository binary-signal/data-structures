import java.util.Random;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		linkedList l = new linkedList();
		Random r = new Random();
		for(int i=0;i<5;i ++) {
			int num = r.nextInt(100);
			l.insert(num);
		}
		l.print();
		l.sort();
		l.print();
		
		
		
		//System.out.println(l.isSorted());
		
	}
	
	 
}
