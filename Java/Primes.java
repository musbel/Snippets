import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {
	public static boolean isPrime(int n)
	{
		// If less than 2 then it's not a prime, 2 is a prime
		if (n < 2) return false;
		if (n == 2) return true;
		
		// If the number is even (and not 2) then it's not a prime
		if ((n & 1) == 0) return false;
		
		for(int i = 3; i < Math.sqrt(n) + 1; i += 2)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		
		return true;
	}
	
	static void primeNumbers(int val)
	{
		List<Integer> primes = new ArrayList<Integer>();
		for (int n = 0; n < val; ++n)
		{
			if (n < 2) continue;
			if (n == 2) System.out.println(n);
			mmmimon
			// If the number is even (and not 2) then it's not a prime
			if ((n & 1) == 0) continue;
			
			for(int i = 3; i < n; i += 2)
			{
				System.out.println("> " + i);
				if (n % i == 0)
				{
					System.out.println("Not prime: " + n);
//					continue;
				}
				else 
				{
					System.out.println("fff");
					System.out.println(n);
				}
			}
		}
	}
	
	public static void main(String[] args) {
		primeNumbers(7);
		
		Scanner in = new Scanner(System.in);
		int p = in.nextInt();
		for(int a0 = 0; a0 < p; a0++){
			int n = in.nextInt();
			if (isPrime(n))
				System.out.println("Prime");
			else
				System.out.println("Not prime");
		}
	}
}

