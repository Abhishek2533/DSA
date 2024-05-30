#include<iostream>
using namespace std;

char getMaxOccurChar(string s)
{
    int arr[26] = {0};

    // create an array of count of characters
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        int num = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            num = ch - 'a';
        }
        else
        {
            num = ch - 'A';
        }
        arr[num]++;   
    }
    
    // find maximum occ character
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
        
    }
    
    char finalAns = 'a' + ans;
    return finalAns;
}

int main()
{
    string s;
    cin >> s;

    cout << getMaxOccurChar(s) << endl;
}