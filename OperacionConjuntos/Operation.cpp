#include "Operation.h"

Operation::Operation(Set a, Set b)
{
    _a = a;
    _b = b;
}

Set Operation::getA()
{
    return _a;
}

Set Operation::getB()
{
    return _b;
}

Set Operation::doUnion() { // O(m+n) = O(n)
    std::set<int> result;

    for (auto it = _a.getData().begin(); it != _a.getData().end(); it++) {
        result.insert(*it);
    }

    for (auto it = _b.getData().begin(); it != _b.getData().end(); it++) {
        if (result.find(*it) == result.end()) {
            result.insert(*it);
        }
    }

    return Set(result);
}

Set Operation::doIntersection() { // O(n log n)
    std::set<int> result;

    for (int x : _a.getData()) {
        if (_b.getData().count(x) > 0) {
            result.insert(x);
        }
    }

    return Set(result);
}

Set Operation::doDifference() { // O(2^n)
    std::set<int> result;
    std::set a(_a.getData());
    std::set b(_b.getData());

    backtrackDifference(a, b, &result);
    return Set(result);
}

Set Operation::doSymmetricDifference() { // O(m+n) = O(n)
    std::set<int> result;
    std::set<int> a(_a.getData());
    std::set<int> b(_b.getData());

    // Iterar por los elementos de A
    for (auto elem : a) {
        // Si el elemento no está en B, agregarlo a la diferencia simétrica
        if (b.find(elem) == b.end()) {
            result.insert(elem);
        }
    }

    // Iterar por los elementos de B
    for (auto elem : b) {
        // Si el elemento no está en A, agregarlo a la diferencia simétrica
        if (a.find(elem) == a.end()) {
            result.insert(elem);
        }
    }

	return Set(result);
}

Set Operation::doComplement() { // O(n)
    std::set<int> complement;
    std::set<int> a(_a.getData());
    std::set<int> b(_b.getData());
    
    for (int elem : b) {
        if (a.count(elem) == 0) {
            complement.insert(elem);
        }
    }

    return Set(complement);
}

void Operation::backtrackDifference(std::set<int>& a, std::set<int>& b, std::set<int>* result)
{
    if (a.empty()) {
        result = new std::set<int>();
        return;
    }

    int x = *a.begin();
    a.erase(x);

    backtrackDifference(a, b, result);

    if (b.find(x) == b.end()) {
        result->insert(x);
    }

    backtrackDifference(a, b, result);

    a.insert(x);
}
