
#include <iostream>
#include <vector>
#include <algorithm>
#include<stdint.h>
#include<cmath>
using namespace std;

/*
Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.

In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.

Return an array containing the index of the row, and the number of ones in it.

  
*/

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
       
        int max=-1;
        int ind;
        for(int i=0;i<mat.size();i++)
        {
            int ans=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                ans++;
            }
            if(ans>max)
            {
                max=ans;
                ind=i;
            }
        }
       
        return {ind,max};
    }
};

int main()
{
  vector< vector<int>> original = {{0,0,0},{0,1,1}};
    int out;
   vector<int>arr;
    Solution s;
    arr=s.rowAndMaximumOnes(original);
    cout<<arr[0]<<" "<<arr[1];
    return 0;
}