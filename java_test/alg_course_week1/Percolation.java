/**
* Author:       Olle Claeson
* Written:       140208
* Last updated: 140208
*
* Compilation:  'javac Perlocation.java'
* Execution:     Not executed separately, see PerlocationStats.java
*
*
**/
public class Percolation
{
  private boolean[][] openTable;
  private int maxSize;
  private int topNode;
  private int botNode;
  private WeightedQuickUnionUF uf;
  private WeightedQuickUnionUF full;  

  public Percolation(int N)
  {
    openTable = new boolean[N+1][N+1];  //Since index starts at 1,1, we create a larger grid.
    maxSize = N;
    topNode = 0;      //create indexes to the virtual nodes at the bottom and top.
    botNode = N*N+1;

    //set up a union find for N*N + topNode +botNode
    uf = new WeightedQuickUnionUF(N*N+2);
    full = new WeightedQuickUnionUF(N*N+1);

    for (int p = 1; p <= N; p++)
    {
      for (int q = 1; q <= N; q++)
      {
        openTable[p][q] = false;
          
        //Connect the virtual topNode to the top row in the grid.
        if (p == 1)
        {
          uf.union(topNode, conversion(p, q));
          full.union(topNode, conversion(p, q));
        }
      }
    }
  }

  private int conversion(int p, int q)
  {
    if (paramCheck(p, q))  
    {
      return ((p-1)*maxSize + q);
    }
    return 0;  
  }

  /**
  *  Opens up a slot in the grid. Also connects itself to all neighbouring slots. 
  **/
  public void open(int p, int q)
  {
    if (paramCheck(p, q))
    {
      //bind (p,q) with (p-1,q)
      if (p != 1 && openTable[p-1][q])
      {
          uf.union(conversion(p, q), conversion(p-1, q));
          full.union(conversion(p, q), conversion(p-1, q));
      }
      //bind (p,q) with (p+1,q)
      if (p != maxSize && openTable[p+1][q])
      {
        uf.union(conversion(p, q), conversion(p+1, q));
        full.union(conversion(p, q), conversion(p+1, q));
      }
      //bind (p,q) with (p, q-1)
      if (q != 1 && openTable[p][q-1])
      {
        uf.union(conversion(p, q), conversion(p, q-1));
        full.union(conversion(p, q), conversion(p, q-1));
      }
      //bind (p,q) with (p,q+1)
      if (q != maxSize && openTable[p][q+1])
      {
        uf.union(conversion(p, q), conversion(p, q+1));
        full.union(conversion(p, q), conversion(p, q+1));
      }
      //connect to the virtual botNode only if we dont percolate
      if (p == maxSize && !percolates())
      {
        uf.union(botNode, conversion(p, q));
      }
      
      openTable[p][q] = true;
    }
  }

  /**
  * Checks if a slot is open.
  **/
  public boolean isOpen(int p, int q)
  {
    if (paramCheck(p, q))
    {
      return openTable[p][q];
    }
    return false;  
  }

  /**
  *  Checks if a slot is full.
  **/
  public boolean isFull(int p, int q)
  {
    if (paramCheck(p, q))
    {
      return (isOpen(p, q) && full.connected(topNode, conversion(p, q)));
    }
    return false;
  }

  /**
  *  Checks if the grid percolates.
  **/
  public boolean percolates()
  {
    if (maxSize == 1)
    {
      return isOpen(1, 1);
    }
    return uf.connected(topNode, botNode);
  }  

  /**
  * Private method to check that parameters fed to other functions are in bounds.
  **/
  private boolean paramCheck(int i, int j)
  {
    if (i > maxSize || j > maxSize || i < 1 || j < 1)
    {
      throw new IndexOutOfBoundsException("i or j was out of bounds");
    }
    return true;
  }

  public static void main(String[] args)
  {
    new Percolation(5);  
  }  
}
