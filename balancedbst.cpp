// Easy  2


// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced binary search tree



// C++ program to print BST in given range
/*Approach 1: 
        since the given array in already in the sorted array so to create a high balances BST
        In BST the left of root node should be less than value of root and right val of the root should be grater than to root 
        so in the sorrted array we can just find the middle of the array (that will be the root of the tree) and then the left side of the array will be the left tree 
        of the root and right side of the tree will be right side of the middle element

        for example : nums = [-10,-3,0,5,9]
                    in this case we have to first convert it to height balance bst.
                    sortedArrayToBST(nums,0,nums.size())
                        in this the middle number =index =2;
                        so 0 will be the root of the tree and {-10,-3} will be left subtree  , {5,9} will be right subtree
                        again the sortedArrayToBST(nums,0,middle-1) and sortedArrayToBST(nums,middle+1,nums.size()) is recursively called 
                         0
                        / \
                      -3  9
                      /   /
                    -10   5



        Basic Algorithm :
        1. find the middle element of the sorted array.
        2.  recursive function
             the travesed value  from (0,middle) -> roots left subtree
             the traversed value from (middle,end) ->roots right subtree

        we have observed that the tree is printed in the level order 

    Time 

*/

#include <bits/stdc++.h>
using namespace std;

/* A Binary Tree node */
class Tree
{
    public:
        int val;
        Tree* left;
        Tree* right;
};


Tree* newNode(int data);

// desired function
/**
 * Constructs a Binary Search Tree (BST) from a sorted array.
 *
 * @param {number[]} nums - The sorted array.
 * @param {number} l - The left index of the current subarray.
 * @param {number} h - The right index of the current subarray.
 * @returns {Tree|null} - The root of the constructed BST or null if the array is empty.
 */
// function to convert the nums to height balanced bst based on approach.
Tree* sortedArrayToheightBST(vector<int> nums, int l, int h)
{
	
	if (l > h)
		return nullptr ;
    // step1
	int middle = (l+h) / 2;
	Tree* root = newNode(nums[middle]);

    // step2 
	root->left = sortedArrayToBST(nums, l, middle- 1);


	root->right = sortedArrayToBST(nums, middle + 1, h);

    return root;

	
}

// inserting the node into the array
Tree* newNode(int data)
{
	Tree* node = new Tree();
	node->val = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}



// printing the level order traversal of the bst
/*
    Algorithm : 
        to get the level order traversal of the bst tree 
        1.create a queue<Tree*> q 
        2.push root in the queue
        3.iterate until the queue is empty
            print the front of queue and pop it.
            if root->left is present then push into the queue
            if root->right is present then push into the queue 

    Time Complexity: O(N)
    space Complecity :O(N) where N is the number of nodes in the bst tree.
    */
void printLevelOrder(Tree* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    queue<Tree*> q;
 
   
    q.push(root);
 
    while (q.empty() == false) {
         
       
        Tree* node = q.front();
        cout << node->val << " ";
        q.pop();
 
        
        if (node->left != NULL)
            q.push(node->left);
 
        if (node->right != NULL)
            q.push(node->right);
    }
    
}
 



// since the size of the arr is not defined so this function is used this take the input from the command line and the number should be in the single line bcs
// taken as string
// converts it into vector


vector<int> readIntegers() {
    vector<int> nums;
    string line;

    getline(cin, line);

    istringstream iss(line);
    int number;

    while (iss >> number) {
        nums.push_back(number);
    }

    return nums;
}


int main()
{

	vector<int> nums;
    nums = readIntegers();

	int n = nums.size();

	
	Tree* root = sortedArrayToBST(nums, 0, n - 1);
	
    printLevelOrder(root);
	

	return 0;
}


