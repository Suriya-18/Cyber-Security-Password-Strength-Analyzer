#include <iostream>
using namespace std;

int checkStrength(string password) {
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        if (isupper(ch)) hasUpper = true;
        if (isdigit(ch)) hasDigit = true;
        if (!isalnum(ch)) hasSpecial = true;
    }

    int score = hasLower + hasUpper + hasDigit + hasSpecial;
    if (password.length() >= 8) score++;
    return score;
}

int main() {
    string password;
    cout << "Enter password: ";
    cin >> password;

    int strength = checkStrength(password);
    if (strength <= 2) cout << "❌ Weak Password\n";
    else if (strength == 3) cout << "⚠️ Medium Password\n";
    else cout << "✅ Strong Password\n";

    return 0;
}
