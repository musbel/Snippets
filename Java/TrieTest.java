import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution 
{
	// TRIE node
	// Useful to represent strings. Each character which can start a word is a node
	// where its children represent possible word scenarios. Each time we see a new
	// word we traverse and add the characters to the tree
	public static class Node
	{
		private char id;
		
		// Each node can have every character as a child to form words
		HashMap<Character, Node> children = new HashMap<Character, Node>();
		private int numOfWords = 0;
		
		public Node(char id)
		{
			this.id = id;
		}
		
		// Get a child node for a given character
		private Node getNode(char c)
		{
			return children.get(c);
		}
		
		// Set a child node for a given character
		private void setNode(char c, Node node)
		{
			children.put(c, node);
		}
		
		public void print()
		{
			System.out.print(id + "[" + numOfWords + "] | ");
			for (Map.Entry<Character, Node> entry : children.entrySet())
			{
				System.out.print(entry.getKey() + " ");
			}
			System.out.println();
			for (Map.Entry<Character, Node> entry : children.entrySet())
			{
				entry.getValue().print();
			}
		}
		
		public void add(String s)
		{
			add(s, 0);    
		}
		
		// Add a word
		public void add(String s, int index)
		{
			numOfWords++;

			// As this will be called recursively we check if the index is
			// out of bounds and if so we just return
			if (index == s.length()) return;
			
			// Get the character at this index and check if we have a child
			// which represents it
			char current = s.charAt(index);
			Node child = getNode(current);
			
			// Create a new child for the character if it doesn't exist
			if (child == null)
			{
				child = new Node(current);
				setNode(current, child);
			}
			
			// Call the add function on the child to keep walking the string
			// and creating any necessary child nodes down the tree
			child.add(s, index + 1);
		}
		
		public int findCount(String s)
		{
			return findCount(s, 0);
		}
		
		// Find how many words have a given string as a prefix
		public int findCount(String s, int index)
		{
			// If we've come to the end of the string we've found a word
			if (index == s.length()) return numOfWords;
	
			// Check if child exists
			char current = s.charAt(index);
			Node child = getNode(current);
			if (child == null) return 0;
			
			// Ask the child for its count
			return child.findCount(s, index + 1);
		}
	}
	
	public static void main(String[] args) {
		Node root = new Node('*');
		
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int a0 = 0; a0 < n; a0++){
			String op = in.next();
			String contact = in.next();
			
			if (op.compareTo("add") == 0)
			{
				root.add(contact);
			}
			else if (op.compareTo("find") == 0)
			{
				System.out.println(root.findCount(contact));
			}
			else if (op.compareTo("print") == 0)
			{
				root.print();
			}
		}
	}
}

