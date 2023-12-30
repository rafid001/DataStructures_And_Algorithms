class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<int> st;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '#' && !st.empty()) {
                st.pop();
            }
            
            else if(s[i] != '#'){
                st.push(s[i]);
            }
        }

        
        stack<int> st2;
        for(int i=0; i<t.length(); i++) {
            if(t[i] == '#' && !st2.empty()) {
                st2.pop();
            }
           
            else if(t[i] != '#'){
                st2.push(t[i]);
            }
        }  


        while(!st.empty() && !st2.empty()) {
            if(st.top() != st2.top()) {
                return false;
            }
            st.pop();
            st2.pop();
        }

        return st.empty() && st2.empty();
    }
};