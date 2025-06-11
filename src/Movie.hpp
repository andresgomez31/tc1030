// File: Movie.hpp

#pragma once

#include "Media.hpp"

class Movie : public Media {
    public:
        // Constructor
        Movie(
            const std::string& id, 
            const std::string& title, 
            const std::string& duration, 
            const std::string& category, 
            const std::string& rate = "SC"
        );

        // Parse from Movie object to CSV
        std::string to_CSV() const;

        // Parse from Movie object to string
        std::string to_string() const override;
};