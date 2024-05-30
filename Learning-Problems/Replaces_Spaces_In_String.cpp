#include <iostream>
using namespace std;

char removeSpace(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str.replace(i,1,"@40");
        }
    }
    cout << str;

    return 0;
}

int main()
{
    string str;
    getline(cin, str);

    removeSpace(str);
}