/* Author: Ashley K. Smith
   Accelerated C++, Chapter 1, Exercise 1-5

   Is this program valid? If so, what does it do? If not, say why not, and rewrite it to
   be valid.

	#include <iostream>
	#include <string> 
	
	int main(){
		{ std::string s = "a string";
	
		{ std::string x = s + ", really";
		  std::cout << s << std::endl; }
	
	          std::cout << x << std::endl;
		}
		
		return 0;
	}
*/

/*

The issue of this program is that x is declared inside a nested block, and is not accessible
outside of that scope on line 16 of this file. 

Ignoring scoping issues with this program it's simple to ascertain the
intent of the program is to print:
		
	A string
	A string, really

and is fixed by defining x in the parent block. 
*/
#include <iostream>
#include <string>

int main(){
	{ std::string s = "a string";
          std::string x = s;
	{ x += ", really";
	  std::cout << s << std::endl; }

	std::cout << x << std::endl;
	}


	return 0;
}
