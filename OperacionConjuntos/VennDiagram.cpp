#include "VennDiagram.h"

VennDiagram::VennDiagram(std::set<int> a, std::set<int> b) : _a(a), _b(b)
{
    compute();
}

std::vector<int> VennDiagram::getLeft()
{
    return std::vector<int>(_left.begin(), _left.end());
}

std::vector<int> VennDiagram::getRight()
{
    return std::vector<int>(_right.begin(), _right.end());
}

std::vector<int> VennDiagram::getIntersection()
{
    return std::vector<int>(_intersection.begin(), _intersection.end());
}

void VennDiagram::compute()
{
    // Compute the left set
    for (auto it = _a.begin(); it != _a.end(); ++it) {
        if (_b.find(*it) == _b.end()) {
			_left.insert(*it);
		}
	}

    // Compute the right set
    for (auto it = _b.begin(); it != _b.end(); ++it) {
        if (_a.find(*it) == _a.end()) {
			_right.insert(*it);
		}
	}

    // compute the intersection
    for (auto it = _a.begin(); it != _a.end(); ++it) {
        if (_b.find(*it) != _b.end()) {
            _intersection.insert(*it);
        }
    }
}
