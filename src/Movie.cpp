// File: Movie.cpp

#include <sstream>
#include "Movie.hpp"

Movie::Movie(
    const std::string& id,
    const std::string& title,
    const std::string& duration,
    const std::string& category,
    const std::string& rate
) : Media("Movie", id, title, duration, category, rate) {}

// Parse from Movie to CSV;
std::string Movie::to_CSV() const {
    std::stringstream result;

    result  << "c" << ","
            << get_id() << ","
            << get_title() << ","
            << get_duration() << ","
            << get_category() << ","
            << get_rate() << ",";

    return result.str();
}

// Parse from Movie to string
std::string Movie::to_string() const {
    std::stringstream result;

    result  << "Media ID: " << get_id() << "\n"
            << "Title: " << get_title()
            << "Duration: " << get_duration() << "\n"
            << "Category: " << get_category() << "\n" 
            << "Rating: " << get_rate();

    return result.str();
}