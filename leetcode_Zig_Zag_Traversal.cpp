//         1
//       /   \
//      2    3
//     / \    /   \
//    4   5 6   7
// Output:
// 1 3 2 4 5 6 7
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
       vector<int>ans;
       if(!root) return ans;
    	bool flag=true;
    	stack<Node *>current;
    	stack<Node *>next;
    	current.push(root);
    	while(!current.empty())
    	{
    	    Node *currTop=current.top();
    	    current.pop();
    	    if(currTop)
    	    {
    	        ans.push_back(currTop->data);
    	        if(flag)
    	        {
    	            if(currTop->left)
    	            {
    	               next.push(currTop->left);
    	            }
    	            if(currTop->right)
    	            {
    	                next.push(currTop->right);
    	            }
    	            
    	        }
    	        else
    	        {
    	             if(currTop->right)
    	            {
    	                next.push(currTop->right);
    	            }
    	             if(currTop->left)
    	            {
    	                next.push(currTop->left);
    	            }
    	            
    	        }
    	        if(current.empty())
    	        {
    	            flag=!flag;
    	            swap(current,next);
    	        }
    	    }
    	}
    	    return ans;
    	    
    }
};