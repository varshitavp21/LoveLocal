// Hard 2 


// You are given a string s. You can convert s to a 
// palindrome by adding characters in front of it.
// Return the shortest palindrome you can find by performing this transformation.

/*
    Approach :
        in this case we can find the longest palindromic substring and the remaining 
        can be reversed and added into front.
        for example :
                        s = "aacecaaa"  
                    in this the longest palindromic substring is from 0 to 6th index so the remaining 
                    is 'a' (reverse the remaining string) and add it in the front.
        example 2 :  s ="abcd"
                here the longest substring is a itself 
                the remaining substring is "bcd" reverse it and add it in the front .


        general:
            find the longest palindrominc substr starting from 0th index
            reverse it and add it in the begining.
    Algo:
        1.first take string r = s +'#'+reverseof(s) 
        The "#" in the middle is required, since without the #, the 2 strings could mix with each ther, producing wrong answer.
        2.creating the vector v and intialising all the values with 0 and findin the length of the longest palindromic substring  
            mainfunc(v,r) =>
                we will traverse r and find the v[i] == v[j]
                    i++ and v[j] = i ,j++;
                else
                    if(i==0)  j++;
                    else
                        i =v[i-1]
        3.find the remaining substring from ith pos and reverse that and add it to the starting of the s.

    Time complexity : O(N)
    Space complexity : O(N)  
                    where N is the length of string.

*/



#include<bits/stdc++.h>
using namespace std;


/**
 * Calculates the longest prefix-suffix array for a given string.
 *
 * @param {number[]} v - The vector to store the longest prefix-suffix array.
 * @param {string} r - The input string for which the longest prefix-suffix array is calculated.
 * @returns {void}
 */

void mainfunc(vector<int> &v,string r)
{
    int i=0;
    int j=1;

    while(j<r.length())
    {
        if(r[i] == r[j])
        {
            i++;
            v[j] = i;
            j++;
        }

        else{
            if(i==0)
                j++;
            else    
                i = v[i-1];
        }

    }

    
}


/**
 * Finds the shortest palindrome by adding characters to the end of the input string.
 *
 * @param {string} s - The input string.
 * @returns {string} - The shortest palindrome obtained by adding characters to the end of the input string.
 */

string shortestpalindrom(string s)
{
   string rev = s;

    reverse(rev.begin(),rev.end());
    string r = s +'#' + rev;

    vector<int> v(r.length(),0);
    mainfunc(v,r);
    int i = v[r.length()-1];
    string test = s.substr(i);

   reverse(test.begin(),test.end());

    return test;


}

int main()
{
    string s;
    cin>>s;

    string ans = shortestpalindrom(s);

    cout<<ans<<endl;

    return 0;

}