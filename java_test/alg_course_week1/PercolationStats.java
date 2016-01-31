/**
* Author:       Olle Claeson
* Written:       140208
* Last updated: 140208
*
* Compilation:  'javac PercolationStats.java'
* Execution:    'java PercolationStats <size of grid> <number of runs>'
* 
* Calculates the mean, standard deviation and confidence intervals at when a grid of
* the given size perculates.
**/
public class PercolationStats
{
  private double noOfRuns;
  private double sizeOfGrid;
  private double mean;  
  private double[] fraction; 

  public PercolationStats(int N, int T)
  {
    if (N <= 0 || T <= 0)
    {
      throw new IllegalArgumentException("wrong arguments");
    }
    sizeOfGrid = N*N;
    noOfRuns = T;
    mean = 0;
    fraction = new double[T];    
    int openSites;
    for  (int i = 0; i < T; i++)
    {
      Percolation per = new Percolation(N);  
      openSites = 0;

      while (!per.percolates())
      {
        int p = StdRandom.uniform(1, N+1);
        int q = StdRandom.uniform(1, N+1);  
        
        if (!per.isOpen(p, q))
        {
          per.open(p, q);
          openSites++;
        }  
      }
      
      fraction[i] = openSites / sizeOfGrid;
    
      mean += (openSites / sizeOfGrid) / noOfRuns;
    }  

    //Print results
    System.out.println("mean:               " + mean());
    System.out.println("stddev:              " + stddev());
    System.out.println("95% conf. interval: " + confidenceLo() + ", " + confidenceHi());
  }


  /**
  * Returns the mean.
  **/
  public double mean()
  {
    return mean;  
  }
  
   /**
  * Returns standard deviation.
  **/
  public double stddev()
  {  
    if (noOfRuns == 1)
      return Double.NaN;
    else
    {  
      double sum = 0.0;
      for (int i = 0; i < noOfRuns; i++)
      {
        sum += (fraction[i] - mean)*(fraction[i] -mean);
      }
      return Math.sqrt(sum / (noOfRuns - 1));
    }
  }
  
  /**
  * Returns lower part of the 95% confidence interval.
  **/
  public double confidenceLo()
  {
    double stddev = stddev();
    return (mean - (1.96*stddev) / Math.sqrt(noOfRuns));
  }

  /**
  * Returns high part of the 95% confidence interval.
  **/
  public double confidenceHi()
  {  
    double stddev = stddev();
    return (mean + (1.96*stddev) / Math.sqrt(noOfRuns));
  }

  /**  
  * Test method that takes the command line arguments and initiates the test.
  **/
  public static void main(String[] args)
  {
    int N = Integer.parseInt(args[0]);
    int T = Integer.parseInt(args[1]);

    new PercolationStats(N, T);
  }        
}
