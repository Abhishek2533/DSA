/*

Problem Statement

In a multiplayer battleground game, there are up to 4 players in each team, and the game supports a maximum of n teams competing simultaneously. Each player in the team has eliminated a certain number of opponents during the game, and the goal is to determine the potential winning teams.
Your manager has tasked you with designing an algorithm that identifies all potential winning teams based on the following criteria:
1. Teams with the highest total eliminations are considered first
2. If multiple teams have the same highest total, compare their highest individual eliminations
3. If teams have both same total AND same highest individual eliminations, all such teams should be included in the result



Input Format

n : Number of teams (1 ≤ n ≤ 10³)
A list of n teams, where:
Each team has 1 to 4 players
Each player has an integer representing their eliminations


Output Format

Return a list containing details of potential winning teams:
Each element should contain: {team_index, total_eliminations, highest_individual_elimination}
team_index should be 1-based
Return multiple teams if they tie on both criteria


Example 1

Input:
n=3
teams: [
[5, 2, 1, 3],
[4, 0, 8],
[2, 2, 3, 4]
]

    
Output: 
[{2, 12, 8}]  // Only Team 2 wins

Explanation:
Team 1: Total = 11, Highest = 5 Team 2: Total = 12, Highest = 8 Team 3: Total = 11, Highest = 4 Team 2 wins with highest total



Example 2

Input:
n=4
teams: [
[3, 3, 4],
[5, 2, 3],
[4, 3, 3],
[5, 3, 2]
]

    
Output: 
[{2, 10, 5}, {4, 10, 5}]  // Teams 2 and 4 tie

Explanation:
Team 1: Total = 11, Highest = 5 Team 2: Total = 12, Highest = 8 Team 3: Total = 11, Highest = 4 Team 2 wins with highest total


Constraints:
1. 1 ≤ n ≤ 10³ (number of teams)
2. 1 ≤ team size ≤ 4 (players per team)
3. ≤ eliminations ≤ 10⁵ (per player)


Hints
Using some Sorting technique to sort the teams based on the total eliminations and highest individual eliminations

*/


// SOURCE CODE


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> func(vector<vector<int>> teams)
{
    vector<vector<int>> teamsData;

    // Step 1: Calculate sum, max eliminations, and team index
    for (int i = 0; i < teams.size(); i++)
    {
        int sum = 0, max_eliminations = teams[i][0];
        for (int j = 0; j < teams[i].size(); j++)
        {
            sum += teams[i][j];
            max_eliminations = max(max_eliminations, teams[i][j]);
        }
        teamsData.push_back({sum, max_eliminations, i});
    }

    // Step 2: Sort teams based on the conditions
    sort(teamsData.begin(), teamsData.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[0] != b[0])
            return a[0] > b[0]; // Higher total eliminations first
        if (a[1] != b[1])
            return a[1] > b[1]; // Higher max eliminations next
        return a[2] < b[2];     // Lower index last
    });

    // Step 3: Collect all teams with the same top scores
    vector<vector<int>> winners;
    int maxTotal = teamsData[0][0];
    int maxIndividual = teamsData[0][1];

    for (const auto &team : teamsData)
    {
        if (team[0] == maxTotal && team[1] == maxIndividual)
        {
            winners.push_back({team[2]+1, team[0], team[1]}); // Index, sum, max eliminations
        }
        else
        {
            break; // Stop when teams no longer meet the criteria
        }
    }

    return winners;
}

int main()
{
    // Input teams data
    vector<vector<int>> teams;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int team_size;
        cin >> team_size;
        vector<int> team(team_size);
        for (int j = 0; j < team_size; j++)
        {
            cin >> team[j];
        }
        teams.push_back(team);
    }

    // Process and get the winners
    vector<vector<int>> result = func(teams);

    // Print the result
    for (int i = 0; i < result.size(); i++)
    {
        if (i == result.size() - 1)
        {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2];
        }
        else
        {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        }
    }

    return 0;
}
