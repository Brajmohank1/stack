/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0



*/

class Solution {
public:
    
    int longestValidParentheses(string s) {
        
        if(s.size() == 0 || s.size() == 1)
                return 0;
 
        stack<int> st;
        int n = s.size();
        for(int i = 0 ; i <n ; i++ ){
            
            if(s[i] == '(')
                st.push(i);
            else{
                if(!st.empty() && s[st.top()] == '('){
                    
                    st.pop();
                }else{
                    st.push(i);
                }
            }
        }
        
        int longest = 0;
         int a = n , b = 0;
        if(st.empty())  longest = n;
        else{
        
            while(!st.empty()){
                b = st.top();
                st.pop();
                
                longest = max(longest ,a - b - 1);
                a = b;
                
            }
        
        }
        
        longest = max(longest , a);
        
        return longest;
        
    }
};
