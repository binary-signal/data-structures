package sourceAsk1;

public class BstNode {
	private BstNode right;
	private BstNode left;
	private int value;
	
	public BstNode(int value) {
		this.value=value;
		right=null;
		left=null;
	}

	public BstNode getRight() {
		return right;
	}

	public void setRight(BstNode right) {
		this.right = right;
	}

	public BstNode getLeft() {
		return left;
	}

	public void setLeft(BstNode left) {
		this.left = left;
	}

	public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}

}
