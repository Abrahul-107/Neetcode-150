#include<iostream>
using namespace std;

void bfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>&grid)
{
    visited[row][col] = 1;
    queue<pair<int,int>>bfsQueue;
    int rowSize = grid.size();
    int colSize = grid[0].size();

    bfsQueue.push({row,col});

    while(!bfsQueue.empty())
    {
        int row = bfsQueue.front().first;
        int col = bfsQueue.front().second;
        bfsQueue.pop();

        for(int neigbourRow = -1;neigbourRow<2;neigbourRow++)
        {
            for(int neigbourCol = -1;neigbourCol<2;neigbourCol++)
            {
                if(abs(neigbourCol)+abs(neigbourRow) == 2) continue;
                int nRow = row + neigbourRow;
                int nCol = col + neigbourCol;
                if(nRow>=0 && nRow<rowSize && nCol>=0 && nCol<colSize && grid[nRow][nCol]=='1' && !visited[nRow][nCol])
                {
                    visited[nRow][nCol] = 1;
                    bfsQueue.push({nRow,nCol});
                }
            }
        }
    }

}

int minIsland(vector<vector<char>>&grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();

    vector<vector<int>>visited(rowSize,vector<int>(colSize));
    int count  = 0;

    for(int i=0;i<rowSize;++i)
    {
        for(int j=0;j<colSize;++j)
        {
            if(!visited[i][j] && grid[i][j]=='1')
            {
                bfs(i,j,visited,grid);
                count++;
            }
        }
    }
    return count;

}


int main()
{

    vector<vector<char>>grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout<<minIsland(grid);



    return 0;
}