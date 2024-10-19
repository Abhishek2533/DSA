//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string roundToNearest(string str)
    {
        // Complete the function
        int n = str.length();
        if (str[n - 1] == '0')
            return str;
        else if (str[n - 1] <= '5')
        {
            str[n - 1] = '0';
            return str;
        }
        str[n - 1] = '0';
        int index = n - 2;
        while (index >= 0 && str[index] == '9')
        {
            str[index] = '0';
            index--;
        }
        if (index < 0)
            return '1' + str;
        str[index]++;
        return str;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends