/**
* Author:       Olle Claeson
* Written:       140214
* Last updated: 140214
*
* Compilation:   'javac Deque.java'
* Exection:     'java Deque' will perform a standard test.
**/

import java.util.Iterator;

public class Deque<Item> implements Iterable<Item>
{
  private int sizeOf;
  private Node first;
  private Node last;
  
  public Deque()
  {
    sizeOf = 0;  

    first = new Node();
    last = new Node();
    
    first.next = last;
    first.previous = null;

    last.next = null;
    last.previous = first;
  }

  public boolean isEmpty()
  {
    return sizeOf == 0;
  }

  public int size()
  {
    return sizeOf;
  }

  public void addFirst(Item item)
  {
    if (item != null)
    {
      Node tmp = first.next;
      Node newNode = new Node();
      newNode.item = item;  

      tmp.previous = newNode;

      first.next = newNode;
  
      newNode.previous = first;
      newNode.next = tmp;

      sizeOf++;
    }
    else
    {
      throw new NullPointerException("Attempted to add null first in queue.");
    }
  }

  public void addLast(Item item)
  {
    if (item != null)
    {
      Node tmp = last.previous;
      Node newNode = new Node();
      newNode.item = item;    

      tmp.next = newNode;

      last.previous = newNode;

      newNode.previous = tmp;
      newNode.next = last;

      sizeOf++;
    }
    else
    {
      throw new NullPointerException("Attempted to add null last in queue.");
    }
  }

  public Item removeFirst()
  {
    if (sizeOf > 0)
    {
      Node oldFirst = first.next;
      first.next = oldFirst.next;
      
      Node newFirst = oldFirst.next;
      newFirst.previous = first;

      sizeOf--;
      return oldFirst.item;
    }
    else
    {
      throw new java.util.NoSuchElementException("Attempted to remove first item, but no items in queue.");
    }
  }
  
  public Item removeLast()
  {
    if (sizeOf > 0)
    {
      Node oldLast = last.previous;
      last.previous = oldLast.previous;

      Node newLast = oldLast.previous;
      newLast.next = last;

      sizeOf--;
      return oldLast.item;
    }
    else
    {
      throw new java.util.NoSuchElementException("Attempted to remove last item, but no items in queue.");
    }
  }
  
  public Iterator<Item> iterator()
  {
    return new DequeIterator();
  }

  public static void main(String[] args)
  {
    Deque<String> deq = new Deque<String>();

    deq.addFirst("på");
    deq.addFirst("Hej");
    deq.addLast("dig");
    deq.addLast("då");
  
    Iterator<String> i = deq.iterator();
    while (i.hasNext())
    {
      System.out.println("Ut: "+i.next());
    }
  
    Iterator<String> i1 = deq.iterator();
    Iterator<String> i2 = deq.iterator();
  }

  private class DequeIterator implements Iterator<Item>
  {
    private Node current = first.next;

    public boolean hasNext()
    {
      return current != last;
    }

    public void remove()
    {
      throw new UnsupportedOperationException("Remove() operation not supported.");
    }

    public Item next()
    {
      if (current.next != null)
      {
        Item item = current.item;
        current = current.next;
        return item;
      }
      else
      {
        throw new java.util.NoSuchElementException("Attempted to acces next element in iterator when there are no more elements.");
      }  
    }    
  }

  private class Node
  {
    Item item;
    Node next;
    Node previous;
  }
}
