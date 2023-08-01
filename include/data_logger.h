#ifndef DATA_LOGGER
#define DATA_LOGGER

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "single_rigidbody.h"


class DataLogger {
public:
	DataLogger() {};
	DataLogger(std::string file_name);
	void addData(SingleRigidbody *body);
	void writeHeaders();
	void writeLine(double time);
	void writeFile();
	void clearBuffer();

	std::string buffer = "";
	std::fstream file;
	std::vector< SingleRigidbody* > single_bodys;
};

#endif