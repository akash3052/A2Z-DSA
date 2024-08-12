class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses);
        vector<int> toposort;
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            for(auto nnode : adj[node]){
                --indegree[nnode];
                if(indegree[nnode] == 0){
                    q.push(nnode);
                }
            }
        }
        return toposort.size() == numCourses;
    }
};


