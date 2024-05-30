#include<iostream>
using namespace std;

void reverse(char name[], int n)
{
    int s = 0, e = n-1;

    while (s<e)
    {
        swap(name[s++],name[e--]);
    }
}

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; i < name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char name[20];

    cout << "Enter your String" << endl;
    cin >> name;

    int len = getLength(name);

    reverse(name,len);
    cout << "Reversing a String : " << name << endl;

}