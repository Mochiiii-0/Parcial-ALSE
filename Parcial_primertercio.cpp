#include <iostream>
#include <cmath>

// Defino Double para almacenar coordenadas (x, y)
struct Point {
    double x, y;
};

// Función para calcular la distancia entre dos puntos.
double calcularDistancia(const Point &p1, const Point &p2)
{
    //formula de distancia euclidiana 
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}

void leerPuntos(Point puntos[], int n)
{
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S')
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    }
}

else
{
    {
        std::cout << "Usando puntos predeterminados...\n";
        if (n > 0) puntos[0] = {0, 0};
        if (n > 1) puntos[1] = {3, 4};
        if (n > 2) puntos[2] = {6, 8};
        if (n > 3) puntos[3] = {9, 12};
        // El resto se inicializa en (0,0) para evitar basura
        for (int i = 4; i < n; i++)
        {
            puntos[i] = {0, 0};
        }
    }
}

