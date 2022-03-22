#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <random>
using namespace std;

int main()
{
    int temp;
    // set size
    cout << "Enter Array Size ";
    cin >> temp;
    const int size = temp;
    int numbers[size];
    // insert
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a number for position " << i << ":";
        cin >> numbers[i];
    }

    // a. classify
    for (int i = 0; i < size; i++)
    {
        int number = numbers[i];

        if (number % 2 != 0)
            cout << "The number " << number << " is odd" << endl;
        else
            cout << "The number " << number << " is even" << endl;
        ;
    }
    // b. make them all odd
    for (int i = 0; i < size; i++)
    {
        int number = numbers[i];
        numbers[i] = 2 * numbers[i] + 1;
        cout << "The number " << number << " has become " << numbers[i] << endl;
    }
    // c. encrypt
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 500 * size);
    int p = dist6(rng);

    // c1. check if prime using miller-rabin:
    int is_prime = 1;
    for (int i = 2; i < int(sqrt(p)) + 1; i++)
    {
        if (p % i == 0)
        {
            is_prime = 0;
        }
    }

    if (is_prime)
    {
        cout << "The number " << p << " is prime" << endl;
        for (int i = 0; i < size; i++)
        {
            int number = numbers[i];
            numbers[i] = (p * numbers[i]) % 17;
            cout << "The number " << number << " has become " << numbers[i] << endl;
        }
    }

    else
    {
        cout << "The number " << p << " is not prime" << endl;
        for (int i = 0; i < size; i++)
        {
            int number = numbers[i];
            numbers[i] = (17 * numbers[i]) % p;
            cout << "The number " << number << " has become " << numbers[i] << endl;
        }
    }

    return (0);
}
