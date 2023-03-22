/*Michal Konopko, WCY22IX3S0
Zajęcia: 2022.11.23, rozliczenie: 2022.12.07
Temat: Zadanie 2 - Maszyna losująca
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int zakres= 0;
    int ile_liczb = 0;
    printf("Program generujacy losowe liczby z dowolnego przedzialu. Podaj ile chcesz liczb dostac\n > ");
    scanf("%d", &ile_liczb); //zczytywanie
    int wygenerowane_liczby[ile_liczb]; //tablica
    printf("podaj ile liczb chcesz w przedziale \n >");
    scanf("%d", &zakres); //zczytywanie
    while(zakres>ile_liczb){   //zabezpieczenie
        printf("Poprosze wiekszy zakres niz ilosc liczb\n");
        scanf("%d", &zakres);
    }
    srand(time(NULL));
    int ctr = 0;
    for(ctr; ctr<ile_liczb; ctr++) {
        wygenerowane_liczby[ctr] = rand() % zakres + 1; //generowanie liczb losowych
        for (int temp = 0; temp < ctr; temp++) {
            if (wygenerowane_liczby[ctr] == wygenerowane_liczby[temp]) {
                ctr--;
            }
        }
    }
    int i = 0;
    for(i; i<ile_liczb; i++){
        printf("%d\n", wygenerowane_liczby[i]); //wypisywanie tablicy
    }
    return 0;
}
