#include <iostream>
using namespace std;

string generatePassword(string name, string site, string password, int digit){
    string specialChars = "!@#$%^&*()_+";
    string generatedPassword = name + site + password + to_string(digit);
    return generatedPassword;
}

int main(){
    cout<<"Welcome to the Password generator"<<endl;

    string name;
    cout<<"Enter your First Name: ";
    cin>>name;

    cout<<"Enter the site name you want to generate password for: ";
    string site;
    cin>>site;

    cout<<"give a easy password you always use :";
    string password;
    cin>>password;

    cout<< " Enter some digit password you always use :";
    int digit;
    cin>>digit;

    string generatedPassword ;
    generatedPassword= generatePassword(name,site,password,digit);

    cout<<"Generated Password is: "<<generatedPassword<<endl;


    return 0;
}