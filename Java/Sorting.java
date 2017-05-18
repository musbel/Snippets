class Sorting
{
	public static void swap(int[] array, int i, int j)
	{
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	
	public static void bubbleSort(int[] array)
	{
		boolean isSorted = false;
		
		// Optimisation: 
		// After one go of sorting, the last element will always been propagated to the back
		// so we can decrement this after each sort iteration
		int lastUnsorted = array.length - 1;
		
		while (!isSorted)
		{
			isSorted = true;
			for (int i = 0; i < lastUnsorted; i++)
			{
				if (array[i] > array[i + 1])
				{
					swap(array, i, i + 1);
					isSorted = false;
				}
			}
			lastUnsorted--;
		}
	}
	
	public static void mergeSort(int[] array)
	{
		// Start by sorting the whole array using merge sort
		// Define a temp array which will be used for merging
		mergeSort(array, new int[array.length], 0, array.length - 1);
	}
	
	private static void mergeSort(int[] array, int[] temp, int startLeft, int endRight)
	{
		// Check base condition
		if (startLeft >= endRight)
			return;
		
		// Find the middle point
		int middle = (startLeft + endRight) / 2;
		
		// Sort left half going from the current start left to the middle
		mergeSort(array, temp, startLeft, middle);
		
		// Sort right half going from the middle to the current end on the right
		mergeSort(array, temp, middle + 1, endRight);
		
		// Merge the two halves
		mergeHalves(array, temp, startLeft, endRight);
	}
	
	private static void copyArray(int[] array, int start, int[] source, int sourceStart, int sourceEnd)
	{
		while (sourceStart <= sourceEnd)
		{
			array[start] = source[sourceStart];
			start++;
			sourceStart++;
		}
	}
	
	private static void mergeHalves(int[] array, int[] temp, int startLeft, int endRight)
	{
		// Define boundaries for where the first half ends and the right one begins
		// The left half ends at the mid-point which is calculated as before
		int endLeft = (startLeft + endRight) / 2;
		// The start of the right half simply begins right behind where the left one ends
		int startRight = endLeft + 1;
		
		// Go through each half and exhaust both halfs until one may have some elements left
		// which we'll deal with later by just adding them on (they're ordered so simples)
		int index = startLeft;	// Running index for the temp array
		int left = startLeft;	// Running index for the left half
		int right = startRight;	// Running index for the right half
		
		while (left <= endLeft && right <= endRight)
		{
			// Copy the smaller of the two item (from left and right halves)
			// to the temp array and update all the running indices
			if (array[left] <= array[right])
			{
				temp[index] = array[left];
				left++;
			}
			else 
			{
				temp[index] = array[right];
				right++;
			}
			
			index++;
		}
		
		// Now we have some elements remaining (in either the left of right half) so we copy
		// them to the temp array
		copyArray(temp, index, array, left, endLeft);
		copyArray(temp, index, array, right, endRight);
				
		// Update the array from the merged temp array
		copyArray(array, startLeft, temp, startLeft, endRight);
	}
	
	public static void quickSort(int[] array)
	{
		quickSort(array, 0, array.length - 1);
	}
	
	private static void quickSort(int[] array, int left, int right)
	{
		// Base condition
		if (left >= right)
			return;
		
		// Pick a pivot point as the mid-point
		int pivotPosition = (left + right) / 2;
		int pivot = array[pivotPosition];
		
		int partitionIndex = sortPartitions(array, left, right, pivot);
		
		quickSort(array, left, partitionIndex - 1);
		quickSort(array, partitionIndex, right);
	}
	
	private static int sortPartitions(int[] array, int left, int right, int pivot)
	{
		// The pivot is somewhere in the middle and the values on the left side
		// should be smaller, and the values on the right should be larger
		
		// Continue until running indices for left and right overlap
		while (left <= right)
		{
			// Walk left until we find a value which is larger than the pivot
			while (array[left] < pivot)
				left++;
			
			// Walk right until we find a value which is smaller than the pivot
			while (array[right] > pivot)
				right--;
				
			// Compare the values on the left and right of the pivot and swap
			// them if they are out of order (left should be smaller).
			//
			// We don't need to fetch the values as the indices have been updated
			// such that what they're pointing at already satisfy that the left
			// one is bigger than the pivot, and the right one is smaller than
			// the pivot. Therefore, we just have to check if the indices for
			// left and right haven't overlapped.
			if (left <= right)
			{
				swap(array, left, right);
				
				// Move both indices
				left++;
				right--;
			}
		}
		
		// Return the partition position which is the left index
		return left;
	}
	
	public static int binarySearch(int[] array, int n)
	{
		return binarySearch(array, n, 0, array.length - 1);
	}
	
	private static int binarySearch(int[] array, int n, int left, int right)
	{
		if (right >= left)
		{
			int middle = left + (right - left) / 2;	// Less likely to overflow than (right + left) / 2
			
			// If the value is the middle element being examined then return the index
			if (array[middle] == n)
				return middle;
				
			if (n < array[middle])
				return binarySearch(array, n, left, middle - 1);

			return binarySearch(array, n, middle + 1, right);
		}
		
		// We didn't find the element, return -1 as index
		return -1;
	}
	
	public static void printArray(int[] array, String description)
	{
		System.out.print(description + ": ");
		for (int elm : array)
			System.out.print(elm + " ");
			
		System.out.println();
	}
	
	public static void binarySearchTest(int[] array, int n)
	{
		int idx = binarySearch(array, n);
		if (idx == -1)
		{
			System.out.println("Element " + n + " not found in array");
		}
		else 
		{
			System.out.println("Element " + n + " found at index " + idx + " | Value = " + array[idx]);
			assert(n == array[idx]);	
		}
	}
	
	public static void main(String[] args) 
	{
		int[] array = {4, 7, 2, 15, 1, 9, 8, 3, 12};
		printArray(array, "Unsorted array");

//		bubbleSort(array);
//		mergeSort(array);
		quickSort(array);
		
		printArray(array, "Sorted array");
		
		// Now that our array is sorted we can use binary search to look for elements
		binarySearchTest(array, 12);
		binarySearchTest(array, 13);
	}
}