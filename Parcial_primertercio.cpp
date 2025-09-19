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
    else   
    {
        std::cout << "Vamos a utilizar los puntos predeterminados\n";
        if (n > 0) puntos[0] = {0, 0};
        if (n > 1) puntos[1] = {3, 4};
        if (n > 2) puntos[2] = {6, 8};
        if (n > 3) puntos[3] = {9, 12};
        for (int i = 4; i < n; i++)
        {
            puntos[i] = {0, 0};
        }
    }
}


// Para hacer el calculo de la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano)
{
    double distanciaMinima = calcularDistancia(pUsuario, puntos[0]);
    indiceMasCercano = 0;

    for (int i = 1; i < n; i++)
    {
        double d = calcularDistancia(pUsuario, puntos[i]);
        if (d < distanciaMinima)
        {
            distanciaMinima = d;
            indiceMasCercano = i;
        }
    }
    return distanciaMinima;
}

// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia)
{
    std::cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

// BONO: distancia total de los puntos recorridos en orden
double distanciaTotal(Point puntos[], int n)
{
    double total = 0;
    for (int i = 0; i < n - 1; i++)
    {
        total += calcularDistancia(puntos[i], puntos[i + 1]);
    }
    return total;
}

int main()
{
    int n;

    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    std::cin >> n;

    if (n < 2)
    {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    Point puntos[n];
    // Leer los punntos (manual o predeterminado)
    leerPuntos(puntos, n);
    // Ingresar el punto del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    // Calcular la distancia más cercana
    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    // Mostrar el resultado
    mostrarResultado(puntos, indiceMasCercano, distancia);


    double total = distanciaTotal(puntos, n);
    std::cout << "La distancia total recorrida al pasar por los puntos en orden es: " << total << std::endl;

    return 0;
}