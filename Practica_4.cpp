#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    int x, y;
};

int orientacion(Punto p, Punto q, Punto r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool enSegmento(Punto p, Punto q, Punto r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

int Se_Cruzan(Punto p1, Punto q1, Punto p2, Punto q2) {
    int o1 = orientacion(p1, q1, p2);
    int o2 = orientacion(p1, q1, q2);
    int o3 = orientacion(p2, q2, p1);
    int o4 = orientacion(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return 1;
    if (o1 == 0 && enSegmento(p1, p2, q1)) return 1;
    if (o2 == 0 && enSegmento(p1, q2, q1)) return 1;
    if (o3 == 0 && enSegmento(p2, p1, q2)) return 1;
    if (o4 == 0 && enSegmento(p2, q1, q2)) return 1;
    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) return 0;

    double m1 = (double)(q1.y - p1.y) / (q1.x - p1.x);
    double m2 = (double)(q2.y - p2.y) / (q2.x - p2.x);
    if (fabs(m1 - m2) < 1e-9 || (isinf(m1) && isinf(m2))) return 0;

    return -1;
}

int Angulo_Linea(Punto p1, Punto q1, bool enGrados = false) {
    int angulo;
    if (p1.x == q1.x || p1.y == q1.y) {
        angulo = 0;
    } else {
        angulo = atan2(q1.y - p1.y, q1.x - p1.x);
    }
    if (enGrados) {
        angulo = angulo * 180 / M_PI;
    }
    return angulo;
}

int Angulo_Cruce(Punto p1, Punto q1, Punto p2, Punto q2, bool enGrados = false) {
    int m1 = atan2(q1.y - p1.y, q1.x - p1.x);
    int m2 = atan2(q2.y - p2.y, q2.x - p2.x);
    int angulo = fabs(m1 - m2);

    if (enGrados) {
        angulo = angulo * 180 / M_PI;
    }

    return angulo;
}

int contadorLlamadas = 0;

void procesoCualquiera(int angulo1, int angulo2) {
    int suma = angulo1 + angulo2;
    cout << "Suma de los angulos de las lineas: " << suma << " grados" << endl;
    contadorLlamadas++;
}

int Llamadas() {
    return contadorLlamadas;
}

int main() {
    Punto p1, q1, p2, q2;
    char opcion;

    cout << "Introduce las coordenadas del primer punto de la primera linea (x y): ";
    cin >> p1.x >> p1.y;
    cout << "Introduce las coordenadas del segundo punto de la primera linea (x y): ";
    cin >> q1.x >> q1.y;

    cout << "Introduce las coordenadas del primer punto de la segunda linea (x y): ";
    cin >> p2.x >> p2.y;
    cout << "Introduce las coordenadas del segundo punto de la segunda linea (x y): ";
    cin >> q2.x >> q2.y;

    int resultado = Se_Cruzan(p1, q1, p2, q2);
    cout << "Resultado: " << resultado << endl;

    int angulo1_rad = Angulo_Linea(p1, q1, false);
    cout << "Angulo de la primera linea: " << angulo1_rad << " radianes" << endl;

    int angulo2_rad = Angulo_Linea(p2, q2, false);
    cout << "Angulo de la segunda linea: " << angulo2_rad << " radianes" << endl;

    if (resultado == 1) {
        int anguloInterseccion_rad = Angulo_Cruce(p1, q1, p2, q2, false);
        cout << "Angulo en el punto de cruce: " << anguloInterseccion_rad << " radianes" << endl;
    }

    cout << "Deseas los angulos en grados? (s/n): ";
    cin >> opcion;
    int angulo1_deg, angulo2_deg;
    if (opcion == 's' || opcion == 'S') {
        angulo1_deg = Angulo_Linea(p1, q1, true);
        cout << "Angulo de la primera linea: " << angulo1_deg << " grados" << endl;

        angulo2_deg = Angulo_Linea(p2, q2, true);
        cout << "Angulo de la segunda linea: " << angulo2_deg << " grados" << endl;

        if (resultado == 1) {
            int anguloInterseccion_deg = Angulo_Cruce(p1, q1, p2, q2, true);
            cout << "Angulo en el punto de cruce: " << anguloInterseccion_deg << " grados" << endl;
        }
    }

    do {
        procesoCualquiera(angulo1_deg, angulo2_deg);
        cout << "Deseas seguir sumando los angulos? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    cout << "La funcion procesoCualquiera fue llamada " << Llamadas() << " veces." << endl;

    return 0;
}