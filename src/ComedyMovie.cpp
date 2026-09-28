#include "ComedyMovie.h"

ComedyMovie::ComedyMovie()
    : Movie("Untitled Comedy", "Comedy", 0.0, 2000), humorStyle("General Comedy") {}

ComedyMovie::ComedyMovie(const std::string& title, double rating, int releaseYear,
                         const std::string& humorStyle)
    : Movie(title, "Comedy", rating, releaseYear) {
    if (!setHumorStyle(humorStyle)) {
        this->humorStyle = "General Comedy";
    }
}

std::string ComedyMovie::getHumorStyle() const {
    return humorStyle;
}

bool ComedyMovie::setHumorStyle(const std::string& style) {
    std::string trimmed = trim(style);
    if (trimmed.empty()) {
        return false;
    }
    humorStyle = trimmed;
    return true;
}

std::string ComedyMovie::getMovieType() const {
    return "Comedy Movie";
}

void ComedyMovie::displayDetails() const {
    Movie::displayDetails();
    std::cout << " Humor Style:  " << humorStyle << "\n";
    std::cout << " Category:     [LAUGHTER GUARANTEED]\n";
}
