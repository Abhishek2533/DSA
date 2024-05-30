#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    // creating a vector
    vector<int> v;

    // insert elements
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    // binary search
    binary_search(v.begin(), v.end(), 6);

    //lower bound
    lower_bound(v.begin(), v.end(), 6)-v.begin();

    //upper bound
    upper_bound(v.begin(), v.end(), 4)-v.begin();

    // rotate vector
    rotate(v.begin(), v.begin()+1, v.end());

    // sorting
    sort(v.begin(), v.end());       // based on intro-sort -> combination of 3 algorith -> quick sort, heap sort, insertion sort




    int a = 3;
    int b = 5;

    // max
    max(a,b);

    // min
    min(a,b);

    // swap
    swap(a,b);




    string s = "abcde";
    
    // reverse
    reverse(s.begin(), s.end());

}