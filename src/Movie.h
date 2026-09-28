#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>

/**
 * @class Movie
 * @brief Represents a general movie with encapsulated attributes and virtual behaviors.
 * 
 * Demonstrates Encapsulation (private members, public getters/validated setters)
 * and Polymorphism (virtual displayDetails method and virtual destructor).
 */
class Movie {
private:
    std::string title;
    std::string genre;
    double rating;      // Valid range: 0.0 to 10.0
    int releaseYear;    // Valid range: 1888 to current year (2026)

public:
    // Constructors
    Movie();
    Movie(const std::string& title, const std::string& genre, double rating, int releaseYear);
    virtual ~Movie() = default;

    // Getters (Const Correctness)
    std::string getTitle() const;
    std::string getGenre() const;
    double getRating() const;
    int getReleaseYear() const;
    virtual std::string getMovieType() const;

    // Validated Setters
    bool setTitle(const std::string& t);
    bool setGenre(const std::string& g);
    bool setRating(double r);
    bool setReleaseYear(int y);

    // Polymorphic display method
    virtual void displayDetails() const;

    // Static Utility Methods
    static std::string trim(const std::string& str);
    static std::string toLower(const std::string& str);
    static bool isValidRating(double r);
    static bool isValidReleaseYear(int y);
};

#endif // MOVIE_H
