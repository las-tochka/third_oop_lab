#include <stdexcept>
#include <cmath>
#include "../include/Rectangle.hpp"

Rectangle::Rectangle() : Figure() {}

Rectangle::Rectangle(std::array<int, 2> a, std::array<int, 2> b, 
               std::array<int, 2> c, std::array<int, 2> d)
    : Figure(a, b, c, d) {}


void Rectangle::getCenter(std::vector<double>& result_coords) const {
    result_coords.clear();
    double x = (A[0] + C[0]) / 2.0; double y = (A[1] + C[1]) / 2.0;
    result_coords.push_back(x);
    result_coords.push_back(y);
}

Rectangle::operator double() const {
    double side1 = std::sqrt(std::pow(A[0] - B[0], 2) + std::pow(A[1] - B[1], 2));
    double side2 = std::sqrt(std::pow(B[0] - C[0], 2) + std::pow(B[1] - C[1], 2));
    return side1 * side2;
}