#include "DB_Reviews.hpp"

DB_Reviews::DB_Reviews(std::string path) : DB_Service(path) {
    load_data();
}

void DB_Reviews::load_data() {
    if (!path_is_ok()) {
        throw std::runtime_error("Invalid path for reviews database.");
    }

    std::vector<std::string> lines = read_CSV();

    for (const std::string& line : lines) {
        std::istringstream ss(line);
        std::string id;
        std::vector<float> reviews;

        std::getline(ss, id, ',');

        do {
            std::string value;
            float fvalue = 0.0f;
            std::getline(ss, value, ',');
            try {
                fvalue = std::stof(value);
            }
            catch (...) {
                throw std::runtime_error("Invalid data on database. May be corrupted.");
            }
            reviews.push_back(fvalue);
        }
        while (!line.empty());

        data.insert({id, reviews});
    }
}

std::unordered_map<std::string, std::vector<float>>& DB_Reviews::get_reviews() {
    return data;
}

std::unordered_map<std::string, std::vector<float>> DB_Reviews::get_reviews(std::map<REVIEW_FIELDS, std::string> filters) {
    std::unordered_map<std::string, std::vector<float>> result;

    for (const auto& review : data) {
        bool match = true;

        float avg = 0.0f;
        if (!review.second.empty()) {
            for (float v : review.second) avg += v;
            avg /= review.second.size();
        }

        for (const auto& filter : filters) {
            switch (filter.first) {
                case ID:
                    if (review.first != filter.second) match = false;
                    break;

                case AVERAGE:
                    if (avg != std::stof(filter.second)) match = false;
                    break;

                case LESS_THAN:
                    if (avg >= std::stof(filter.second)) match = false;
                    break;

                case MORE_THAN:
                    if (avg <= std::stof(filter.second)) match = false;
                    break;

                case MORE_THAN_N:
                    if (review.second.size() <= std::stoi(filter.second)) match = false;
                    break;

                case LESS_THAN_N:
                    if (review.second.size() >= std::stoi(filter.second)) match = false;
                    break;

                case EXACTLY_N:
                    if (review.second.size() != std::stoi(filter.second)) match = false;
                    break;

                default:
                    break;
            }
            if (!match) break;
        }
        if (match) result[review.first] = review.second;
    }
    return result;
}

void DB_Reviews::append_review(std::string id, float review) {
    data[id].push_back(review);
}

void DB_Reviews::undo_review(std::string id) {
    data[id].pop_back();
}

void DB_Reviews::delete_review(std::string id) {
    data.erase(id);
}

float DB_Reviews::get_rating(std::string id) {
    int counter = 0; 
    float avg = 0.0f;
    for (float v : data[id]) avg += v;
    avg /= data[id].size();
    return avg;
}

std::map<std::string, float> DB_Reviews::get_ratings() {
    std::map<std::string, float> result;
    for (const auto& review : data) {
        result.insert({review.first, get_rating(review.first)});
    }
    return result;
}