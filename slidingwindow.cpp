// Hard1

// Return the max sliding window.
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. Each time the sliding window moves right by one position.


#include<bits/stdc++.h>
using namespace std;

/*
    Approach 1 :
                One method is to iterate the array to the size of n-k each time and 
                storing the maximum in variable max 
                push the max variable to the vector 
                return the vector

            ALgorithm:
            1.create a for loop to iterate to a window of size k.
            2.The innner loop will run for k iterations
            3.find the maximun within the array size k and push it into the vector
            4.return vector

        Time complexity: O(N*K)  because the window moves to right by 1 and it repeates.
                    where N- size of the array , K= window size.
        Space Complexity: O(N)

    */


// 
vector<int> maxsize(vector<int> nums, int N, int K)
{
    vector<int> ans;

    for (int i = 0; i <= N - K; i++) {
        int maxVal = nums[i];

        for (int j = 1; j < K; j++) {
            maxVal = max(maxVal, nums[i + j]);
        }

        ans.push_back(maxVal);
    }

    return ans;
}

// main function 
/*
    1. when we traverse through the window size k then we will push the elements into the queue in descending order 
    bcs if the encoutered ele is greater than the q.rear() then it will be of no use bcs we are looking for the max ele
    so we will pop until the q.front() > ele
    2. when the first window is traversed then we will push the q.front() into the vector and pop it we will continue .

    Algo:
    1.create a dequeue bcs we need to add and delete at the same time .
    push first k ele in the descending order and push the q.front() in the vector
    2.process the remaining ele of the nums
        If the index of the top element is less than or equal to i – k, it means the element is outside the current window and should be removed.

    lets take and simple example : [1,3,-1,-3,5,3,6,7] and k=3
                         1. {1,3,-1}   = {1} pushed and 3 is checked and it is greater than 1 so it is poped  => {3,-1} since -1 is smaller it is pushed into deque d
                         push the q.front() and poped int the vector
                         2.{3,-1,-3}  ={3,-1}  when -3 is encounter it is smaller than the -1 so pushed into d and q.front() into vector
                         3.{-1,-3,5} = {-1,-3,} 5 is greater so pop until either the queue is empty or u find a ele greater than 5 =>queue ={5} add to vector
                         4.{-3,5,3} ={-3} 5>-3 so d = {5,3} add q.front() into vector
                         5.{5,3,6} = {5,3} -> 6> 3 so pop 3 and 6>5 so pop 5 and push 6into d and then to the vector 
                         6.{3,6,7} = {3,} 6>3 so pop 3=>d={6,} 7>6 so =>d = {7} add to vector

        in this way we will get the desired output.
 
    Time Complexity : O(Nlog(N)) where N is the size of the nums
    Space Complexity: O(N)

*/

vector<int> slidingwindow(vector<int> nums, int k)
{
    deque<int> d;
    vector<int> ans;

    
    for (int i = 0; i < k; i++)
    {
        while (!d.empty() && d.back() < nums[i])
        {
            d.pop_back();
        }
        d.push_back(nums[i]);
    }

    ans.push_back(d.front());

   
    for (int i = k; i < nums.size(); i++)
    {
        if (d.front() == nums[i - k])
            d.pop_front();


        while (!d.empty() && d.back() < nums[i])
        {
            d.pop_back();
        }

        d.push_back(nums[i]);
        ans.push_back(d.front());
    }

    return ans;
}

vector<int> input() {
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
    vector<int> nums = input();
    int k;
    cin >> k;

    vector<int> result = slidingwindow(nums, k);

    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}
