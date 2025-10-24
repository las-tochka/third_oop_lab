#include "Figure.hpp"
#include "Square.hpp"
#include <iostream>
#include <memory>
#include <vector>

#include "Figure.hpp"
#include "Square.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include "functions.cpp"

int main() {
    auto figures = createFigures();
    printFigures(figures, "Исходный массив фигур");

    auto copied = copyFigures(figures);
    printFigures(copied, "Копия");

    auto moved = moveFigures(copied);
    printFigures(moved, "Массив после перемещения");

    double totalArea = getTotalArea(figures);
    cout << "\nОбщая площадь всех фигур: " << totalArea << "\n";

    double expected = static_cast<double>(*figures[0]) + static_cast<double>(*figures[1]);
    if (std::abs(totalArea - expected) < 1e-6)
        cout << "Площадь верно вычислена.\n";
    else
        cout << "Площадь неверна.\n";

    printFigures(figures, "До удаления");
    removeFigureByIndex(figures, 0);
    printFigures(figures, "После удаления");

    return 0;
}
