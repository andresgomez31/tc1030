// File: DB_Reviews.hpp

#pragma once

#include "DB_Service.hpp"

enum REVIEW_FIELDS {
    ID,
    AVERAGE,
    LESS_THAN,
    LESS_OR_EQUAL_THAN,
    MORE_THAN,
    MORE_OR_EQUAL_THAN,
    LESS_THAN_N,
    LESS_OR_EQUAL_THAN_N,
    MORE_THAN_N,
    MORE_OR_EQUAL_THAN_N,
    EXACTLY_N
};

class DB_Reviews : public DB_Service {
    private:
        std::unordered_map<std::string, std::vector<float>> data;
        
        void load_data() override;

    public:
        // Constructor method
        DB_Reviews(std::string path);

        // Getters
        std::unordered_map<std::string, std::vector<float>>& get_reviews();
        std::unordered_map<std::string, std::vector<float>> get_reviews(std::map<REVIEW_FIELDS, std::string> filters);

        // Appending review on vector:
        void append_review(std::string id, float review);

        void undo_review(std::string id);
        // Not supported deleting an specific review due proyect data structure.
        // Does not make sense deleting just a value if found.

        // Delete a complete review. Use this to reset rate counting.
        void delete_review(std::string id);

        // Get the rating of specific media;
        float get_rating(std::string id);

        // Get all ratings of all media;
        std::map<std::string, float> get_ratings();

        ~DB_Reviews() override;
};