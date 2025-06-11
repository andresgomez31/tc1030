// File: Media.cpp

#include "Media.hpp"
#include <stdexcept>

Media::Media(
    const std::string& type,
    const std::string& id,
    const std::string& title,
    const std::string& duration,
    const std::string& category,
    const std::string& rate = "SC"
) : type(type), id(id), title(title), duration(duration), category(category), rate(rate) {}

// Getters
const std::string Media::get_type() const { return type; }
const std::string Media::get_id() const { return id; }
const std::string Media::get_title() const { return title; }
const std::string Media::get_duration() const { return duration; }
const std::string Media::get_category() const { return category; }
const std::string Media::get_rate() const { return rate; }

// Update rating of media object
void Media::update_rate(float new_rate) {
    if (new_rate < 0) {
        throw std::invalid_argument("Rating cannot be negative.");
    }
    else if (new_rate > 5) {
        throw std::invalid_argument("Rating cannot be greater than 5.");
    }
    rate = std::to_string(new_rate);
}

// Updaters
void Media::update_title(std::string new_title) { this->title = new_title; }
void Media::update_duration(std::string new_duration) { this->duration = new_duration; }
void Media::update_category(std::string new_category) { this->category = new_category; }
