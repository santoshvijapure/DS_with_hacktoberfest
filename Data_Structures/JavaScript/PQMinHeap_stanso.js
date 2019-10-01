// LANGUAGE: JavaScript
// AUTHOR: Stan So
// GITHUB: https://github.com/stanley-c-so/

module.exports = class PQMinHeap {
  constructor() {
    this.queue = [];      // elements will be in the form of {value: someValue, priority: somePriority}
  }

  // UTILITY METHODS
  _swap(idxA, idxB) {
    [this.queue[idxA], this.queue[idxB]] = [this.queue[idxB], this.queue[idxA]];
  }
  _parentIdx(childIdx) {
    return Math.floor((childIdx - 1) / 2);
  }
  _childrenIndices(parentIdx) {
    return [2 * parentIdx + 1, 2 * parentIdx + 2];
  }

  // PRIORITY QUEUE METHODS
  peek() {
    return this.queue[0];
  }
  insert(value, priority = value) {         // if priority is not provided, then value and priority are the same
    this.queue.push({ value, priority });
    let currentNodeIdx = this.queue.length - 1;
    while (currentNodeIdx !== 0 && this.queue[currentNodeIdx].priority < this.queue[this._parentIdx(currentNodeIdx)].priority) {
      this._swap(currentNodeIdx, this._parentIdx(currentNodeIdx));
      currentNodeIdx = this._parentIdx(currentNodeIdx);
    }
    return this;    // for chaining
  }
  popMin() {
    const poppedMin = this.queue.shift();
    const lastElement = this.queue.pop();
    if (lastElement !== undefined) this.queue.unshift(lastElement);
    let currentNodeIdx = 0;
    let [left, right] = this._childrenIndices(currentNodeIdx);
    while (left < this.queue.length) {
      let smallestChildIdx = right < this.queue.length && this.queue[right].priority < this.queue[left].priority
        ? right
        : left;
      if (this.queue[smallestChildIdx].priority < this.queue[currentNodeIdx].priority) {
        this._swap(currentNodeIdx, smallestChildIdx);
        currentNodeIdx = smallestChildIdx;
        [left, right] = this._childrenIndices(currentNodeIdx);
      } else {
        break;
      }
    }
    return poppedMin;
  }
}