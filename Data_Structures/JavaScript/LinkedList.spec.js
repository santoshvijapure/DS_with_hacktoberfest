const LL = require('./LinkedList')
const { describe, it } = require('mocha')
const { expect } = require('chai')

describe('LinkedList', () => {
  it('should have sensible initializations', () => {
    const ll = new LL();
    expect(ll.length()).to.equal(0);
    expect(ll.contains('nothing')).to.equal(false)
  })
  it('should be able to add an element', () => {
    const ll = new LL();
    const str = 'my value @ 0'
    ll.prepend(str);
    expect(ll.length()).to.equal(1)
    expect(ll.contains(str)).to.equal(true)
    expect(ll.get(0)).to.equal(str)
  })
  it('should be able to add more elements', () => {
    const ll = new LL();
    const stuff = [
      'A', 'B', 'C',
    ];
    stuff.forEach((el) => ll.append(el))

    expect(ll.toArray()).to.deep.equal(stuff)

  })

  it('should be able to remove stuff', () => {
    const ll = new LL();
    const stuff = [
      'A', 'B', 'C'
    ];
    stuff.forEach((el) => ll.append(el))

    ll.remove(1)
    expect(ll.toArray()).to.deep.equal(['A', 'C'])

  })

  it('should handle complex operations', () => {
    const ll = new LL();
    const stuff = [
      'B', 'C', 'Z'
    ]
    stuff.forEach((el) => ll.append(el))

    ll.prepend('A')
    ll.append('D')

    ll.remove(3)

    expect(ll.toArray()).to.deep.equal('ABCD'.split(''))

  })
})
