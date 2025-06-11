// File: DB.cpp

#include "DB.hpp"

DB::DB(std::string path) 
    : path(path), media(path + "/media.csv"), reviews(path + "/reviews.csv") {}

DB::~DB() {
    delete &media;
    delete &reviews;
}