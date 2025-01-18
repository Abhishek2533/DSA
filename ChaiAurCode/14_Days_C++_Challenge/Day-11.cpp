/*

Problem Statement

As an SDE at Meta, your manager has assigned you an important task to help the marketing team identify influential users on the platform. These influential users will be key targets for focused marketing campaigns. In the context of a social network, users are represented as nodes, and their connections are modeled as directed edges in a graph. An edge from user 𝑢 to user 𝑣 indicates that 𝑢 follows 𝑣. Your goal is to determine the user with the highest influence score.The influence score of a user is defined as the total number of followers they have in the network. If there is a tie in influence scores, you must return the user with the smallest user ID.Your solution will serve as the backbone for the marketing team's targeted strategy, so accuracy and efficiency are crucial.


Input Format

An integer 𝑛 representing the number of users (nodes) in the network, where users are indexed from 0 to 𝑛−1
An integer 𝑚 representing the number of directed edges (connections) in the network.
𝑚 lines follow, each containing two integers 𝑢 and 𝑣, representing a directed edge from 𝑢 to v.


Output Format

Return a single integer representing the ID of the user with the highest influence score. (0 <= ID < n)


Example Input

6 4
1 
2 3
3 4
4 5 


Example Output

2
Explanation:
Every user has 1 follower but user 2 is the most influential user.


Constraints

1. (0 <= n <= 10^5)
2. (0 <= m <= 10^6)
3. 0 <= u,v < n
4. Self-loops and duplicate edges may exist in the input


*/


// SOURCE CODE


#include <iostream>
#include <vector>
using namespace std;

int mostInfluentialUser(const vector<int>& influenceScore) {
    int maxInfluence = -1;
    int mostInfluential = -1;

    // Iterate through the influence scores to find the user with the highest score
    for (int i = 0; i < influenceScore.size(); i++) {
        if (influenceScore[i] > maxInfluence || (influenceScore[i]==maxInfluence && i<mostInfluential)) {
            maxInfluence = influenceScore[i];
            mostInfluential = i;
        }
    }
    return mostInfluential;
}

int main() {
    // Read input
    int n, m;
    cin >> n >> m;
    vector<int> influenceScore(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u != v) { 
            influenceScore[v]++;
        }
        if(u==v) continue;
    }

    // Output the most influential user
    cout << mostInfluentialUser(influenceScore);
    return 0;
}