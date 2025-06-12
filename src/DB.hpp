// File: DB.hpp

#pragma once

#include "DB_Media.hpp"
#include "DB_Reviews.hpp"

class DB {
    private:
        std::string path;
        
    public:
        // Constructor
        DB(std::string path);

        DB_Media media;
        DB_Reviews reviews;

        // Destructor
        ~DB();
};