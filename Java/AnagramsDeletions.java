import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution 
{
	private static int NUMBER_OF_CHARS = 26;
	
	private static int[] getCharCount(String s)
	{
		int[] count = new int[NUMBER_OF_CHARS];
		for (int i = 0; i < s.length(); ++i)
		{
			char current = s.charAt(i);
			int charCode = current - 'a';
			count[charCode]++;
		}
		
		return count;
	}
	
	private static int deletionsRequired(int[] first, int[] second)
	{
		if (first.length != second.length) return -1;
		int deletions = 0;
		for (int i = 0; i < first.length; ++i)
		{
			deletions += Math.abs(first[i] - second[i]);
		}
		
		return deletions;
	}
	
	public static int numberNeeded(String first, String second) 
	{
		int[] charCountFirst = getCharCount(first);
		int[] charCountSecond = getCharCount(second);
		return deletionsRequired(charCountFirst, charCountSecond);
	}
  
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		String a = in.next();
		String b = in.next();
		System.out.println(numberNeeded(a, b));
	}
}

