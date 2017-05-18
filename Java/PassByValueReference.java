class Untitled 
{
	public static class A
	{
		int number;
		
		A(int number)
		{
			this.number = number;
		}
	}
	
	public static void changePrim(int n)
	{
		n = 3;
	}
	
	public static void changeObj(A a)
	{
		a.number = 10;
	}
	
	public static void changeObj2(A a, A a2)
	{
		a = a2;
	}
	
	public static void main(String[] args) 
	{
		int k = 2;
		System.out.println("k = " + k);
		changePrim(k);
		System.out.println("k = " + k);
		
		A a = new A(4);
		System.out.println("a = " + a.number);
		changeObj(a);
		System.out.println("a = " + a.number);

		A a2 = new A(8);
		System.out.println("a2 = " + a2.number);
		changeObj2(a, a2);
		System.out.println("a = " + a.number);
	}
}