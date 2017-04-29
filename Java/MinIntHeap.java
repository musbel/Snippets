import java.util.*;

public class MinIntHeap 
{
	MinIntHeap(int capacity)
	{
		this.capacity = capacity;
	}
	
	// Uses an array to be more compact (could use a class with left and right child)
	private int capacity = 10;
	private int size = 0;
	
	int[] items = new int[capacity];

	// An example to keep in mind
	//         2
	//    3        5
	//  7   9   12   18
	// [2, 3, 5, 7, 9, 12, 18]
	// [0, 1, 2, 3, 4, 5, 6] (inds)

	void print()
	{
		System.out.print("Heap: ");
		for (int item : items)
		{
			System.out.print(item + " ");
		}
		System.out.println();

		for (int i = 0; i < size; i++)
		{
			System.out.print(items[i] + " ");
			if (hasLeftChild(i))
				System.out.print("(L) " + leftChild(i) + " ");
			if (hasRightChild(i))
				System.out.print("(R) " + rightChild(i) + " ");

			System.out.println();
		}
	}

	// Find left child index given a node index (its parent)
	// [2, 3, 5, 7, 9, 12, 18]
	// Given 5 (index 2), find left child 12 (index 5) -> 2 * 2 + 1 = 5
	private int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }

	// Same as for left child but we need to increment by 2 to get to the right child
	private int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
	
	// Find a parent index given a child index
	// [2, 3, 5, 7, 9, 12, 18]
	// Given 7 (index 3), find parent 3 (index 1) -> (3 - 1) / 2 = 1
	// Given 12 (index 5), find parent 5 (index 2) -> (5 - 1) / 2 = 2
	// Given 18 (index 6), find parent 5 (index 2) -> (6 - 1) / 2 = 2.5 ~ 2
	private int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }	
	
	// Check if node in the heap has a left child
	// We do this by checking if the child index does not exceed the heap size (running size)
	private boolean hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
	
	private boolean hasRightChild(int index) { return getRightChildIndex(index) < size; }
	private boolean hasParent(int index) { return getParentIndex(index) >= 0; }
	
	// Get left child by returning its index in the array (should check if it exists)
	private int leftChild(int index) { return items[getLeftChildIndex(index)]; }
	private int rightChild(int index) { return items[getRightChildIndex(index)]; }
	private int parent(int index) { return items[getParentIndex(index)]; }
	
	// Swap two nodes
	private void swap(int index1, int index2)
	{
		int temp = items[index1];
		items[index1] = items[index2];
		items[index2] = temp;
	}
	
	private void ensureExtraCapacity()
	{
		if (size == capacity)
		{
			items = Arrays.copyOf(items, capacity * 2);
			capacity *= 2;
		}
	}
	
	public int peek()
	{
		if (size == 0) throw new IllegalStateException();
		return items[0];
	}
	
	public int poll()
	{
		if (size == 0) throw new IllegalStateException();
		int item = items[0];
		items[0] = items[size - 1];
		size--;
		
		heapifyDown();
		return item;
	}
	
	public void add(int item)
	{
		ensureExtraCapacity();
		items[size] = item;
		size++;
		
		heapifyUp();
	}
	
	public void heapifyUp()
	{
		// Start with the last element as we're going up
		int index = size - 1;
		while (hasParent(index) && parent(index) > items[index])
		{
			swap(index, getParentIndex(index));
			index = getParentIndex(index);
		}
	}
	
	public void heapifyDown()
	{
		// Start with the first element	as we're going down
		int index = 0;
		while (hasLeftChild(index)) // Only need to check left
		{
			// Determine which child value is smaller
			int smallerChildIndex = getLeftChildIndex(index);
			if (hasRightChild(index) && rightChild(index) < leftChild(index))
			{
				smallerChildIndex = getRightChildIndex(index);
			}
			
			// If the element is smaller than its smallest child then
			// the heap is good
			if (items[index] < items[smallerChildIndex]) 
			{
				break;
			}
			else 
			{
				// Otherwise swap the element with its smaller child
				swap(index, smallerChildIndex);
			}
			
			// Go to the smaller child and repeat
			index = smallerChildIndex;
		}
	}
	
	public static void main(String[] args) 
	{
		MinIntHeap heap = new MinIntHeap(10);
		
		// We're expecting:
		//         2
		//    5         3
		// 14   20   10
		heap.add(10);
		heap.add(14);
		heap.add(2);
		heap.add(5);
		heap.add(20);
		heap.add(3);
		heap.print();
		System.out.println();
		
		// Poll top element: Remove 2, put last (10) at the top and then update heap (down)
		// Now we're expecting:
		//         3
		//    5         10
		// 14   20		
		heap.poll();
		heap.print();
	}
}