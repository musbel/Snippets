import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashSet;

class IntervalTree 
{
	public static class AppointmentCalendar
	{
		String name;
		ArrayList<Interval> appointments;
		
		AppointmentCalendar(String name)
		{
			this.name = name;
			appointments = new ArrayList<Interval>();
		}
		
		public void addAppointment(Interval interval)
		{
			appointments.add(interval);
		}
		
		public ArrayList<Interval> getAppointments()
		{
			return appointments;
		}
	}
	
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

		public void overlap(Interval query, HashSet<Node> overlapping)
		{
			overlap(query, overlapping, true);
		}
		
		public void overlap(Interval query, HashSet<Node> overlapping, boolean strictSpan)
		{
			if (overlapping == null)
				overlapping = new HashSet<Node>();
			
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
		
		public void inOrder(ArrayList<Interval> intervals)
		{
			if (left != null) left.inOrder(intervals);
			intervals.add(interval);
			if (right != null) right.inOrder(intervals);
		}
	}
	
	public static ArrayList<Interval> availability(ArrayList<Interval> appointments, int start, int end)
	{
		ArrayList<Interval> slots = new ArrayList<Interval>();
		ArrayList<Interval> ordered = new ArrayList<Interval>();
		Node aRoot = null;
		for (Interval a : appointments)
		{
			if (aRoot == null) aRoot = new Node(a, "");
			else aRoot.insert(a, "");
		}
		
		aRoot.inOrder(ordered);
		for (int i = 0; i < ordered.size() - 1; ++i)
		{
			Interval current = ordered.get(i);
			Interval nextInt = ordered.get(i + 1);
			
			if (i == 0 && current.start > start)
				slots.add(new Interval(start, current.start));	

			if (current.end < nextInt.start)
				slots.add(new Interval(current.end, nextInt.start));
			
		}
		Interval lastInt = ordered.get(ordered.size() - 1);
		if (lastInt.end < end)
			slots.add(new Interval(lastInt.end, end));
		
		return slots;
	}
	
	public static void testOverlap(Node root, Interval query)
	{
		System.out.println("Overlapping: " + query.toString());
		HashSet<Node> overlapping = new HashSet<Node>();
		
		root.overlap(query, overlapping);
		for (Node node : overlapping)
			System.out.println(node.interval.toString() + " | " + node.data);

		System.out.println();
	}
	
	public static void main(String[] args) 
	{
		AppointmentCalendar cal1 = new AppointmentCalendar("John");
		AppointmentCalendar cal2 = new AppointmentCalendar("Tom");
		AppointmentCalendar cal3 = new AppointmentCalendar("Greg");
		
		cal1.addAppointment(new Interval(8, 10));
		cal1.addAppointment(new Interval(16, 17));
		cal1.addAppointment(new Interval(12, 15));

		cal2.addAppointment(new Interval(9, 10));
		cal2.addAppointment(new Interval(11, 13));
		cal2.addAppointment(new Interval(15, 16));
		
		cal3.addAppointment(new Interval(11, 12));
		cal3.addAppointment(new Interval(14, 15));
		
		ArrayList<Interval> slots1 = availability(cal1.getAppointments(), 8, 17);
		ArrayList<Interval> slots2 = availability(cal2.getAppointments(), 8, 17);
		ArrayList<Interval> slots3 = availability(cal3.getAppointments(), 8, 17);
//		for (Interval s : slots3) System.out.println(s.toString());
		
		Node rootSchedule = null;
		for (Interval slot : slots1)
		{
			if (rootSchedule == null)
				rootSchedule = new Node(slot, "John");
			else
				rootSchedule.insert(slot, "John");
		}
		for (Interval slot : slots2)
		{
			rootSchedule.insert(slot, "Tom");
		}
		for (Interval slot : slots3)
		{
			rootSchedule.insert(slot, "Greg");
		}
		
		int duration = 1;
		for (int i = 8; i < 17; i += duration)
		{
			Interval queryMeetingTime = new Interval(i, i + duration);
			HashSet<Node> availabilities = new HashSet<Node>();
			rootSchedule.overlap(queryMeetingTime, availabilities);
			if (availabilities.size() == 3)
			{
				System.out.println("Earliest availability is: " + queryMeetingTime.toString());
				break;
			}
		}
	}
}