#include <iostream>
#include <string>
#include <regex>
using namespace std;
void assessPasswordStrength(const string& password) {
    string feedback;
    int strengthScore = 0;
   
    if (password.length() < 8) {
        feedback += "Password should be at least 8 characters long.\n";
    } else {
        strengthScore++;
    }
   
    if (!regex_search(password, regex("[A-Z]"))) {
        feedback += "Password should include at least one uppercase letter.\n";
    } else {
        strengthScore++;
    }
  
    if (!regex_search(password, regex("[a-z]"))) {
        feedback += "Password should include at least one lowercase letter.\n";
    } else {
        strengthScore++;
    }
    
    if (!regex_search(password, regex("[0-9]"))) {
        feedback += "Password should include at least one number.\n";
    } else {
        strengthScore++;
    }
  
    if (!regex_search(password, regex("[!@#$%^&*(),.?\":{}|<>]"))) {
        feedback += "Password should include at least one special character.\n";
    } else {
        strengthScore++;
    }
    // Provide overall assessment
    if (strengthScore == 5) {
        feedback += "Your password is strong.\n";
    } else if (strengthScore >= 3) {
        feedback += "Your password is moderate. Consider making it stronger.\n";
    } else {
        feedback += "Your password is weak. Please improve it using the above suggestions.\n";
    }
    cout << feedback;
}
int main() {
    string userPassword;
    cout << "Enter a password to assess its strength: ";
    cin >> userPassword;
    assessPasswordStrength(userPassword);
    return 0;
}
