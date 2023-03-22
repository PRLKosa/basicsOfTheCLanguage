/*Michal Konopko, WCY22IX3S0
Zajęcia: 2022.11.16, rozliczenie: 2022.11.23
Temat: Zadanie 1 - Kalkulator dwóch zmiennych
*/
#include <stdio.h>
int main()
{
    int start = 1; //stan logiczny
    while(start == 1) //start lub koniec programu
    {
        int dzialanie = 0;
        int a = 0;
        int b = 0;
        int wynik = 0;
        printf("Kalkulator liczb calkowitych\n      a [dzialanie] b = [wynik]\nWybierz dzialanie: [1] + [2] - [3] * [4] /       [0] zakoncz\n>");
        scanf("%d", &dzialanie); //rodzaj dzialania
        printf("a =");
        scanf("%d", &a); //pobranie wartosci a
        printf("b =");
        scanf("%d", &b); //pobranie wartosci b
        //czesc wlasniwa i operacjae
        if (dzialanie == 1)
        {
            wynik = a + b;
        }
        else if (dzialanie == 2)
        {
            wynik = a - b;
        }
        else if (dzialanie == 3)
        {
            wynik = a * b;
        }
        else if (dzialanie == 4)
        {
            wynik = a / b;
        }
        else if (dzialanie == 0)
        {
            start = 0; //jump w celu wylaczenia programu
        }
        printf("wynik = %d\n", wynik); //wyswietlenie wartosci
    }
    return 0;
}