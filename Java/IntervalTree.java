import java.util.LinkedList;
import java.util.ArrayList;

class IntervalTree 
{
	public static class Interval
	{
		int start, end;
		int min, max;
		
		Interval(int start, int end)
		{
			this.start = start;
			this.end = end;
			this.min = start;
			this.max = end;
		}
		
		public int duration()
		{
			return end - start;
		}
		
		public String toString()
		{
			return "[" + start + ", " + end + "] min(" + min + ") max(" + max + ")";
		}
		
		public boolean spans(Interval interval)
		{
			// Check if we span the entire interval given
			if (start <= interval.start && end >= interval.end)
				return true;
			
			return false;
		}
		
		public boolean isOverlap(Interval interval)
		{
			// The given interval overlaps if:
			//   - It starts before we end (we end after it starts)
			//   - It ends after we start
			// [6, 8] | [5, 10], [8, 9], [1, 4], [2, 7]
			if (interval.start < end && interval.end > start)
				return true;
				
			return false;
		}
	}
	
	public static class Node
	{
		Interval interval;
		Node left, right;
		
		String data;
		
		public Node(int start, int end, String data)
		{
			interval = new Interval(start, end);
			this.data = data;
		}

		public Node(Interval interval, String data)
		{
			this.interval = interval;
			this.data = data;
		}
		
		public void insert(int start, int end, String data)
		{
			insert(new Interval(start, end), data);
		}
		
		public void insert(Interval newInterval, String data)
		{
			if (newInterval.start < interval.min) 
				interval.min = newInterval.start;
				
			if (newInterval.end > interval.max) 
				interval.max = newInterval.end;
			
			// Check where it belongs in the tree
			if (newInterval.start < interval.start)
			{
				if (left == null)
					left = new Node(newInterval, data);
				else 
					left.insert(newInterval, data);
			}
			else
			{
				if (right == null)
					right = new Node(newInterval, data);
				else 
					right.insert(newInterval, data);
			}
		}

		public void overlap(Interval query, ArrayList<Node> overlapping)
		{
			overlap(query, overlapping, true);
		}
		
		public void overlap(Interval query, ArrayList<Node> overlapping, boolean strictSpan)
		{
			if (overlapping == null)
				overlapping = new ArrayList<Node>();
			
			if (interval.isOverlap(query))
			{
				if (!strictSpan || strictSpan && interval.spans(query))
					overlapping.add(this);
			}

			if (left != null && interval.max >= query.start)
				left.overlap(query, overlapping);
			if (right != null && interval.min <= query.end)
				right.overlap(query, overlapping);
		}
		
		public String toString()
		{
			String desc = interval.toString() + " | ";
			if (left != null) desc += "(L) " + left.interval.toString();
			if (right != null) desc += " (R) " + right.interval.toString();
			return desc;
		}
		
		public void printBFS()
		{
			LinkedList<Node> nodesToVisit = new LinkedList<Node>();
			nodesToVisit.add(this);
			
			while (!nodesToVisit.isEmpty())
			{
				Node current = nodesToVisit.remove();
				System.out.println(current.toString());
				if (current.left != null) nodesToVisit.add(current.left);
				if (current.right != null) nodesToVisit.add(current.right);
			}
		}
		
		public void printInOrder()
		{
			if (left != null) left.printInOrder();
			System.out.println(interval.toString());
			if (right != null) right.printInOrder();
		}
	}
	
	public static void testOverlap(Node root, Interval query)
	{
		System.out.println("Overlapping: " + query.toString());
		ArrayList<Node> overlapping = new ArrayList<Node>();
		
		root.overlap(query, overlapping);
		for (Node node : overlapping)
			System.out.println(node.interval.toString() + " | " + node.data);

		System.out.println();
	}
	
	public static void main(String[] args) 
	{
		Node rootComposers = new Node(1843, 1907, "Grieg");
		rootComposers.insert(1874, 1951, "Schoenberg");
		rootComposers.insert(1888, 1971, "Stravinsky");
		rootComposers.insert(1779, 1828, "Schubert");
		rootComposers.insert(1756, 1791, "Mozart");
		rootComposers.insert(1585, 1672, "Schuetz");

		Interval queryYearSpan = new Interval(1907, 1910);
		testOverlap(rootComposers, queryYearSpan);
		
		Node rootSchedule = new Node(8, 11, "John");
		rootSchedule.insert(9, 12, "Tom");
		rootSchedule.insert(10, 11, "Greg");	
		
		Interval queryMeetingTime = new Interval(9, 11);
		testOverlap(rootSchedule, queryMeetingTime);
	}
}