/*

Problem Statement

You are working on a text analytics tool that processes textual documents for various applications, such as content summarization and keyword extraction. The document is a string that contains multiple words separated by spaces. Your task is to identify the most common word in the document. If there is a tie, return the word that appears first.


Input Format

document: A string representing a document(length: 1 to 10^5).
    Contains only letters, numbers, and spaces.
    Punctuation marks (such as commas, periods, etc.) are removed before processing.
    Words are case-insensitive (i.e., "Hello" and "hello" are treated as the same word).


Output Format

    Return the most common word in the document in lowercase.
    If there is a tie (i.e., multiple words with the same frequency), return the word that appears first
    

Example Input
"Hello world hello Universe".

Example Output
"hello"


Constraints:
1. (1 \leq) length of document (\leq 10^5)
2. The string contains alphanumeric characters and spaces only. All punctuation marks are removed before processing.

*/


// SOURCE CODE

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

using namespace std;

// Helper function to convert a string to lowercase
string toLowerCase(const string &word) {
    string lowerWord;
    for (char c : word) {
        lowerWord += tolower(c);
    }
    return lowerWord;
}

// Function to find the most common word
string mostCommonWord(string document) {
    unordered_map<string, int> mpp;
    string word;
    vector<string> wordArr;

    // Parse the document into words
    for (char c : document) {
        if (c == ' ') {
            if (!word.empty()) {
                word = toLowerCase(word);
                wordArr.push_back(word);
                mpp[word]++;
                word.clear();
            }
        }
        else word += c;
    }

    // Handle the last word
    if (!word.empty()) {
        word = toLowerCase(word);
        wordArr.push_back(word);
        mpp[word]++;
    }

    // Find the most common word
    string ans;
    int maxCount = 0;

    for (const auto &entry : mpp) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            ans = entry.first;
        }
    }

    return ans;
}

int main() {
    string document;
    getline(cin, document); // Read the entire line of input

    // Output the most common word
    cout << mostCommonWord(document) << endl;
    return 0;
}
