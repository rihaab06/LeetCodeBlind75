    #include<iostream>
    #include<vector>
    using namespace std;
    class Solution{
    public:
        vector<vector<int>> result;
            void dfs(vector<int>& candidates, int target, int i, int total, vector<int>& cur) {
                    if(total==target){
                        result.push_back(cur);
                        return;
                    }
                    if (i>=candidates.size() || target<total)
                    {
                        return;
                    }
                    //  To incluce
                    cur.push_back(candidates[i]);
                    dfs(candidates,target,i,total+candidates[i],cur);
                    cur.pop_back();
                    //  to exclude
                    dfs(candidates,target,i+1,total,cur);
                    
            
        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int>cur;
            dfs(candidates,target,0,0,cur); 
            return result;
        }

    };
    int main(){
        Solution sol;
        vector<int> candidates = {2, 3, 6, 7};
        int target = 7;
        vector<vector<int>> result = sol.combinationSum(candidates, target);
        cout << "Combinations that sum to " << target << ":\n";
        for (auto &comb : result) {
            cout << "[ ";
            for (int num : comb) cout << num << " ";
            cout << "]\n";
        }
    return 0;
    }