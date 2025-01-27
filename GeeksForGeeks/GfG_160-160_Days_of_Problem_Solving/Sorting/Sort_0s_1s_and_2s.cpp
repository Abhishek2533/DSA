/*

Company Tags:

        Paytm
        Flipkart
        Morgan Stanley
        Amazon
        Microsoft
        OYO Rooms
        Samsung
        Snapdeal
        Hike
        MakeMyTrip
        Ola Cabs
        Walmart
        MAQ Software
        Adobe
        Yatra.com
        SAP Labs
        Qualcomm
        

*/






// METHOD 1:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int countZero=0, countOne=0, countTwo=0;
        
        for(int i=0; i<n; i++) {
            if(arr[i]==0) countZero++;
            else if(arr[i] == 1) countOne++;
            else countTwo++;
        }
        
        int ind=0;
        for(int i=0; i<countZero; i++) arr[ind++]=0;
        for(int i=0; i<countOne; i++) arr[ind++]=1;
        for(int i=0; i<countTwo; i++) arr[ind++]=2;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
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
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int zeroInd=0, oneInd=0, twoInd=n-1;
        
        while(oneInd<=twoInd) {
            if(arr[oneInd]==0) swap(arr[zeroInd++], arr[oneInd++]);
            else if(arr[oneInd]==1) oneInd++;
            else swap(arr[oneInd], arr[twoInd--]);
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends