// LANGUAGE: java
// ENV: JVM
// AUTHOR: Naman Jain
// GITHUB: https://github.com/njain-01

import java.util.LinkedList;

public class bfsalgo{

	class Graph
	{
		int vertex;
		LinkedList<Integer> adj[];
		Graph(int n)
		{
			this.vertex=n;
			adj= new LinkedList[n];
			for (int i=0; i<n ; i++)
			{
				adj[i]= new LinkedList<>();
			}
		}
		public void addedge(int src, int des)
		{
			adj[src].add(des);
			adj[des].add(src); // for undirected graph
		}
		public void print()
		{
			for (int i = 0; i < vertex ; i++) {
	            if(adj[i].size()>0) {
	                System.out.print("Vertex " + i + " is connected to: ");
	                for (int j = 0; j < adj[i].size(); j++) {
	                    System.out.print(adj[i].get(j) + " ");
	                }
	                System.out.println();
	            }
	        }
		}
		public int[] bfs(int x)
		{
			LinkedList<Integer> queue= new LinkedList<>();
			boolean[] vis= new boolean[vertex];
			int[] dis= new int[vertex];
			for(int i=0; i<vertex ; i++)
			{
				dis[i]=-1;
			}
			vis[x]=true;
			dis[x]=0;
			queue.addFirst(x);
			int v= -1;
			while(queue.size()!=0)
			{
				v=queue.removeLast();
				for ( int j :adj[v])
				{
					if(dis[j]==-1)
					{
						dis[j]=dis[v]+1;
						queue.addFirst(j);								
					}
				}
			}
			return dis;
		}
		
	}

	public static void main(String[] args) {
		q3 ab= new q3();
// Let 5 be the total no. of vertices
		Graph ob= ab.new Graph(5);
// Vertices are numbered from 0 to 4
		ob.addedge(0, 4);
		ob.addedge(1, 2);
		ob.addedge(2, 3);
		int[] ans= ob.bfs(0);
		for (int i=0; i<5; i++)
		{
			System.out.print("Distance from vertex "+i+" :");
			System.out.print(ans[i]);
			System.out.print("\n");
		}
		
	}

}
