#include<iostream>
using namespace std;

int bfs(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&grid)
{
    visited[row][col] = 1;
    int rowSize = grid.size();
    int colSize = grid[0].size();
    queue<pair<int,int>>q;
    q.push({row,col});

    int area = 1;
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();


        for(int nRow=-1;nRow<=1;++nRow)
        {
            for(int nCol=-1;nCol<=1;++nCol)
            {
                if(nRow ==0 && nCol==0)
                    continue;
                if(abs(nRow)+abs(nCol)==2)
                    continue;
                int connectedRow = row+nRow;
                int connectedCol = col+nCol;
                if(connectedRow>=0 && connectedRow<rowSize  && connectedCol>=0 && connectedCol<colSize 
                && !visited[connectedRow][connectedCol] && grid[connectedRow][connectedCol]==1)
                {
                    visited[connectedRow][connectedCol] = 1;
                    q.push({connectedRow,connectedCol});
                    area++;

                }
            }
        }
    }
    return area;

}

int maxAreaOfIsland(vector<vector<int>>&grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();

    vector<vector<int>>visited(rowSize,vector<int>(colSize,0));
    int maxArea = 0;

    for(int row=0;row<rowSize;++row)
    {
        for(int col=0;col<colSize;++col)
        {
            if(!visited[row][col] && grid[row][col]==1)
            {
                int area = bfs(row,col,visited,grid);
                maxArea = max(maxArea,area);
            }
        }
    }
    return maxArea;
}

int main() 
{
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    cout << maxAreaOfIsland(grid) << endl;  // prints maximum island area
    return 0;
}
