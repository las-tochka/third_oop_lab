#include "Figure.hpp"
#include "Square.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <string>

using std::vector;
using std::shared_ptr;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::array;
using std::make_shared;

double getTotalArea(const vector<shared_ptr<Figure>>& figures) {
    double total = 0.0;
    for (const auto& fig : figures) {
        total += static_cast<double>(*fig);
    }
    return total;
}

void removeFigureByIndex(vector<shared_ptr<Figure>>& figures, size_t index) {
    if (index >= figures.size()) {
        cerr << "Ошибка: индекс " << index << " вне диапазона." << endl;
        return;
    }
    figures.erase(figures.begin() + index);
    cout << "Фигура с индексом " << index << " удалена.\n" << endl;
}

vector<shared_ptr<Figure>> createFigures() {
    vector<shared_ptr<Figure>> figures;

    const array<int, 2> a1 = {0, 0};
    const array<int, 2> b1 = {1, 0};
    const array<int, 2> c1 = {1, 1};
    const array<int, 2> d1 = {0, 1};

    const array<int, 2> a2 = {2, 2};
    const array<int, 2> b2 = {4, 2};
    const array<int, 2> c2 = {4, 4};
    const array<int, 2> d2 = {2, 4};

    figures.push_back(make_shared<Square>(a1, b1, c1, d1));
    figures.push_back(make_shared<Square>(a2, b2, c2, d2));

    return figures;
}

void printFigures(const vector<shared_ptr<Figure>>& figures, const string& title) {
    cout << "\n--- " << title << " ---" << endl;
    for (size_t i = 0; i < figures.size(); ++i) {
        vector<double> center;
        figures[i]->getCenter(center);
        cout << "Фигура " << i << ": Центр (" << center[0] << ", " << center[1]
             << "), Площадь: " << static_cast<double>(*figures[i]) << endl;
    }
}

vector<shared_ptr<Figure>> copyFigures(const vector<shared_ptr<Figure>>& figures) {
    return figures;
}

vector<shared_ptr<Figure>> moveFigures(vector<shared_ptr<Figure>>& figures) {
    return std::move(figures);
}
