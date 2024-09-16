/*

539. Minimum Time Difference


Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.


Example 1:
Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0


Constraints:
2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".


*/

// SOURCE CODE

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> minutes(timePoints.size());

        // Convert all given time in minutes
        for (int i = 0; i < timePoints.size(); ++i)
        {
            int hr = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3));
            minutes[i] = hr * 60 + m;
        }

        // Sort time in ascending order
        sort(minutes.begin(), minutes.end());

        // Obtain minimum difference of all adjacent elements
        int minDiff = INT_MAX;
        for (int i = 0; i < minutes.size() - 1; ++i)
        {
            minDiff = min(minDiff, minutes[i + 1] - minutes[i]);
        }

        // Circular difference between last and first element as we have done sorting
        minDiff = min(minDiff, 24 * 60 - minutes.back() + minutes.front());

        return minDiff;
    }
};