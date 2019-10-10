# Add Java Programs here

@ram-nad: Added Doubly Linked List
@njain-01 : Added BFS program

## Dimond Problem

The “diamond problem” is an ambiguity that can arise as a consequence of allowing multiple inheritance. 
It is a serious problem for languages (like C++) that allow for multiple inheritance of state. 
In Java, however, multiple inheritance is not allowed for classes, only for interfaces, and these do not contain state.

Why Java doesn’t support Multiple Inheritance?

Consider the below Java code. It shows error:
// First Parent class 
class Parent1 
{ 
	void fun() 
	{ 
		System.out.println("Parent1"); 
	} 
} 

// Second Parent Class 
class Parent2 
{ 
	void fun() 
	{ 
		System.out.println("Parent2"); 
	} 
} 

// Error : Test is inheriting from multiple 
// classes 
class Test extends Parent1, Parent2 
{ 
public static void main(String args[]) 
{ 
	Test t = new Test(); 
	t.fun(); 
} 
} 

From the code, we see that, on calling the method fun() using Test object will cause complications such as 
whether to call Parent1’s fun() or Parent2’s fun() method.

         GrandParent
           /     \
          /       \
      Parent1      Parent2
          \       /
           \     /
             Test

// A Grand parent class in diamond 
class GrandParent 
{ 
	void fun() 
	{ 
		System.out.println("Grandparent"); 
	} 
} 

// First Parent class 
class Parent1 extends GrandParent 
{ 
	void fun() 
	{ 
		System.out.println("Parent1"); 
	} 
} 

// Second Parent Class 
class Parent2 extends GrandParent 
{ 
	void fun() 
	{ 
		System.out.println("Parent2"); 
	} 
} 


// Error : Test is inheriting from multiple 
// classes 
class Test extends Parent1, Parent2 
{ 
public static void main(String args[]) 
{ 
	Test t = new Test(); 
	t.fun(); 
} 
} 

From the code, we see that: On calling the method fun() using Test object will cause complications such as whether to call Parent1’s fun() or Child’s fun() method.

Therefore, in order to avoid such complications Java does not support multiple inheritance of classes.
