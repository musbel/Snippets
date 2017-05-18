import java.util.*;

class Permutations 
{
	public static void permutations(String word)
	{
		permutations(word, "");
	}
	
	private static void permutations(String word, String perm)
	{
		System.out.println("W[" + word + "] P[" + perm + "]");
		if (word.isEmpty()) 
		{
			System.err.println("- " + perm + word);
		} 
		else 
		{
			for (int i = 0; i < word.length(); i++) 
			{
				permutations(word.substring(0, i) + word.substring(i + 1, word.length()), perm + word.charAt(i));
			}
		}
	}
	
	private static void powerset(String word, HashSet<String> set)
	{
		set.add(word);
		for (int i = 0; i < word.length(); ++i)
		{
			powerset(word.substring(0, i) + word.substring(i + 1, word.length()), set);
		}
	}
	
	private static void powerset_bit(ArrayList<Integer> input, ArrayList<Integer> set)
	{
		for (int i = 0; i < (1 << input.size()); ++i)
		{
			ArrayList<Integer> ss = new ArrayList<Integer>();
			for (int j = 0; j < input.size(); ++j)
			{
				if ((i & (1 << j)) > 0)
					ss.add(input.get(j));
			}
			
			for (Integer k : ss)
				set.add(k);
		}
	}
	
	public static void main(String[] args) 
	{
		permutations("123");
		
		ArrayList<Integer> input = new ArrayList<Integer>(Arrays.asList(1, 2, 3));
		ArrayList<Integer> set = new ArrayList<Integer>();
		powerset_bit(input, set);
		for (Integer s : set) System.out.print("'" + s + "' ");		
	}
}