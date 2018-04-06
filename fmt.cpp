// 17/11/22 = Thu

// format a data file, converting all whitespaces into newlines

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#define BAD_READ -1
#define MAX_LEN 10000

int read(std::string fname, double * t, int n);

int read(std::string fname, double * t, int n)
{
	if (n <= 0) {
		std::cerr << "Read Error : Length n = " << n << std::endl;
		return BAD_READ;
	}

	std::ifstream ifile(fname, std::ifstream::in);
	if (!ifile.good()) {
		std::cerr << "Read Error : File Name = " << fname << std::endl;
		return BAD_READ;
	}

	double point;
	int i = 0;
	while (ifile >> point && i < n) {
		t[i] = point;
		i += 1;
	}
	return i;
}

template<typename T>
int awrite(T const* a, int n, std::string fname = "out") {
    std::ofstream ofile(fname, std::ofstream::out);
    for (int i = 0; i < n; ++i)
    	ofile << a[i] << std::endl;
    ofile.flush();
    ofile.close();
    return 0;
}

int main (int argc, char * argv[])
{
	double * t = new double[MAX_LEN];
	if (argc != 2 || argc != 3) {
		std::cerr << "[Command] [Input Filename] (Default out)" << std::endl;
		std::cerr << "[Command] [Input Filename] [Output Filename]" << std::endl;
		return EXIT_FAILURE;
	}
	int nread = read(argv[1], t, MAX_LEN);
	awrite(t, nread, argv[2]);

	return EXIT_SUCCESS;
}