#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
class Solution{
public:
set<pair<int,int>> visited;
    void bfs(vector<vector<char>>& grid,int r, int c){
        
        int rows = grid.size();
        int columns = grid[0].size();
        queue<pair<int,int>> q;
        visited.insert({r, c});   // pair<int,int> instead of tuple
        q.push({r,c});
        while (!q.empty())
        {
          
         pair<int,int> cell = q.front(); // get the front element
    q.pop();                        // then remove it from the queue
    int x = cell.first;
    int y = cell.second;

         vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      for (int dr = 0; dr < directions.size(); dr++) {
    int newRow = x + directions[dr][0];
    int newCol = y + directions[dr][1];

    // Check if the new cell is within grid bounds
    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns) {
        // Check if it is land ('1') and not visited
        if (grid[newRow][newCol] == '1' && !visited.count({newRow, newCol})) {
            q.push({newRow, newCol});         // Add to queue for BFS
            visited.insert({newRow, newCol}); // Mark as visited
        }
    }
}

        
        }
        


    }

     int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int islands = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        
      for (int r = 0; r < rows; r++)
      {
        for (int  c = 0; c < columns ; c++)
        {
            if (grid[r][c] =='1'&& visited.find({r,c})==visited.end())
            {
                bfs(grid,r,c);
                islands+=1;
            }
            
        }
        
      }
      
        return islands;
    }
};

    int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int count = sol.numIslands(grid);
    cout << "Number of islands: " << count << endl;

    return 0;
}
