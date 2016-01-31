import java.util.TreeSet;
import java.util.Iterator;
import java.util.ArrayList;

public class PointSET
{
	private TreeSet<Point2D> tree;

	public PointSET()
	{
		tree = new TreeSet<Point2D>();
	}

	public boolean isEmpty()
	{
		return tree.isEmpty();
	}
	
	public int size()
	{
		return tree.size();
	}
	
	public void insert(Point2D p)
	{
		tree.add(p);
	}

	public boolean contains(Point2D p)
	{
		return tree.contains(p);
	}

	public void draw()
	{
		Iterator<Point2D> it = tree.iterator();

		while(it.hasNext())
		{
			Point2D p = it.next();
			StdDraw.point(p.x(), p.y());
		}

		StdDraw.show(0);
	}

	public Iterable<Point2D> range(RectHV rect)
	{
		ArrayList<Point2D> list = new ArrayList<Point2D>();
		Iterator<Point2D> it = tree.iterator();

		while(it.hasNext())
		{
			Point2D p = it.next();
			if(rect.contains(p))
				list.add(p);
		}

		return list;
	}

	public Point2D nearest(Point2D p)
	{
		Point2D min = null;
		Iterator<Point2D> it = tree.iterator();
	
		while(it.hasNext())
		{
			Point2D itP = it.next();
			if(min == null)
				min = itP;

			if(p.distanceTo(itP) < p.distanceTo(min))
				min = itP;
		}
		return min;
	}
}
