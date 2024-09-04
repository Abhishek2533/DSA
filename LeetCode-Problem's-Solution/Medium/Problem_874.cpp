/*

874. Walking Robot Simulation


A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a sequence of these three possible types of commands:
-2: Turn left 90 degrees.
-1: Turn right 90 degrees.
1 <= k <= 9: Move forward k units, one unit at a time.
Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.
Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25).

Note:
North means +Y direction.
East means +X direction.
South means -Y direction.
West means -X direction.
There can be obstacle in [0,0].



Example 1:
Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: The robot starts at (0, 0):
1. Move north 4 units to (0, 4).
2. Turn right.
3. Move east 3 units to (3, 4).
The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.

Example 2:
Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: The robot starts at (0, 0):
1. Move north 4 units to (0, 4).
2. Turn right.
3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
4. Turn left.
5. Move north 4 units to (1, 8).
The furthest point the robot ever gets from the origin is (1, 8), which squared is 12 + 82 = 65 units away.

Example 3:
Input: commands = [6,-1,-1,6], obstacles = []
Output: 36
Explanation: The robot starts at (0, 0):
1. Move north 6 units to (0, 6).
2. Turn right.
3. Turn right.
4. Move south 6 units to (0, 0).
The furthest point the robot ever gets from the origin is (0, 6), which squared is 62 = 36 units away.


Constraints:
1 <= commands.length <= 104
commands[i] is either -2, -1, or an integer in the range [1, 9].
0 <= obstacles.length <= 104
-3 * 104 <= xi, yi <= 3 * 104
The answer is guaranteed to be less than 231.


*/

// SOURCE CODE

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        // initialize given stuff
        int i = 0, j = 0, res = 0;
        int direction = 1; // 1->north, 2->east, 3->south, 4->west

        // storing obstacles
        set<pair<int, int>> st;
        for (const auto &it : obstacles)
        {
            st.insert({it[0], it[1]});
        }

        // listening command
        for (const auto &command : commands)
        {
            if (command == -1)
            {
                // turn right -> increment in direction (clowckwise)
                direction = (direction + 1) % 5; // not going out of 4 directions
                if (direction == 0)
                    direction = 1; // if it reached to 5 -> comes to initial direction -> north = 1
            }
            else if (command == -2)
            {
                // turn left -> decrement in direction (anticlockwise)
                direction = (direction - 1);
                if (direction == 0)
                    direction = 4; // if it reached to before 1-> means set to North to West = 4
            }
            else
            {
                int distance = command;
                while (distance > 0)
                {
                    if (direction == 1)
                    { // moving in North
                        if (st.find({i, j + 1}) != st.end())
                            break;
                        j++;
                    }
                    else if (direction == 2)
                    { // moving in East
                        if (st.find({i + 1, j}) != st.end())
                            break;
                        i++;
                    }
                    else if (direction == 3)
                    { // moving in South
                        if (st.find({i, j - 1}) != st.end())
                            break;
                        j--;
                    }
                    else
                    { // moving in West
                        if (st.find({i - 1, j}) != st.end())
                            break;
                        i--;
                    }

                    // store distance covered
                    res = max(res, i * i + j * j);
                    distance--;
                }
            }
        }
        return res;
    }
};