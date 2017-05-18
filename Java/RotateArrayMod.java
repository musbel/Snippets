import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution 
{	
	public static int[] arrayLeftRotation(int[] a, int n, int k) 
	{
		int[] rotatedArray = new int[n];
		
		// Go through item and find the target index using
		// modulus and swap with current index
		for (int i = 0; i < n; i++)
		{
			int targetIndex = (((i - k) % n) + n) % n;
			rotatedArray[targetIndex] = a[i];
		}
		
		return rotatedArray;
	}
	
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		int a[] = new int[n];
		for(int a_i=0; a_i < n; a_i++){
			a[a_i] = in.nextInt();
		}
	  
		int[] output = new int[n];
		output = arrayLeftRotation(a, n, k);
		for(int i = 0; i < n; i++)
			System.out.print(output[i] + " ");
	  
		System.out.println();
	  
	}
}

