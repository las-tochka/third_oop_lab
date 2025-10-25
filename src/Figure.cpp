#include <stdexcept>
#include "../include/Figure.hpp"

Figure::Figure() : A{0, 0}, B{0, 1}, C{1, 1}, D{1, 0} {}

Figure::Figure(std::array<int, 2> a, std::array<int, 2> b, 
               std::array<int, 2> c, std::array<int, 2> d)
    : A(a), B(b), C(c), D(d) {}

    
Figure& Figure::operator=(const Figure& other) {
    if (typeid(*this) != typeid(other)) {
        throw std::invalid_argument("Cannot assign: different types");
    }
    A = other.A;
    B = other.B;
    C = other.C;
    D = other.D;
    return *this;
}

Figure& Figure::operator=(Figure&& other) {
    if (typeid(*this) != typeid(other)) {
        throw std::invalid_argument("Cannot move assign: different types");
    }
    A = std::move(other.A);
    B = std::move(other.B);
    C = std::move(other.C);
    D = std::move(other.D);
    other.A = {0, 0}; other.B = {0, 0}; other.C = {0, 0}; other.D = {0, 0};
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    os << "A: {" << figure.A[0] << "; " << figure.A[1] << "}, "
       << "B: {" << figure.B[0] << "; " << figure.B[1] << "}, "
       << "C: {" << figure.C[0] << "; " << figure.C[1] << "}, "
       << "D: {" << figure.D[0] << "; " << figure.D[1] << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    is >> figure.A[0] >> figure.A[1]
       >> figure.B[0] >> figure.B[1]
       >> figure.C[0] >> figure.C[1]
       >> figure.D[0] >> figure.D[1];
    return is;
}
