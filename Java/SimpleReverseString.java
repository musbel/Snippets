class Untitled 
{
	public static String reverse(String str)
	{
		char[] c = str.toCharArray();
		int s = 0;
		int e = str.length() - 1;
		for (int i = 0; i < str.length() / 2 + 1; ++i)
		{
			char temp = c[s];
			c[s] = c[e];
			c[e] = temp;
			s++;
			e--;
		}
		
		return String.valueOf(c);
	}
	
	public static String reverse_bit(String str)
	{
		int start = 0;
		int end = str.length() - 1;
		char[] s = str.toCharArray();
		
		while (start < end)
		{
			s[start] ^= s[end];
			s[end] ^= s[start];
			s[start] ^= s[end];
			start++;
			end--;
		}
		
		return String.valueOf(s);
	}
	
	public static void main(String[] args) 
	{
		String s = "Hello";
		s = reverse_bit(s);
		System.out.println(s);
	}
}