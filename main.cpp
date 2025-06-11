#include "menu.hpp"
#include "src/DB.hpp"
#include <iostream>

int main() {
    std::string path = "data/";
    DB db(path);

    try {
        menu(db);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}