#include <iostream> 
#include <cmath>


/*

пример:
𝑓(2.5) = 2sin⁡(2.5)−arctan⁡(2.5)

𝑓(2.6) = 2sin⁡(2.6)−arctan⁡(2.6)

𝑓(2.5)≈2×0.5984−1.1659≈1.0309

𝑓(2.6)≈2×0.5150−1.1659≈−0.1359

*/

 

double f(double x) {
    return 2 * sin(x) - atan(x);
}

double bisection(double a, double b, double tol) {


    double c;

    if (f(a) * f(b) >= 0) {
        std::cerr << "Некорректный интервал [a, b]: f(a) * f(b) должно быть < 0" << std::endl;// Неопред значение
        return NAN;
    }

    while ((b - a) / 2.0 > tol) {// середина
        c = (a + b) / 2.0;

        if (f(c) == 0.0) // c — корень 
            return c;

        if (f(c) * f(a) < 0) // Корень в [a, c] 
            b = c;
        else // Корень в [c, b] 
            a = c;
    }

    return (a + b) / 2.0; // Возвр среднего значения как приближ корень 
}

int main() {
    setlocale(LC_ALL, "ru");
    double a = 2.5;
    double b = 2.6;
    double tolerance = 0.001;

    double root = bisection(a, b, tolerance);

    if (!std::isnan(root))
        std::cout << "Корень уравнения: " << root << std::endl;

    return 0;
}
