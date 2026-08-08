#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& order){
    if(visited[node]==1){ return false ; }//cycle found
    if(visited[node]==2){ return true ; }//already processed

    visited[node] = 1;//visiting 
        for(int next: adj[node]){
            if(!dfs(next,adj,visited,order)) return false;
        }
    visited[node] = 2; //visited node
    order.push_back(node);
    return true;


}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> visited(numCourses,0),order;
        for (int i = 0; i < numCourses; i++)
        {
            if(!visited[i]){
                if(!dfs(i,adj,visited,order)) return {}; //cycle found
            } 
        }
        reverse(order.begin(),order.end());
        return order;
    }
};
int main(){
        Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    
    vector<int> result = sol.findOrder(numCourses, prerequisites);
    
    if (result.empty()) {
        cout << "No valid course order exists (cycle detected)." << endl;
    } else {
        cout << "One possible course order: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }
    
    return 0;

}