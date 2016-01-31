import java.util.Iterator;
import java.util.ArrayList;

public class Board
{
	private int[][] board;
	private int hamming;
	private int manhattan;
	private int dimen;

	public Board(int[][] blocks)
	{
		dimen = blocks.length;
		board = new int[dimen][dimen];

		for(int i = 0; i < dimen; i++)
		{
			for(int j = 0; j < dimen; j++)
			{
				board[i][j] = blocks[i][j];
			}
		}

		hamming = calcHamming();
		manhattan = calcManhattan();
	}

	public int dimension()
	{
		return board.length;
	}

	public int hamming()
	{
		return hamming;
	}

	private int calcHamming()
	{
		int distance = 0;
		
		for(int i = 0; i < dimen; i++)
		{
			for(int j = 0; j < dimen; j++)
			{
				if(board[i][j] != (i*dimen+j+1) && board[i][j] != 0)
					distance++;
			}
		}
		return distance;
	}

	public int manhattan()
	{
		return manhattan;
	}

	private int calcManhattan()
	{
		int distance = 0;
	
		for(int i = 0; i < dimen; i++)
		{
			for(int j = 0; j < dimen; j++)
			{
				if(board[i][j] != 0)
				{
					int value = board[i][j];
					int expX = (value-1)/dimen;
					int expY = (value-1)%dimen;			
					int diffY = Math.abs(expX - i);
					int diffX = Math.abs(expY - j);	
					int tDistance = diffY + diffX;
					distance += tDistance;
				}
			}
		}
		return distance;	
	}

	public boolean isGoal()
	{
		if(manhattan == 0)
			return true;
		
		return false;
	}
	
	public Board twin()
	{
		int[][] twin = copy();

		for(int i = 0; i < dimen; i++)
		{
			for(int j = 0; j < dimen-1; j++)
			{
				if(twin[i][j] != 0 && twin[i][j+1] != 0)
				{	
					int copy = twin[i][j];
					int copyTo = twin[i][j+1];
					twin[i][j] = copyTo;
					twin[i][j+1] = copy;
					return new Board(twin);	
				}
			}
		}
		return null;
	}

	public boolean equals(Object y)
	{
		if(y != null && y instanceof Board)
		{
			return toString().equals(((Board)y).toString());
		}
		return false;
	}

	public Iterable<Board> neighbors()
	{
		ArrayList<Board> neighbours = new ArrayList<Board>();
		boolean foundNeighbours = false;
		
		for(int i = 0; i < dimen; i++)
		{
			for(int j = 0; j < dimen; j++)
			{
				if(board[i][j] == 0 && !foundNeighbours)
				{
					if(i != 0)
					{
						int[][] copyB = copy();
						copyB[i][j] = copyB[i-1][j];
						copyB[i-1][j] = 0;
						neighbours.add(new Board(copyB));
					}
					if(j != 0)
					{
						int[][] copyB = copy();
						copyB[i][j] = copyB[i][j-1];
						copyB[i][j-1] = 0;
						neighbours.add(new Board(copyB));
					}
					if(i != dimen-1)
					{
						int[][] copyB = copy();
						copyB[i][j] = copyB[i+1][j];
						copyB[i+1][j] = 0;
						neighbours.add(new Board(copyB));
					}
					if(j != dimen-1)
					{
						int[][] copyB = copy();
						copyB[i][j] = copyB[i][j+1];
						copyB[i][j+1] = 0;
						neighbours.add(new Board(copyB));
					}
					foundNeighbours = true;
				}
			}
		}
		return neighbours;
	}

	private int[][] copy()
	{
		int[][] copy = new int[dimen][dimen];
		
		for(int i = 0; i < dimen; i++)
			for(int j = 0; j < dimen; j++)
				copy[i][j] = board[i][j];

		return copy;
	}

	public String toString()
	{
		String output = dimension() + "\n";

		for(int i = 0; i < dimen; i++)
		{
			for(int j = 0; j < dimen; j++)
			{
				output += " " + board[i][j];
			}
			output += "\n";
		}
		return output;
	}

	public static void main(String[] args)
	{
		int[][] test = new int[3][3];
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				test[i][j] = (i*3) + j;
		//test[2][2] = 0;
		Board b = new Board(test);
		Board bTwin = b.twin();
		System.out.println(b.toString());
		System.out.println(bTwin.toString());
		System.out.println("Hamm dist: " + b.hamming());
		System.out.println("Manh dust: " + b.manhattan());
		System.out.println("Is goal  : " + b.isGoal());
		System.out.println("Twin, hamm dist: " + bTwin.hamming());
		System.out.println("Twin, manh dist: " + bTwin.manhattan());
		System.out.println("Twin, is goal  : " + bTwin.isGoal());
		System.out.println("Compare twin   : " + bTwin.equals(b));
		
		Iterable<Board> it = b.neighbors();
	
		System.out.println("Attempting to find neoghbors:");
		for(Board c : it)
		{
			System.out.println(c.toString());
		} 	
	} 
}
