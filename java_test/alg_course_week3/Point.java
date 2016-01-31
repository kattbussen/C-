 /*********************************************************************** 
 *
 * Name:
 * Email:
 *
 * Compilation:  javac Point.java
 * Execution:
 * Dependencies: StdDraw.java
 *
 * Description: An immutable data type for points in the plane.
 *
 *************************************************************************/

import java.util.Comparator;
import java.util.Arrays;

public class Point implements Comparable<Point> {

  // compare points by slope
  public final Comparator<Point> SLOPE_ORDER = new CompareSlope();       // YOUR DEFINITION HERE

  private final int x;                              // x coordinate
  private final int y;                              // y coordinate

  // create the point (x, y)
  public Point(int x, int y) {
      /* DO NOT MODIFY */
      this.x = x;
      this.y = y;
  }

  // plot this point to standard drawing
  public void draw() {
      /* DO NOT MODIFY */
      StdDraw.point(x, y);
  }

  // draw line between this point and that point to standard drawing
  public void drawTo(Point that) {
      /* DO NOT MODIFY */
      StdDraw.line(this.x, this.y, that.x, that.y);
  }

  // slope between this point and that point
  public double slopeTo(Point that) {
  	double calcX = this.x - that.x;
		double calcY = this.y - that.y;

		//degenerate line segment, same point
		if(calcX == 0 && calcY == 0)
		{
			return Double.NEGATIVE_INFINITY;
		}
		//vertical line
		if(calcX == 0)
		{
			return Double.POSITIVE_INFINITY;
		}
		//horizontal line
		else if(calcY == 0)
		{
			return 0.0;
		}
		else
		{
			return calcY / calcX;
		}
	}

  // is this point lexicographically smaller than that one?
  // comparing y-coordinates and breaking ties by x-coordinates
  public int compareTo(Point that) {
   	if(that != null)
		{
			if (this.y < that.y || (this.y == that.y && this.x < that.x))
			{
				return -1;
			}
			else if(this.x == that.x && this.y == that.y)
			{
				return 0;
			}
			return 1;
		}
		else
			throw new NullPointerException("Called compareTo method with null.");
	}

  // return string representation of this point
  public String toString() {
      /* DO NOT MODIFY */
      return "(" + x + ", " + y + ")";
  }

  // unit test
  public static void main(String[] args) {
		System.out.println("Defining Points.");
		Point zero = new Point(0,0);
		Point[] points = new Point[13];
		points[0] = zero;
		points[1] = new Point(1,1);
		points[2] = new Point(2,2);
		points[3] = new Point(3,3);
		points[4] = new Point(2,1);
		points[5] = new Point(3,1);
		points[6] = new Point(4,1);
		points[7] = new Point(6,0);
		points[8] = new Point(1,5);
		points[9] = new Point(0,6);
		points[10] = new Point(1,4);
		points[11] = new Point(1,7);
		points[12] = new Point(6,5);
		System.out.println("Points defined.");

		System.out.println("First Normal sort, then by SLOPE_ORDER to (0,0):");
		Arrays.sort(points);
		Arrays.sort(points, zero.SLOPE_ORDER);
		printPoints(points);

		System.out.println("Sort by SLOPE_ORDER to (1,7)");
		Arrays.sort(points, points[6].SLOPE_ORDER);
		printPoints(points);
	}

	private static void printPoints(Point[] points)
	{
		for(int i = 0; i < points.length; i++)
		{
			System.out.println(i + ": " + points[i]);
		}

	}

	private class CompareSlope implements Comparator<Point>
	{
		public int compare(Point first, Point second)
		{
			if(first != null && second != null)
			{
				double firstSlope = Point.this.slopeTo(first);
				double secondSlope = Point.this.slopeTo(second);

				if(firstSlope < secondSlope)
					return -1;

				if(secondSlope < firstSlope)
					return 1;

				return 0;
			}
			else
				throw new NullPointerException("Called compare method with null.");
		}
	}
}
