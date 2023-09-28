
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

A subarray is a contiguous subsequence of the array.


Easy solution 
start * end==total combintaions
odd subarray=total/2
if total odd  odd subarray+1

sum =sum+(no of times an index element occured ) * nums[i]
*/

class Solution
{
public:
   int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0,n=arr.size(),cal;
        for(int i=0;i<n;i++)
        {
            cal=(n-i)*(i+1);
            if(cal%2!=0)
                cal=(cal/2)+1;
            else cal=cal/2;
               sum+=(cal * arr[i]); 
        }
        return sum;
    }
};

int main()
{
    vector<int> original = {1,4,2,5,3};
    int out;
    Solution s;
    out = s.sumOddLengthSubarrays(original);
    cout<<out;

    return 0;
}