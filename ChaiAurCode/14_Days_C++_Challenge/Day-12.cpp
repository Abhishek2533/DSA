/*

Problem Statement

You are an SDE at a logistics company, and your manager has tasked you with optimizing delivery routes. You are given a list of ( n ) roads, where each road takes a specific amount of time to travel at a given speed. You need to determine the minimum speed ( s ) (in km/h) needed to travel all roads in less than or equal to a given time limit ( t ).
If it is impossible to complete the journey within the given time ( t ), return ( -1 ).


Input Format

An integer ( n ) representing the number of roads.
A floating-point number ( t ) representing the maximum allowed time (in hours).
An array ( dist ) of length ( n ), where ( dist[i] ) represents the distance of the ( i )-th road (in kilometers).


Output Format

Return the minimum speed ( s ) (an integer) required to complete the journey in less than or equal to ( t ), or ( -1 ) if it is not possible.


Constraints

1 <= n <= 10^5 (Number of distances)
1 <= dist[i] <= 10^6 (Each distance is at most 10^6)
1 <= t <= 10^9 (Maximum allowed time)
s(speed) must be a positive integer (s>0)


*/


// SOURCE CODE

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minSpeedOnTime(const vector<int>& dist, double timeLimit) {
    int n = dist.size();
    
    // Binary search for the minimum speed
    int left = 1, right = 1e7, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        double totalTime = 0.0;

        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                // For the last road, use exact time
                totalTime += (double)dist[i] / mid;
            } else {
                // For other roads, use ceiling for time calculation
                totalTime += ceil((double)dist[i] / mid);
            }
        }

        // If total time is less than or equal to the time limit, update the result and try for a smaller speed
        if (totalTime <= timeLimit) {
            result = mid;
            right = mid - 1;  // Try smaller speed
        } else {
            left = mid + 1;  // Try larger speed
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    double t;
    cin >> t;
    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }

    cout << minSpeedOnTime(dist, t);
    return 0;
}
