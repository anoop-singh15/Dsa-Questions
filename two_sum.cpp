#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++)
        {

            if (m.find(target - nums[i]) != m.end())
            {
                arr.push_back(m[target - nums[i]]);
                arr.push_back(i);
                return arr;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return arr;
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
    solution s;
    int x;
    cin >> x;
    arr2 = s.twoSum(arr, x);
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}