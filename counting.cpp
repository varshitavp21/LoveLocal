// Hard 3  

// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

/*
    Approach 1 :
            counting then numbers from 1 to n by iterating the digits of the number.
            countingnumberofones(n)=>
                int count=0
                iterating from i=1 to n 
                    temp =i
                    while temp>0 
                        r= temp%10
                        if(r==1)      count++            checking if the reminder i.e r is 1    
                        temp=temp/10
            return couunt

    Time Complexity : O(N^2)
                    where N is the value n
    Space Complexiyt : O(1)             
*/


#include<bits/stdc++.h>
using namespace std;



// Aproach 1

/**
 * Counts the number of occurrences of the digit '1' in the decimal representation of numbers
 * from 1 to the given number (inclusive).
 *
 * @param {number} n - The input number.
 * @returns {number} - The count of occurrences of the digit '1'.
 */

int countingnumberofones(int n)
{
    int count=0;
    int r;
    for(int i=1;i<=n;i++)
    {
        int temp = i;
        while (temp > 0)
        {
            r = temp%10;
            if(r==1)
                count++;

            temp = temp/10;      
        }

        
    }
    return count;
}

/*
    Approach 2 :
        1.count =0
        2.Iterate  i = 1 to n incrementing by 10 each time.
        3.Add (n / (i * 10 ) ) * i to countr after each (i*10) interval.
        Add min( max(n mod (i*10) – i + 1, 0), i) to countr.

    Time Complexity : O(logn)

*/

/**
 * Counts the number of occurrences of the digit '1' in the decimal representation of numbers
 * from 1 to the given number (inclusive).
 *
 * @param {number} n - The input number.
 * @returns {number} - The count of occurrences of the digit '1'.
 */

int countingone(int n)
{
    int count =0;
    int div = 0;
    int fac = 1;
    int i=1;

    while(i<=n)
    {
        div = i*10;
        count += (n/div)* i +min(max(n% div - i+1,0),i);
        i*=10;

    }

    return count;
}


int main()
{
    int n;
    cin>>n;

    int ans = countingnumberofones(n);
    int res = countingone(n);

    cout<<res<<endl;

    return 0;
}