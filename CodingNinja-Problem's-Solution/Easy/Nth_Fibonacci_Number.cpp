#include<bits/stdc++.h>
using namespace std;

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int a =1,b =1;
        int n, res;

        cin >> n;

        if (n<1) {
                res = 0;
        }
        else if(n==1 || n==2) {
                res = 1;
        }
        else {
                for(int i=3; i<=n; i++) {
                        res = a+b;
                        a=b;
                        b=res;
                }
        }
        cout << res;
}