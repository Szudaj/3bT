#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <windows.h>

using namespace std;

void delta(int a, int b, int c) // metoda liczaca wszystkie przypadku delty PO OBLICZENIU STOPNIA DRUGIEGO WIELOMIANU (FUNCKJA KWADRATOWA)
{
    int delta;
    float x0;
    float x1;
    float x2;

    delta =(b*b) - 4 * a * c;

    if (delta==0)
    {
        x0 = -b / (2*a);
    }
    else
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
    }

    cout<<endl<<"Delta = "<<delta<<endl;

    if (delta==0)
    {
        cout<<endl<<"x0 = "<<x0<<endl<<endl;
    }
    else if (delta>0)
    {
        cout<<endl<<"x1 = "<<x1<<endl;
        cout<<"x2 = "<<x2<<endl<<endl;
    }
    else
    {
        cout<<endl<<"DELTA UJEMNA - BRAK ROZWIAZANIA"<<endl<<endl;
    }
}

int main()
{
    srand(time(NULL));

    int stopien_wielomianu;             //podajemy stopien wielomianu od ktorego zaczynamy
    cout<<"Stopien wielomianu: ";
    cin>>stopien_wielomianu;

    int stopien_wielomianu_tab[stopien_wielomianu];

    for (int i=0; i<=stopien_wielomianu; i++)
    {
        cout<<i+1<<". argument wielomianu: ";
        cin>>stopien_wielomianu_tab[i];                 //podajemy argumenty wielomianu
    }

    int wynik=1;
    int mnoznik;
    int czy_odwrocic;
    int nowa_wartosc[stopien_wielomianu];

    if (stopien_wielomianu == 4)            //nieszczesny przypadek kiedy to musimy zaczac liczyc od czwartego stopnia (nie jestem w stanie sobie z tym poradzic)
    {
        while (wynik!=0)
        {
            mnoznik = rand()%100+1;

            czy_odwrocic = rand()%2+1;

            if (czy_odwrocic==1)
            {
                mnoznik = mnoznik * (-1);
            }

            wynik=stopien_wielomianu_tab[0];

            for (int i=0; i<stopien_wielomianu; i++)
            {
                nowa_wartosc[i] = wynik;
                wynik = (mnoznik * wynik) + stopien_wielomianu_tab[i+1];
            }
        }
        stopien_wielomianu--;                     //odejmujemy jeden stopien poniewaz teraz po obliczeniu stopnia czwartego msuimy obliczyc stopien trzeci, po nim juz tylko delte
    }

    if (stopien_wielomianu == 3)                //przypadek kiedy liczymy od trzeciego stopnia (dziala bezblednie)
    {
        while (wynik!=0)
        {
            mnoznik = rand()%100+1;

            czy_odwrocic = rand()%2+1;

            if (czy_odwrocic==1)
            {
                mnoznik = mnoznik * (-1);
            }

            wynik=stopien_wielomianu_tab[0];

            for (int i=0; i<stopien_wielomianu; i++)
            {
                nowa_wartosc[i] = wynik;
                wynik = (mnoznik * wynik) + stopien_wielomianu_tab[i+1];
            }

            if (wynik==0)                                   //wypisywanie wynikow koncowych na ekranie
            {
                cout<<endl<<endl<<"Liczba "<<mnoznik<<" jest miejscem zerowym wielomianu"<<endl<<endl;

                mnoznik = mnoznik * (-1);

                cout<<"(x + "<<mnoznik<<") (";

                string pluss = " + ";

                for (int i=0; i<stopien_wielomianu; i++)
                {
                    cout<<nowa_wartosc[i];

                    if (i==stopien_wielomianu-3)
                    {
                        cout<<"x^2 ";
                    }

                    if (i==stopien_wielomianu-2)
                    {
                        cout<<"x ";
                    }

                    if (i!=stopien_wielomianu-1)
                    {
                        cout<<pluss;
                    }
                }
                cout<<")"<<endl<<endl;

                delta(nowa_wartosc[0], nowa_wartosc[1], nowa_wartosc[2]);
            }
        }
    }

    if (stopien_wielomianu==2)          //wypisywanie delty x0, x1, x2
    {
        delta(stopien_wielomianu_tab[0], stopien_wielomianu_tab[1], stopien_wielomianu_tab[2]);
    }



    system("pause");

    return {};

}
