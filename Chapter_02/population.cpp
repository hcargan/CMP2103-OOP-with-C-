
// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.

#include <iostream>
using namespace std;

int main()
{
    const long long START_POP = 312032486LL;
    const long long SECONDS_PER_YEAR = 365LL * 24LL * 60LL * 60LL;

    const long long birthsPerYear = SECONDS_PER_YEAR / 7LL;
    const long long deathsPerYear = SECONDS_PER_YEAR / 13LL;
    const long long immigrantsPerYear = SECONDS_PER_YEAR / 45LL;

    long long population = START_POP;

    for (int year = 1; year <= 5; ++year)
    {
        population += birthsPerYear - deathsPerYear + immigrantsPerYear;
        cout << "Population after year " << year << ": " << population << endl;
    }

    return 0;
}
