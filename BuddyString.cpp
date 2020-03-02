/*
859. Buddy Strings
E
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.


Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() > 1 && A.size() == B.size())
        {    
            int index_i=0, index_j= A.size()-1;
            while(index_i < index_j && A[index_i] == B[index_i])  index_i++;
            while(index_i < index_j && A[index_j] == B[index_j])  index_j--;
            
            if(index_i == index_j)
            { //both strings are same, find whether we can swap two char in A and be equal
                std::array<bool, 26> visited;
                visited.fill(false);
                for(int i= A.size() - 1; i >= 0 ; i--)
                {
                    int index = A[i] - 'a';
                    if(visited[index]) return true;
                    visited[index] = true;
                }
            }
            else  if( A[index_j] == B[index_i] && 
               A[index_i] == B[index_j] )
            {
                index_i++;
                index_j--;
                while(index_i <= index_j && A[index_i] == B[index_i])
                    index_i++;
            }
            return index_i > index_j;
        }
        return false;
    }
};