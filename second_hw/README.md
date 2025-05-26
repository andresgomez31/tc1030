# C++ Inheritance Project – `Smartphone`

This project is an object-oriented programming practice in C++, demonstrating the use of:

- Multiple inheritance
- Virtual methods and overloading
- Encapsulation
- Timers (`std::chrono`)
- Input/output with `std::cin` and `std::cout`

## Structure

- `Camera`: Base class with virtual method `takePicture()`
- `Computer`: Base class representing computer specifications
- `MobileDev`: Inherits from `Camera` and `Computer`, represents a mobile device
- `Smartphone`: Inherits from `MobileDev`, adds the carrier property and method overloading

## Files

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

## Compilation

### On macOS or Linux

```bash
clang++ -std=c++17 -o main main.cpp src/*.cpp
```
or
```bash
g++ -std=c++17 -o main main.cpp src/*.cpp
```

### On Windows (with MinGW or Visual Studio)

Option 1: Using MinGW (recommended if you use a terminal like Git Bash or PowerShell)

```bash
g++ -std=c++17 -o main.exe main.cpp src/*.cpp
```
Make sure you have g++ (MinGW) installed with C++17 support.

Option 2: Using Visual Studio (Developer Command Prompt)

```bash
cl /EHsc /std:c++17 main.cpp src\*.cpp
```
You need to open the "Developer Command Prompt for VS" so that cl is available.


## Execution

macOS or Linux:

```bash
./main
```
Windows (CMD or PowerShell):

```bash
main.exe
```

The program will prompt for a countdown to take a simulated photo from a smartphone.


## Requirements

C++17 compiler (or higher)

Compatible environment:

macOS/Linux: clang++, g++

Windows: g++ (MinGW) or MSVC (Visual Studio)

Terminal that accepts standard input (std::cin)

## Compatibility

This project uses only standard libraries:

<iostream>, <ctime>, <iomanip>, <sstream>, <string>, <chrono>, <thread>, <limits>

Therefore, it is compatible with Windows, macOS, and Linux, as long as a modern compiler with full C++17 support is used.

## Notes

This exercise was carried out as practice to understand multiple inheritance, the use of virtual methods, and control of input/output flow in C++.