#include <iostream>

using namespace std;

class null_exception : public exception
{
public:
	null_exception() {}

	null_exception(const char* message) : exception(message) {}
};
