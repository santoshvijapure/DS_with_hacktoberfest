module.exports = class LinkedList {
  constructor() {
    this.head = null;
    this._size = 0;
  }

  prepend() {

  }

  append() {

  }

  insert(value, idx) {

  }

  remove(idx) {

  }

  get(idx) {

  }

  contains(value) {
    let curr = this.head;
    while (curr !== null && curr.value !== value) {
      curr = curr.head;
    }
    return curr !== null
  }

  size() {
    return this._size;
  }


}

class Node {
  constructor(value, next = null) {
    this.value = value;
    this.next = null;
  }
}
