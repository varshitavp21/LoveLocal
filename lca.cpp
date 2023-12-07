// Medium 1 


// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

#include <bits/stdc++.h>
using namespace std;

/*
    Apporach 1 : 
        1.First taking input and converting to vector readIntegers() function 
        2.We observe that the given input is in the form of level so we have to convert into bst
            if the vectors data is less the root then it will be the left subtree 
            else it will be at the right subtree
        3.create CreateBst 
        4. Now we have to find the lowest common ancestor 
                if root is NULL or given node is p or q , => then return the current node
                recursively calling the left and right subtree
                if both left and right are not NULL , it means that the nodes p ,q exists in different subtree and the current root is their lowest common ancestor.
                If one of left or right is NULL, it means both nodes p and q exist in the same subtree. In this case, the lowsest common ancestor is in the non-NULL subtree.
.       
    Time complexity : O(N) 
                     where N is the number of the nodes in the tree.
    Space Complexity : O(N)
                    extra constant space 

*/

// node of a BST
class Tree
{
    public:
        int data;
        Tree* left;
        Tree* right;
};

// creating the new node
Tree* getNode(int data)
{
	Tree* node = new Tree();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

// since the given input is in the level order so it is needed to convert the level order into the needed  bst 
Tree* LevelOrder(Tree* root, int data)
{
	if (root == NULL) {
		root = getNode(data);
		return root;
	}
	if (data <= root->data)
		root->left = LevelOrder(root->left, data);
	else
		root->right = LevelOrder(root->right, data);
	return root;
}

// constructing the bst from the level order, n - size of the sorted array
Tree* CreateBst(vector<int> nums, int n)
{
	if (n == 0)
		return NULL;
	Tree* root = NULL;

	for (int i = 0; i < n; i++)
		root = LevelOrder(root, nums[i]);

	return root;
}


//  function to return the lowest common ancestor of p and q
/**
 * Creates a binary search tree (BST) from an array of integers using level-order traversal.
 *
 * @param {number[]} nums - The array of integers to be used for constructing the BST.
 * @param {number} n - The number of elements in the array.
 * @returns {Tree|null} - The root of the constructed BST or null if the array is empty.
 */

// desired function to find the common ancestor between p and q.
Tree* commonancestor(Tree* root, Tree* p , Tree* q)
{
    if (root == NULL)
        return NULL;
 
    
    if (root->data > p->data && root->data > q->data)
        return commonancestor(root->left, p, q);
 
 
    if (root->data < p->data && root->data < q->data)
        return commonancestor(root->right, p, q);
 
    return root;
}



// enter the input of the tree nodes in one line as it is taken as a input using istringstream
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
    vector<int> nums = readIntegers();
	int n = nums.size();

	Tree* root = CreateBst(nums, n);


    	int d1 ;
	cin>>d1;
	int d2;
	cin>>d2;
	
	Tree* p = getNode(d1);
	Tree* q = getNode(d2);
	Tree* ans =commonancestor(root,p,q);
	if(ans)
	{
	    cout<<ans->data<<endl;
	}

	return 0;
}
