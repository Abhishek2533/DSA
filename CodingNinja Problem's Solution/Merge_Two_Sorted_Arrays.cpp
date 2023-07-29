#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i = 0;
    int j = 0;
    int k = 0;
    vector<int> temp;

    while(i<m) {
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<n) {
        temp.push_back(arr2[j]);
        j++;
    }
	sort(temp.begin(), temp.end());
    arr1 = temp;
	return arr1;
}