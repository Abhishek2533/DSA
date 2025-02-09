// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n=arr.size();
        int count = 0;
        
        for(int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                for(int k=j+1; k<n; k++) {
                    if(arr[i]+arr[j]+arr[k] == target) count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends













// METHOD 2:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n=arr.size();
        int count = 0;
        
        for(int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            
            while(l<r) {
                int sum=arr[i]+arr[l]+arr[r];
                
                if(sum<target) l++;
                else if(sum>target) r--;
                else if(sum==target) {
                    int ele1=arr[l], ele2=arr[r];
                    int c1=0, c2=0;
                    
                    while(l<=r && arr[l]==ele1) {
                        l++;
                        c1++;
                    }
                    
                    while(l<=r && arr[r]==ele2) {
                        r--;
                        c2++;
                    }
                    
                    if(ele1==ele2) count+=(c1*(c1-1))/2;
                    else count+=(c1*c2);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends