#include <iostream>
#include <vector>
using namespace std;

/*
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
*/
class Solution
{
public:
   int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0,sum;
        for(int i=0;i<accounts.size();i++)
        {
            sum=0;
            for(int j=0;j<accounts[i].size();j++)
            {
                sum+=accounts[i][j];
            }
            ans= std::max(sum,ans);
        }
        return ans;
    }
};

int main()
{
    vector <vector <int> > original = {{1,2,3},{4,5,6},{7,8,10}};
    Solution s;

    cout << s.maximumWealth(original) << endl;

    return 0;
}

// C language stack