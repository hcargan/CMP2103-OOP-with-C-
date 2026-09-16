#include <iostream>

// Function prototypes
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    std::cout << "Enter a credit card number as an integer: ";
    std::cin >> cardNumber;

    if (isValid(cardNumber)) {
        std::cout << cardNumber << " is valid." << std::endl;
    } else {
        std::cout << cardNumber << " is invalid." << std::endl;
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int size = getSize(number);
    
    // Check length constraint (between 13 and 16 digits)
    if (size < 13 || size > 16) {
        return false;
    }

    // Check starting prefix matching constraints
    if (!prefixMatched(number, 4) &&   // Visa
        !prefixMatched(number, 5) &&   // MasterCard
        !prefixMatched(number, 37) &&  // American Express
        !prefixMatched(number, 6)) {   // Discover
        return false;
    }

    // Apply the Mod 10 Luhn check total sum
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0);
}

// Get the result from Step 2 (Sum of doubled even-place digits from right to left)
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    number /= 10; // Drop the first rightmost digit to start at the 2nd position
    
    while (number > 0) {
        int lastDigit = number % 10;
        sum += getDigit(lastDigit * 2);
        number /= 100; // Move left by 2 positions
    }
    return sum;
}

// Return this number if it is a single digit, otherwise return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number / 10) + (number % 10);
}

// Return sum of odd place digits in number from right to left
int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += (number % 10);
        number /= 100; // Move left by 2 positions
    }
    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int dSize = getSize(d);
    return getPrefix(number, dSize) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    int count = 0;
    if (d == 0) return 1;
    while (d > 0) {
        count++;
        d /= 10;
    }
    return count;
}

// Return the first k number of digits from number.
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int size = getSize(number);
    if (size <= k) {
        return number;
    }
    
    // Divide out the extra digits at the end
    long long divisor = 1;
    for (int i = 0; i < (size - k); ++i) {
        divisor *= 10;
    }
    return number / divisor;
}
