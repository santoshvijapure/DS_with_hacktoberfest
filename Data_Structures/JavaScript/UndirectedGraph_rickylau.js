// Graphs

// A graph structure consists of a finite (and possibly mutable) set of vertices or nodes or points, together with a set of unordered pairs of these vertices for an undirected graph or a set of ordered pairs for a directed graph.

// Nodes + Connections

// Uses for graphs
// social networks
// location/mapping
// routing algorithims
// visual hierarchy
// file system optimizations
// EVERYWHERE!

// Undirected Graph
// no direction to the connections(edge)

// Directed Graph
// direction is involved in connections(edge)

// Weighted Graph
// each edge has a weight associated with it.

// Unweighted Graph
// each edge has no weight associated with it.

// This is an example of an Undirected Graph in JavaScript.

class Graph {
  constructor() {
    this.adjacencyList = {};
  }

  addVertex(vertex) {
    if (!this.adjacencyList[vertex]) this.adjacencyList[vertex] = [];
  }

  addEdge(vertex1, vertex2) {
    if (this.adjacencyList[vertex1]) this.adjacencyList[vertex1].push(vertex2);
    if (this.adjacencyList[vertex2]) this.adjacencyList[vertex2].push(vertex1);
  }

  removeEdge(vertex1, vertex2) {
    // only works if vertex already exists in graph
    this.adjacencyList[vertex1] = this.adjacencyList[vertex1].filter(
      val => val !== vertex2
    );
    this.adjacencyList[vertex2] = this.adjacencyList[vertex2].filter(
      val => val !== vertex1
    );
  }

  removeVertex(vertex) {
    for (let key in this.adjacencyList) {
      if (key === vertex) {
        for (let val of this.adjacencyList[vertex]) {
          this.removeEdge(vertex, val);
        }
        delete this.adjacencyList[key];
      }
    }
  }

  // dfs recursive
  dfsRecursive(start) {
    const results = [];
    const visited = {};
    const adjacencyList = this.adjacencyList;

    function dfs(vertex) {
      if (!vertex) return null;
      visited[vertex] = true;
      results.push(vertex);
      adjacencyList[vertex].forEach(neighbor => {
        if (!visited[neighbor]) {
          return dfs(neighbor);
        }
      });
    }
    dfs(start);
    return results;
  }

  // dfs iterative
  dfsIterative(start) {
    const stack = [start];
    const result = [];
    const visited = {};
    let currentVertex;

    visited[start] = true;

    while (stack.length) {
      currentVertex = stack.pop();
      result.push(currentVertex);
      this.adjacencyList[currentVertex].forEach(neighbor => {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          stack.push(neighbor);
        }
      });
    }
    return result;
  }

  // bfs iterative
  bfs(start) {
    const queue = [start];
    const result = [];
    const visited = {};
    let currentVertex;

    visited[start] = true;

    while (queue.length) {
      currentVertex = queue.shift();
      result.push(currentVertex);
      this.adjacencyList[currentVertex].forEach(neighbor => {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          queue.push(neighbor);
        }
      });
    }
    return result;
  }
}
