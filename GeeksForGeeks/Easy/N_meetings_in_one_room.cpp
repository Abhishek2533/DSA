class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int, int>> arr;
        int n=start.size();
        for(int i=0; i<n; i++){
            arr.push_back({end[i], start[i]});
        }
        sort(arr.begin(), arr.end());
        
        int prevEnd=-1;
        int cnt=0;
        
        for(int i=0; i<n; i++){
            if(prevEnd==-1 || arr[i].second>prevEnd){
                prevEnd=arr[i].first;
                cnt++;
            }
        }
        return cnt;
    }
};