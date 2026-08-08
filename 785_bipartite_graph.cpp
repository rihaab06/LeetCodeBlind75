#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for (int i = 0; i < n; i++)
        {
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i] =0;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for(int neighbour: graph[node]){
                        if (color[neighbour]==-1)
                        {
                            color[neighbour] = 1-color[node];
                            q.push(neighbour);

                        }
                        else if(color[neighbour] == color[node]){
                            return false;
                        }
                        
                    }

                }
                
            }
        }
        return true;
    }

};
int main(){
     Solution s;
    vector<vector<int>> graph1 = {
        {1,3}, {0,2}, {1,3}, {0,2}
    }; 
    cout << (s.isBipartite(graph1) ? "true" : "false") << endl; // true

    vector<vector<int>> graph2 = {
        {1,2,3}, {0,2}, {0,1,3}, {0,2}
    };
    cout << (s.isBipartite(graph2) ? "true" : "false") << endl; // false
return 0;
}