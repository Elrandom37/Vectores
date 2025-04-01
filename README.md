# Vectores Giovanni antolinez y Duban Vargas
# README - Registro de Vértices y Caras en C++ y Python

Este proyecto permite registrar vértices y caras de una figura geométrica utilizando arreglos. Se proporciona un menú interactivo en C++ y una versión en Python para facilitar la entrada de datos y la generación de un modelo en formato OBJ.

## Descripción del código

El programa maneja dos estructuras principales:
- **Vértices**: Representados por coordenadas (x, y, z).
- **Caras**: Definidas por un conjunto de índices que hacen referencia a los vértices.

El usuario puede:
1. **Registrar un vértice**: Ingresar coordenadas (x, y, z).
2. **Registrar una cara**: Especificar los vértices que la componen.
3. **Mostrar vértices y caras**: Visualizar la información almacenada.
4. **Generar salida en formato OBJ**: Exportar los datos en un formato compatible con software de modelado 3D.
5. **Salir**: Terminar la ejecución del programa (en C++).

## Instrucciones para ejecutar el programa

### Ejecución en C++

1. Guardar el siguiente código en un archivo `figura.cpp`:
   ```cpp
   #include <iostream>
   using namespace std;

   int main() {
       const int MAX_VERTICES = 100;
       const int MAX_FACES = 50;
       const int MAX_FACE_SIZE = 10;

       float vertices[MAX_VERTICES][3];
       int faces[MAX_FACES][MAX_FACE_SIZE];
       int face_sizes[MAX_FACES];
       int num_vertices = 0, num_faces = 0;

       int opcion;
       do {
           cout << "\nMenú:\n";
           cout << "1. Ingresar vértices\n";
           cout << "2. Ingresar caras\n";
           cout << "3. Mostrar datos\n";
           cout << "4. Generar salida en formato OBJ\n";
           cout << "5. Salir\n";
           cout << "Seleccione una opción: ";
           cin >> opcion;

           switch (opcion) {
               case 1:
                   cout << "Ingrese el número de vértices: ";
                   cin >> num_vertices;
                   for (int i = 0; i < num_vertices; i++) {
                       cout << "Ingrese las coordenadas x, y, z del vértice " << (i + 1) << ": ";
                       cin >> vertices[i][0] >> vertices[i][1] >> vertices[i][2];
                   }
                   break;
               case 2:
                   cout << "Ingrese el número de caras: ";
                   cin >> num_faces;
                   for (int i = 0; i < num_faces; i++) {
                       cout << "Ingrese la cantidad de vértices de la cara " << (i + 1) << ": ";
                       cin >> face_sizes[i];
                       cout << "Ingrese los índices de los vértices de la cara: ";
                       for (int j = 0; j < face_sizes[i]; j++) {
                           cin >> faces[i][j];
                       }
                   }
                   break;
               case 3:
                   cout << "\nVértices ingresados:\n";
                   for (int i = 0; i < num_vertices; i++) {
                       cout << "v " << vertices[i][0] << " " << vertices[i][1] << " " << vertices[i][2] << endl;
                   }
                   cout << "\nCaras ingresadas:\n";
                   for (int i = 0; i < num_faces; i++) {
                       cout << "f";
                       for (int j = 0; j < face_sizes[i]; j++) {
                           cout << " " << faces[i][j];
                       }
                       cout << endl;
                   }
                   break;
               case 4:
                   cout << "\nSalida en formato OBJ:\n";
                   for (int i = 0; i < num_vertices; i++) {
                       cout << "v " << vertices[i][0] << " " << vertices[i][1] << " " << vertices[i][2] << endl;
                   }
                   for (int i = 0; i < num_faces; i++) {
                       cout << "f";
                       for (int j = 0; j < face_sizes[i]; j++) {
                           cout << " " << faces[i][j];
                       }
                       cout << endl;
                   }
                   break;
               case 5:
                   cout << "Saliendo...\n";
                   break;
               default:
                   cout << "Opción no válida. Intente nuevamente.\n";
           }
       } while (opcion != 5);

       return 0;
   }
   ```

2. Compilar y ejecutar el programa:
   ```sh
   g++ figura.cpp -o figura && ./figura
   ```

### Explicación del menú

1. **Ingresar vértices**: Permite al usuario ingresar las coordenadas de los vértices.
2. **Ingresar caras**: El usuario define las caras de la figura usando los índices de los vértices ingresados.
3. **Mostrar datos**: Muestra los vértices y caras ingresadas hasta el momento.
4. **Generar salida en formato OBJ**: Exporta los datos en un formato compatible con software de modelado 3D.
5. **Salir**: Finaliza la ejecución del programa.

### Ejecución en Python

1. Guardar el siguiente código en un archivo `figura.py`:
   ```python
   python figura.py
   ```

2. Ejecutar el programa:
   ```sh
   python figura.py
   ```

## Consideraciones

- **Límites de datos**: En C++, el número máximo de vértices es 100 y el de caras es 50.
- **Errores de entrada**: Se han agregado controles para evitar valores fuera de rango.
- **Formato OBJ**: La salida puede copiarse en un archivo `.obj` para ser utilizado en software de modelado 3D.

