
class Solution
{
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V);
	    vector<int> indegree(V);
	    vector<int> toposort;
	    
	    for(int u = 0; u < V; u++){
	        for(auto v : adj[u]){
	            indegree[v]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0; i < V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        toposort.push_back(node);
	        for(auto adjNode : adj[node]){
                if(--indegree[adjNode] == 0){
                    q.push(adjNode);
                }
	        }
	    }
	    
	    return toposort;
	}
};




