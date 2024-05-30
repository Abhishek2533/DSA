#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int sum = 0;
    for (int counter = 1; counter <= n; counter++)
    {
        sum = sum + counter;
    }

    cout << sum;
    return 0;
}

/*

for loop can be...

int i
for(; ; ){
    if(i <=n){
        cout<< i<< endl;
    }
    else {
        break;
    }
    i++
}

*/


// we can also apply condition and operation in for loop

/*

for( int a = 0, int b = 1; a>=0 && b>=1; a-- , b-- ){
    cout << a << " " << b;
}

*/