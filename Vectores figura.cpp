#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;
const int MAX_CARAS = 100;

struct Vertice {
    float x, y, z;
};

struct Cara {
    int indices[MAX_VERTICES];
    int numVertices;
};

Vertice vertices[MAX_VERTICES];
Cara caras[MAX_CARAS];
int numVertices = 0, numCaras = 0;

void registrarVertice() {
    if (numVertices >= MAX_VERTICES) {
        cout << "Límite de vértices alcanzado." << endl;
        return;
    }
    cout << "Ingrese coordenadas x, y, z: ";
    cin >> vertices[numVertices].x >> vertices[numVertices].y >> vertices[numVertices].z;
    numVertices++;
}

void registrarCara() {
    if (numCaras >= MAX_CARAS) {
        cout << "Límite de caras alcanzado." << endl;
        return;
    }
    cout << "Ingrese número de vértices en la cara: ";
    cin >> caras[numCaras].numVertices;
    if (caras[numCaras].numVertices > numVertices) {
        cout << "Error: Hay menos vértices registrados." << endl;
        return;
    }
    cout << "Ingrese los índices de los vértices: ";
    for (int i = 0; i < caras[numCaras].numVertices; i++) {
        cin >> caras[numCaras].indices[i];
    }
    numCaras++;
}

void imprimirFigura() {
    cout << "Vértices:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << i << ": (" << vertices[i].x << ", " << vertices[i].y << ", " << vertices[i].z << ")\n";
    }
    cout << "Caras:\n";
    for (int i = 0; i < numCaras; i++) {
        cout << "Cara " << i << ": ";
        for (int j = 0; j < caras[i].numVertices; j++) {
            cout << caras[i].indices[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "\n1. Registrar Vértice\n2. Registrar Cara\n3. Imprimir Figura\n4. Salir\nOpción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: registrarVertice(); break;
            case 2: registrarCara(); break;
            case 3: imprimirFigura(); break;
            case 4: cout << "Saliendo..." << endl; break;
            default: cout << "Opción inválida." << endl;
        }
    } while (opcion != 4);
    return 0;
}
    