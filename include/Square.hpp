#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include <vector>
#include "Figure.hpp"

class Square : public Figure {
public:
    Square();
    Square(std::array<int, 2> a, std::array<int, 2> b, 
           std::array<int, 2> c, std::array<int, 2> d);
    void getCenter(std::vector<double>& result_coords) const override;
    operator double() const override;
};

#endif // SQUARE_HPP
