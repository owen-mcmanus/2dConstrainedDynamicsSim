#include "../include/data_logger.h"


DataLogger::DataLogger(std::string file_name) {
	file.open(file_name + ".csv", std::ios::out);
}

void DataLogger::addData(SingleRigidbody* body) {
	single_bodys.push_back(body);
}

void DataLogger::addData(DoubleRigidbody* body) {
	double_bodys.push_back(body);
}

void DataLogger::writeHeaders() {
	buffer = "time,";
	for (auto i = single_bodys.begin(); i != single_bodys.end(); ++i) {
		SingleRigidbody* item = *i;
		std::string n = item->name + ":";
		buffer = buffer + n + "FX," + n + "FY," + n + "AX," + n + "AY," + n + "VX," + n + "VY," + n + "PX," + n + "PY," + n + "mass,";
	}
	for (auto i = double_bodys.begin(); i != double_bodys.end(); ++i) {
		DoubleRigidbody* item = *i;
		std::string n = item->name + ":";
		buffer = buffer + n + "FX0," + n + "FY0," + n + "AX0," + n + "AY0," + n + "VX0," + n + "VY0," + n + "PX0," + n + "PY0," + n + "mass0,";
		buffer = buffer + n + "FX1," + n + "FY1," + n + "AX1," + n + "AY1," + n + "VX1," + n + "VY1," + n + "PX1," + n + "PY1," + n + "mass1,";
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
	for (auto i = double_bodys.begin(); i != double_bodys.end(); ++i) {
		DoubleRigidbody* item = *i;
		buffer = buffer + std::to_string(item->state.f.x) + "," + std::to_string(item->state.f.y) + "," + std::to_string(item->state.a.x) + "," + std::to_string(item->state.a.y) + "," + std::to_string(item->state.v.x) + "," + std::to_string(item->state.v.y) + "," + std::to_string(item->state.p.x) + "," + std::to_string(item->state.p.y) + "," + std::to_string(item->state.mass) + ",";
		buffer = buffer + std::to_string(item->state1.f.x) + "," + std::to_string(item->state1.f.y) + "," + std::to_string(item->state1.a.x) + "," + std::to_string(item->state1.a.y) + "," + std::to_string(item->state1.v.x) + "," + std::to_string(item->state1.v.y) + "," + std::to_string(item->state1.p.x) + "," + std::to_string(item->state1.p.y) + "," + std::to_string(item->state1.mass) + ",";
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