#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <bitset>
#include <iterator>
#include <string>
#include "functions.cpp"

void readFile (std::string fileName, std::string &data);
void to_bin(std::string &input, std::vector<int> &bin);
std::string mixing_bin (std::vector<int> &bin);
void padding (std::vector<int> &bin);
std::string to_hex(std::vector<int> &bin);

#endif// FUNCTIONS_H
