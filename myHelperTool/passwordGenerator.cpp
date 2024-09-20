#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <functional>
#include <algorithm>

using namespace std;

string generatePassword(const string& name, const string& site, const string& password, int digit) {
    // Step 1: Concatenate the inputs
    string input = name + site + password + to_string(digit);

    // Step 2: Hash the concatenated string using std::hash
    hash<string> hasher;
    size_t hashValue = hasher(input);

    // Step 3: Convert the hash to a readable password format
    stringstream ss;
    ss << hex << hashValue;
    string hashStr = ss.str();

    // Step 4: Transform the hash to ensure a mix of character types
    string generatedPassword;
    size_t nameIndex = 0, siteIndex = 0, passwordIndex = 0;
    for (size_t i = 0; i < hashStr.size(); i += 4) {
        // Add characters from the name
        if (nameIndex < name.size()) {
            generatedPassword += toupper(name[nameIndex++]);
        }
        // Add characters from the site
        if (siteIndex < site.size()) {
            generatedPassword += tolower(site[siteIndex++]);
        }
        // Add characters from the password
        if (passwordIndex < password.size()) {
            generatedPassword += password[passwordIndex++];
        }
        // Add digits and special characters from the hash
        if (i < hashStr.size()) generatedPassword += (hashStr[i] % 10) + '0'; // Digit
        if (i + 1 < hashStr.size()) generatedPassword += "!@#$%^&*()"[hashStr[i + 1] % 10]; // Special character
    }

    // Ensure the password is at least 16 characters long
    while (generatedPassword.size() < 16) {
        generatedPassword += "!@#$%^&*()"[generatedPassword.size() % 10];
    }

    return generatedPassword.substr(0, 16); // Return the first 16 characters
}

int main() {
    cout << "Welcome to the Password generator" << endl;

    string name;
    cout << "Enter your First Name: ";
    cin >> name;

    cout << "Enter the site name you want to generate password for: ";
    string site;
    cin >> site;

    cout << "Give an easy password you always use: ";
    string password;
    cin >> password;

    cout << "Enter some digit password you always use: ";
    int digit;
    cin >> digit;

    string generatedPassword = generatePassword(name, site, password, digit);

    cout << "Generated Password is: " << generatedPassword << endl;

    return 0;
}