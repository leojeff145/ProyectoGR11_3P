#pragma once
#include "Validacion.h"
#include <set>
#include <vector>
#include <string>

class Set {
public:
	Set() = default;
	Set(std::set<int> data, std::string label = "");
	Set(std::string label);
	void insert(int n);
	std::set<int>& getData();
	std::vector<int> getAsVector();
	std::string getLabel();
	int size();

private:
	std::set<int> _data;
	std::string _label;
};
