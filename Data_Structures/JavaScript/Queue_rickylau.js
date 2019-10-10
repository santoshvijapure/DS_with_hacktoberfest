// Queues

// A FIFO (First In First Out) data structure.

// TIME COMPLEXITY
// Insertion - O(1)
// Removal - O(1)
// Searching - O(n)
// Access - O(n)

class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.first = null;
    this.last = null;
    this.size = 0;
  }

  enqueue(val) {
    let newNode = new Node(val);
    if (!this.first) {
      this.first = newNode;
      this.last = newNode;
    } else {
      let currentLast = this.last;
      currentLast.next = newNode;
      this.last = newNode;
    }
    return ++this.size;
  }

  dequeue() {
    if (!this.first) return null;
    let currentFirst = this.first;
    if (this.first === this.last) this.last = null;

    this.first = currentFirst.next;
    currentFirst.next = null;
    this.size--;
    return currentFirst.value;
  }
}
