/* Author: Ashley K. Smith (github.com/ashksmith)
 * Accelerated C++, Chapter 3, Exercise 3-3
 *
 * Write a program to count how many times each distinct word appears in it's input
*/

#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
int main(void){
	// Create a vector to store words
	vector<string> words;
	// Storage location for input string
	string input;

	// Get input
	while(std::cin >> input)
		words.push_back(input);

	// Sort words
	sort(words.begin(), words.end());

	int count = 1;
	// Loop through the words and count
	for(int i = 0; i < words.size(); i++){
		if(words[i] == words[i + 1]){
			count++;
		} else {
			cout << words[i] << " was found " << count << " times.\n";
			count = 1;
		}

	}
}
