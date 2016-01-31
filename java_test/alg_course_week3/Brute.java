/*************************************************************************
 *  Compilation:  javac Brute.java
 *  Execution:    java Brute input.txt
 *  Dependencies: Point.java, In.java, StdDraw.java
 *
 *  Takes the name of a file as a command-line argument.
 *  Reads in an integer N followed by N pairs of points (x, y)
 *  with coordinates between 0 and 32,767, and plots them using
 *  standard drawing.
 *
 *************************************************************************/

import java.util.Arrays;

public class Brute {
	public static void main(String[] args) {

		// rescale coordinates and turn on animation mode
		StdDraw.setXscale(0, 32768);
    StdDraw.setYscale(0, 32768);
    StdDraw.show(0);

    // read in the input
    String filename = args[0];
    In in = new In(filename);
    int N = in.readInt();
    Point[] indata = new Point[N];    
		for(int i = 0; i < N; i++ )
		{	
			int x = in.readInt();
			int y = in.readInt();
			indata[i] = new Point(x, y);
		}

		for(int i = 0; i < N; i++)
		{
			indata[i].draw();
		}	
		
		for(int first = 0; first < N-3; first++)
		{
			for(int second = first+1; second < N-2; second++)
			{
				for(int third = second+1; third < N-1; third++)
				{
					for(int fourth = third+1; fourth < N; fourth++)
					{
						if((indata[first].slopeTo(indata[second]) == indata[first].slopeTo(indata[third])) &&
							 (indata[first].slopeTo(indata[second]) == indata[first].slopeTo(indata[fourth])))
						{
							//the points are on a line, draw a line between the smallest and the largest
							Point smallest = findSmallest(indata[first], indata[second], indata[third], indata[fourth]);
							Point largest = findLargest(indata[first], indata[second], indata[third], indata[fourth]);

							Point[] sortlist = new Point[4];
							sortlist[0] = indata[first];
							sortlist[1] = indata[second];
							sortlist[2] = indata[third];
							sortlist[3] = indata[fourth];
		
							Arrays.sort(sortlist);

							System.out.println(sortlist[0] + " -> " + sortlist[1] + " -> " + sortlist[2] + " -> " + sortlist[3]);
							smallest.drawTo(largest);
						}
					}
				}
			}
		}	
    StdDraw.show(0);
  }

	private static Point findSmallest(Point one, Point two, Point three, Point four)
	{
		if(one.compareTo(two) > 0 &&  one.compareTo(three) > 0 && one.compareTo(four) > 0)
		{
			return one;
		}
		else if(two.compareTo(three) > 0 && two.compareTo(four) > 0)
		{
			return two;
		}
		else if(three.compareTo(four) > 0)
		{
			return three;
		}
		else
		{
			return four;
		}
	}
	
	private static Point findLargest(Point one, Point two, Point three, Point four)
	{
		if(one.compareTo(two) < 0 && one.compareTo(three) < 0 && one.compareTo(four) < 0)
		{
			return one;
		}
		else if(two.compareTo(three) < 0 && two.compareTo(four) < 0)
		{
			return two;
		}
		else if(three.compareTo(four) < 0)
		{
			return three;
		}
		else
		{
			return four;
		}
	}
}
