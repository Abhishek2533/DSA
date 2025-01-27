/*

Company Tags:

        Flipkart
        Amazon
        Microsoft
        MakeMyTrip
        Adobe
        BankBazaar
        Myntra


*/



// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int count=0;
        for(int i=0; i<arr.size()-1; i++) {
            for(int j=i+1; j<arr.size(); j++) {
                if(arr[i]>arr[j]) count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends








// METHOD 2:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int mergeInv(vector<int>& arr, int start, int mid, int end) {
        int count=0;
        vector<int> temp;
        int left=start, right=mid+1;
        
        while(left<=mid && right<=end) {
            if(arr[left]<=arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                count+=(mid-left+1);
                right++;
            }
        }
        
        while(left<=mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=end) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=0; i<temp.size(); i++) {
            arr[i+start] = temp[i];
        }
        
        return count;
    }
    int countInv(vector<int>& arr, int start, int end) {
        int count=0;
        if(start>=end) return count;
        int mid=start+(end-start)/2;
        
        count += countInv(arr, start, mid);
        count += countInv(arr, mid+1, end);
        count += mergeInv(arr, start, mid, end);
        
        return count;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        return countInv(arr, 0, n-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends