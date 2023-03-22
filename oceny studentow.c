#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define numerStudenta 20
#define numerPrzedmiotu 4

struct Student {
    char imie[30];
    char nazwisko[30];
    int oceny[numerPrzedmiotu];
};

int main() {
    char imieStudenta[numerStudenta][30] = { "Michal", "Janek", "Szymon", "Mariusz", "Robert", "Lana", "Marcin", "Arkadiusz", "Stefan", "Szczepan", "Alicja", "Kot", "Alicja", "Wojtek", "Leo", "Cristiano", "Janusz", "Basia", "Kasia", "Asia"};
    char nazwiskoStudenta[numerStudenta][30] = { "Konopko", "Cichy", "Glosny", "Pudzianowski", "Lewandowski", "Dobra", "Najman", "Milik", "Batory", "Szczepanski", "ZKrainyCzarow", "WButach", "Kopytko", "Szczesny", "Messi" "Ronaldo", "Tracz", "Wojtkiewicz", "Taka", "Kowalska", "Nowakowska"};
    char nazwaPrzedmiotu[numerPrzedmiotu][30]= {"Polski", "Angielski", "Fizyka", "Matematyka"};
    struct Student studenci[numerStudenta];
    int przedmiotOceny[numerStudenta][numerPrzedmiotu];
    float sredniaStudenta[numerStudenta];
    float sredniaPrzedmiotu[numerPrzedmiotu];
    float koncowaSrednia = 0;

    srand(time(0));

    // Wczytanie danych studentów
    for (int i = 0; i < numerStudenta; i++) {
        strcpy(studenci[i].imie, imieStudenta[i]);
        strcpy(studenci[i].nazwisko, nazwiskoStudenta[i]);
    }

    // Losowanie ocen dla poszczególnych przedmiotów
    for (int i = 0; i < numerStudenta; i++) {
        for (int j = 0; j < numerPrzedmiotu; j++) {
            przedmiotOceny[i][j] = rand() % 4 + 2;
        }
    }

    // Wczytanie ocen do struktury studentów
    for (int i = 0; i < numerStudenta; i++) {
        for (int j = 0; j < numerPrzedmiotu; j++) {
            studenci[i].oceny[j] = przedmiotOceny[i][j];
        }
    }

    // Wyświetlanie danych studentów i ich ocen
    for (int i = 0; i < numerStudenta; i++) {
        printf("Studenci: %s %s\n", studenci[i].imie, studenci[i].nazwisko);
        printf("Oceny:\n");
        for (int j = 0; j < numerPrzedmiotu; j++) {
            printf("%s %d \n",nazwaPrzedmiotu[j], studenci[i].oceny[j]);
        }
        printf("\n");
    }

    // Obliczanie średniej ocen dla każdego studenta
    for (int i = 0; i < numerStudenta; i++) {
        float sum = 0;
        for (int j = 0; j < numerPrzedmiotu; j++) {
            sum += studenci[i].oceny[j];
        }
        sredniaStudenta[i] = sum / numerPrzedmiotu;
        printf("Srednia studenta %s %s: %.2f\n", studenci[i].imie, studenci[i].nazwisko, sredniaStudenta[i]);
    }

    // Obliczanie średniej ocen z każdego przedmiotu
    for (int i = 0; i < numerPrzedmiotu; i++) {
        float sum = 0;
        for (int j = 0; j < numerStudenta; j++) {
            sum += studenci[j].oceny[i];
        }
        sredniaPrzedmiotu[i] = sum / numerStudenta;
        printf("Srednia z przedmiotu %d %s: %.2f\n", i+1, nazwaPrzedmiotu[i], sredniaPrzedmiotu[i]);
    }

    // Obliczanie średniej ocen ze wszystkich ocen
    for (int i = 0; i < numerStudenta; i++) {
        for (int j = 0; j < numerPrzedmiotu; j++) {
            koncowaSrednia += studenci[i].oceny[j];
        }
    }
    koncowaSrednia /= (numerStudenta * numerPrzedmiotu);
    printf("Srednia koncowa: %.2f\n", koncowaSrednia);

    return 0;
}