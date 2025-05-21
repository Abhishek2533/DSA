// METHOD 1: Max-Heap -> TLE

class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        priority_queue<int> pq;
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                int val=i*j;
                pq.push(val);
                while(pq.size()>k) pq.pop();
            }
        }
        
        return pq.top();
    }
};



// METHOD 2: Binary Search

class Solution {
  public:
    int countNumbers(int mid, int m, int n) {
        int count=0;
        
        for(int i=1; i<=m; i++) {
            count += min(mid/i, n);
        }
        
        return count;
    }
    
    int kthSmallest(int m, int n, int k) {
        // code here
        int start=1;
        int end=m*n;
        
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(countNumbers(mid, m, n) < k) start=mid+1;
            else end=mid-1;
        }
        
        return start;
    }
};
