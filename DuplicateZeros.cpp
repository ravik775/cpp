/*
1089. Duplicate Zeros
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
		/*
		int size= arr.size();
        vector<int> temp(size);
        for(int ind=0, i=0; ind<size; i++, ind++){
            temp[ind]=arr[i];
            if(!arr[i])
                if(++ind<size)
                   temp[ind]=0;
        }
        arr=std::move(temp);
		*/
        int i=0, s = arr.size();
        queue<int> temp;
        while(i < s){
            temp.push(arr[i]);
            if(!arr[i] && (temp.size() <= (s-i)))
                temp.push(0);
            arr[i++] = temp.front();
            temp.pop();
        }
    }
};