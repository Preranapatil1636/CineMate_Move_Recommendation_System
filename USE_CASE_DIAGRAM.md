# CineMate - Use Case Diagram

The following diagram illustrates the functional interactions between the **User** actor and the **CineMate (Movie Recommendation System)**.

```mermaid
graph LR
    User([User])

    subgraph CineMate System Boundary
        UC1(Add New Movie)
        UC2(Display All Movies)
        UC3(Search Movies by Genre)
        UC4(Filter Movies by Minimum Rating)
        UC5(Search Movies by Release Year)
        UC6(Get Recommendations using AND Logic)
        UC7(Exit Application)
    end

    User --> UC1
    User --> UC2
    User --> UC3
    User --> UC4
    User --> UC5
    User --> UC6
    User --> UC7
```

---

## Detailed Use Case Summaries

| Use Case ID | Use Case Name | Description |
| :--- | :--- | :--- |
| **UC-1** | Add New Movie | User inputs movie details (title, genre/category, rating, year, subgenre/humor style). System validates inputs and checks duplicate rules before storing. |
| **UC-2** | Display All Movies | User views a complete listing of all sample and custom movies stored in the system. |
| **UC-3** | Search Movies by Genre | User enters a genre keyword; system performs case-insensitive filtering and displays matches. |
| **UC-4** | Filter Movies by Rating | User enters a rating threshold; system displays all movies with $Rating \ge \text{threshold}$. |
| **UC-5** | Search Movies by Release Year | User selects exact year or year range search to discover matching movies. |
| **UC-6** | Get Recommendations | User combines genre, minimum rating, and optional year range using AND logic to receive customized recommendations. |
| **UC-7** | Exit Application | User exits the console application cleanly. |
