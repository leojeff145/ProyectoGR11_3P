#pragma once
#include "Set.h"

class Operation {
public:
	Operation(Set a, Set b);
	Set getA();
	Set getB();
	Set doUnion();
	Set doIntersection();
	Set doDifference();
	Set doSymmetricDifference();
	Set doComplement();

private:
	Set _a;
	Set _b;

	void backtrackDifference(std::set<int>& a, std::set<int>& b, std::set<int>* result);
};
