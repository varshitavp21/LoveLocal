// Medium 3

// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

#include<bits/stdc++.h>
using namespace std;

/*lets take a 2d vector as  [["1","0","1","0","0"],
                             ["1","0","1","1","1"],
                             ["1","1","1","1","1"],
                             ["1","0","0","1","0"]]

    Algo:
    1.Use a nested loop to traverse each cell of the matrix.
    2.For each cell at position (i, j):
    3.If it is in the first row or first column, set v[i][j] to 1 if the corresponding element in the matrix is 1; otherwise, it remains 0.
    4.If it is not in the first row or first column:
    5.If the element at (i, j) in the matrix is 1, set v[i][j] to the minimum of the values to the left, above, and diagonally left-up, and then add 1. This represents the size of the square ending at (i, j) with all 1's.
    5.Update the ans with the maximum size encountered so far.

    Time Complexity : O(r*c) where r=rows ,c = column of the matrix
    

*/


// desired function 
// r= number of rows , c= number of columns 
// explaination:
/**
 * Finds the largest square containing only 1's in a given binary matrix.
 *
 * @param {number[][]} matrix - The binary matrix.
 * @returns {number} - The area of the largest square containing only 1's.
 */

int largestnumberof1s(vector<vector<int>>& matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    vector<vector<int>> v(r, vector<int>(c, 0));
    int ans = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || j == 0)
            {
                if (matrix[i][j] == 1)
                    v[i][j] = 1;
            }
            else
            {
                if (matrix[i][j] == 1)
                    v[i][j] = min(v[i - 1][j], min(v[i][j - 1], v[i - 1][j - 1])) + 1;
            }
            ans = max(ans, v[i][j]);
        }
    }

    return ans * ans;
}


// taking the 2d vector ad a input 
int main()
{
    vector<vector<int>> matrix {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    int ans = largestnumberof1s(matrix);
    cout << ans;

    return 0;
}
