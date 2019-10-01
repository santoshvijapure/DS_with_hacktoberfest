module.exports = class LinkedList {
  constructor() {
    this.head = null;
    this._size = 0;
  }

  prepend(value) {
    this.insert(value, 0)
  }

  append(value) {
    this.insert(value, this._size)
  }

  insert(value, idx) {
    this._size++;

    if (idx === 0) { // only case where we have to modify the head
      this.head = new Node(value, this.head);
      return;
    }
    let curr = this.head;
    let i = 0;
    // stop 1 before where we want to add
    while (curr !== null && i < idx - 1) {
      i++;
      curr = curr.next
    }
    // grab the one after
    const succ = curr.next;
    // make the new one with next as the one after
    const node = new Node(value, succ)
    // assign prev's node next to new
    curr.next = node;
  }

  remove(idx) {
    if (this._size === 0) { return }

    this._size--;
    if (idx === 0) { // only case where we have to modify the head
      this.head = this.head.next;
      return;
    }

    let curr = this.head;
    let i = 0;
    // stop 1 before where we want to remove
    while (curr !== null && i < idx - 1) {
      i++;
      curr = curr.next
    }

    // grab the one after
    const succ = curr.next && curr.next.next;
    // assign prev's node next to new
    curr.next = succ;

  }

  get(idx) {
    let curr = this.head;
    let i = 0;
    while (curr !== null && i < idx) {
      curr = curr.next;
      i++;
    }
    return curr.value
  }

  contains(value) {
    let curr = this.head;
    while (curr !== null && curr.value !== value) {
      curr = curr.head;
    }
    return curr !== null
  }

  length() {
    return this._size;
  }

  toArray() {
    const arr = [];
    let curr = this.head;
    while (curr !== null) {
      arr.push(curr.value)
      curr = curr.next;
    }
    return arr;
  }


}

class Node {
  constructor(value, next = null) {
    this.value = value;
    this.next = next;
  }
}
