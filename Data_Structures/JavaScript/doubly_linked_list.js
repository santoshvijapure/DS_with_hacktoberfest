class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
    this.prev = null;
  }
}

class DoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }
  push(value) {
    let newNode = new Node(value);
    if (!this.head) {
      this.head = newNode;
      this.tail = this.head;
    } else {
      this.tail.next = newNode;
      newNode.prev = this.tail;
      this.tail = newNode;
    }
    this.length++;
    return this;
  }
  pop() {
    if (!this.tail) return false;
    let removedNode = this.tail;
    if (this.length === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.tail = removedNode.prev;
      this.tail.next = null;
      removedNode.prev = null;
    }
    this.length--;
    return removedNode;
  }
  shift() {
    let oldHead = this.head;
    if (!this.head) {
      return false;
    } else if (this.length === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.head = oldHead.next;
      this.head.prev = null;
      oldHead.next = null;
    }
    this.length--;
    return oldHead;
  }
  unshift(value) {
    let newNode = new Node(value);
    if (!this.head) {
      this.head = newHead;
      this.tail = this.head;
    } else {
      newNode.next = this.head;
      this.head.prev = newNode;
      this.head = newNode;
    }
    this.length++;
    return this;
  }
  get(idx) {
    if (idx >= this.length || idx < 0) return false;

    let curNode;
    let count;

    if (idx < this.length / 2) {
      count = 0;
      curNode = this.head;
      while (count !== idx) {
        curNode = curNode.next;
        count++;
      }
    } else {
      count = this.length - 1;
      curNode = this.tail;
      while (count !== idx) {
        curNode = curNode.prev;
        count--;
      }
    }
    return curNode;
  }
  set(idx, value) {
    let foundNode = this.get(idx);
    if (foundNode) {
      foundNode.value = value;
      return true;
    } else {
      return false;
    }
  }
  insert(idx, value) {
    if (idx < 0 || idx > this.length) return false;
    if (idx === 0 || !this.head) {
      return !!this.unshift(value);
    } else if (idx === this.length) {
      return !!this.push(value);
    } else {
      let newNode = new Node(value);
      let prevNode = this.get(idx - 1);
      let nextNode = prevNode.next;

      newNode.prev = prevNode;
      newNode.next = nextNode;
      prevNode.next = newNode;
      nextNode.prev = newNode;
      this.length++;
      return true;
    }
  }
  remove(idx) {
    if (idx < 0 || idx >= this.length) return false;
    if (idx === 0) {
      return this.shift();
    } else if (idx === this.length - 1) {
      return this.pop();
    } else {
      let removedNode = this.get(idx);
      let prevNode = removedNode.prev;
      let nextNode = removedNode.next;

      prevNode.next = nextNode;
      nextNode.prev = prevNode;
      removedNode.next = null;
      removedNode.prev = null;
      this.length--;
      return removedNode;
    }
  }
  reverse() {
    let curNode = this.head;
    this.head = this.tail;
    this.tail = curNode;
    let nextNode;
    for (let i = 0; i < this.length; i++) {
      nextNode = curNode.next;
      curNode.next = curNode.prev;
      curNode.prev = nextNode;
      curNode = nextNode;
    }
    return this;
  }
}
