import java.util.*;

class Node<T extends Comparable<T>>
{
	Node<T> left, right;
	private T data;
	
	Node(T data)
	{
		this.data = data;
	}
	
	public T getData() { return data; }
	public Node<T> leftChild() { return left; }
	public Node<T> rightChild() { return right; }
	
	public void insert(T value)
	{
		if (value.compareTo(data) < 0)
		{
			if (left == null)
			{
				left = new Node<T>(value);
			}
			else 
			{
				left.insert(value);
			}
		}
		else 
		{
			if (right == null)
			{
				right = new Node<T>(value);
			}
			else 
			{
				right.insert(value);
			}
		}
	}
	
	public boolean contains(T value)
	{
		if (value.compareTo(data) == 0)
		{
			// We found it!
			return true;
		}
		else if (value.compareTo(data) < 0)
		{
			// Value is less: Check the left child if we have any
			if (left == null)
				return false;
			else 
				return left.contains(value);
		}
		else
		{
			// Value is more: Check the right child if we have any
			if (right == null)
				return false;
			else
				return right.contains(value);
		}
	}
	
	public void printInOrder()
	{
		if (left != null) { left.printInOrder(); }
		System.out.print(data + " | ");
		if (hasLeftChild()) System.out.print("L: " + left.getData() + "  ");
		if (hasRightChild()) System.out.print("R: " + right.getData());
		System.out.println();
		if (right != null) { right.printInOrder(); }
	}
	
	public void printPreOrder()
	{
		System.out.println(data);
		if (left != null) { left.printPreOrder(); }
		if (right != null) { right.printPreOrder(); }
	}
	
	public void printPostOrder()
	{
		if (left != null) { left.printPostOrder(); }
 		if (right != null) { right.printPostOrder(); }
		System.out.println(data);
	}
	
	public void printBFS()
	{
		LinkedList<Node> nodesToVisit = new LinkedList<Node>();
		nodesToVisit.add(this);
		
		while (!nodesToVisit.isEmpty())
		{
			Node node = nodesToVisit.remove();
			System.out.println(node.getData());
			
			if (node.hasLeftChild()) { nodesToVisit.add(node.leftChild()); }
			if (node.hasRightChild()) { nodesToVisit.add(node.rightChild()); }
		}
	}
	
	public boolean hasLeftChild()
	{
		return left != null;
	}
	
	public boolean hasRightChild()
	{
		return right != null;
	}
	
	public Node<T> leftMostChild()
	{
		Node<T> node = this;
		while (node.hasLeftChild())
		{
			node = node.leftChild();
		}
		
		return node;
	}
	
	public Node<T> rightMostChild()
	{
		Node<T> node = this;
		while (node.hasRightChild())
		{
			node = node.rightChild();
		}
		
		return node;
	}
	
	public boolean isBst()
	{
		// If our value is smaller than the left most child then we are not a BST
		if (hasLeftChild() && getData().compareTo(leftMostChild().getData()) < 0) 
			return false;
		
		// If our value is bigger than the right most child then we are not a BST
		if (hasRightChild() && getData().compareTo(rightMostChild().getData()) > 0) 
			return false;
		
		// Traverse down the tree on both sides and repeat
		if (hasLeftChild() && !leftChild().isBst() || hasRightChild() && !rightChild().isBst()) 
			return false;
		
		return true;
	}
	
	public static void main(String[] args) 
	{
		Node<Integer> root = new Node<Integer>(10);
		root.insert(5);
		root.insert(15);
		root.insert(8);
		root.insert(1);
		root.printInOrder();
//		root.printPreOrder();
//		root.printPostOrder();
		System.out.println("Contains 3? " + root.contains(3));
		System.out.println("Contains 8? " + root.contains(8));
		
		System.out.println("Left most child: " + root.leftMostChild().getData());
		
		System.out.println("Breadth First Search Traversal");
		root.printBFS();
		
		System.out.println("Is BST: " + root.isBst());
	}
}
