#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <locale>

using namespace std;

void clearConsole() {
    // Konsole leeren
    cout << "\033[2J\033[1;1H";
}

// SI-Präfixe und ihre Potenzen
map<string, int> si_prefixes = {
    {"yotta", 24}, {"Y", 24}, {"zetta", 21}, {"Z", 21},
    {"exa", 18}, {"E", 18}, {"peta", 15}, {"P", 15},
    {"tera", 12}, {"T", 12}, {"giga", 9}, {"G", 9},
    {"mega", 6}, {"M", 6}, {"kilo", 3}, {"k", 3},
    {"hecto", 2}, {"h", 2}, {"deca", 1}, {"da", 1},
    {"0", 0}, // Basis-Einheit ohne Präfix
    {"deci", -1}, {"d", -1}, {"centi", -2}, {"c", -2},
    {"milli", -3}, {"m", -3}, {"micro", -6}, {"u", -6},
    {"nano", -9}, {"n", -9}, {"pico", -12}, {"p", -12},
    {"femto", -15}, {"f", -15}, {"atto", -18}, {"a", -18},
    {"zepto", -21}, {"z", -21}, {"yocto", -24}, {"y", -24}
};

// Zeitumrechnung (z. B. Stunde -> Sekunde)
map<string, int> time_units = {
    {"sekunde", 0}, {"s", 0},
    {"minute", 1}, {"min", 1},
    {"stunde", 2}, {"h", 2}
};


// Funktion zur Berechnung des Potenzverhältnisses
int calculatePowerDifference(const string& numerator, const string& denominator) {
    string num_lower = numerator;
    string denom_lower = denominator;


    // Prüfen, ob es sich um Zeiteinheiten handelt
    if (time_units.count(num_lower) && time_units.count(denom_lower)) {
        int time_factors[] = {1, 60, 3600}; // Faktoren für Sekunde, Minute, Stunde
        int num_factor = time_factors[time_units[num_lower]];
        int denom_factor = time_factors[time_units[denom_lower]];
        return log10(num_factor) - log10(denom_factor);

        //this is a comment
    }

    // Standardmäßig SI-Präfixe verwenden
    int num_power = si_prefixes[num_lower];
    int denom_power = si_prefixes[denom_lower];
    return num_power - denom_power;
}

bool operator==(const string & lhs, const map<string, int> & map);

int main() {
    // Variablen deklarieren
    string a, b, c, d;

    // Benutzeroberfläche erstellen
    clearConsole();
    cout << "**********************************************\n";
    cout << "*     Willkommen zum Bruchgleichungspruefer   *\n";
    cout << "*   (Format: T/m = n/G oder tera/milli)     *\n";
    cout << "**********************************************\n\n";

    // Eingabe mit automatischem Weiterspringen
    cout << "Geben Sie die SI-Praefixe des Zaehlers und Nenners ein:\n";
    cout << "Zaehler a (z. B. T oder tera): ";
    cin >> a;
    clearConsole();

    cout << "**********************************************\n";
    cout << "a: " << a << "\n";
    cout << "Nenner b (z. B. m oder milli): ";
    cin >> b;
    clearConsole();

    cout << "**********************************************\n";
    cout << "Ihr erster Bruch: " << a << "/" << b << "\n";
    cout << "Zaehler c (z. B. n oder nano): ";
    cin >> c;
    clearConsole();

    cout << "**********************************************\n";
    cout << "Ihr erster Bruch: " << a << "/" << b << "\n";
    cout << "Nenner d (z. B. G oder giga): ";
    cin >> d;
    clearConsole();

    cout << "**********************************************\n";
    cout << "Ihre Brueche: \n";
    cout << "a/b: " << a << "/" << b << "\n";
    cout << "c/d: " << c << "/" << d << "\n";

    // Berechnung des Verhältnisses
    int numerator_diff = calculatePowerDifference(a, c);
    int denominator_diff = calculatePowerDifference(d, b); // Nennerunterschied wird negiert

    int result = numerator_diff + denominator_diff;

    cout << "Das Ergebnis der Berechnung ist: " << std::scientific << "1e" << result << "\n";

  getchar();
  getchar();

    return 0;
}

