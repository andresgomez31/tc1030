// File: src/Chapter.hpp

#pragma once

#include "Media.hpp"

class Chapter : public Media {
    private:
        std::string series_title, chapter;

    public:
        Chapter(
            std::string& id, 
            std::string& title,
            std::string& duration,
            std::string& genre,
            std::string& series_title,
            std::string& chapter,
            std::string& rate
        );

        // Getters
        const std::string& get_series_title() const;
        const std::string& get_chapter() const;

        // No setters needed.

        // Parse to string
        std::string to_string() const override;

        // Parse to csv
        std::string to_csv() const override;

        // Destructor
        ~Chapter();
};