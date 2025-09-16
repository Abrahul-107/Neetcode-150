#include<iostream>
using namespace std;

int searchInMatrix(vector<vector<int>>&matrix,int target)
{
    int colSize = matrix.size();
    int rowSize = matrix[0].size();

    int left = 0;
    int right = colSize*rowSize - 1;
    
    while (left<=right)
    {
        //Finding the middle
        int mid = left + (right-left) / 2;
        //By this we can get the middle row 
        int midRow = mid / rowSize;
        //By this we can get the middle col 
        int midCol = mid % rowSize;

        if(matrix[midRow][midCol]==target)  
            return true;
        else if(matrix[midRow][midCol]<target)
            left = mid+1;
        else
            right = mid -1;
    }
    return false;
    

}

int main()
{
    vector<vector<int>>matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout<<searchInMatrix(matrix,target);
    return 0;
    
}