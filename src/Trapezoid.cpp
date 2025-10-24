#include <stdexcept>
#include <cmath>
#include "../include/Trapezoid.hpp"

Trapezoid::Trapezoid() : Figure() {}

Trapezoid::Trapezoid(std::array<int, 2> a, std::array<int, 2> b, 
               std::array<int, 2> c, std::array<int, 2> d)
    : Figure(a, b, c, d) {}

void Trapezoid::getCenter(std::vector<double>& result_coords) const {
    result_coords.clear();
    double x = (A[0] + B[0] + C[0] + D[0]) / 4.0;
    double y = (A[1] + B[1] + C[1] + D[1]) / 4.0;
    result_coords.push_back(x);
    result_coords.push_back(y);
}

double distancePointToLine(const std::array<int, 2>& p, 
                          const std::array<int, 2>& a, 
                          const std::array<int, 2>& b) {
    double A = b[1] - a[1];
    double B = a[0] - b[0];
    double C = b[0] * a[1] - a[0] * b[1];
    return std::abs(A * p[0] + B * p[1] + C) / std::sqrt(A * A + B * B);
}

Trapezoid::operator double() const {
    double base1 = std::sqrt(std::pow(B[0] - A[0], 2) + std::pow(B[1] - A[1], 2));
    double base2 = std::sqrt(std::pow(D[0] - C[0], 2) + std::pow(D[1] - C[1], 2));

    double height = distancePointToLine(C, A, B);

    return (base1 + base2) / 2.0 * height;
}