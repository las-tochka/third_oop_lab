#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <vector>
#include "Figure.hpp"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(std::array<int, 2> a, std::array<int, 2> b, 
           std::array<int, 2> c, std::array<int, 2> d);
    void getCenter(std::vector<double>& result_coords) const override;
    operator double() const override;
};

#endif // RECTANGLE_HPP
