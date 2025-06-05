// File: DB_Media.hpp

#pragma once

#include "DB_Service.hpp"

enum MEDIA_FIELDS {
    TYPE,
    ID,
    TITLE,
    DURATION,
    CATEGORY,
    SERIES_TITLE,
    CHAPTER,
    RATE
};

class DB_Media : public DB_Service {
    private:
        std::vector<Media*> data;
        std::unordered_map<std::string, Media*> index_by_id;

        void load_data() override;
        void create_indexes();

    public:
        DB_Media(std::string path);
        // Getters
        const std::vector<Media*>& get_media() const;
        const std::vector<Media*> get_media(std::map<MEDIA_FIELDS, std::string> filters) const;

        // Setting rating on Media objects:
        void update_rating(std::string id, float rating) const;

        // Additional methods not implemented for this project.
        // void update_id(std::string id, std::string new_id) const;
        // void update_title(std::string id, std::string new_title) const;
        // void update_duration(std::string id, std::string new_duration) const;
        // void update_category(std::string id, std::string new_category) const;

        ~DB_Media();
};