#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include <iostream>
#include <vector>
#include "Figure.hpp"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(std::array<int, 2> a, std::array<int, 2> b, 
           std::array<int, 2> c, std::array<int, 2> d);
    void getCenter(std::vector<double>& result_coords) const override;
    operator double() const override;
};

#endif // TRAPEZOID_HPP
