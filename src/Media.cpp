// File: src/Media.cpp

#include "Media.hpp"

// Constructor
Media::Media(
    std::string& id,
    std::string& title,
    std::string& duration,
    std::string& genre,
    std::string& rate
) : id(id), title(title), duration(duration), genre(genre), rate(rate) {}

// Getters
const std::string& Media::get_id() const { return this->id; }
const std::string& Media::get_title() const { return this->title; }
const std::string& Media::get_duration() const { return this->duration; }
const std::string& Media::get_genre() const { return this->genre; }
const std::string& Media::get_rate() const { return this->rate; }

// Setters
void Media::set_rate(std::string rate) { this->rate = rate; }

Media::~Media() {}