
class GFG { 

	static class Node { 
		int data; 
		Node next; 
		Node prev; 
	}; 

	// Function to insert node in the list 
	static Node insert(Node start, int value) 
	{ 

		if (start == null) { 
			Node new_node = new Node(); 
			new_node.data = value; 
			new_node.next = new_node.prev = new_node; 
			start = new_node; 
			return start; 
		} 



		Node last = (start).prev; 

		Node new_node = new Node(); 
		new_node.data = value; 


		new_node.next = start; 

	
		(start).prev = new_node; 

		new_node.prev = last; 

		last.next = new_node; 
		return start; 
	} 


	static Node deleteNode(Node start, int key) 
	{ 
	
		if (start == null) 
			return null; 

		Node curr = start, prev_1 = null; 
		while (curr.data != key) {
			if (curr.next == start) { 
				System.out.printf("\nList doesn't have node with value = %d", key); 
				return start; 
			} 

			prev_1 = curr; 
			curr = curr.next; 
		} 

		if (curr.next == start && prev_1 == null) { 
			(start) = null; 
			return start; 
		} 

		if (curr == start) { 
			// Move prev_1 to last node 
			prev_1 = (start).prev; 

			start = (start).next; 

			prev_1.next = start; 
			(start).prev = prev_1; 
		} 

	
		else if (curr.next == start) { 
		
			prev_1.next = start; 
			(start).prev = prev_1; 
		} 
		else { 
			Node temp = curr.next; 

			prev_1.next = temp; 
			temp.prev = prev_1; 
		} 
		return start; 
	} 


	static void display(Node start) 
	{ 
		Node temp = start; 

		while (temp.next != start) { 
			System.out.printf("%d ", temp.data); 
			temp = temp.next; 
		} 
		System.out.printf("%d ", temp.data); 
	} 

	// Driver program to test above functions 
	public static void main(String args[]) 
	{ 
		
		Node start = null; 


		start = insert(start, 4); 
		start = insert(start, 5); 
		start = insert(start, 6); 
		start = insert(start, 7); 
		start = insert(start, 8); 

		System.out.printf("List Before Deletion: "); 
		display(start); 

		
		start = deleteNode(start, 9); 
		System.out.printf("\nList After Deletion: "); 
		display(start); 

		
		start = deleteNode(start, 4); 
		System.out.printf("\nList After Deleting %d: ", 4); 
		display(start); 

		start = deleteNode(start, 8); 
		System.out.printf("\nList After Deleting %d: ", 8); 
		display(start); 

		start = deleteNode(start, 6); 
		System.out.printf("\nList After Deleting %d: ", 6); 
		display(start); 
	} 
} 
