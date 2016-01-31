/*************************************************************************
 *  Compilation:  javac Fast.java
 *  Execution:    java Fast input.txt
 *  Dependencies: Point.java, In.java, StdDraw.java
 *
 *  Takes the name of a file as a command-line argument.
 *  Reads in an integer N followed by N pairs of points (x, y)
 *  with coordinates between 0 and 32,767, and plots them using
 *  standard drawing.
 *
 *************************************************************************/

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class Fast {
		
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
		Point[] tmp = new Point[N];
		ArrayList<Point> usedPoints = new ArrayList<Point>(); 
		ArrayList<Point> possLine = new ArrayList<Point>();		
	
		for(int i = 0; i < N; i++ )
		{	
			int x = in.readInt();
			int y = in.readInt();
			indata[i] = new Point(x, y);
			tmp[i] = new Point(x,y);
			indata[i].draw();
		}
	
		Arrays.sort(indata);

		for(int i = 0; i < N; i++)
		{
			Arrays.sort(tmp);
			Arrays.sort(tmp, indata[i].SLOPE_ORDER);

			for(int j = 0; j < tmp.length-2; j++)
			{
				int noSameSlope = 1;
				int startIndex = j;
				boolean alreadyUsed = false;			
				possLine.add(tmp[j]);

				while(j < (tmp.length - 1) && indata[i].slopeTo(tmp[j]) == indata[i].slopeTo(tmp[j+1]))
				{
					possLine.add(tmp[j+1]);
					noSameSlope++;
					j++;
				}

				Iterator<Point> possIt = possLine.listIterator();
				Iterator<Point> usedIt = usedPoints.listIterator();
				ArrayList.sort(usedPoints);	
			
				while(possIt.hasNext() && !alreadyUsed)
				{
					Point p = possIt.next();
		
					while(usedIt.hasNext() && !alreadyUsed)
					{
						Point q = usedIt.next();
		
						if(p.compareTo(q) == 0)
							alreadyUsed = true;
					}
				}	
			
				if(noSameSlope >= 3 && !alreadyUsed)
				{
					usedPoints.add(indata[i]);				
	
					System.out.printf(indata[i] + " -> ");
					
					for(int index = startIndex; index < j; index ++)
					{
						System.out.printf(tmp[index] + " -> ");
					}
					System.out.println(tmp[j]);
					indata[i].drawTo(tmp[j]);
				}
				possLine.clear();
			}
		}
   	StdDraw.show(0);
  }
}
