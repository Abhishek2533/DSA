/*

Problem Statement

You are a software engineer at a Google working on google maps, and your team is tasked with designing a route optimization system. The system models the road network as a directed weighted graph, where nodes represent locations, and edges represent roads with weights corresponding to the travel time between locations.
Given the number of locations ( n ), the number of roads ( m ), the roads' details, and a starting location ( s ), your task is to find the shortest travel time from ( s ) to every other location. If a location is unreachable, the travel time should be reported as ( -1 ).
Your solution must efficiently handle large graphs, as the road network can have up to ( 10^5 ) locations and ( 10^6 ) roads.


Input Format

1. An integer ( n ) representing the number of locations.
2. An integer ( m ) representing the number of roads.
3. ( m ) lines follow, each containing three integers ( u ), ( v ), and ( w ), where:
    ( u ): The starting location of the road.
    ( v ): The ending location of the road.
    ( w ): The travel time of the road (( w > 0 )).
4. An integer ( s ), representing the starting location.


Output Format

Return ( n ) integers, where the ( i )-th integer represents the shortest travel time from location ( s ) to location ( i ). If a location is unreachable, print ( -1 ).


Example Input 1

6 9
0 1 4
0 2 2
1 2 5
1 3 10
2 4 3
4 3 4
3 5 11
4 5 2
5 0 7
0

Example Output 1

0 4 2 9 5 7
Explanation:
Location 0 to Location 0: Travel time is (0).
Location 0 to Location 1: Travel time is (4)(0->1).
Location 0 to Location 2: Travel time is (2)(0->2).
Location 0 to Location 3: Travel time is (9)(0->2->4>3).
Location 0 to Location 4: Travel time is (5)(0->2->4).
Location 0 to Location 5: Travel time is (7)(0->2->4->5).


Example Input 2

4 3
0 1 1
1 2 2
2 3 3
0

Example Output 1

0 1 3 6



Constraints

1. ( 1 \leq n \leq 10^5 )
2. ( 0 \leq m \leq 10^6 )
3. ( 0 \leq u, v < n )
4. ( 1 \leq w \leq 10^6 )


*/


// SOURCE CODE

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> sol(int n, vector<vector<pair<int, int>>>& graph, int start) {
    // Initialize the distance vector with INF
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    // Min-heap to store (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  // Start with the starting location

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // If the distance in the queue is already greater than the current known distance, we skip it
        if (currentDist > dist[currentNode]) continue;

        // Explore neighbors
        for (auto& neighbor : graph[currentNode]) {
            int neighborNode = neighbor.first;
            int edgeWeight = neighbor.second;

            // Relax the edge
            if (dist[currentNode] + edgeWeight < dist[neighborNode]) {
                dist[neighborNode] = dist[currentNode] + edgeWeight;
                pq.push({dist[neighborNode], neighborNode});
            }
        }
    }

    // Replace unreachable locations (still INT_MAX) with -1
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);  // Directed edge u -> v with weight w
    }

    int start;
    cin >> start;

    vector<int> result = sol(n, graph, start);

    // Output the result
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }

    return 0;
}