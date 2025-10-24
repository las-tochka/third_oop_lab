#include <gtest/gtest.h>
#include <sstream>
#include <array>
#include <memory>
#include "../include/Figure.hpp"
#include "../include/Square.hpp"
#include "../include/Rectangle.hpp"
#include "../include/Trapezoid.hpp"

TEST(SquareTest, OutputOperator) {
    const std::array<int, 2> a = {0, 0};
    const std::array<int, 2> b = {1, 0};
    const std::array<int, 2> c = {1, 1};
    const std::array<int, 2> d = {0, 1};

    Square sqr(a, b, c, d);

    std::ostringstream out;
    out << sqr;

    std::string expected = "A: {0; 0}, B: {1; 0}, C: {1; 1}, D: {0; 1}";
    EXPECT_EQ(out.str(), expected);
}

TEST(SquareTest, InputOperator) {
    std::istringstream in("1 2 3 4 5 6 7 8");
    const std::array<int, 2> dummy = {0, 0};
    Square sqr(dummy, dummy, dummy, dummy);

    in >> sqr;

    std::ostringstream out;
    out << sqr;

    std::string expected = "A: {1; 2}, B: {3; 4}, C: {5; 6}, D: {7; 8}";
    EXPECT_EQ(out.str(), expected);
}

TEST(FigureTest, DefaultConstructor) {
    EXPECT_NO_THROW({
        Square sqr;
    });
    
    Square sqr;
    std::vector<double> center;
    sqr.getCenter(center);
    
    ASSERT_EQ(center.size(), 2);
    EXPECT_TRUE(center[0] >= 0 && center[1] >= 0);
}

TEST(SquareTest, GetCenter) {
    std::array<int, 2> a = {0, 0};
    std::array<int, 2> b = {0, 2};
    std::array<int, 2> c = {2, 2};
    std::array<int, 2> d = {2, 0};

    Square square(a, b, c, d);

    std::vector<double> center;
    square.getCenter(center);

    ASSERT_EQ(center.size(), 2);
    EXPECT_EQ(center[0], 1);
    EXPECT_EQ(center[1], 1);
}

TEST(SquareTest, AreaCalculation) {
    std::array<int, 2> a = {0, 0};
    std::array<int, 2> b = {0, 2};
    std::array<int, 2> c = {2, 2};
    std::array<int, 2> d = {2, 0};
    Square square(a, b, c, d);

    double expected_area = 4.0;
    double area_via_cast = static_cast<double>(square);
    EXPECT_DOUBLE_EQ(area_via_cast, expected_area);
}

TEST(RectangleTest, GetCenter) {
    std::array<int, 2> a = {0, 0};
    std::array<int, 2> b = {0, 4};
    std::array<int, 2> c = {6, 4};
    std::array<int, 2> d = {6, 0};

    Rectangle rect(a, b, c, d);

    std::vector<double> center;
    rect.getCenter(center);

    ASSERT_EQ(center.size(), 2);
    EXPECT_DOUBLE_EQ(center[0], 3.0);
    EXPECT_DOUBLE_EQ(center[1], 2.0);
}

TEST(RectangleTest, AreaCalculation) {
    std::array<int, 2> a = {0, 0};
    std::array<int, 2> b = {0, 4};
    std::array<int, 2> c = {6, 4};
    std::array<int, 2> d = {6, 0};

    Rectangle rect(a, b, c, d);

    double area = static_cast<double>(rect);

    EXPECT_DOUBLE_EQ(area, 24.0);
}

TEST(TrapezoidTest, GetCenter_CorrectCoordinates) {
    std::array<int, 2> A = {0, 0};
    std::array<int, 2> B = {4, 0};
    std::array<int, 2> C = {3, 3};
    std::array<int, 2> D = {1, 3};
    Trapezoid trap(A, B, C, D);

    std::vector<double> center;
    trap.getCenter(center);

    ASSERT_EQ(center.size(), 2);
    EXPECT_NEAR(center[0], (0 + 4 + 3 + 1) / 4.0, 1e-9);
    EXPECT_NEAR(center[1], (0 + 0 + 3 + 3) / 4.0, 1e-9);
}

TEST(TrapezoidTest, AreaCalculation_CorrectArea) {
    std::array<int, 2> A = {0, 0};
    std::array<int, 2> B = {4, 0};
    std::array<int, 2> C = {3, 3};
    std::array<int, 2> D = {1, 3};
    Trapezoid trap(A, B, C, D);

    double area = static_cast<double>(trap);
    EXPECT_NEAR(area, 9.0, 1e-9);
}

TEST(FigurePolymorphismTest, StoreAndCallVirtualMethods) {
    std::vector<std::unique_ptr<Figure>> figures;

    std::array<int, 2> a = {0, 0};
    std::array<int, 2> b = {0, 2};
    std::array<int, 2> c = {2, 2};
    std::array<int, 2> d = {2, 0};

    figures.push_back(std::make_unique<Square>(a, b, c, d));
    figures.push_back(std::make_unique<Rectangle>(a, b, c, d));

    for (const auto& figure : figures) {
        std::vector<double> center;
        figure->getCenter(center);
        
        ASSERT_EQ(center.size(), 2);
        EXPECT_NEAR(center[0], 1.0, 1e-6);
        EXPECT_NEAR(center[1], 1.0, 1e-6);

        double area = static_cast<double>(*figure);
        EXPECT_GT(area, 0.0);
    }
}

TEST(AssignmentTest, SameTypeAssignment) {
    const std::array<int, 2> a1 = {0, 0};
    const std::array<int, 2> b1 = {1, 0};
    const std::array<int, 2> c1 = {1, 1};
    const std::array<int, 2> d1 = {0, 1};
    Square sq1(a1, b1, c1, d1);

    const std::array<int, 2> a2 = {2, 2};
    const std::array<int, 2> b2 = {3, 2};
    const std::array<int, 2> c2 = {3, 3};
    const std::array<int, 2> d2 = {2, 3};
    Square sq2(a2, b2, c2, d2);
    
    sq1 = sq2;
    
    std::ostringstream out;
    out << sq1;
    std::string expected = "A: {2; 2}, B: {3; 2}, C: {3; 3}, D: {2; 3}";
    EXPECT_EQ(out.str(), expected);
    
    std::ostringstream out2;
    out2 << sq2;
    std::string expected2 = "A: {2; 2}, B: {3; 2}, C: {3; 3}, D: {2; 3}";
    EXPECT_EQ(out2.str(), expected2);
}

TEST(AssignmentTest, DifferentTypeAssignment) {
    const std::array<int, 2> a_sq = {0, 0};
    const std::array<int, 2> b_sq = {1, 0};
    const std::array<int, 2> c_sq = {1, 1};
    const std::array<int, 2> d_sq = {0, 1};
    Square square(a_sq, b_sq, c_sq, d_sq);

    const std::array<int, 2> a_trap = {0, 0};
    const std::array<int, 2> b_trap = {3, 0};
    const std::array<int, 2> c_trap = {2, 2};
    const std::array<int, 2> d_trap = {1, 2};
    Trapezoid trapezoid(a_trap, b_trap, c_trap, d_trap);
    
    EXPECT_THROW({
        Figure& fig_square = square;
        const Figure& fig_trap = trapezoid;
        fig_square = fig_trap;
    }, std::invalid_argument);
    
    std::ostringstream out;
    out << square;
    std::string expected = "A: {0; 0}, B: {1; 0}, C: {1; 1}, D: {0; 1}";
    EXPECT_EQ(out.str(), expected);
}

TEST(MoveAssignmentTest, SameTypeMoveAssignment) {
    const std::array<int, 2> a1 = {0, 0};
    const std::array<int, 2> b1 = {1, 0};
    const std::array<int, 2> c1 = {1, 1};
    const std::array<int, 2> d1 = {0, 1};
    Square sq1(a1, b1, c1, d1);

    const std::array<int, 2> a2 = {2, 2};
    const std::array<int, 2> b2 = {3, 2};
    const std::array<int, 2> c2 = {3, 3};
    const std::array<int, 2> d2 = {2, 3};
    Square sq2(a2, b2, c2, d2);
    
    sq1 = std::move(sq2);
    
    std::ostringstream out;
    out << sq1;
    std::string expected = "A: {2; 2}, B: {3; 2}, C: {3; 3}, D: {2; 3}";
    EXPECT_EQ(out.str(), expected);
}

TEST(MoveAssignmentTest, DifferentTypeMoveAssignment) {
    const std::array<int, 2> a_sq = {0, 0};
    const std::array<int, 2> b_sq = {1, 0};
    const std::array<int, 2> c_sq = {1, 1};
    const std::array<int, 2> d_sq = {0, 1};
    Square square(a_sq, b_sq, c_sq, d_sq);

    const std::array<int, 2> a_trap = {0, 0};
    const std::array<int, 2> b_trap = {3, 0};
    const std::array<int, 2> c_trap = {2, 2};
    const std::array<int, 2> d_trap = {1, 2};
    Trapezoid trapezoid(a_trap, b_trap, c_trap, d_trap);
    
    Figure* fig_square = &square;
    Figure* fig_trap = &trapezoid;
    
    EXPECT_THROW({
        *fig_square = std::move(*fig_trap);
    }, std::invalid_argument);
    
    std::ostringstream out;
    out << square;
    std::string expected = "A: {0; 0}, B: {1; 0}, C: {1; 1}, D: {0; 1}";
    EXPECT_EQ(out.str(), expected);
}

TEST(MoveAssignmentTest, SelfMoveAssignment) {
    const std::array<int, 2> a = {0, 0};
    const std::array<int, 2> b = {1, 0};
    const std::array<int, 2> c = {1, 1};
    const std::array<int, 2> d = {0, 1};
    Square square(a, b, c, d);
    
    EXPECT_NO_THROW({
        square = std::move(square);
    });
    
    std::ostringstream out;
    out << square;
    EXPECT_TRUE(out.str().length() > 0);
}

TEST(MoveAssignmentTest, MoveFromTemporary) {
    const std::array<int, 2> a1 = {0, 0};
    const std::array<int, 2> b1 = {1, 0};
    const std::array<int, 2> c1 = {1, 1};
    const std::array<int, 2> d1 = {0, 1};
    Square sq1(a1, b1, c1, d1);
    
    const std::array<int, 2> temp_a = {2, 2};
    const std::array<int, 2> temp_b = {3, 2};
    const std::array<int, 2> temp_c = {3, 3};
    const std::array<int, 2> temp_d = {2, 3};
    sq1 = Square(temp_a, temp_b, temp_c, temp_d);
    
    std::ostringstream out;
    out << sq1;
    std::string expected = "A: {2; 2}, B: {3; 2}, C: {3; 3}, D: {2; 3}";
    EXPECT_EQ(out.str(), expected);
}

TEST(FigureComparisonTest, EqualAndNotEqual) {
    const std::array<int, 2> a1 = {0, 0};
    const std::array<int, 2> b1 = {1, 0};
    const std::array<int, 2> c1 = {1, 1};
    const std::array<int, 2> d1 = {0, 1};
    Square sq1(a1, b1, c1, d1);

    const std::array<int, 2> a2 = {2, 2};
    const std::array<int, 2> b2 = {3, 2};
    const std::array<int, 2> c2 = {3, 3};
    const std::array<int, 2> d2 = {2, 3};
    Square sq2(a2, b2, c2, d2);

    const std::array<int, 2> a3 = {0, 0};
    const std::array<int, 2> b3 = {2, 0};
    const std::array<int, 2> c3 = {2, 2};
    const std::array<int, 2> d3 = {0, 2};
    Square sq3(a3, b3, c3, d3);

    EXPECT_TRUE(sq1 == sq2);
    EXPECT_FALSE(sq1 != sq2);

    EXPECT_TRUE(sq1 != sq3);
    EXPECT_FALSE(sq1 == sq3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}