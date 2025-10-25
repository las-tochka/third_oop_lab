#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <typeinfo>
#include <utility>
#include <array>
#include <vector>

class Figure {
protected:
    std::array<int, 2> A, B, C, D;

public:
    Figure();
    Figure(std::array<int, 2> a, std::array<int, 2> b, 
           std::array<int, 2> c, std::array<int, 2> d);
    ~Figure() = default;
    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other);
    virtual void getCenter(std::vector<double>& result_coords) const = 0;
    virtual operator double() const = 0;
    bool operator==(const Figure& other) const {
        return static_cast<double>(*this) == static_cast<double>(other);
    }
    bool operator!=(const Figure& other) const {
        return !(*this == other);
    }
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);
};


#endif // FIGURE_HPP
