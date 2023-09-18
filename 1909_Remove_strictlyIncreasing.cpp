#include <iostream>
#include <vector>
using namespace std;

/*
Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.

The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).
*/
class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        int a = nums[0];
        bool c = true;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= a)
            {
                if (c)
                {
                    c = false;
                    if (i == 1 || nums[i] > nums[i - 2])
                    {
                        a = nums[i];
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                a = nums[i];
            }
        }
        // printf("%d", i);
        return true;
    }
};

int main()
{
    vector<int> arr;
    vector<int> arr2;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    Solution s;

    cout << s.canBeIncreasing(arr) << endl;

    return 0;
}

// C language stack