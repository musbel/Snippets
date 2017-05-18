class HashTable<K, V>
{
	private int hashSize;
	private Node<K, V>[] entries;

	class Node<K, V>
	{
		K key;
		V value;

		Node next;
		
		Node(K key, V value, Node<K, V> next)
		{
			this.key = key;
			this.value = value;
			this.next = next;
		}
	}
	
	HashTable(int hashSize)
	{
		this.hashSize = hashSize;
		this.entries = new Node[hashSize];
	}
	
	// We need some hashing function to get array indices for our keys
	// We make sure the hash index fits within our hash table size
	private int getIndex(K key)
	{
		return key.hashCode() % hashSize;
	}
	
	public void add(K key, V value)
	{
		// We get the hash code (array index) for our key
		int hashIndex = getIndex(key);
		Node<K, V> entry = new Node<K, V>(key, value, entries[hashIndex]);
		entries[hashIndex] = entry;
	}
	
	public V get(K key)
	{
		int hashIndex = getIndex(key);
		Node<K, V> node = entries[hashIndex];
		while (node != null)
		{
			if (node.key == key)
				return node.value;
			
			node = node.next;
		}
		
		return null;
	}
	
	public String toString()
	{
		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < hashSize; i++)
		{
			builder.append("Hash Index: " + i + "\n");
			Node entry = entries[i];
			while (entry != null)
			{
				builder.append(" - " + entry.key + " : " + entry.value + "\n");
				entry = entry.next;
			}
		}
		
		return builder.toString();
	}
	
	public static void main(String[] args) 
	{
		HashTable<String, Integer> map = new HashTable<String, Integer>(1);
		map.add("John", 1);
		map.add("Smith", 2);
		map.add("Bill", 3);
		
//		System.out.println(map.toString());
		System.out.println(map.get("Bill"));
	}
}