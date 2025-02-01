/*

Company Tags:

        Infosys
        Amazon
        Microsoft
        Google
        Codenation
        Uber


*/




// METHOD 1:


//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countStudents(vector<int>& arr, int pages) {
        int student=1, currPage=0;
        for(int i=0; i<arr.size(); i++) {
            if(currPage+arr[i] <= pages) currPage+=arr[i];
            else {
                student++;
                currPage=arr[i];
            }
        }
        
        return student;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k) return -1;
        int start=*max_element(arr.begin(), arr.end());
        int end=accumulate(arr.begin(), arr.end(), 0);

        for(int i=start; i<=end; i++) {
            int cntStudent = countStudents(arr,i);
            if(cntStudent==k) return i; 
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends






// METHOD 2:

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countStudents(vector<int>& arr, int pages) {
        int student=1, currPage=0;
        for(int i=0; i<arr.size(); i++) {
            if(currPage+arr[i] <= pages) currPage+=arr[i];
            else {
                student++;
                currPage=arr[i];
            }
        }
        
        return student;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k) return -1;
        int low=*max_element(arr.begin(), arr.end());
        int high=accumulate(arr.begin(), arr.end(), 0);
        
        while(low<=high) {
            int mid=low + (high-low)/2;
            int students=countStudents(arr, mid);
            if(students>k) low=mid+1;
            else high=mid-1;
        }
        
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends