// Medium 2 


// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*
    Approach 1 :
        Using count inbuilt funciton 

    Time Complexity : O(N);
    Space Complexity : O(1);

    Approach 2 :
        Using space 
        taking the input from the readInteger() function.
        Count all the number using hashMap

        and traverse thorugh the map and print all the numbers which are repeted more than n/3 times 

        for example :nums = [3,2,3] 
                    then using the map 3 -> 2
                                       2 -> 1
                    then we will iterate the map 
                    and see if map->second > n/3 here n=3 and only 3 is repeated more than 1 times so output will be 3

        Time Complexity : O(N);
        Space Compleity : O(N);

        where n is number length of the array

*/


// reading the input and  forming the vector<int> integers
vector<int> readIntegers() {
    vector<int> integers;
    string line;

   
    getline(std::cin, line);

    istringstream iss(line);
    int number;

    while (iss >> number) {
        integers.push_back(number);
    }

    return integers;
}


/**
 * Finds all numbers in the given array that occur more than n/3 times.
 *
 * @param {vector<int>} array - The input array of numbers.
 * @param {number} n - The length of the input array.
 * @returns {vector<int>} - An array containing numbers that occur more than n/3 times.
 */

// desired function
vector<int> getAllNumbers(vector<int> array, int n) {

   vector<int> ans;
   map<int,int> m;
   for(auto i:array)
   {
        m[i]++;
   }
   for(auto i :m)
   {
        if(i.second > n/3)
        {
            ans.push_back(i.first);
        }
   }
   for(auto i :ans)
   {
        cout<<i<<" ";
   }
    return ans;
}

int main()

{
    vector<int> array;
    array = readIntegers();

    vector<int> ans;

    ans = getAllNumbers(array, array.size());

    return 0;
}
