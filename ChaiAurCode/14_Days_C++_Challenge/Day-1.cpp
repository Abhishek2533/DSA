/*

Problem Background

You are a Software engiiner ar FreeFlix, a leading video streaming platform. The platform processes millions of video frames every second, converting them into binary streams for transmission. Recently, customers reported seeing occasional frame glitches in their favorite shows.
The engineering team discovered that these glitches occur when certain


Problem Statement

You need to implement a function that can efficiently detect if a specific "glitch pattern" exists within a larger stream of video data. This will help prevent corrupted frames from reaching users' devices.


Input Format

videoStream: A string representing a segment of the video data stream (length: 1 to 10^5).
    Contains only '0' and '1' characters.
glitchPattern: A string representing the known problematic pattern (length: 1 to 100).
    Contains only '0' and '1' characters.


Output Format

    Return true if the glitch pattern is found in the video stream.
    Return false otherwise.

*/


// SOURCE CODE


#include <iostream>
#include <string>

using namespace std;

// you just need to implement this function
bool containsGlitchPattern(const string& videoStream, const string& glitchPattern) {
    // your code here
    int i=0, j=0;
    while(i<videoStream.size() && j<glitchPattern.size()) {
        if(videoStream[i]==glitchPattern[j]) {
            i++, j++;
        } else i++, j=0;
    }
    if(j==glitchPattern.size()) return true;
    return false;
 }

int main() {
    string videoStream, glitchPattern;
    cin >> videoStream;
    cin >> glitchPattern;

    // please do not change the below code
    if (containsGlitchPattern(videoStream, glitchPattern)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}