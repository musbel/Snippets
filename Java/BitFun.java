import java.util.*;

class BitFun
{
	public static int getBit(int n, int i)
	{
		int bitSet = ((n & (1 << i)) > 0) ? 1 : 0;
		return bitSet;
	}
	
	public static int setBit(int n, int i)
	{
		return (n | (1 << i));
	}
	
	public static int clearBit(int n, int i)
	{
		return (n & (~(1 << i)));
	}
	
	public static void toBinary(int n)
	{
		toBinary(n, 8);
	}
	
	public static void toBinary(int n, int numDigits)
	{
		for (int i = 0; i < numDigits; i++)
		{
			System.out.print(getBit(n, i));
		}
		System.out.println();
	}
	
	public static int countBits(int n)
	{
		int numBits = 0;
		for (int i = 0; i < 32; i++)
		{
			numBits += ((n & (1 << i)) > 0) ? 1 : 0;
		}
		return numBits;
	}
	
	public static ArrayList<ArrayList<Integer>> powerset(ArrayList<Integer> n)
	{
		ArrayList<ArrayList<Integer>> _powerset = new ArrayList<ArrayList<Integer>>();
		
		for (int i = 0; i < (1 << n.size()); i++)
		{
			ArrayList<Integer> ss = new ArrayList<Integer>();
			for (int j = 0; j < n.size(); j++)
			{
				if (((1 << j) & i) > 0)
					ss.add(n.get(j));
			}
			
			_powerset.add(ss);
		}
		
		return _powerset;
	}
		
	public static void main(String[] args) 
	{
		int n = 4;
		toBinary(n);
		System.out.println(setBit(n, 0));
		System.out.println(clearBit(5, 0));
		
		
		System.out.println(">>>" + countBits(-5));
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(1);
		list.add(2);
		list.add(3);
		ArrayList<ArrayList<Integer>> p = powerset(list);
		System.out.println(p);
	}
}