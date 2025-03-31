num_vertices = int(input("Ingrese el número de vértices: "))
vertices = []

for i in range(num_vertices):
    x, y, z = map(float, input(f"Ingrese las coordenadas x, y, z del vértice {i+1}: ").split())
    vertices.append((x, y, z))

num_faces = int(input("Ingrese el número de caras: "))
faces = []

for i in range(num_faces):
    face = list(map(int, input(f"Ingrese los índices de los vértices para la cara {i+1} (ejemplo: 1 2 3): ").split()))
    faces.append(face)

print("\nSalida en formato OBJ:")
for v in vertices:
    print(f"v {v[0]} {v[1]} {v[2]}")

for f in faces:
    print("f", " ".join(map(str, f)))