// File: src/Chapter.cpp

#include "Chapter.hpp"

Chapter::Chapter(
    std::string& id, 
    std::string& title,
    std::string& duration,
    std::string& genre,
    std::string& series_title,
    std::string& chapter,
    std::string& rate
) : Media(id, title, duration, genre, rate), series_title(series_title), chapter(chapter) {}

// Getters
const std::string& Chapter::get_series_title() const { return this->series_title; }
const std::string& Chapter::get_chapter() const { return this->chapter; }

// No setters needed

// Parse to string
std::string Chapter::to_string() const {
    std::stringstream chapter;
    chapter << "ID: " << get_id() << "\n"
            << "Title: " << get_title() << "\n"
            << "Duration: " << get_duration() << "\n"
            << "Genre: " << get_genre() << "\n"
            << "Series title: " << get_series_title() << "\n"
            << "Chapter No. " << get_chapter() << "\n"
            << "Rate: " << get_rate() << "\n";
    return chapter.str(); 
}

// Parse to csv string format
std::string Chapter::to_csv() const {
    std::stringstream chapter;
    chapter << "c,"
            << get_id() << ","
            << get_title() << ","
            << get_duration() << ","
            << get_genre() << ","
            << get_series_title() << ","
            << get_chapter() << ","
            << get_rate();
    return chapter.str();
}

// Destructor
Chapter::~Chapter() {}