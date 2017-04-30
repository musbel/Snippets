public class LinkedList<T extends Comparable<T>> 
{
	Node<T> head = null;
	Node<T> tail = null;
	
	class Node<T>
	{
		Node<T> next = null;
		Node<T> prev = null;
		T data;
		
		public Node(T data)
		{
			this.data = data;
		}
	}
	
	public void append(T data)
	{
		if (head == null) 
		{ 
			head = new Node<T>(data);
			tail = head;
			return;
		}
		
		Node<T> current = head;
		while (current.next != null)
		{
			current = current.next;
		}
		
		Node<T> newNode = new Node<T>(data);
		current.next = newNode;
		newNode.prev = current;
		tail = newNode;
	}
	
	public void prepend(T data)
	{
		Node newHead = new Node<T>(data);
		newHead.next = head;
		head.prev = newHead;
		head = newHead;
	}
	
	public void insert(T data)
	{
		insert(data, 0);
	}
	
	public void insert(T data, int index)
	{
		if (index < 0 || (head == null && index != 0)) 
			return;	// TODO: Perhaps throw an exception
		
		if (head == null && index == 0)
			append(data);
			
		Node<T> current = head;
		for (int i = 0; i < index; i++)
		{
			if (current.next == null) 
				return;	// TODO: Perhaps throw an exception
			
			current = current.next;
		}
		
		if (current.next == null)
		{
			// There's no next node in the list so we just append it
			current.next = new Node<T>(data);
			current.next.prev = current;
		}
		else 
		{
			// Create a new node
			Node<T> node = new Node<T>(data);
			
			// Reference old next node
			Node<T> oldNext = current.next;

			// New node takes over the current next slot
			node.next = oldNext;
			
			// New node connects back to current
			node.prev = current;
			
			// Update the current and old next node to point to the new node
			current.next = node;
			oldNext.prev = node;
		}
	}
	
	public void deleteValue(T value)
	{
		if (head == null) return;
		
		// Special case if we're deleting the head
		if (head.data.compareTo(value) == 0)
		{
			head = head.next;
		}
		
		Node<T> current = head;
		while (current.next != null)
		{
			// Special case if we're deleting the tail
			if (current.next == tail)
			{
				current.next = null;
				return;
			}
			
			// If the next node contains the value we're looking for
			// we bypass the node and connect the current node to
			// the next one along. Since this is Java the garbage
			// collection will delete it at some point
			if (current.next.data.compareTo(value) == 0)
			{
				current.next = current.next.next;
				current.next.prev = current;
				
				return;
			}
			
			// We haven't found the value yet so keep going
			current = current.next;
		}
	}
	
	public void print(String description)
	{
		System.out.println(description + ":");
		Node current = head;
		while (current != null)
		{
			System.out.print(current.data);
			if (current.next != null) System.out.print(" -> ");
			current = current.next;
		}
		System.out.println();
	}
	
	public void printReverse(String description)
	{
		System.out.println(description + ":");
		Node current = tail;
		while (current != null)
		{
			System.out.print(current.data);
			if (current.prev != null) System.out.print(" -> ");
			current = current.prev;
		}
		System.out.println();
	}
	
	public static void main(String[] args) 
	{
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.append(4);
		list.append(6);
		list.append(7);
		list.append(9);
		list.append(10);
		list.append(12);
		list.print("Append some values");
		
		list.prepend(2);
		list.print("Prepend 2");
		
		list.insert(15, 4);
		list.print("Insert 15 (4th)");
		
		list.deleteValue(7);
		list.print("Delete 7");
		
		list.printReverse("Reverse");
	}
}