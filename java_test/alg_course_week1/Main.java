/**
* Name: Olle Claeson
* Login: olleclaeson@gmail.com
* Date: 140208
**/

public class Main
{
	public static void main(String[] args)
	{
		//int N = StdIn.readInt();
		//UF uf = new UF(N);
		int N = 3;
		Percolation per = new Percolation(N);

		//while(!StdIn.isEmpty())
		//{
			//int p = StdIn.readInt();
			//int q = StdIn.readInt();

			int p = 2;
			int q = 1;
			
			if(!per.isOpen(p,q))
			{
				//per.open(0,0);
				//per.open(1,0);
				//per.open(2,0);
				System.out.println("percolates: " + per.percolates());
				
			}
			else
			{
				System.out.println("Not open");
			}	
		
			//if(!uf.connected(p,q))
			//{
			//	uf.union(p,q);
			//	System.out.println(p + " " + q);
			//}
		//}
	}
}


