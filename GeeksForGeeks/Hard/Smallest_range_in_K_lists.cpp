// METHOD 1: TC-> O(N*K) | SC -> O(K)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        int k=arr.size();
        vector<int> range(k, 0);
        vector<int> res={-1000000, 1000000};
        
        while(true) {
            int minEle=INT_MAX, minEleIdx=0;
            int maxEle=INT_MIN;
            
            for(int i=0; i<k; i++) {
                int idx=i;
                int eleIdx=range[i];
                int ele = arr[idx][eleIdx];
                
                if(ele<minEle) {
                    minEle=ele;
                    minEleIdx=idx;
                }
                maxEle=max(maxEle, ele);
            }
            
            // range = (minELe, maxEle)
            if(maxEle-minEle < res[1]-res[0]) {
                res[0]=minEle;
                res[1]=maxEle;
            }
            
            // shorten this range by moving min element index
            int nextIdx=range[minEleIdx]+1;
            if(nextIdx>=arr[minEleIdx].size()) break;
            range[minEleIdx] = nextIdx;
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));
        
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
            cin >> arr[i][j];
            
            Solution obj;
            vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends










// METHOD 2: TC-> O(N*log(K)) | SC -> O(K)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        int k=arr.size();
        
        // {element, row, col} -> vector<int> {a, b, c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int maxEle=INT_MIN;
        
        for(int i=0; i<k; i++) {
            pq.push({arr[i][0], i, 0});
            maxEle=max(maxEle, arr[i][0]);
        }
        
        vector<int> res= {-1000000, 1000000};
        
        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            
            int minEle=curr[0];
            int row=curr[1];
            int col=curr[2];
            
            if(maxEle-minEle < res[1]-res[0]) {
                res[0]=minEle;
                res[1]=maxEle;
            }
            
            // decrese the range from minimum
            if(col+1 < arr[row].size()) {
                int nextEle = arr[row][col+1];
                pq.push({nextEle, row, col+1});
                maxEle=max(maxEle, nextEle);
            } else break;
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends