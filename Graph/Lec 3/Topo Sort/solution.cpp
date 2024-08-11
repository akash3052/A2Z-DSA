
class Solution
{
	public:
	
	void dfs(int src, stack<int> &stk, vector<int> adj[], vector<int> &visited){
	    visited[src] = 1;
	    for(auto adjacentNode: adj[src]){
	        if(!visited[adjacentNode]){
	            dfs(adjacentNode, stk, adj, visited);
	        }
	    }
      // note : after proccessing each node, push it into the stack.
	    stk.push(src);
	}

  vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V);
	    stack<int> stk;
	    vector<int> toposort;
	    for(int i = 0; i < V; i++){
	        if(!visited[i]){
	            dfs(i, stk, adj, visited);
	        }
	    }
	    while(!stk.empty()){
	        toposort.push_back(stk.top());
	        stk.pop();
	    }
	    return toposort;
	}
};

// TC = O(V+E)
// SC = O(V) + O(V)


