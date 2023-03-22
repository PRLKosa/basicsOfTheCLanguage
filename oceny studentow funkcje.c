/*Michal Konopko, WCY22IX3S0
Zajęcia: 2023.01.25, rozliczenie: 2023.01.30
Temat: Zadanie 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENT 20
#define MAX_PRZEDMIOTOW 5
#define MIN_OCENA 2
#define MAX_OCENA 5
#define NUM_IMION 50
#define LEN_IMIENIA 20

struct student {
    char imie[LEN_IMIENIA];
    char nazwisko[LEN_IMIENIA];
    float oceny[MAX_PRZEDMIOTOW];
};

void generuj_dane_studenta(struct student *studenci) {
    "nie wiem jak wkleic baze wpisuje imiona recznie to co mi przyjdzie do glowy";
    char imiona[NUM_IMION][LEN_IMIENIA] = { "Adam", "Agnieszka","Alan","Aleksandra","Aleksander","Amelia","Andrzej","Ania","Anna","Antoni","Barbara","Bartek","Basia","Bogdan","Cezary","Damian","Daniel","Dawid","Dorota","Ewa","Filip","Gabriela","Grzegorz","Iga","Ilona","Jan","Joanna","Jakub","Kamil","Karol","Kinga","Krzysztof","Laura","Lena","Lukasz","Maja","Marek","Maria","Mateusz","Michal","Monika","Natalia","Nina","Oliwia","Patrycja","Pawel","Paulina","Piotr","Radek","Robert"};
    char nazwiska[NUM_IMION][LEN_IMIENIA] = {  "Adamczyk","Andrzejewski","Bak","Bielawski","Borowski","Chmielewski","Cieslak","Czarnecki","Duda","Dudek","Falkowski","Gorecki","Glowacki","Grabowski","Jankowski","Jasinski","Kaczmarek","Kania","Kowalczyk","Kowalski","Kozlowski","Krupa","Kwiatkowski","Lis","Majewski","Makowski","Mazur","Michalski","Nowak","Nowicki","Olszewski","Pawlowski","Pietrzak","Przybylski","Rutkowski","Sadowski","Sikora","Skowronski","Smolinski","Szewczyk","Szostak","Szulc","Tomaszewski","Urban","Urbanski","Wieczorek","Wojciechowski","Wojcik","Wolski","Wrobel" };
    for (int i = 0; i < MAX_STUDENT; i++) {
        int indeks_imienia = rand() % NUM_IMION;
        int indeks_nazwiska = rand() % NUM_IMION;
        strcpy(studenci[i].imie, imiona[indeks_imienia]);
        strcpy(studenci[i].nazwisko, nazwiska[indeks_nazwiska]);
        float tempoceny[6] = {2, 3, 3.5, 4, 4.5, 5};
        for (int j = 0; j < MAX_PRZEDMIOTOW; j++) {
            studenci[i].oceny[j] = tempoceny[rand()%6];
        }
    }
}

void wypisz_dane_studenta(struct student *studenci) {
    printf("Dane uczniow:\n");
    for (int i = 0; i < MAX_STUDENT; i++) {
        printf("%s %s: ", studenci[i].imie, studenci[i].nazwisko);
        for (int j = 0; j < MAX_PRZEDMIOTOW; j++) {
            printf("%.1f ", studenci[i].oceny[j]);
        }
        printf("\n");
    }
}
void wypisz_karte_studenta(struct student student) {
    printf("Karta ucznia:\n");
    printf("Imie: %s %s\n", student.imie, student.nazwisko);
    printf("Oceny: ");
        for (int i = 0; i < MAX_PRZEDMIOTOW; i++) {
            printf("%.1f ", student.oceny[i]);
        }
        printf("\n");
        float avg = 0.0;
        for (int i = 0; i < MAX_PRZEDMIOTOW; i++) {
            avg += student.oceny[i];
        }
        avg /= MAX_PRZEDMIOTOW;
        printf("Srednia ocen: %.2f\n\n", avg);
    }
// Obliczanie średniej ocen dla każdego studenta
void wypisz_student_avg(struct student *studenci) {
    float sredniaStudenta[MAX_STUDENT];
    printf("Srednia ocen ucznia:\n");
    for (int i = 0; i < MAX_STUDENT; i++) {
        float sum = 0;
        for (int j = 0; j < MAX_PRZEDMIOTOW; j++) {
            sum += studenci[i].oceny[j];
        }
        sredniaStudenta[i] = sum / MAX_PRZEDMIOTOW;
        printf("Srednia studenta %s %s: %.2f\n", studenci[i].imie, studenci[i].nazwisko, sredniaStudenta[i]);
    }
}

// Obliczanie średniej ocen z każdego przedmiotu
//void wypisz_srednia_wszystkich(struct  student *studenci) {
//    float sredniaPrzedmiotu[MAX_PRZEDMIOTOW];
//    for (int i = 0; i < MAX_PRZEDMIOTOW; i++) {
//        float sum = 0;
//        for (int j = 0; j < MAX_STUDENT; j++) {
//            sum += studenci[j].oceny[i];
//        }
//        sredniaPrzedmiotu[i] = sum / MAX_STUDENT;
//        printf("Srednia z przedmiotu %d %s: %.2f\n", i + 1, /*nazwaPrzedmiotu[i], */sredniaPrzedmiotu[i]);
//    }
//}
// Obliczanie średniej ocen ze wszystkich ocen
void wypisz_koncowa_srednia(struct student *studenci) {
    float koncowaSrednia = 0;
    for (int i = 0; i < MAX_STUDENT; i++) {
        for (int j = 0; j < MAX_PRZEDMIOTOW; j++) {
            koncowaSrednia += studenci[i].oceny[j];
        }
    }
    koncowaSrednia /= (MAX_STUDENT * MAX_PRZEDMIOTOW);
    printf("Srednia koncowa: %.2f\n", koncowaSrednia);
}

int main(void) {
    srand(time(NULL));
    struct student studenci[MAX_STUDENT];
    int start = 1;
    printf("USOS DZIENNIK [0] wczytaj nowych uczniow [1] studenci [2] student [3] avg studenci [4] avg wszystkich [5] zakoncz\n>");
    int liczba = 0;
    generuj_dane_studenta(studenci);
    while (start == 1) {
        printf("co chcesz zrobic? \n>");
        scanf("%d", &liczba);
        switch (liczba) {
            case 0:
                generuj_dane_studenta(studenci);
                break;
            case 1:
                wypisz_dane_studenta(studenci);
                break;
            case 2:

                printf("Podaj numer indeksu ucznia (0-19)>");
                int index;
                scanf("%d", &index);
                wypisz_karte_studenta(studenci[index]);
                break;
            case 3:
                wypisz_student_avg(studenci);
                break;
            case 4:
                wypisz_koncowa_srednia(studenci);
                break;
            case 5:
                start = 0;
            default:
                break;
        }
    }

    return 0;
}




