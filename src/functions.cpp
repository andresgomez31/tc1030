// File: src/functions.cpp

#include "functions.hpp"

std::vector<std::string> read_csv(std::string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error ("Cannot open file on " + path);
    }
    std::string line;
    std::vector<std::string> result;
    while(std::getline(file, line)) result.push_back(line);

    return result;
}

Media* instance_media(std::string csv_line) {
    std::stringstream ss(csv_line);
    std::string type, id, title, duration, genre, rate;

    std::getline(ss, type, ',');
    std::getline(ss, id, ',');
    std::getline(ss, title, ',');
    std::getline(ss, duration, ',');
    std::getline(ss, genre, ',');

    if (type == "p") {
        if (!std::getline(ss, rate, ',')) {
            rate = "SC";
        }
        return new Movie(id, title, duration, genre, rate);
    }
    else if (type == "c") {
        std::string series_title, chapter;
        std::getline(ss, series_title, ',');
        std::getline(ss, chapter, ',');
        if (!std::getline(ss, rate, ',')) {
            rate = "SC";
        }
        return new Chapter(id, title, duration, genre, series_title, chapter, rate);
    }
    else {
        throw std::runtime_error ("Unknown type of media.");
    }
}

std::unordered_map<std::string, Media*> create_id_indexes(std::vector<Media*> data) {
    std::unordered_map<std::string, Media*> id_indexes;
    
    for (Media* media : data) {
        id_indexes[media->get_id()] = media;
    }
    return id_indexes;
}

std::unordered_map<std::string, std::vector<Media*>> create_genre_indexes(std::vector<Media*> data) {
    std::unordered_map<std::string, std::vector<Media*>> genre_indexes;

    for (Media* media : data) {
        genre_indexes[media->get_genre()].push_back(media);
    }
    return genre_indexes;
}

std::unordered_map<std::string, float> create_rate_indexes(std::vector<Media*> data) {
    std::unordered_map<std::string, float> rate_indexes;

    for (const Media* media : data) {
        if (media->get_rate() == "SC") {
            continue; // Skip media with no rating
        }
        rate_indexes[media->get_id()] = std::stof(media->get_rate());
    }
    return rate_indexes;
}
