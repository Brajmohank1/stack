/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1
 

Constraints:

1 <= n <= 231 - 1


*/

typedef long long ll;
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        
        int n1 = str.size();
        
        int i = n1-1;
        while(i >= 1 && str[i] <= str[i - 1]) i--;
        
        if(i == 0) return -1;
        
        
        char last = str[i - 1];
        char l1 = str[n1 -1];
        int j = n1-1 , ind = n-1;
        for( j = n1-1 ; j >= i ; j--){
            if(last < str[j]   )
            { break;
            }
        }
        
       swap(str[i-1] , str[j]);
        reverse(str.begin() + i , str.end());
         
        ll res = stoll(str);
        return  res > INT_MAX ? -1 : res ;
    }
};
