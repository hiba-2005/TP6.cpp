#include <iostream>
#include <string>
using namespace std;


class Personne {
protected:
    string nom;
    int age;

public:

    Personne(const string& n, int a) : nom(n), age(a) {
        cout << "[Constructeur Personne] " << nom << " (" << age << " ans)" << endl;
    }


    void afficher() const {
        cout << "Nom : " << nom << " | �ge : " << age << endl;
    }
};


class Etudiant : public Personne {
private:
    string niveau;

public:

    Etudiant(const string& n, int a, const string& niv)
        : Personne(n, a), niveau(niv) {
        cout << "[Constructeur Etudiant] Niveau : " << niveau << endl;
    }


    void afficher() const {
        cout << "Nom : " << nom
             << " | �ge : " << age
             << " | Niveau : " << niveau << endl;
    }
};


int main() {
    cout << "=== D�but du programme ===" << endl;

    Etudiant e1("Hiba", 21, "Licence 3");
    cout << "\n--- Informations de l'�tudiant ---" << endl;
    e1.afficher();

    cout << "=== Fin du programme ===" << endl;
    return 0;
}
