#include <stdexcept>
#include <cmath>
#include "../include/Square.hpp"

Square::Square() : Figure() {}

Square::Square(std::array<int, 2> a, std::array<int, 2> b, 
               std::array<int, 2> c, std::array<int, 2> d)
    : Figure(a, b, c, d) {}


void Square::getCenter(std::vector<double>& result_coords) const {
    result_coords.clear();
    double x = (A[0] + C[0]) / 2.0;
    double y = (A[1] + C[1]) / 2.0;
    result_coords.push_back(x);
    result_coords.push_back(y);
}

Square::operator double() const {
    double x = std::abs(A[0] - B[0]);
    double y = std::abs(A[1] - B[1]);
    double side = std::sqrt(x * x + y * y);
    return side * side;
}