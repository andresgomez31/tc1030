// File: Chapter.cpp

#include <sstream>
#include "Chapter.hpp"

Chapter::Chapter(
    const std::string& id,
    const std::string& title,
    const std::string& duration,
    const std::string& category, 
    const std::string& series_title,
    const std::string& chapter,
    const std::string& rate
) : Media("Chapter", id, title, duration, category, rate), series_title(series_title), chapter(chapter) {}

// Getters
const std::string& Chapter::get_series_title() const { return series_title; }
const std::string& Chapter::get_chapter() const { return chapter; }

// Updaters
void Chapter::update_series_title(const std::string& new_series_title) { this->series_title = new_series_title; }
void Chapter::update_chapter(const std::string& new_chapter) { this->chapter = new_chapter; }

// Parse from Chapter to CSV;
std::string Chapter::to_CSV() const {
    std::stringstream result;

    result  << "c" << ","
            << get_id() << ","
            << get_title() << ","
            << get_duration() << ","
            << get_category() << ","
            << get_series_title() << ","
            << get_chapter << ","
            << get_rate() << ",";

    return result.str();
}

// Parse from Chapter to string
std::string Chapter::to_string() const {
    std::stringstream result;

    result  << "Media ID: " << get_id() << "\n"
            << "Title: " << get_title()
            << "Duration: " << get_duration() << "\n"
            << "Category: " << get_category() << "\n" 
            << "Series Name: " << get_series_title() << "\n"
            << "Chapter Number: " << get_chapter() << "\n" 
            << "Rating: " << get_rate();

    return result.str();
}