// File: Media.hpp

#pragma once

#include <string>

class Media {
    private:
        std::string type, id, title, duration, category, rate;

    public:
        // Constructor
        Media(
            const std::string& type,
            const std::string& id,
            const std::string& title,
            const std::string& duration,
            const std::string& category,
            const std::string& rate = "SC"
        );

        // Getters
        const std::string get_type() const;
        const std::string get_id() const;
        const std::string get_title() const;
        const std::string get_duration() const;
        const std::string get_category() const;
        const std::string get_rate() const;

        // Parse from Media subclass to CSV
        virtual std::string to_CSV() const = 0;

        // Parse from Media subclass to string
        virtual std::string to_string() const = 0;

        // Update the rating
        void update_rate(float rate);

        // Not asked for this methods.
        void update_title(std::string new_title);
        void update_duration(std::string new_duration);
        void update_category(std::string new_category);

        virtual ~Media();
};