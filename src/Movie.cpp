// File: src/Movie.cpp

#include "Movie.hpp"

Movie::Movie(
    std::string id, 
    std::string title,
    std::string duration,
    std::string genre,
    std::string rate
) : Media(id, title, duration, genre, rate) {}

// Parse to string
std::string Movie::to_string() const {
    std::stringstream movie;
    movie   << "ID: " << get_id() << "\n"
            << "Title: " << get_title() << "\n"
            << "Duration: " << get_duration() << "\n"
            << "Genre: " << get_genre() << "\n"
            << "Rate: " << get_rate() << "\n";
    return movie.str(); 
}

// Parse to csv string format
std::string Movie::to_csv() const {
    std::stringstream movie;
    movie   << "p,"
            << get_id() << ","
            << get_title() << ","
            << get_duration() << ","
            << get_genre() << ","
            << get_rate();
    return movie.str();
}

Movie::~Movie() {}