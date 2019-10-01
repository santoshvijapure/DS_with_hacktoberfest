const BST = require('./BinarySearchTree');
const { describe, it } = require('mocha');
const { expect } = require('chai');

describe('BST', () => {
  it('should be able to create a new BST with a value', () => {
    const binarySearchTree = new BST(10);
    expect(binarySearchTree.val).to.equal(10);
  });
  it('should be able to add an element and insert left', () => {
    const binarySearchTree = new BST(10);
    binarySearchTree.insert(5);
    expect(binarySearchTree.val).to.equal(10);
    expect(binarySearchTree.right).to.equal(null);
    expect(binarySearchTree.left.val).to.equal(5);
  });
  it('should be able to add elements to the right', () => {
    const binarySearchTree = new BST(10);
    binarySearchTree.insert(50);
    expect(binarySearchTree.val).to.equal(10);
    expect(binarySearchTree.left).to.equal(null);
    expect(binarySearchTree.right.val).to.equal(50);
  });

  it('should be able search for values that exist in BST', () => {
    const binarySearchTree = new BST(10);
    binarySearchTree.insert(5);
    binarySearchTree.insert(50);
    expect(binarySearchTree.search(5)).to.equal(true);
  });

  it("should be able return false if can't find the value", () => {
    const binarySearchTree = new BST(10);
    binarySearchTree.insert(5);
    binarySearchTree.insert(50);
    expect(binarySearchTree.search(500)).to.equal(false);
  });
});
