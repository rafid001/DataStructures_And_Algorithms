#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string rev(string temp) {
        
        stack<char> s;

        for(char c : temp) {
            s.push(c);
        }

        string ans = "";

        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
    string reverseWords(string s) {
        string ans = "";
        int i = 0;

        while (i < s.length()) {
            if (s[i] == ' ') {
                ans += ' '; // Preserve the space
                i++;
            } else {
                int start = i;
                while (i < s.length() && s[i] != ' ') {
                    i++;
                }
                string temp = s.substr(start, i - start);
                ans += rev(temp);
            }
        }

        return ans;
    }
};