#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Person
{
    string name;
    string surname;
    Date birthDate;
    string knownFor;
};

struct Film
{
    string name;
    Date releaseDate;
    double rating;
    Person producer;
    Person storyWriter;
    string genre;
    string comments;
};

Film FillFilm();
void PrintFilm(const Film* films, const int SIZE);
void PrintFilm(const Film& film);

Person FillPerson();
void PrintPerson(Person person);

int main()
{
    const int SIZE = 3;
    Film favoriteFilms[SIZE]{};

    for (int i = 0; i < SIZE; i++)
    {
        favoriteFilms[i] = FillFilm();
    }
    PrintFilm(favoriteFilms, SIZE);
}

Film FillFilm()
{
    Film film;

    cout << "Please, enter some information about the film.\n";

    cout << "Enter a name: ";
    cin >> film.name;

    cout << "Enter a releaseDate (10 11 2022): ";
    cin >> film.releaseDate.day >> film.releaseDate.month >> film.releaseDate.year;

    cout << "Enter a viewers rating: ";
    cin >> film.rating;

    cout << "Enter a producer:\n";
    film.producer = FillPerson();
    cout << "Enter a story writer:\n";
    film.storyWriter = FillPerson();

    cout << "Enter a genre: ";
    cin >> film.genre;

    cin.ignore();

    cout << "Enter some comments: ";
    getline(cin, film.comments);

    return film;
}

void PrintFilm(const Film* films, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Film #" << i + 1 << "\n";

        cout << "-Name: " << films[i].name << "\n";
        cout << "-Relise date: "
            << films[i].releaseDate.day << "."
            << films[i].releaseDate.month << "."
            << films[i].releaseDate.year << "\n";
        cout << "-Rating: " << films[i].rating << "\n";
        cout << "-Producer:\n";
        PrintPerson(films[i].producer);
        cout << "-Story writer:\n";
        PrintPerson(films[i].storyWriter);
        cout << "-Genre: " << films[i].genre << "\n";
        cout << "-Comments: " << films[i].comments << "\n\n";
    }
}

void PrintFilm(const Film& film)
{
    cout << "Film" << "\n";

    cout << "-Name: " << film.name << "\n";
    cout << "-Relise date: "
        << film.releaseDate.day << "."
        << film.releaseDate.month << "."
        << film.releaseDate.year << "\n";
    cout << "-Rating: " << film.rating << "\n";
    cout << "-Producer:\n";
    PrintPerson(film.producer);
    cout << "-Story writer:\n";
    PrintPerson(film.storyWriter);
    cout << "-Genre: " << film.genre << "\n";
    cout << "-Comments: " << film.comments << "\n\n";
}

Person FillPerson()
{
    Person person;

    cout << "Please, enter some information about the person.\n";

    cout << "Enter a name: ";
    cin >> person.name;

    cout << "Enter a surname: ";
    cin >> person.surname;

    cout << "Enter date of birth: ";
    cin >> person.birthDate.day >> person.birthDate.month >> person.birthDate.year;

    cout << "Known for: ";
    cin >> person.knownFor;

    return person;
}

void PrintPerson(Person person)
{
    cout << "--Name: " << person.name << "\n";
    cout << "--Surname: " << person.surname << "\n";
    cout << "--Date of birth: "
        << person.birthDate.day << "."
        << person.birthDate.month << "."
        << person.birthDate.year << "\n";
    cout << "--Known for: " << person.knownFor << "\n";
}
