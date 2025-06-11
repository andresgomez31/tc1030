// File: DB_Media.cpp

#include "DB_Media.hpp"
#include "Movie.hpp"
#include "Chapter.hpp"

DB_Media::DB_Media(std::string path) : DB_Service(path) {
    load_data();
}

void DB_Media::load_data() {
    if (!path_is_ok()) {
        throw std::runtime_error("Invalid path for media database.");
    }

    std::vector<std::string> lines = read_CSV();
    for (const std::string& line : lines) {
        std::istringstream ss(line);
        std::string type, id, title, duration, category, rate;

        std::getline(ss, type, ',');
        std::getline(ss, id, ',');
        std::getline(ss, title, ',');
        std::getline(ss, duration, ',');
        std::getline(ss, category, ',');
        std::getline(ss, rate);

        if (type == "c") {
            std::string series_title, chapter;
            std::getline(ss, series_title, ',');
            std::getline(ss, chapter);
            data.push_back(new Chapter(id, title, duration, category, series_title, chapter, rate));
        } else if (type == "p") {
            data.push_back(new Movie(id, title, duration, category, rate));
        }
    }
    create_indexes();
}

void DB_Media::create_indexes() {
    for (const auto& _ : data) {
        index_by_id[_->get_id()] = _;
    }
}

const std::vector<Media*>& DB_Media::get_media() const {
    return data;
}

std::vector<Media*> DB_Media::get_media(std::map<MEDIA_FIELDS, std::string> filters) {
    std::vector<Media*> result;

    for (const auto& media : data) {
        bool match = true;
        for (const auto& filter : filters) {
            switch (filter.first) {
                case ID:
                    if (media->get_id() != filter.second) match = false;
                    break;
                case TYPE:
                    if (media->get_type() != filter.second) match = false;
                    break;
                case TITLE:
                    if (media->get_title() != filter.second) match = false;
                    break;
                case DURATION:
                    if (media->get_duration() != filter.second) match = false;
                    break;
                case CATEGORY:
                    if (media->get_category() != filter.second) match = false;
                    break;
                case SERIES_TITLE: {
                    // Only check if media is a Chapter
                    const Chapter* chapter = dynamic_cast<const Chapter*>(media);
                    if (!chapter || chapter->get_series_title() != filter.second) match = false;
                    break;
                }
                case CHAPTER: {
                    const Chapter* chapter = dynamic_cast<const Chapter*>(media);
                    if (!chapter || chapter->get_chapter() != filter.second) match = false;
                    break;
                }
                case RATE_FROM:
                    if (std::stod(media->get_rate()) < std::stod(filter.second)) match = false;
                    break;
                case RATE_TO:
                    if (std::stod(media->get_rate()) > std::stod(filter.second)) match = false;
                    break;
                case RATE:
                    if (media->get_rate() != filter.second) match = false;
                    break;
                default:
                    break;
            }
            if (!match) break;
        }
        if (match) result.push_back(media);
    }
    return result;
}

// Got help from GitHub Copilot to implement this function
void DB_Media::update_media(std::map<MEDIA_FIELDS, std::string> data, std::string& id) {
    auto it = index_by_id.find(id);
    if (it != index_by_id.end()) {
        Media* media = it->second;
        if (data.find(TITLE) != data.end()) media->update_title(data[TITLE]);
        if (data.find(DURATION) != data.end()) media->update_duration(data[DURATION]);
        if (data.find(CATEGORY) != data.end()) media->update_category(data[CATEGORY]);
        
        // For Chapters, update series title and chapter
        if (dynamic_cast<Chapter*>(media)) {
            Chapter* chapter = static_cast<Chapter*>(media);
            if (data.find(SERIES_TITLE) != data.end()) chapter->update_series_title(data[SERIES_TITLE]);
            if (data.find(CHAPTER) != data.end()) chapter->update_chapter(data[CHAPTER]);
        }
    } else {
        throw std::runtime_error("Media with ID " + id + " not found.");
    }
}

DB_Media::~DB_Media() {
    for (auto& media : data) {
        delete media;
    }
    data.clear();
    index_by_id.clear();
}