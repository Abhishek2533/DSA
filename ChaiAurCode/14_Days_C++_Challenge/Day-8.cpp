/*

Problem Statement

You are working at Dreamflix, a popular streaming service, on their adaptive streaming engine. Your task is to help the system automatically select the highest quality video that can be streamed without buffering, based on a user's available bandwidth.
Each video quality has a minimum bandwidth requirement, and the system must:
1. Select the highest quality that fits within the available bandwidth.
2. If no quality is suitable, return "No Quality Available"

This feature ensures smooth playback while maximizing video quality. Choosing the wrong quality may lead to either buffering (annoying!) or unnecessarily low-quality playback.


Input

An integer ( b ) representing the user's current bandwidth in kbps.
An array ( q ) of ( n ) elements, where each element is a dictionary with the following keys:
    quality: A string representing the quality of the stream.
    required: An integer representing the minimum bandwidth required for that quality.


Output Format

A string representing the highest quality stream that won't buffer.
If no quality is available, return "No Quality Available".


Example

Input:
badwidth = 5000(kbps)
qualities =[
    {quality: "4K", required: 15000},
    {quality: "1080p", required: 5000},
    {quality: "720p", required: 3000},
    {quality: "480p", required: 1000}
]

    
Output: 
1080p


Explanation:
The user's bandwidth is 5000 kbps, so the highest quality stream that won't buffer is "1080p".


*/


// SOURCE CODE



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// You need to implement the function below
string selectStreamQuality(int bandwidth, vector<pair<string, int>>& qualities) {
    // Your code here
    if(qualities.empty()) return "No Quality Available";

    sort(qualities.begin(), qualities.end(), [](const pair<string, int>&a, pair<string, int>&b) {
        return a.second<b.second;
    });

    string highest_quality = "No Quality Available";
    for(auto it : qualities) {
        if(it.second <= bandwidth) highest_quality=it.first;
        else break;
    }
    return highest_quality;
}

int main() {
    int bandwidth;
    cin >> bandwidth;

    int n;
    cin >> n;


    vector<pair<string,int>> qualities(n);
    for (int i = 0; i < n; ++i) {
        cin >> qualities[i].first >> qualities[i].second;
    }

    cout << selectStreamQuality(bandwidth, qualities);
}