// Easy 3


// Given an integer numRows, return the first numRows of Pascal's triangle.


#include<bits/stdc++.h>
using namespace std;

/*
    Approach 1 : 
        We can see that the binomial coefficient of rows r and columns c . =>  r-1Cc-1
        Alogorithm:
        iterate from  1 to n
        caluculate the binominal coefficinet and and that to the vector using binomialCoeff function 

        Time Complexity : O(N^3)
        Space :O(1);
        This is not the optimal solution 
    */


// Approach 1 

/**
 * Finds all numbers in the given array that occur more than n/3 times.
 *
 * @param {Array<number>} array - The input array of numbers.
 * @param {number} n - The length of the input array.
 * @returns {Array<number>} - An array containing numbers that occur more than n/3 times.
 */

int binomialCoeff(int n, int k);



// Function to generate Pascal's Triangle and store values in a 2D vector
// Iterate through every line and populate the vector
 // Every line has number of integers equal to line number
vector<vector<int>> generatePascal(int n)
{
    vector<vector<int>> pascalTriangle(n, vector<int>());

    for (int line = 0; line < n; line++) {
       
        for (int i = 0; i <= line; i++) {
            pascalTriangle[line].push_back(binomialCoeff(line, i));
        }
    }

    return pascalTriangle;
}


// generating the each value of the triangle
int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}


/*
    Approach 2 :  if numRoms =3 
                                                                     1           i=0
                                                                1          1     i=1
                                                                  \      /
                                                              1       2      1 

               we can see that all the right and left corner of the trianle are 1 ; 
            Algo :
            1.create a vector<int> v which is size of i+1 and the default value will be 1 as all the left and right values are 1;
            to get the ans we have to observe that it is the sum of the previous rows values .
            2.add the values and insert in the vector v and later the vector v is inserted in the 2d vector. 

            Time complexity : O(N^2)


*/            

/**
 * Generates Pascal's Triangle up to the specified number of rows.
 *
 * @param {number} numRows - The number of rows to generate in Pascal's Triangle.
 * @returns {vector<vector<int>>} - Two-dimensional vector representing Pascal's Triangle.
 */

vector<vector<int>> pascaltrianle(int numRows) {
 
    vector<vector<int>> ans;
    for(int i=0;i<numRows;i++)
    {
        vector<int> v(i+1,1);
        for(int j=1;j<i;j++)
        {
            v[j] = ans[i-1][j] + ans[i-1][j-1];
        }

        ans.push_back(v);

    }

    return ans;

    }
  


int main()
{
    int numRows;
    cin>>numRows;
    vector<vector<int>> ans;
    ans = pascaltrianle(numRows);

    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<ans[i][j]<<" ";
        }
    }

    return 0;
}
