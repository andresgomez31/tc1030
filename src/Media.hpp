// File: src/Media.hpp

#pragma once

#include <string>
#include <sstream>

class Media {
    private: 
        std::string id, title, duration, genre, rate;

    public:
        // Constructor
        Media(
            std::string& id, 
            std::string& title,
            std::string& duration,
            std::string& genre,
            std::string& rate
        );

        // Getters
        const std::string& get_id() const;
        const std::string& get_title() const;
        const std::string& get_duration() const;
        const std::string& get_genre() const;
        const std::string& get_rate() const;

        // Setters
        // Only need set_rate();
        void set_rate(std::string rate);

        // Parse to string
        virtual std::string to_string() const = 0;

        // Parse to csv string format
        virtual std::string to_csv() const = 0;

        // Destructor;
        virtual ~Media();
};