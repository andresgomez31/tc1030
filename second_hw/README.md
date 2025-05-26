# C++ Inheritance Project – `Smartphone`

Este proyecto es una práctica de programación orientada a objetos en C++, que demuestra el uso de:

- Herencia múltiple
- Métodos virtuales y sobrecarga
- Encapsulamiento
- Temporizadores (`std::chrono`)
- Entrada/salida con `std::cin` y `std::cout`

## Estructura

- `Camera`: Clase base con método virtual `takePicture()`
- `Computer`: Clase base que representa especificaciones de una computadora
- `MobileDev`: Hereda de `Camera` y `Computer`, representa un dispositivo móvil
- `Smartphone`: Hereda de `MobileDev`, agrega la propiedad de carrier y sobrecarga de métodos

## Archivos

```text
second_hw/
│
├── main.cpp
├── src/
│   ├── Camera.cpp
│   ├── Camera.hpp
│   ├── Computer.cpp
│   ├── Computer.hpp
│   ├── MobileDev.cpp
│   ├── MobileDev.hpp
│   ├── Smartphone.cpp
│   └── Smartphone.hpp
└── README.md
```

## Compilación

### En macOS o Linux

```bash
clang++ -std=c++17 -o main main.cpp src/*.cpp
```
o 
```bash
g++ -std=c++17 -o main main.cpp src/*.cpp
```

### En Windows (con MinGW o Visual Studio)

Opción 1: Usando MinGW (recomendado si usas terminal como Git Bash o PowerShell)

```bash
g++ -std=c++17 -o main.exe main.cpp src/*.cpp
```
Asegúrate de tener instalado g++ (MinGW) con soporte para C++17.

Opción 2: Usando Visual Studio (Developer Command Prompt)

```bash
cl /EHsc /std:c++17 main.cpp src\*.cpp
```
Necesitas abrir el "Developer Command Prompt for VS" para que cl esté disponible.


## Ejecución

macOS o Linux:

```bash
./main
```
Windows (CMD o PowerShell)

```bash
main.exe
```

El programa pedirá una cuenta regresiva para tomar una foto simulada desde un smartphone.


## Requisitos

Compilador C++17 (o superior)

Entorno compatible:

macOS/Linux: clang++, g++

Windows: g++ (MinGW) o MSVC (Visual Studio)

Terminal que acepte entrada estándar (std::cin)

## Compatibilidad

Este proyecto usa solo librerías estándar:

<iostream>, <ctime>, <iomanip>, <sstream>, <string>, <chrono>, <thread>, <limits>

Por tanto, es compatible con Windows, macOS y Linux, siempre que se use un compilador moderno que implemente C++17 completamente.

## Notas

Este ejercicio fue realizado como práctica para comprender la herencia múltiple, el uso de métodos virtuales y el control del flujo de entrada/salida en C++.