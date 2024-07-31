#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_OF_MOVIES 3450

typedef struct Budget
{
    int budget;
    int year;
    char *title;
    char *titletype;
    char *top250;
} Budget;

typedef struct Name
{
    char **genre;
    char *title;
    char **directors;
    char *mustsee;
    double rating;
    double score;
    double runtime;
    double votes;
    char *url;
} Name;

typedef struct Genre
{
    char *genre;
    int frequency;
} Genre;

void saveMovies(Budget *budget, Name *name, FILE *fp);
void initializeMemory(Budget *budget, Name *name);
void printBudgetArray(Budget *budget);
void printNameArray(Name *name);
void sortMoviesByYear(Budget *budget, Name *name);
void sortMoviesByRating(Budget *budget, Name *name);
void printAllInfoForSingleMovie(Budget *budget, Name *name);
void printGenreFrequency(Name *name);
void listGenres(Name *name);
void swapBudget(Budget *budget1, Budget *budget2);
void swapName(Name *name1, Name *name2);
void printTitleAndYear(Budget *budget, Name *name);
void printTitleAndRating(Budget *budget, Name *name);

int main(int argc, char *argv[]) {
    Budget *budget = (Budget*)malloc(sizeof(Budget) * NUMBER_OF_MOVIES);
    Name *name = (Name*)malloc(sizeof(Name) * NUMBER_OF_MOVIES);
    FILE *fp;

    fp = fopen("movie.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    saveMovies(budget, name, fp);
    fclose(fp);

    while (1) {
        printf("Select Operations:\n");
        printf("1. List of budget array\n");
        printf("2. List of name array\n");
        printf("3. List of genres\n");
        printf("4. List of the Movie Through the Years\n");
        printf("5. List of the Movie Through the Scores\n");
        printf("6. All Information of a Single Movie\n");
        printf("7. Frequency of the Genres\n");
        printf("8. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printBudgetArray(budget);
                break;
            case 2:
                printNameArray(name);
                break;
            case 3:
                listGenres(name);
                break;
            case 4:
                sortMoviesByYear(budget, name);
                printTitleAndYear(budget, name);
                break;
            case 5:
                sortMoviesByRating(budget, name);
                printTitleAndRating(budget, name);
                break;
            case 6:
                printAllInfoForSingleMovie(budget, name);
                break;
            case 7:
                printGenreFrequency(name);
                break;
            case 8:
                free(budget);
                free(name);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}

void saveMovies(Budget *budget, Name *name, FILE *fp) {
    char *line = NULL, *tmp2, *tmp3;
    tmp2 = (char*)malloc(sizeof(char) * 100);
    tmp3 = (char*)malloc(sizeof(char) * 100);
    double tmp;
    int i = 0, j = 0, k = 0, index = 0;

    line = (char*)malloc(sizeof(char) * 1000);
    while (fgets(line, 1000, fp) != NULL) {
        tmp = atof(strtok(line, ";"));
        budget[index].budget = tmp;

        budget[index].title = (char*)malloc(sizeof(char) * 100);
        strcpy(budget[index].title, strtok(NULL, ";"));

        name[index].title = (char*)malloc(sizeof(char) * 100);
        strcpy(name[index].title, budget[index].title);

        budget[index].titletype = (char*)malloc(sizeof(char) * 100);
        strcpy(budget[index].titletype, strtok(NULL, ";"));

        strcpy(tmp2, strtok(NULL, ";"));

        name[index].rating = atof(strtok(NULL, ";"));

        name[index].runtime = atof(strtok(NULL, ";"));

        budget[index].year = atoi(strtok(NULL, ";"));

        strcpy(tmp3, strtok(NULL, ";"));

        name[index].votes = atof(strtok(NULL, ";"));

        budget[index].top250 = (char*)malloc(sizeof(char) * 100);
        strcpy(budget[index].top250, strtok(NULL, ";"));

        name[index].mustsee = (char*)malloc(sizeof(char) * 100);
        strcpy(name[index].mustsee, strtok(NULL, ";"));

        name[index].url = (char*)malloc(sizeof(char) * 1000);
        strcpy(name[index].url, strtok(NULL, "\0"));

        name[index].genre = (char**)malloc(sizeof(char*) * 100);
        i = 0; j = 0; k = 0;
        while (tmp3[j] != '\0') {
            name[index].genre[i] = (char*)malloc(sizeof(char) * 100);
            k = 0;
            while (tmp3[j] != ',') {
                if (tmp3[j] == '\0') {
                    k++;
                    break;
                }
                name[index].genre[i][k] = tmp3[j];
                j++;
                k++;
            }
            name[index].genre[i][k] = '\0';

            if (tmp3[j] == '\0') {
                name[index].genre[i + 1] = NULL;
                break;
            }
            j++;
            i++;
        }
        j = 0; i = 0; k = 0;
        name[index].directors = (char**)malloc(sizeof(char*) * 100);
        while (tmp2[j - 1] != '\0') {
            name[index].directors[i] = (char*)malloc(sizeof(char) * 100);
            k = 0;
            while (tmp2[j] != ',') {
                if (tmp2[j] == '\0') {
                    break;
                }
                name[index].directors[i][k] = tmp2[j];
                j++;
                k++;
            }
            name[index].directors[i][k] = '\0';

            if (tmp2[j] == '\0') {
                name[index].directors[i + 1] = NULL;
            }
            j++;
            i++;
        }
        index++;
    }
}

void initializeMemory(Budget *budget, Name *name) {
    budget->title = (char*)malloc(sizeof(char) * 100);
    budget->titletype = (char*)malloc(sizeof(char) * 100);
    budget->top250 = (char*)malloc(sizeof(char) * 100);

    name->genre = (char**)malloc(sizeof(char*) * 100);
}

void printTitleAndYear(Budget *budget, Name *name) {
    int i = 0;
    for (i = 0; i < NUMBER_OF_MOVIES; i++) {
        printf("Title: %s\n", name[i].title);
        printf("Year: %d\n\n", budget[i].year);
    }
}

void printTitleAndRating(Budget *budget, Name *name) {
    int i = 0;
    for (i = 0; i < NUMBER_OF_MOVIES; i++) {
        printf("Title: %s\n", name[i].title);
        printf("Rating: %lf\n\n", name[i].rating);
    }
}

void printBudgetArray(Budget *budget) {
    int i = 0;
    for (i = 0; i < NUMBER_OF_MOVIES; i++) {
        printf("Budget: %d\n", budget[i].budget);
        printf("Title: %s\n", budget[i].title);
        printf("Titletype: %s\n", budget[i].titletype);
        printf("Top250: %s\n", budget[i].top250);
        printf("Year: %d\n\n", budget[i].year);
    }
}

void printNameArray(Name *name) {
    int i = 0, j = 0;
    for (i = 0; i < NUMBER_OF_MOVIES; i++) {
        printf("Title: %s\n", name[i].title);
        printf("Must see number: %s\n", name[i].mustsee);
        printf("Rating: %lf\n", name[i].rating);
        printf("Runtime: %lf\n", name[i].runtime);
        printf("Votes: %lf\n", name[i].votes);
        printf("Url: %s\n", name[i].url);
        printf("Genre: ");
        for (j = 0; name[i].genre[j] != NULL; j++) {
            printf("%s,", name[i].genre[j]);
        }
        printf("\n");
        printf("Directors: ");
        for (j = 0; name[i].directors[j] != NULL; j++) {
            printf("%s,", name[i].directors[j]);
        }
        printf("\n\n");
    }
}

void swapBudget(Budget *budget1, Budget *budget2) {
    Budget temp = *budget1;
    *budget1 = *budget2;
    *budget2 = temp;
}

void swapName(Name *name1, Name *name2) {
    Name temp = *name1;
    *name1 = *name2;
    *name2 = temp;
}

void sortMoviesByYear(Budget *budget, Name *name) {
    int i, j, min_idx;
    for (i = 0; i < NUMBER_OF_MOVIES - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < NUMBER_OF_MOVIES; j++) {
            if (budget[j].year < budget[min_idx].year) {
                min_idx = j;
            }
        }
        swapBudget(&budget[min_idx], &budget[i]);
        swapName(&name[min_idx], &name[i]);
    }
}

void sortMoviesByRating(Budget *budget, Name *name) {
    int i, j, min_idx;
    for (i = 0; i < NUMBER_OF_MOVIES - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < NUMBER_OF_MOVIES; j++) {
            if (name[j].rating < name[min_idx].rating) {
                min_idx = j;
            }
        }
        swapBudget(&budget[min_idx], &budget[i]);
        swapName(&name[min_idx], &name[i]);
    }
}

void printAllInfoForSingleMovie(Budget *budget, Name *name) {
    int i = 0, j = 0;
    char *movie_name = (char*)malloc(sizeof(char) * 100);
    printf("Enter the movie name: ");
    scanf(" %[^\n]", movie_name);
    for (i = 0; i < NUMBER_OF_MOVIES; i++) {
        if (strcmp(name[i].title, movie_name) == 0) {
            printf("Title: %s\n", name[i].title);
            printf("Must see number: %s\n", name[i].mustsee);
            printf("Rating: %lf\n", name[i].rating);
            printf("Runtime: %lf\n", name[i].runtime);
            printf("Votes: %lf\n", name[i].votes);
            printf("Url: %s\n", name[i].url);
            printf("Genre: ");
            for (j = 0; name[i].genre[j] != NULL; j++) {
                printf("%s,", name[i].genre[j]);
            }
            printf("\n");
            printf("Directors: ");
            for (j = 0; name[i].directors[j] != NULL; j++) {
                printf("%s,", name[i].directors[j]);
            }
            printf("\n\n");
            break;
        }
    }
    free(movie_name);
}

void printGenreFrequency(Name *name) {
    int i = 0, j = 0, k = 0, index = 0;
    Genre *genre = (Genre*)malloc(sizeof(Genre) * 100);
    for (i = 0; i < NUMBER_OF_MOVIES; i++) {
        for (j = 0; name[i].genre[j] != NULL; j++) {
            for (k = 0; k < index; k++) {
                if (strcmp(genre[k].genre, name[i].genre[j]) == 0) {
                    genre[k].frequency++;
                    break;
                }
            }
            if (k == index) {
                genre[index].genre = (char*)malloc(sizeof(char) * 100);
                strcpy(genre[index].genre, name[i].genre[j]);
                genre[index].frequency = 1;
                index++;
            }
        }
    }
    for (i = 0; i < index; i++) {
        printf("%s: %d\n", genre[i].genre, genre[i].frequency);
    }
    for (i = 0; i < index; i++) {
        free(genre[i].genre);
    }
    free(genre);
}

void listGenres(Name *name) {
    int i = 0, j = 0, k = 0, index = 0;
    char **genre = (char**)malloc(sizeof(char*) * 100);
    for (i = 0; i < NUMBER_OF_MOVIES; i++) {
        for (j = 0; name[i].genre[j] != NULL; j++) {
            for (k = 0; k < index; k++) {
                if (strcmp(genre[k], name[i].genre[j]) == 0) {
                    break;
                }
            }
            if (k == index) {
                genre[index] = (char*)malloc(sizeof(char) * 100);
                strcpy(genre[index], name[i].genre[j]);
                index++;
            }
        }
    }
    for (i = 0; i < index; i++) {
        printf("%s\n", genre[i]);
    }
    for (i = 0; i < index; i++) {
        free(genre[i]);
    }
    free(genre);
}
