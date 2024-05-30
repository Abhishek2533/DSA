// Break -> it is used to stop the iteratons in loops after call when it needed,,, it helps to reduce the code runtime for running the unnecessary iterrations


// Checking Prime Number or Not

#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Ënetr the value of n: " << endl;
    cin >> n;

    // creating a variable to check prime number ( initially it sets to Prime Number )
    bool isPrime = 1;

    for (int i = 2; i < n; i++)
    {
        // if remainder is 0 then ,,, not Prime
        if (n % i == 0)
        {
            // setting variable to 0 then break as no need to check further
            isPrime = 0;
            break; // this will break the loop and come outside the loop
        }
    }

    // Now checking the condition using variable to conclude the output
    if (isPrime == 0)
    {
        cout << "Not a Prime Number" << endl;
    }
    else
    {
        cout << "is a Prime Number" << endl;
    }
}