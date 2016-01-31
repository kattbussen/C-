import java.util.Iterator;

public class RandomizedQueue<Item> implements Iterable<Item>
{
  private int sizeOf;
  private Item[] stack;
  private int stackSize;
  private int lastPos;

  public RandomizedQueue()
  {
    sizeOf = 0;
    stackSize = 1;
    stack = (Item[]) new Object[stackSize];
    stack[0] = null;
    lastPos = 0;
  }

  public boolean isEmpty()
  {
    return sizeOf == 0;
  }

  public int size()
  {
    return sizeOf;
  }

  public void enqueue(Item item)
  {
    if (item != null)
    {
      //If stack is full, dobule stacksize
      if (sizeOf >= stack.length || lastPos >= stack.length)
      {
        doubleQueue();
      }
        
      int  index = lastPos;
      lastPos++;
      stack[index] = item;
      sizeOf++;
    }
    else
    {
      throw new NullPointerException("Attempted to add null to the queue.");
    }
  }

  public Item dequeue()
  {
    if (sizeOf > 0)
    {
      if (sizeOf <= stackSize/4)
      {  
        halveQueue();
      }

      boolean foundItem = false;
      int randIndex = 0;

      while (!foundItem)
      {
        randIndex = StdRandom.uniform(0, lastPos);
        if (stack[randIndex] != null)
        { 
          foundItem = true;
        }
      }
    
      Item item = stack[randIndex];
      stack[randIndex] = null;
      sizeOf--;
      return item;
    }
    else
    {
      throw new java.util.NoSuchElementException("Attempted to dequeue with no items in the queue.");
    }
  }

  public Item sample()
  {
    if (sizeOf > 0)
    {
      boolean foundItem = false;
      int randIndex = 0;
          
      while (!foundItem)
      {
        randIndex = StdRandom.uniform(0, lastPos);
        if (stack[randIndex] != null)
        {
          foundItem = true;
        }
      }  
      return stack[randIndex];
    }
    else
    {
      throw new java.util.NoSuchElementException("Attempted to sample a item with no items in the queue.");
    }
  }

  public Iterator<Item> iterator()
  {
    return new RandomIterator();
  }

  private void doubleQueue()
  {
    Item[] tmp = (Item[]) new Object[2*stackSize];

    for (int i = 0; i < lastPos; i++)
    {
      tmp[i] = stack[i];
      stack[i] = null;
    }

    stackSize = 2*stackSize;
    stack = tmp;
  }

  private void halveQueue()
  {
    Item[] tmp = (Item[]) new Object[stackSize/2];
    int newI = 0;
    Iterator<Item> it = iterator();
    
    while (it.hasNext())
    {
      tmp[newI] = it.next();
      newI++;
    }  

    stackSize = stackSize/2;
    lastPos = newI;
    stack = tmp;
  }

  public static void main(String[] args)
  {
    RandomizedQueue<Integer> randQ = new RandomizedQueue<Integer>();

    for (int i = 0; i < 50; i++)
    {
      randQ.enqueue(i);
    }

    randQ.itItems();

    for (int i = 0; i < 49; i++)
      randQ.dequeue();

    randQ.printStats();
  }

  private void printStats()
  {
    System.out.println("=================");  
    System.out.println("isEmpty: " + isEmpty());
    System.out.println("lastPos: " + lastPos);  
    System.out.println("sizeOf: " + sizeOf);  
    System.out.println("stackSize: " + stackSize);  
    System.out.println("=================");  
  }

  private void itItems()
  {
    System.out.println("Iterating all items in queue;");
    Iterator it = iterator();
    while (it.hasNext())
    {
      System.out.println(it.next());
    }  
    System.out.println("Done.");  
  }

  private class RandomIterator implements Iterator<Item>
  {
    int index = 0;
    Item[] list;
  
    public RandomIterator()
    {
      list = (Item[]) new Object[sizeOf];
    
      int ins = 0;
      for (int i = 0; i < lastPos; i++)
      {
        if (stack[i] != null)
        {
          list[ins] = stack[i];
          ins++;
        }
      }
      StdRandom.shuffle(list);
    }

    public boolean hasNext()
    {
      return (index < list.length);
    }
    
    public void remove()
    {
      throw new UnsupportedOperationException("Attempted to call unsupported function 'remove' in Iterator.");
    }

    public Item next()
    {
      if (!hasNext())
      {
        throw new java.util.NoSuchElementException("Tried to call next with no elements left to iterate.");
      }

      Item item = list[index];
      list[index] = null;
      index++;
      return item;
    }
  }
}
