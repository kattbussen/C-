public class Subset
{
  public static void main(String[] args)
  {
    int readNr = Integer.parseInt(args[0]);
  
    RandomizedQueue<String> randQ = new RandomizedQueue<String>();

    while (!StdIn.isEmpty())
    {
      String tmp = StdIn.readString();
      randQ.enqueue(tmp);
    }
    
    int i = 0;
    while (i < readNr && !randQ.isEmpty())
    {
      System.out.println(randQ.dequeue());
      i++;
    }  
  }
}
