// File: src/Movie.hpp

#include "Media.hpp"

class Movie : public Media {
    public:
        // Constructor
        Movie(
            std::string id, 
            std::string title,
            std::string duration,
            std::string genre,
            std::string rate
        );

        // Parse to string
        std::string to_string() const override;

        // Parse to csv
        std::string to_csv() const override;

        // Destructor
        ~Movie();
};