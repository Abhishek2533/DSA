class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> res;
        sort(b.begin(), b.end());
        
        int n=a.size(), m=b.size();
        
        for(int i=0; i<n; i++) {
            int count=0;
            int left=0, right=m-1;
            
            while(left<=right) {
                int mid = left + (right-left)/2;
                if(b[mid] <= a[i]) left=mid+1;
                else right=mid-1;
            }
            
            res.push_back(left);
        }
        
        return res;
    }
};