/*
696. Count Binary Substrings

Add to List

Share
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
Note:

s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
*/
class Solution {
public:
     int countBinarySubstrings(string s) {
        int cnt = 0;
        int prevCnt = 0;
        for(int i=0, ml=s.length(); i < ml;){
            int j=i+1;
            while(s[j] == s[i] && j < ml) j++;
            const int diff = j - i;
            cnt += diff < prevCnt ? diff: prevCnt;
            prevCnt = diff;
            i = j;
        }
        return cnt;
    }
    
    /*
     int countBinarySubstrings(string s) {
        int cnt = 0;
        int prev = 0;
        int curr = 1;
        for(int i=1, ml=s.length(); i < ml; i++){
            if(s[i-1] == s[i]) curr++;
            else{
                cnt += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }
        return cnt+= min(curr, prev);
    }
    */
};