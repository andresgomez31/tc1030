// File: DB_Service.hpp

#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include "Media.hpp"

class DB_Service {
    private:
        std::string path;

    protected:
        DB_Service(std::string path);

        bool path_is_ok() const;

        std::vector<std::string> read_CSV() const;
        virtual void load_data() = 0;

        virtual ~DB_Service() = default;
};