#include <iostream>
#include <string>
using namespace std;

class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    Employe(const string& n, int i, float sb)
        : nom(n), id(i), salaireDeBase(sb) {}

virtual ~Employe() {
        cout << "[Destructeur Employe] " << nom << endl;
    }


    virtual void afficherInfos() const {
        cout << "Employe  | Nom: " << nom
             << " | ID: " << id
             << " | Salaire base: " << salaireDeBase << " DH" << endl;
    }
};


class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(const string& n, int i, float sb, float prime)
        : Employe(n, i, sb), primeAnnuelle(prime) {}

    ~Permanent() override {
        cout << "[Destructeur Permanent] " << nom << endl;
    }

    void afficherInfos() const override {
        cout << "Permanent | Nom: " << nom
             << " | ID: " << id
             << " | Salaire base: " << salaireDeBase << " DH"
             << " | Prime annuelle: " << primeAnnuelle << " DH" << endl;
    }
};


class Contractuel : public Employe {
private:
    int dureeContrat;
    float tauxHoraire;
public:
    Contractuel(const string& n, int i, float sb, int duree, float taux)
        : Employe(n, i, sb), dureeContrat(duree), tauxHoraire(taux) {}

    ~Contractuel() override {
        cout << "[Destructeur Contractuel] " << nom << endl;
    }


    float calculerSalaireMensuel(int heures) const {

        return salaireDeBase + (tauxHoraire * heures);
    }

    void afficherInfos() const override {
        cout << "Contractuel | Nom: " << nom
             << " | ID: " << id
             << " | Durée: " << dureeContrat << " mois"
             << " | Taux horaire: " << tauxHoraire << " DH/h"
             << " | Base fixe: " << salaireDeBase << " DH" << endl;
    }
};


int main() {
    cout << "=== Début du programme ===\n";

    const int N = 4;
    Employe** staff = new Employe*[N];

    staff[0] = new Permanent("Amine", 1001, 9000.0f, 12000.0f);
    staff[1] = new Permanent("Sara",  1002, 8500.0f,  8000.0f);
    staff[2] = new Contractuel("Hiba", 2001, 1500.0f, 6, 120.0f);
    staff[3] = new Contractuel("Yassine", 2002, 0.0f, 3, 95.0f);

    cout << "\n--- Fiches employés (polymorphisme) ---\n";
    for (int i = 0; i < N; ++i) {
        staff[i]->afficherInfos();
    }


    cout << "\n--- Simulation paie contractuels ---\n";
    Contractuel* c1 = dynamic_cast<Contractuel*>(staff[2]);
    Contractuel* c2 = dynamic_cast<Contractuel*>(staff[3]);
    if (c1) cout << "Salaire du mois (Hiba, 160 h) : " << c1->calculerSalaireMensuel(160) << " DH\n";
    if (c2) cout << "Salaire du mois (Yassine, 120 h) : " << c2->calculerSalaireMensuel(120) << " DH\n";

    cout << "\n--- Libération mémoire ---\n";
    for (int i = 0; i < N; ++i) {
        delete staff[i];
    }
    delete[] staff;

    cout << "=== Fin du programme ===\n";
    return 0;
}
