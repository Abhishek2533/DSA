/*

Company Tags:

        Flipkart
        Morgan Stanley
        Facebook


*/


// METHOD 1: TC -> O(Nlog(N)) | SC -> O(N)

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int res=0;
        vector<vector<int>> arr;
        
        for(int i=0; i<start.size(); i++) arr.push_back({finish[i], start[i]});
        
        sort(arr.begin(), arr.end());
        
        int finishTime=-1;
        for(int i=0; i<arr.size(); i++) {
            vector<int> activity = arr[i];
            
            if(activity[1]>finishTime) {
                finishTime=activity[0];
                res++;
            }
        }
        
        return res;
    }
};