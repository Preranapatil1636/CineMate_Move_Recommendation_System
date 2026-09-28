#include "ActionMovie.h"

ActionMovie::ActionMovie()
    : Movie("Untitled Action", "Action", 0.0, 2000), actionSubgenre("General Action") {}

ActionMovie::ActionMovie(const std::string& title, double rating, int releaseYear,
                         const std::string& actionSubgenre)
    : Movie(title, "Action", rating, releaseYear) {
    if (!setActionSubgenre(actionSubgenre)) {
        this->actionSubgenre = "General Action";
    }
}

std::string ActionMovie::getActionSubgenre() const {
    return actionSubgenre;
}

bool ActionMovie::setActionSubgenre(const std::string& subgenre) {
    std::string trimmed = trim(subgenre);
    if (trimmed.empty()) {
        return false;
    }
    actionSubgenre = trimmed;
    return true;
}

std::string ActionMovie::getMovieType() const {
    return "Action Movie";
}

void ActionMovie::displayDetails() const {
    Movie::displayDetails();
    std::cout << " Subgenre:     " << actionSubgenre << "\n";
    std::cout << " Category:     [ACTION EXTREME]\n";
}
