/*

Problem Statement

You're implementing a browser's back/forward feature. Each time a user visits a URL, it's added to history. Users can go back X steps or forward Y steps. Implement this browser history manager.

Operations
1. visit(string url) - User visits a URL.
2. back(int steps) - Go back steps steps, return the current URL.
3. forward(int steps) - Go forward steps steps, return the current URL.

Your manager only needs you to implement the viste, back and forward functionalities.


Input Format

An integer ( n ) representing the number of operations.
A list of operations, each operation is a string representing the operation name and its arguments.


Output Format

A list of URLs, each URL is a string representing the current URL after each operation.


Example

Input:

6
visit chaicode.com
visit facebook.com
visit youtube.com
back 1
back 1
forward 1

    
Output: 

chaicode.com facebook.com youtube.com facebook.com chaicode.com facebook.com



Constraints:
1. 1 ≤ URL length ≤ 100
2. 1 ≤ steps ≤ 100
3. Test cases are in a way that the browser history is always valid.


*/


// SOURCE CODE

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// you just need to implement the BrowserHistory class below
class BrowserHistory {
    // your code here
private:
    vector<string> history;
    int currIndex;
public:
    BrowserHistory(string homepage) {
       // your code here
       history.push_back(homepage);
       currIndex=0;
    }

    BrowserHistory() {
        currIndex=0;
    }

    void visit(string url) {
        // your code here
        history.resize(currIndex+1);
        // add new url
        history.push_back(url);
        currIndex++;
    }

    string back(int steps) {
        // your code here
        currIndex=max(0,currIndex-steps);
        return history[currIndex];
    }

    string forward(int steps) {
        // your code here
        currIndex=min((int)history.size()-1,currIndex+steps);
        return history[currIndex];
    }
};

int main() {
    int n;
    cin >> n; 
    string operation, url;
    int steps;

    // please do not change below code
    BrowserHistory browserHistory("chaicode.com");
    
    string result = "chaicode.com ";
    for (int i = 0; i < n; i++) {
        cin >> operation;

        if (operation == "visit") {
            cin >> url;
            browserHistory.visit(url);
            result += url + " ";
        } else if (operation == "back") {
            cin >> steps;
            result += browserHistory.back(steps) + " ";
        } else if (operation == "forward") {
            cin >> steps;
            result += browserHistory.forward(steps) + " ";
        }
    }
    
    cout << result.substr(0, result.size() - 1);

    return 0;
}