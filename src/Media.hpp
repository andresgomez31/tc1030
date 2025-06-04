// File: Media.hpp

#include <string>

/**
 * type, id, title, duration, category, rate
 */

class Media {
    private:
        std::string type, id, title, duration, category, rate;

    public:
        // Constructor
        Media(
            std::string type,
            std::string id,
            std::string title,
            std::string duration,
            std::string category,
            std::string rate = "SC"
        );

        // Getters
        std::string get_type() const;
        std::string get_id() const;
        std::string get_title() const;
        std::string get_duration() const;
        std::string get_category() const;
        std::string get_rate() const;

        // Parse from Media subclass to CSV
        virtual std::string toCSV() const = 0;

        // Update the rating
        void update_rate(float rate);

        virtual ~Media();
};