import java.util.*;

public class Graph<T>
{
	// The graph keeps a map of values and nodes
	private HashMap<T, Node> nodeMap = new HashMap<T, Node>();
	
	// A node which makes up the graph by connecting to other nodes
	private class Node
	{
		// The node has data, here simply an id for testing
		T id;
		
		// We keep a list of adjacent nodes
		LinkedList<Node> adjacent = new LinkedList<Node>();
		
		Node(T id)
		{
			this.id = id;
		}
	}
	
	public void addNode(T id)
	{
		Node node = new Node(id);
		nodeMap.put(id, node);
	}
	
	public Node getNode(T id)
	{
		return nodeMap.get(id);
	}

	public void addEdge(T source, T destination)
	{
		getNode(source).adjacent.add(getNode(destination));
		getNode(destination).adjacent.add(getNode(source));
	}
	
	public void print()
	{
		for (Map.Entry<T, Node> entry : nodeMap.entrySet())
		{
			Node node = entry.getValue();
			System.out.print("Node " + node.id + " | ");
			for (Node adjacentNode : node.adjacent)
			{
				System.out.print(adjacentNode.id + " ");
			}
			System.out.println();
		}
	}
	
	public boolean hasPathDFS(T source, T destination)
	{
		// Keep a record of visited nodes
		HashSet<T> visited = new HashSet<T>();
		
		return hasPathDFS(getNode(source), getNode(destination), visited);
	}
	
	private boolean hasPathDFS(Node source, Node destination, HashSet<T> visited)
	{
		// Check if node has been visited before and clock it if it hasn't
		if (visited.contains(source.id)) return false;
		visited.add(source.id);
		
		// If the nodes are the same then we've traversed to the destination
		// so we return true
		if (source == destination) return true;
		
		// Original problem: P(s, d)
		// Sub-problem: P(u, d) + D(s, u)
		// Check the adjacent nodes
		for (Node node : source.adjacent)
		{
			if (hasPathDFS(node, destination, visited)) return true;
		}
		
		return false;
	}
	
	public boolean hasPathBFS(T source, T destination)
	{
		return hasPathBFS(getNode(source), getNode(destination));
	}
	
	private boolean hasPathBFS(Node source, Node destination)
	{
		// Breadth-First-Search is not recursive, instead we keep a list of
		// the next nodes we want to visit (the child nodes) to ensure they
		// are visited one level at a time
		LinkedList<Node> nextToVisit = new LinkedList<Node>();
		
		// Keep a list of visited nodes
		HashSet<T> visited = new HashSet<T>();
		
		// Add the source as the first to visit
		nextToVisit.add(source);
		
		// Continue until we have no more nodes to visit
		while (!nextToVisit.isEmpty())
		{
			Node node = nextToVisit.remove();
			if (node == destination) return true;

			// Ignore node if we've visited it before
			if (visited.contains(node.id)) continue;
			
			// Add the node to visited list
			visited.add(node.id);
			
			// Add each adjacent node to the list to visit next
			for (Node adjacentNode : node.adjacent)
			{
				nextToVisit.add(adjacentNode);
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) 
	{
		Graph<Integer> graph = new Graph<Integer>();
		graph.addNode(1);
		graph.addNode(2);
		graph.addNode(3);
		graph.addNode(4);
		graph.addNode(5);
		graph.addEdge(1, 2);
		graph.addEdge(1, 3);
		graph.addEdge(3, 4);
		graph.print();
		System.out.println("[DFS] Path 1->4: " + graph.hasPathDFS(1, 4));
		System.out.println("[DFS] Path 1->5: " + graph.hasPathDFS(1, 5));
		System.out.println("[BFS] Path 1->4: " + graph.hasPathBFS(1, 4));
		System.out.println("[BFS] Path 1->5: " + graph.hasPathBFS(1, 5));
	}
}