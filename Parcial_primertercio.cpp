#include <iostream>
#include <cmath>

// Defino Double para almacenar coordenadas (x, y)
struct Point {
    double x, y;
};

// Función para calcular la distancia entre dos puntos.
double calcularDistancia(const Point &p1, const Point &p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}

