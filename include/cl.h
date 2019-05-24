#ifndef _cl_h_
#define _cl_h_
#include <vector>
#include <sstream>
using std::vector;

int to_int(char * str) {
	std::stringstream ss {str};
	int x;
	ss >> x;
	return x;
}

vector<int> parse_int(int argc, char **argv) {
	vector<int> result;
	for(int i = 1; i < argc; ++i) {
		result.push_back(to_int(argv[i]));
	}
	return result;
}
#endif //_cl_h_
