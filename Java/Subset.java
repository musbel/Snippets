class Substrings 
{
	public static boolean findSubstring(String s, String ss)
	{
		char[] string = s.toCharArray();
		char[] substr = ss.toCharArray();

		// A substring cannot be longer than the string
		if (substr.length > string.length) return false;
		if (string.length == 0) return true;
		
		for (int i = 0; i < string.length; ++i)
		{
			boolean foundMatch = true;
			for (int j = 0; j < substr.length; ++j)
			{
				if (string[i + j] != substr[j])
				{
					foundMatch = false;
					break;
				}			
			}
			
			if (foundMatch)
				return true;
		}
		
		return false;
	}
	
	public static void main(String[] args) 
	{
		System.out.println(findSubstring("abcabcabcd", "abcabcd"));
	}
}