#pragma once
#include "Operation.h"
#include "VennDiagram.h"
#include <string>
#include <optional>
#include <conio.h>


class SetsApp {
public:
	SetsApp();
	void init();
	void runMenu();

private:
	void makeUnion();
	void makeIntersection();
	void makeDifference();
	void makeSymmetricDifference();
	void makeComplement();

	std::optional<int> scan_int(std::string message, int min_value, int max_value, bool allowEmpty = true);
	Set scanSet(std::string message, std::string label);
	
};

