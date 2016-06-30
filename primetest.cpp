/*
 *  Author: Sabrina Ip
 *  Date: Sept 18, 2015
 *
 *  This program takes in a number and tells the user whether it is prime or not.
 *
  */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>

int main()
{
	unsigned long number;
	cout << "Enter a number:" <<endl;
		
	while (cin >> number) {
		int divisor = 3;
		bool isPrime = true;

		if (number <= 1) {
			isPrime = false;
		} else if (number == 2) {
			isPrime = true;
		} else if (number % 2 == 0) {
			isPrime = false;
		} else {
			while (isPrime == true && divisor <= sqrt(number)) {
				if (number % divisor == 0) {
					isPrime = false;
				} else {
					divisor+=2;
				}
			}
		}

		if (isPrime == false) {
			cout << "It is not prime" <<endl;
		} else {
			cout << "It's prime!" <<endl;
		}
		cout << "\n Enter a number:" <<endl;
	}
	return 0;
}
