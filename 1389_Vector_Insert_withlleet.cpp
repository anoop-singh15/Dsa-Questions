
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given two arrays of integers nums and index. Your task is to create target array under the following rules:

Initially target array is empty.
From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.

It is guaranteed that the insertion operations will be valid.
*/

class Solution
{
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> arr;
        for(int i=0;i<nums.size();i++)
        {
            arr.insert(arr.begin()+index[i],nums[i]);
        }
        return arr;
    }
};

int main()
{
    vector<int> original = {0,1,2,3,4};
    vector<int> original2 = {0,1,2,2,1};
    vector<int> out;
    
    Solution s;
    out = s.createTargetArray(original,original2);
    for (int i = 0; i < out.size(); i++)
    {
        
            cout << out[i] << " ";
        
        
    }

    return 0;
}