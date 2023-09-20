#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

Return a list of groups such that each person i is in a group of size groupSizes[i].

Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.
*/

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        // Make an pair vector having value inorder=====>(elements,index)
        vector<pair<int, int>> m;

        for (int i = 0; i < groupSizes.size(); i++)
        {
            m.push_back({groupSizes[i], i});
        }

        // sort pair using first element of pair like (2,1) and (0,2) so (0,2) and (2,1)
        sort(m.begin(), m.end());

        // make an arr which will store values(indexes) till count of elements
        vector<int> arr;
        // push arr into ans vector when count reach to elements
        // then clear vector 
        vector<vector<int>> ans;

        for (int i = 0; i < m.size(); i++)
        {
            arr.push_back(m[i].second);
            if (arr.size() == m[i].first)
            {
                ans.push_back(arr);
                arr.clear();
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> original = {3, 3, 3, 3, 3, 1, 3};
    vector<vector<int>> out;
    Solution s;
    out = s.groupThePeople(original);
    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}