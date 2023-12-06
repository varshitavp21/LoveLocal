// Easy 1


// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal 
// substring consisting of non-space characters only.

// Explentation.
    // pointing the index at sentence.length()-1 
    // and increment the length umtil u encounter space
    // if length is greater than 0 the n break;
    // else
    // index--
    // for example "Hello World"
    //     in this example we will increment length until space and we see that it is greater than 0 so we will break and print the lengthOfLastWord
    // ex 2 :"   fly me   to   the moon  "
    //     in this example we are having the space at the end so it will check if the length is >0 it is not true so index-- and continue until lengthOfLastWord>0 ;

/**
 * 
 * Calculates the length of the last word in a given string.
 *
 * @param {string} sentence - The input string containing words and spaces.
 * @returns {number} - The length of the last word. Returns 0 if the string is empty.
 */

// time complexity :O(N)
// space complexity : O(1)



#include<bits/stdc++.h>
using namespace std;



int lengthOfLastWord(string sentence) {
    int length = 0;

    for (int index = sentence.length() - 1; index >= 0; --index) {
        
        if (sentence[index] != ' ') {
            ++length;
        } else if (length > 0) {
    
            break;
        }
    }

    return length;
}

int main() {
    // taking the input from the command prompt as the input string 
    string input;                        
    getline(cin, input);

    int result = lengthOfLastWord(input);
    cout << result << endl;

    return 0;
}