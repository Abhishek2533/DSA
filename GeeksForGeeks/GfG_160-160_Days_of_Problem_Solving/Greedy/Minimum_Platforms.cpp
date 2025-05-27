/*

Company Tags:

        Paytm
        Amazon
        Microsoft
        D-E-Shaw
        Hike
        Walmart
        Adobe
        Google
        Boomerang Commerce
        Zillious
        Atlassian


*/


// METHOD 1: TC -> O(N^2) | SC -> O(1)

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=arr.size();
        int res=0;
        
        for(int i=0; i<n; i++) {
            int count=1;
            for(int j=0; j<n; j++) {
                if(i!=j && arr[i] >= arr[j] && dep[j]>=arr[i]) count++;
            }
            
            res=max(res, count);
        }
        
        return res;
    }
};






// METHOD 2: TC -> O(Nlog(N)) | SC -> O(1)


class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=arr.size();
        int res=0, count=0, j=0;
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        for(int i=0; i<n; i++) {
            while(j<n && dep[j]<arr[i]) count--, j++;
            count++;
            res=max(res, count);
        }
        
        return res;
    }
};
