// @check-accepted: esempi H_uguale N_piccolo N_grande
#include <iostream>
#include <vector>
#include <limits> // Per std::numeric_limits

int main()
{
    int N; // Numero di edifici
    std::cin >> N;

    if (N <= 0)
    {
        return 1; // Termina il programma con un codice di errore
    }

    std::vector<int> altezze(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> altezze[i];
    }

    // Inizializza il minimo con un valore molto grande
    int minimo = std::numeric_limits<int>::max();

    // Trova l'edificio più basso
    for (int altezza : altezze)
    {
        if (altezza < minimo)
        {
            minimo = altezza;
        }
    }

    std::cout << minimo << std::endl;

    return 0; // Termina il programma con successo
}
