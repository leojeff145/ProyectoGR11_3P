#include "Set.h"

Set::Set(std::set<int> data, std::string label) : _data(data), _label(label) {}

Set::Set(std::string label) : _label(label) {}

void Set::insert(int n) {
	_data.insert(n);
}

std::set<int>& Set::getData() {
	return _data;
}

std::vector<int> Set::getAsVector() {
	return std::vector<int>(_data.begin(), _data.end());
}

std::string Set::getLabel() {
	return _label;
}

int Set::size()
{
	return _data.size();
}
