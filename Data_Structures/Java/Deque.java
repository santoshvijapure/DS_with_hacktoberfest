// Deque.java

public class Deque extends Queue {

  public void insertFront(int key) {
      insertFirst(key);  	// Calls LinkedList's insertFirst
  }

  public int deleteFront() {
      return dequeue();  	// Calls Queue's dequeue method
  }

  public void insertRear(int key) {
      enqueue(key);  		// Calls Queue's enqueue method
  }

  public int deleteRear() {
      if(Deque.isEmpty()){	//Checks if Deque is empty
	  System.out.println("Deque underflow, unable to remove.");
	  return; 
      }
      // Find the size of the queue
      int len = size();  	// Calls LinkedList's size method

      // Last node is at (len-1)th position
      Node curr = head;
      for (int i=0; i<len-2; i++) 	// reach last but one node
          curr = curr.next;

      // Copy the data in last node
      int val = curr.next.data;

      // Reset curr's next to null thereby dropping last node
      curr.next = null;
      return val;
                  
  }

  public int rear() {
      int len = size();  // Find the length

      Node curr = head;
      for (int i=0; i<len-1; i++)  // Get to last node
          curr = curr.next; 

      return curr.data; 
  }
}
// DequeTest.java

public class DequeTest {
    public static void main(String[] args) {
        Deque d = new Deque();
        System.out.println( d.isEmpty() ); // prints true
        d.insertFront(45);
        d.insertRear(20);
        d.insertFront(15);
        d.insertFront(25);
        System.out.println( d.rear() ); // prints 20
        d.deleteRear();
        System.out.println( d.rear() ); // prints 45
        d.enqueue(30);
        d.dequeue();
        System.out.println( d.isEmpty() ); // prints false
        d.print(); // prints 15 45 30
    }
}
