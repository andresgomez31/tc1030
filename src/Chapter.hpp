// File: Chapter.hpp

#pragma once

#include "Media.hpp"

class Chapter : public Media {
    private:
        std::string series_title;
        std::string chapter;
        
    public:
        // Constructor
        Chapter(
            const std::string& id,
            const std::string& title,
            const std::string& duration,
            const std::string& category, 
            const std::string& series_title,
            const std::string& chapter,
            const std::string& rate = "SC"
        );

        // Getters
        const std::string& get_series_title() const;
        const std::string& get_chapter() const;

        // Parse from Chapter object to CSV
        std::string to_CSV() const;

        // Parse from Chapter object to string
        std::string to_string() const override;

        // Not asked for this methods.
        void update_series_title(const std::string& new_series_title);
        void update_chapter(const std::string& new_chapter);
};