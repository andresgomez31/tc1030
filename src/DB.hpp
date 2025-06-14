// File: src/DB.hpp

#pragma once

#include "functions.hpp"

class DB {
    private:
        // Path for data csv
        std::string csv_path;

    public:
        // Data and indexes
        std::vector<Media*> data;
        std::unordered_map<std::string, std::vector<float>> rates;
        std::unordered_map<std::string, Media*> id_indexes;
        std::unordered_map<std::string, std::vector<Media*>> genre_indexes;
        std::unordered_map<std::string, float> rate_indexes;

        // Constructor
        DB(std::string& csv_path);

        // Destructor
        ~DB();
};