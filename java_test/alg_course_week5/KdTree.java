import java.util.TreeSet;
import java.util.Iterator;
import java.util.ArrayList;

public class KdTree
{
	private Node root;
	private int noElements;
	private Point2D min;

	public KdTree()
	{
		root = null;
		noElements = 0;
		min = null;	
	}

	public boolean isEmpty()
	{
		return noElements == 0;
	}
	
	public int size()
	{
		return noElements;
	}
	
	public void insert(Point2D p)
	{
		boolean foundInsertion = false;
		Node iNode = new Node();
		iNode.point = p;
		iNode.left = null;
		iNode.right = null;
		
		if(root == null)
		{
			iNode.depth = 0;
			iNode.rect = new RectHV(0,0,1,1);
			root = iNode;
			foundInsertion = true;
			noElements++;
			return;
		}

		Node currNode = root;
		int depth = 0;

		if(contains(p))
		{
			foundInsertion = true;	
		}
	
		while(!foundInsertion)
		{
			//compare x values
			if(depth % 2 == 0)
			{
				if(p.x() >= currNode.point.x())
				{
					if(currNode.right != null)
					{
						currNode = currNode.right;
						depth++;
					}
					else
					{
						if(!p.equals(currNode.point))
						{
							iNode.depth = depth;
							iNode.rect = new RectHV(currNode.point.x(), currNode.rect.ymin(), currNode.rect.xmax(), currNode.rect.ymax());
							currNode.right = iNode;
							noElements++;
						}
						foundInsertion = true;
					}
				}
				else
				{
					if(currNode.left != null)
					{
						currNode = currNode.left;
						depth++;
					}
					else
					{
						if(!p.equals(currNode.point))
						{
							iNode.depth = depth;
							iNode.rect = new RectHV(currNode.rect.xmin(), currNode.rect.ymin(), currNode.point.x(), currNode.rect.ymax());
							currNode.left = iNode;
							noElements++;
						}
						foundInsertion = true;
					}
				}
			}
			//compare y values
			else
			{
				if(p.y() >= currNode.point.y())
				{
					if(currNode.right != null)
					{
						currNode = currNode.right;
						depth++;
					}	
					else
					{
						if(!p.equals(currNode.point))
						{
							iNode.depth = depth;
							iNode.rect = new RectHV(currNode.rect.xmin(), currNode.point.y(), currNode.rect.xmax(), currNode.rect.ymax());
							currNode.right = iNode;
							noElements++;
						}
						foundInsertion = true;
					}
				}
				else
				{
					if(currNode.left != null)
					{
						currNode = currNode.left;
						depth++;
					}
					else
					{
						if(!p.equals(currNode.point))
						{
							iNode.rect = new RectHV(currNode.rect.xmin(), currNode.rect.ymin(), currNode.rect.xmax(), currNode.point.y());
							iNode.depth = depth;
							currNode.left = iNode;
							noElements++;
						}
						foundInsertion = true;
					}
				}
			}
		}
	}

	public boolean contains(Point2D p)
	{
		if(root == null)
		{
			return false;
		}

		Node currNode = root;
		int depth = 0;

		while(true)
		{
			if(currNode.point.x() == p.x() && currNode.point.y() == p.y())
			{
				return true;
			}
			//compare x values
			if(depth % 2 == 0)
			{
				if(p.x() >= currNode.point.x())
				{
					if(currNode.right != null)
					{
						currNode = currNode.right;
						depth++;
					}
					else
					{
						return false;
					}
				}
				else
				{
					if(currNode.left != null)
					{
						currNode = currNode.left;
						depth++;
					}
					else
					{
						return false;
					}
				}
			}
			//compare y values
			else
			{
				if(p.y() >= currNode.point.y())
				{
					if(currNode.right != null)
					{
						currNode = currNode.right;
						depth++;
					}	
					else
					{
						return false;
					}
				}
				else
				{
					if(currNode.left != null)
					{
						currNode = currNode.left;
						depth++;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}

	public void draw()
	{
		//draw root
		StdDraw.setPenRadius(0.01);
		StdDraw.setPenColor(StdDraw.BLACK);
		StdDraw.point(root.point.x(), root.point.y());
		StdDraw.setPenRadius();
		StdDraw.setPenColor(StdDraw.RED);
		StdDraw.line(root.point.x(), 0, root.point.x(), 1);
		//drawRect(root);

		//Iterate through the rest of the nodes and draw them
		drawNodes(root);	
		StdDraw.show(0);
	}

	private void drawNodes(Node node)
	{
		if(node != null)
		{
			if(node.left != null)
			{
				node.left.draw(node);
				//drawRect(node.left);
				drawNodes(node.left);
			}
			if(node.right != null)
			{
				node.right.draw(node);
				//drawRect(node.right);
				drawNodes(node.right);
			}
		}
	}

	private void drawRect(Node node)
	{
		StdDraw.setPenColor(StdDraw.GREEN);
		node.rect.draw();
	}

	public Iterable<Point2D> range(RectHV rect)
	{
		ArrayList<Point2D> intersectingPoints = new ArrayList<Point2D>();
		if(root != null)
			checkRange(intersectingPoints, root, rect);	
		return intersectingPoints;
	}

	private ArrayList<Point2D> checkRange(ArrayList<Point2D> list, Node node, RectHV rect)
	{
		if(rect.contains(node.point))
		{
			list.add(node.point);
		}

		if(node.left != null && rect.intersects(node.left.rect))
		{
			checkRange(list, node.left, rect);
		}
		if(node.right != null && rect.intersects(node.right.rect))
		{	
			checkRange(list, node.right, rect);
		}
		return list;
	}

	public Point2D nearest(Point2D p)
	{
		min = null;
	
		if(root != null)
		{
			min = root.point;
			min = findNearest(root, p);
		}
	
		return min;
	}
	
	private Point2D findNearest(Node node, Point2D p)
	{
		if(node.point.distanceSquaredTo(p) < min.distanceSquaredTo(p))
		{	
			min = node.point;
		}	
			
		double left = -1;
		double right = -1;
		double minDist = min.distanceSquaredTo(p);

 		if(node.left != null)
			left = node.left.rect.distanceSquaredTo(p);
		if(node.right != null)
			right = node.right.rect.distanceSquaredTo(p);

		//both left and right are valid
		if(left >= 0 && right >= 0 && left < minDist && right < minDist)
		{
			if(node.left.rect.contains(p))
			{
				findNearest(node.left, p);
				findNearest(node.right, p);
			}
			else
			{
				findNearest(node.right, p);
				findNearest(node.left, p);
			}
		}
		//only go down right
		else if(right >= 0 && right < minDist)
		{
			findNearest(node.right, p);
		}
		//only go down left
		else if(left >= 0 && left < minDist)
		{
			findNearest(node.left, p);
		}

		return min;
	}

	private class Node
	{
		private Point2D point;
		private RectHV rect;
		private Node left;
		private Node right;
		private int depth;

		private void draw(Node limit)
		{
			//draw the point
			StdDraw.setPenRadius(0.01);
			StdDraw.setPenColor(StdDraw.BLACK);
			StdDraw.point(point.x(), point.y());

			StdDraw.setPenRadius();
			//draw horizontal line
			if(depth % 2 == 0)
			{	
				double refX = limit.point.x();
				StdDraw.setPenColor(StdDraw.BLUE);
				if(refX >= point.x())
				{
					StdDraw.line(point.x(), point.y(), refX, point.y());
					StdDraw.line(point.x(), point.y(), limit.rect.xmin(), point.y());
				}
				else
				{
					StdDraw.line(point.x(), point.y(), refX, point.y());
					StdDraw.line(point.x(), point.y(), limit.rect.xmax(), point.y());
				}
			}
			//draw vertical line
			else
			{
				double refY = limit.point.y();
				StdDraw.setPenColor(StdDraw.RED);
				if(refY >= point.y())
				{
					StdDraw.line(point.x(), point.y(), point.x(), refY);
					StdDraw.line(point.x(), point.y(), point.x(), limit.rect.ymin());
				}
				else
				{
					StdDraw.line(point.x(), point.y(), point.x(), refY);
					StdDraw.line(point.x(), point.y(), point.x(), limit.rect.ymax());
				}
			}		
		}
	}

	public static void main(String[] args)
	{
		String filename = args[0];
		In in = new In(filename);
		KdTree tree = new KdTree();
	
		while(!in.isEmpty())
		{
			double x = in.readDouble();
      double y = in.readDouble();
      Point2D p = new Point2D(x, y);
      tree.insert(p);
		}
	
		tree.draw();
		tree.nearest(new Point2D(1,1));	
		System.out.println(tree.size());
	}	
}
