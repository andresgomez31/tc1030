// File: src/functions.hpp

#pragma once

#include "Media.hpp"
#include "Chapter.hpp"
#include "Movie.hpp"
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <stdexcept>

// Read csv default function. Returns a vector of lines.
std::vector<std::string> read_csv(std::string path);

// Create the corresponding media object from a csv line.
Media* instance_media(std::string csv_line);

// Create indexes by ID
std::unordered_map<std::string, Media*> create_id_indexes(std::vector<Media*> data);

// Create indexes by Genre
std::unordered_map<std::string, std::vector<Media*>> create_genre_indexes(std::vector<Media*> data);

// Create indexes by Rating
std::unordered_map<std::string, float> create_rate_indexes(std::vector<Media*> data);