#include <iostream>

int main()
{
    // Part 2: Palindrome Check

    // Input string from command-line
    std::string str;
    std::cout << "Enter String:" << std::endl;
    std::cin >> str;

    // Palindrome Check
    // WRITE YOUR PALINDROME CHECK HERE
    int l = 0;
    int r = str.length() - 1;
    bool is_palindrome = true;
    while (l < r) {
        if (str[l] != str[r]) {
            is_palindrome = false;
        }
        l++;
        r--;
    }
    std::cout << is_palindrome << "\n";


    return 0;
}
