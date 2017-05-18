import java.util.*;

class Solution 
{
	Map<String, Integer> magazineMap;
	Map<String, Integer> noteMap;
	
	private void addWordsToMap(String words, Map<String, Integer> map)
	{
		StringTokenizer tokens = new StringTokenizer(words);
		while (tokens.hasMoreTokens())
		{
			String word = tokens.nextToken();
			if (!map.containsKey(word))
				map.put(word, 1);
			else
				map.put(word, map.get(word) + 1);
		}
	}
	
	public Solution(String magazine, String note) 
	{
		magazineMap = new HashMap<String, Integer>();
		noteMap = new HashMap<String, Integer>();
		addWordsToMap(magazine, magazineMap);
		addWordsToMap(note, noteMap);
	}
	
	public boolean solve(int numWordsMagazine, int numWordsNote) 
	{
        if (numWordsNote > numWordsMagazine) return false;
        
		// Go through each word in the ransom note and check if we have word in the magazine
		// We make sure we go test each word as many time as it appears int the ransom note,
		// making sure we have enough words in the magazine, where we decrement the word count 
		// in the magazine each time.
        int numMatches = 0;
		for (Map.Entry<String, Integer> entry : noteMap.entrySet())
		{
			String word = entry.getKey();
			for (int i = 0; i < entry.getValue(); i++)
			{
				// Find the word in the magazine
				if (magazineMap.containsKey(word))
				{
					// Make sure we haven't used up all occurrences
					// of this word in the magazine
					int wordCount = magazineMap.get(word);
					if (wordCount == 0) return false;
					magazineMap.put(word, wordCount - 1);
                    numMatches++;
				}
				else 
				{
					return false;
				}
			}
		}
		
        // Make sure we've managed to find a match for all the words in the ransom note
        return numWordsNote == numMatches;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		int n = scanner.nextInt();
		
		// Eat whitespace to beginning of next line
		scanner.nextLine();
		
		Solution s = new Solution(scanner.nextLine(), scanner.nextLine());
		scanner.close();
		
		boolean answer = s.solve(m, n);
		if(answer)
			System.out.println("Yes");
		else System.out.println("No");
	  
	}
}


