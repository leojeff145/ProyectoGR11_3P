#pragma once
#include "Validacion.h"
#include <set>
#include <vector>

class VennDiagram {
public:
	VennDiagram(std::set<int> a, std::set<int> b);

	std::vector<int> getLeft();
	std::vector<int> getRight();
	std::vector<int> getIntersection();

private:
	std::set<int> _a;
	std::set<int> _b;
	std::set<int> _left;
	std::set<int> _right;
	std::set<int> _intersection;

	void compute();
};
