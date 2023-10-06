
#include <iostream>
#include <vector>
#include <algorithm>
#include<stdint.h>
#include<cmath>
using namespace std;

/*
The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 
*/

class Solution_beats5percent
{
public:
   int64_t  binaryTodecimal(int x)
    {
        int64_t  ret=0,pow=1;
        while(x)
        {
            ret=ret+(x%2)*pow;
            pow*=10;
            x/=2;

        }
        return ret;
    }


     int subsetXORSum(vector<int>& nums) {
        int sum=0,sum2=0,n=nums.size();
        int subset=pow(2,n);    
        for(int i=0;i<subset;i++)
        {
            int64_t bin=binaryTodecimal(i);
            int64_t  div=pow(10,n-1);
            for(int j=0;j<n;j++)
            {
                
                if((bin/div)==1)
                {
                    sum2=(sum2^nums[j]);
                   

                }
                bin=bin%div;
                div/=10;
            }
            sum+=sum2;
            sum2=0;
           

        }
        return sum;
    }
};


class Solution_Online
{
public:
    int subset(vector<int>nums,int level,int currentXor)
    {
        if(level==nums.size())
        {
            return currentXor;
        }
        int include=subset(nums,level+1,currentXor^nums[level]);
        int exclude=subset(nums,level+1,currentXor);
        return (include+exclude);
    }
     int subsetXORSum(vector<int>& nums) {
        return subset(nums,0,0);
               
    }

};

int main()
{
    vector<int> original = {5,1,6};
    int out;
    // Solution_beats5percent s;
    // out = s.subsetXORSum(original);
    // cout<<out<<endl;
    Solution_Online s2;
    out=s2.subsetXORSum(original);
    cout<<out;
    return 0;
}