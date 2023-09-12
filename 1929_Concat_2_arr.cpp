
#include<iostream>
#include<vector>
using namespace std;



// c language solution
// int* concat(int* nums, int numsSize, int* returnSize)
// {
//     int *arr =(int *)malloc((2 * numsSize) * sizeof(int));
//     int i=0,j=0;
//     *returnSize=2 * numsSize;
//     while(i!=*returnSize)
//     {
//         if(j==numsSize)
//         {
//             j=0;
//         }
//         arr[i]=nums[j];
//         i++;
//         j++;
//     }
//     return arr;
   
// }

// c++ solution Save file with c++ extension and apply class

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

int main()
{

//    int arr[10000];
//    int *brr;
//    int n;
//    int retn=0;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++)
//    {
//         scanf("%d",&arr[i]);   
//    }
//    brr=concat(arr,n,&retn);
//    for(int i=0;i<retn;i++)
//    {
//         printf("%d ",brr[i]);
//    }

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
    
    arr2 = s. getConcatenation(arr);
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    
   return 0;
}