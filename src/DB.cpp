// File: src/DB.cpp

#include "DB.hpp"

DB::DB(std::string& csv_path) : csv_path(csv_path) {
    std::vector<std::string> csv_lines = read_csv(this->csv_path);
    for (const std::string& line : csv_lines) {
        this->data.push_back(instance_media(line));
    }

    /**
     * for loops can be reduced from 3 to 1 by agrouping all the 
     * index creations on a single loop, but for readability, I 
     * choose this way.
     */
    this->id_indexes = create_id_indexes(this->data);
    this->genre_indexes = create_genre_indexes(this->data);
    this->rate_indexes = create_rate_indexes(this->data);
}

DB::~DB() {
    for (Media* media : this->data) {
        delete media;
    }
    this->data.clear();
    this->id_indexes.clear();
    this->genre_indexes.clear();
    this->rate_indexes.clear();
}
