import java.util.ArrayList;
import java.util.Collections;

public class Solver
{
	private Board twin;
	private Storage solution;
	private boolean solvable;
	private int noOfMoves;

	public Solver(Board initial)
	{
		twin = initial.twin();
		solvable = false;
		
		Storage init = new Storage(initial, null, 0);
		Storage twi = new Storage(twin, null, 0);

		MinPQ<Storage> orgQueue = new MinPQ<Storage>(2);
		MinPQ<Storage> twiQueue = new MinPQ<Storage>(2);
		orgQueue.insert(init);
		twiQueue.insert(twi);

		Storage orgMin = orgQueue.min();
		Storage twiMin = twiQueue.min();

		while(!orgMin.currBoard.isGoal() && !twiMin.currBoard.isGoal())
		{
			Iterable<Board> orgNeigh = orgMin.currBoard.neighbors();
			for(Board b: orgNeigh)
			{
				if(orgMin.prevStorage == null)
				{
					Storage s = new Storage(b, orgMin, orgMin.noMoves+1);
					orgQueue.insert(s);
				}
				else if(!b.equals(orgMin.prevStorage.currBoard))
				{
					Storage s = new Storage(b, orgMin, orgMin.noMoves+1);
					orgQueue.insert(s);
				}
			}

			Iterable<Board> twiNeigh = twiMin.currBoard.neighbors();
			for(Board b: twiNeigh)
			{
				if(twiMin.prevStorage == null)
				{
					Storage s = new Storage(b, twiMin, twiMin.noMoves+1);	
					twiQueue.insert(s);
				}
				else if(!b.equals(twiMin.prevStorage.currBoard))
				{
					Storage s = new Storage(b, twiMin, twiMin.noMoves+1);	
					twiQueue.insert(s);
				}
			}

			orgMin = orgQueue.min();
			twiMin = twiQueue.min();

			orgQueue.delMin();
			twiQueue.delMin();
		}
		
		solvable = orgMin.currBoard.isGoal();
	
		if(solvable)
		{
			noOfMoves = orgMin.noMoves;
			solution = orgMin;
		}
		else
			noOfMoves = -1;
	}

	public boolean isSolvable()
	{
		return solvable;
	}
	
	public int moves()
	{
		return noOfMoves;
	}
	
	public Iterable<Board> solution()
	{
		if(!isSolvable())
			return null;

		ArrayList<Board> solutionPath = new ArrayList<Board>();
		
		if(isSolvable())
		{	
			Storage s = solution;
			while(s.prevStorage != null)
			{
				solutionPath.add(s.currBoard);
				s = s.prevStorage;
			}
			solutionPath.add(s.currBoard);
		}

		Collections.reverse(solutionPath);
		return solutionPath;	
	}

	public static void main(String[] args)
	{
		In in = new In(args[0]);
		int N = in.readInt();
		//int N = 3;
		int[][] blocks = new int[N][N];
		//int score = 0;

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				blocks[i][j] = in.readInt();
				//blocks[i][j] = score;
				//score++;
			}
		}
		Board initial = new Board(blocks);

		Solver solver = new Solver(initial);
	
		if(!solver.isSolvable())
			StdOut.println("No solution possible.");
		else
		{
			StdOut.println("Minimum number of moves = " + solver.moves());
			for(Board board : solver.solution())
				StdOut.println(board);
		}
	}
	
	private class Storage implements Comparable<Storage>
	{
		Board currBoard;
		Storage prevStorage;
		int noMoves;			

		private Storage(Board curr, Storage prev, int moves)
		{
			currBoard = curr;
			prevStorage = prev;
			noMoves = moves;
		}

		public int compareTo(Storage b)
		{
			return (currBoard.manhattan() + noMoves) - (b.currBoard.manhattan() + b.noMoves);
			//return currBoard.hamming() - b.currBoard.hamming();
		}
	} 
}
