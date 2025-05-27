/*

Company Tags:

        Flipkart
        Accolite
        Microsoft


*/


// METHOD 1: TC -> O(Nlog(N)) | SC -> O(N)

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<int> res={0, 0};
        
        vector<pair<int, int>> jobs;
        for(int i=0; i<n; i++) jobs.push_back({deadline[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(const auto& job : jobs) {
            if(job.first>pq.size()) pq.push(job.second);
            else if(!pq.empty() && job.second>pq.top()) {
                pq.pop();
                pq.push(job.second);
            }
        }
        
        while(!pq.empty()) {
            res[1] += pq.top();
            pq.pop();
            res[0]++;
        }
        
        return res;
    }
};