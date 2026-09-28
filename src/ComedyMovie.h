#ifndef COMEDY_MOVIE_H
#define COMEDY_MOVIE_H

#include "Movie.h"

/**
 * @class ComedyMovie
 * @brief Represents a comedy-genre movie derived from Movie.
 * 
 * Demonstrates Inheritance and Polymorphism by extending Movie properties
 * with a humorStyle field and overriding displayDetails().
 */
class ComedyMovie : public Movie {
private:
    std::string humorStyle;

public:
    // Constructors
    ComedyMovie();
    ComedyMovie(const std::string& title, double rating, int releaseYear,
                const std::string& humorStyle = "General Comedy");

    // Getter and Setter for derived property
    std::string getHumorStyle() const;
    bool setHumorStyle(const std::string& style);

    // Overridden Virtual Methods (Polymorphism)
    std::string getMovieType() const override;
    void displayDetails() const override;
};

#endif // COMEDY_MOVIE_H
