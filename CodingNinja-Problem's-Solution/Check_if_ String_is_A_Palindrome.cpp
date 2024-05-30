#include <bits/stdc++.h>

char toLowerCase(char s)
{
    if (s >= 'A' && s <= 'Z')
    {
        return s - 'A' + 'a';
    }
    return s;
}

bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start <= end)
    {

        char c1 = toLowerCase(s[start]);
        char c2 = toLowerCase(s[end]);

        // Skip non-alphanumeric characters
        if (!std::isalnum(c1))
        {
            start++;
        }

        else if (!std::isalnum(c2))
        {
            end--;
        }

        else
        {
            if (c1 != c2)
            {
                return 0;
            }

            else
            {
                start++;
                end--;
            }
        }
    }
    return 1;
}