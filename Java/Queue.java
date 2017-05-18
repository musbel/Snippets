public class Queue<T extends Comparable<T>>
{
	private static class Node<T>
	{
		private T data;
		Node<T> next = null;
		
		// Doubly linked list to support double ended queue
		Node<T> prev = null;
		
		Node(T data)
		{
			this.data = data;
		}
	}
	
	private Node<T> front = null;
	private Node<T> back = null;
	
	public boolean isEmpty()
	{
		if (front == null) return true;
		return false;
	}
	
	public T peek()
	{
		if (front == null)
		{
			// TODO: Throw exception etc.	
		}
		
		// Return the data at the front of the queue
		return front.data;
	}
	
	public T peek_back()
	{
		if (back == null) {}
		
		return back.data;
	}
	
	// Pop from the front of the queue
	public T remove()
	{
		// The front node is the first one out so we grab its data
		// and then return it later
		T data = front.data;
		
		// We remove it by asking the next node in line to be
		// the new front of the line
		front = front.next;
		
		return data;
	}
	
	// Push to the back of the queue (we could return the newly created node)
	public void add(T data)
	{
		// Create a new node which will go at the back of the queue
		Node<T> node = new Node(data);
		
		// If we have no queue just add the node as the back and front
		// of the queue
		if (back == null)
		{
			front = node;
			back = node;
			return;
		}
		
		// If there is something in the queue, we add it to the back
		// The current back of the queue will connect its next slot
		// to the new (back) node
		back.next = node;
		back = node;
	}
	
	public static void main(String[] args) 
	{
		Queue<Integer> queue = new Queue<Integer>();
		
		queue.add(1);
		queue.add(2);
		queue.add(3);
		queue.add(4);
		
		// Remove and print the queue elements. They should be in ascending
		// order as a queue is FIFO
		while (!queue.isEmpty())
		{
			System.out.println(queue.remove());
		}
	}
}