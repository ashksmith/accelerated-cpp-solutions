/* Author: Ashley K. Smith (github.com/ashksmith)
 * Accelerated C++, Chapter 3, Exercise 3-4
 *
 * Write a program to report the length of the longest and shortest string in its input
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
	string s, longest_str, shortest_str;
	size_t longest_str_len = 0, shortest_str_len = 0;	

	while(std::cin >> s){
		size_t strlen = s.length();

		if(strlen > longest_str_len){
			longest_str = s;
			longest_str_len = strlen;
		}
		if(strlen < shortest_str_len || shortest_str_len == 0){
			shortest_str = s;
			shortest_str_len = strlen;
		}
	}
			
	cout << "Longest word: " << longest_str << ", length: " << longest_str_len << std::endl;
	cout << "Shortest word: " << shortest_str << ", length: " << shortest_str_len << std::endl;

	return 0;
}
