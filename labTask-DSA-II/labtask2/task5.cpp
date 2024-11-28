// Task 5: Is this a Palindrome?

// Write a recursive program to check if a given string is a palindrome or not (not case sensitive, ignore whitespaces)

#include <iostream>
#include <string>
#include <cctype> // For tolower and isspace functions
using namespace std;

bool isPalindromeHelper(string str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (isspace(str[start])) {
        return isPalindromeHelper(str, start + 1, end);
    }
    if (isspace(str[end])) {
        return isPalindromeHelper(str, start, end - 1);
    }
    if (tolower(str[start]) != tolower(str[end])) {
        return false;
    }
    return isPalindromeHelper(str, start + 1, end - 1);
}


bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;
    return isPalindromeHelper(str, start, end);
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Read a whole line including spaces
    if (isPalindrome(input)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}