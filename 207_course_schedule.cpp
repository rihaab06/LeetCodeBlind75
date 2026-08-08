#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution{
public:
unordered_set<int> visitSet; 
unordered_set<int> checked;
bool dfs(int course,unordered_map<int,vector<int>>& preMap){
    if(visitSet.count(course)) return false;
    if(checked.count(course)) return true;
    visitSet.insert(course);
    
    for(int nextCourses: preMap[course]){
         if(!dfs(nextCourses,preMap)) return false;
    }
    visitSet.erase(course);
    checked.insert(course);

    return true;    
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> preMap;
        for (auto &p:prerequisites)
        {
            int course = p[0];
            int prereq = p[1];
            preMap[prereq].push_back(course);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if(!dfs(i,preMap)) return false;
        }
            return true; // no cycles found

        
        
    }

};
int main(){
    Solution sol;
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{1,0},{2,1},{3,2}};
    cout << "Can finish courses? " << (sol.canFinish(numCourses1, prerequisites1) ? "Yes" : "No") << endl;
return 0;
}