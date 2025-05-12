//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        int m=meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<int> rooms(n, 0);
        priority_queue<int, vector<int>, greater<int>> empty_room;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;
        
        for(int i=0; i<n; i++) empty_room.push(i);
        
        for(auto meeting : meetings) {
            int start=meeting[0];
            int end=meeting[1];
            
            while(!occupied.empty() && occupied.top().first<=start) {
                empty_room.push(occupied.top().second);
                occupied.pop();
            }
            
            if(!empty_room.empty()) {
                int room=empty_room.top();
                empty_room.pop();
                rooms[room]++;
                occupied.push({end, room});
            } else {
                int freedTime = occupied.top().first;
                int curr_room = occupied.top().second;
                freedTime+=(end-start);
                occupied.pop();
                occupied.push({freedTime, curr_room});
                rooms[curr_room]++;
            }
        }
        
        int maxRoomUsed=0;
        for(int i=0;i<n;i++){
            if(rooms[i]>rooms[maxRoomUsed]){
                maxRoomUsed=i;
            }
        }
        return maxRoomUsed;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends