#include "../include/data_logger.h"


DataLogger::DataLogger(std::string file_name) {
	file.open(file_name + ".csv", std::ios::out);
}

void DataLogger::addData(SingleRigidbody* body) {
	single_bodys.push_back(body);
}

void DataLogger::writeHeaders() {
	buffer = "time,";
	for (auto i = single_bodys.begin(); i != single_bodys.end(); ++i) {
		SingleRigidbody* item = *i;
		std::string n = item->name + ":";
		buffer = buffer + n + "FX," + n + "FY," + n + "AX," + n + "AY," + n + "VX," + n + "VY," + n + "PX," + n + "PY," + n + "mass,";
	}
	file << buffer << "\n";
	this->clearBuffer();
}

void DataLogger::writeLine(double time) {
	buffer = std::to_string(time) + ",";
	for (auto i = single_bodys.begin(); i != single_bodys.end(); ++i) {
		SingleRigidbody* item = *i;
		buffer = buffer + std::to_string(item->state.f.x) + "," + std::to_string(item->state.f.y) + "," + std::to_string(item->state.a.x) + "," + std::to_string(item->state.a.y) + "," + std::to_string(item->state.v.x) + "," + std::to_string(item->state.v.y) + "," + std::to_string(item->state.p.x) + "," + std::to_string(item->state.p.y) + "," + std::to_string(item->state.mass) + ",";
	}
	file << buffer << "\n";
	this->clearBuffer();
}

void DataLogger::writeFile() {
	file.close();
	this->clearBuffer();
}

void DataLogger::clearBuffer() {
	buffer = "";
}