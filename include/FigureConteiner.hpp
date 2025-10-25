#pragma once
#include "Figure.hpp"
#include <array>
#include <memory>
#include <iostream>
#include <string>

template <size_t N>
class FigureContainer {
public:
    using FigurePtr = std::shared_ptr<Figure>;
    using ContainerType = std::array<FigurePtr, N>;

private:
    ContainerType figures_{};

public:
    FigureContainer() = default;

    void set(size_t index, FigurePtr fig) {
        if (index >= N) {
            std::cerr << "Ошибка: индекс " << index << " вне диапазона.\n";
            return;
        }
        figures_[index] = std::move(fig);
    }

    void remove(size_t index) {
        if (index >= N) {
            std::cerr << "Ошибка: индекс " << index << " вне диапазона.\n";
            return;
        }
        figures_[index].reset();
        std::cout << "Фигура с индексом " << index << " удалена.\n";
    }

    FigurePtr get(size_t index) const {
        if (index >= N) return nullptr;
        return figures_[index];
    }

    double totalArea() const {
        double total = 0.0;
        for (const auto& f : figures_) {
            if (f) total += static_cast<double>(*f);
        }
        return total;
    }

    void print(const std::string& title = "Фигуры") const {
        std::cout << "\n--- " << title << " ---\n";
        for (size_t i = 0; i < N; ++i) {
            if (figures_[i]) {
                std::vector<double> center;
                figures_[i]->getCenter(center);
                std::cout << "Фигура " << i << ": Центр (" 
                          << center[0] << ", " << center[1]
                          << "), Площадь: " << static_cast<double>(*figures_[i]) << "\n";
            } else {
                std::cout << "Фигура " << i << ": отсутствует\n";
            }
        }
    }

    ContainerType getAll() const {
        return figures_;
    }

    FigureContainer moveOut() {
        FigureContainer tmp = std::move(*this);
        return tmp;
    }
};
