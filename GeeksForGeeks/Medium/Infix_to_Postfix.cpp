//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        string ans = "";
        unordered_map<char, int> val;
        val['+'] = 1;
        val['-'] = 1;

        val['*'] = 2;
        val['/'] = 2;

        val['^'] = 3;

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
                ans += s[i];

            else if (st.empty() || s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                // bool flag=false;
                while (!st.empty())
                {
                    char t = st.top();
                    st.pop();
                    if (t == '(')
                        break;
                    else
                        ans += t;
                }
            }
            else
            {

                while (!st.empty())
                {
                    char t = st.top();
                    if (t == '(')
                        break;
                    if (val[t] >= val[s[i]])
                    {
                        ans += t;
                        st.pop();
                    }
                    else
                        break;
                }
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return (ans);
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends