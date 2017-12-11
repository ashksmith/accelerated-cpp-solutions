/* Author: Ashley K. Smith (github.com/ashksmith)
 * Accelerated C++, Chapter 3, Exercise 3-2
 *
 * Write a program to compute and print the quartiles of a set of integers.
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using std::cout;
using std::vector;
using std::endl;

double find_median(vector<int>);

int main(void){
	// Wikipedia method 1
	// 1. Use the median to divide the ordered data set into two halves.
	// 	if there is an odd number, not not include the median value in either half
	//      if there is a even number of data points in the original set, split exactly in half
	//
	// 2. The lower quartile value is the median of the lower half of the data. The upper
	//    quartile value is the median of the upper half of the data.
	srand(time(0));

	vector<int> values;

	// Populate vector with random values between 0 and 25.
	for(int i = 0; i < 20; i++)
		values.push_back(rand() % 25);

	sort(values.begin(), values.end());

	typedef std::vector<double>::size_type vec_sz;
	vec_sz size = values.size();

	for(int i = 0; i < 20; i++)
		cout << values[i] << " ";

	cout << std::endl;

	vec_sz mid = size / 2;
	double median;
	median = find_median(values); 

	vector<int> upper_quartile, lower_quartile;

	for(int i = 0; i < median; i++)
		lower_quartile.push_back(values[i]);

	for(int i = median; i < size; i++)
		upper_quartile.push_back(values[i]);

	cout << "Median: " << median << endl;
	cout << "Lower quartile: " << find_median(lower_quartile) << endl;
	cout << "Upper qurtile: " << find_median(upper_quartile) << endl;
}

double find_median(vector<int> v){
	sort(v.begin(), v.end());
	double m;
	double mid = v.size() / 2;
	if (v.size() % 2 == 0){
		return (v[mid] + v[mid-1]) / 2;
	} else {
		return v[mid];
	}
}
