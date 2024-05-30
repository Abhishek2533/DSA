#include <iostream>
using namespace std;

int getMin(int num[], int n)
{
    int minimum = INT_MAX; // INT_MAX = 2^31

    for (int i = 0; i < n; i++)
    {
        // if(num[i] < minimum)
        // {
        //     minimum = num[i];
        // }

        // above logic can be replaced by inbuild function for minimum:
        minimum = min(minimum, num[i]);     // this will store the min value between minimum & num[i]
    }

    // returning min value
    return minimum;
}

int getMax(int num[], int n)
{
    int maximum = INT_MIN; // INT_MIN = -2^31

    for (int i = 0; i < n; i++)
    {
        // if (num[i] > maximum)
        // {
        //     maximum = num[i];
        // }

        // above logic can be replaced by inbuild function for maximum:
        maximum = max(maximum, num[i]);     // this will store the max value between maximum & num[i]
    }

    // returning max value
    return maximum;
}

int main()
{
    int size;
    cin >> size;

    int num[100];

    // taking input in array
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    cout << "Maximin value is " << getMax(num, size) << endl;
    cout << "Minimum value is " << getMin(num, size) << endl;

    return 0;
}