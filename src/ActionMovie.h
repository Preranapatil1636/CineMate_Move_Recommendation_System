#ifndef ACTION_MOVIE_H
#define ACTION_MOVIE_H

#include "Movie.h"

/**
 * @class ActionMovie
 * @brief Represents an action-genre movie derived from Movie.
 * 
 * Demonstrates Inheritance and Polymorphism by extending Movie properties
 * with an actionSubgenre field and overriding displayDetails().
 */
class ActionMovie : public Movie {
private:
    std::string actionSubgenre;

public:
    // Constructors
    ActionMovie();
    ActionMovie(const std::string& title, double rating, int releaseYear,
                const std::string& actionSubgenre = "General Action");

    // Getter and Setter for derived property
    std::string getActionSubgenre() const;
    bool setActionSubgenre(const std::string& subgenre);

    // Overridden Virtual Methods (Polymorphism)
    std::string getMovieType() const override;
    void displayDetails() const override;
};

#endif // ACTION_MOVIE_H
