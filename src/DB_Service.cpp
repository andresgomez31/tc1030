#include "DB_Service.hpp"

DB_Service::DB_Service(std::string path) : path(path) {}

bool DB_Service::path_is_ok() const {
    return std::filesystem::exists(path);
}

std::vector<std::string> DB_Service::read_CSV() const {
    std::vector<std::string> result;

    if (!path_is_ok()) {
        throw std::runtime_error("File not found");
    }
    
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file. ");
    }

    std::string line;
    while(std::getline(file, line)) {
        if (!line.empty()) {
            result.push_back(line);
        }
    }

    file.close();
    return result;
}
