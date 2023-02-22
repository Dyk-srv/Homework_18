#include <iostream>
#include <cstdlib>
#include <ctime>

double sum(double num1, double num2 = 0, double num3 = 0, double num4 = 0, double num5 = 0) {
	return num1 + num2 + num3 + num4 + num5;
}

inline double ariph_mean(double num1, double num2, double num3) {
	return (num1 + num2 + num3) / 3;
}

void max(int num1, int num2, int num3) {
	std::cout << "INT:\n";
	int max = num1 > num2 ? num1 : num2;
	if (num3 > max)
		max = num3;
	std::cout << "Maximum of " << num1 << ", " << num2 << " and " << num3 << " is " << max << '\n';
}

void max(short num1, short num2, short num3) {
	std::cout << "SHORT:\n";
	short max = num1 > num2 ? num1 : num2;
	if (num3 > max)
		max = num3;
	std::cout << "Maximum of " << num1 << ", " << num2 << " and " << num3 << " is " << max << '\n';
}

void max(double num1, double num2, double num3) {
	std::cout << "DOUBLE:\n";
	double max = num1 > num2 ? num1 : num2;
	if (num3 > max)
		max = num3;
	std::cout << "Maximum of " << num1 << ", " << num2 << " and " << num3 << " is " << max << '\n';
}

template <typename T>
T first_prime_el(T arr[], int size) {
	T first_prime = 0;
	int counter;
	for (int i = 0; i < size; i++) {
		counter = 0;
		for (int j = 1; j <= arr[i]; j++)
			if (arr[i] % j == 0) 
				counter++;
		if (counter == 2) {
			first_prime = arr[i];
			break;
		}
	}
	return first_prime;
}

int main() {
	int n;
	double n1, n2, n3, n4, n5;

	// 18.1 Default arguments: Sum from 1 to n numbers
	std::cout << "\t18.1 Default arguments: Sum from 1 to n numbers.\n";
	double result = 0;
	std::cout << "How many numbers do you want to sum up (1 to 5)? -> ";
	std::cin >> n;
	if (n < 1 || n > 5)
		std::cout << "Input error!\n";
	else {
		std::cout << "Enter numbers -> ";
		switch (n) {
		case 1: std::cin >> n1 ;
			result = sum(n1);
			break;
		case 2: std::cin >> n1 >> n2;
			result = sum(n1, n2);
			break;
		case 3: std::cin >> n1 >> n2 >> n3;
			result = sum(n1, n2, n3);
			break;
		case 4: std::cin >> n1 >> n2 >> n3 >> n4;
			result = sum(n1, n2, n3, n4);
			break;
		case 5: std::cin >> n1 >> n2 >> n3 >> n4 >> n5;
			result = sum(n1, n2, n3, n4, n5);
		}
		std::cout << "Sum = " << result << '\n';
	}


	// 18.2 Inline function: Ariphmetic mean of 3 numbers
	std::cout << "\n\t18.2 Inline function: Ariphmetic mean of 3 numbers.\n";
	std::cout << "Enter 3 numbers -> ";
	std::cin >> n1 >> n2 >> n3;
	std::cout << "Ariphmetic mean = " << ariph_mean(n1, n2, n3) << '\n';


	// 18.3 Overloaded function: Maximum of 3 numbers
	std::cout << "\n\t18.3 Overloaded function: Maximum of 3 numbers.\n";
	std::cout << "Enter data type (1 - int, 2 - short, 3 - double) -> ";
	std::cin >> n;
	if (n < 1 || n > 3)
		std::cout << "Input error!\n";
	else {
		int a, b, c;
		std::cout << "Enter numbers -> ";
		switch (n) {
		case 1: std::cin >> a >> b >> c;
			max(a, b, c);
			break;
		case 2: std::cin >> a >> b >> c;
			max(short(a), short(b), short(c));
			break;
		case 3: std::cin >> n1 >> n2 >> n3;
			max(n1, n2, n3);
		}
	}


	//18.4 Template function: The 1st prime array element 
	std::cout << "\n\t18.4 Template function: The 1st prime array element.\n";
	srand(time(NULL));
	const int size = 10;
	int arr[size];
	std::cout << "An array filled with random elements from 2 to 100:\n[";
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 99 + 1;  // [2...100]
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b]\n";
	if (first_prime_el(arr, size))
		std::cout << "The 1st prime array element: " << first_prime_el(arr, size) << '\n';
	else
		std::cout << "The array doesn't have any prime elements\n";

	return 0;
}