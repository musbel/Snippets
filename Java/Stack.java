public class Stack<T extends Comparable<T>>
{
	// Stack node in a linked list
	private static class Node<T>
	{
		T data;
		Node<T> next = null;
		
		Node(T data)
		{
			this.data = data;
		}
	}
	
	// The stack has a top node and we always push/pop using the top
	// to implement the LIFO (Last In First Out) stack behaviour
	private Node top = null;
	
	public boolean isEmpty()
	{
		if (top == null) return true;
		return false;
	}
	
	public void push(T data)
	{
		// Start by creating a new node we want to push
		Node<T> node = new Node<T>(data);
		
		// The current top will be the next node as the
		// new node will replace it as the new head.
		
		// Therefore, start by telling the new node that
		// its next slot points to the old head.
		node.next = top;
		
		// Now replace the top with the new node
		top = node;
	}
	
	public T pop()
	{
		if (top == null)
		{
			// TODO: Handle using e.g. exception
		}
		
		// Grap the data from the top so we can return it later
		Node<T> popped = top;
		
		// We're popping the top node so the next node connected
		// to the current top is assigned as the new top node
		top = top.next;
			
		// Remove the top node by disconnecting its next slot
		popped.next = null;
		
		// Return the popped value
		return popped.data;
	}
	
	public static void main(String[] args) 
	{
		Stack<Character> stack = new Stack<Character>();
		stack.push('[');
		stack.push('{');
		stack.push('(');
		stack.push('<');
		
		while (!stack.isEmpty())
		{
			System.out.println(stack.pop());		
		}
	}
}
