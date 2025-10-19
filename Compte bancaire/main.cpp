#include <iostream>
#include <string>
using namespace std;


class Compte {
protected:
    int numero;
    double solde;

public:

    Compte(int num, double s) : numero(num), solde(s) {
        cout << "[Constructeur Compte] Numéro : " << numero << " | Solde initial : " << solde << " DH" << endl;
    }


    void deposer(double montant) {
        solde += montant;
        cout << "Dépôt de " << montant << " DH effectué. Nouveau solde : " << solde << " DH" << endl;
    }


    void retirer(double montant) {
        if (montant <= solde) {
            solde -= montant;
            cout << "Retrait de " << montant << " DH effectué. Nouveau solde : " << solde << " DH" << endl;
        } else {
            cout << "Fonds insuffisants pour retirer " << montant << " DH." << endl;
        }
    }


    void afficher() const {
        cout << "Compte N°" << numero << " | Solde : " << solde << " DH" << endl;
    }
};


class CompteEpargne : public Compte {
private:
    double tauxInteret;

public:

    CompteEpargne(int num, double s, double taux)
        : Compte(num, s), tauxInteret(taux) {
        cout << "[Constructeur CompteEpargne] Taux d'intérêt : " << tauxInteret << "%" << endl;
    }


    void calculerInteret() {
        double interet = solde * (tauxInteret / 100);
        solde += interet;
        cout << "Intérêt ajouté : " << interet << " DH | Nouveau solde : " << solde << " DH" << endl;
    }


    void afficher() const {
        cout << "Compte Épargne N°" << numero
             << " | Solde : " << solde
             << " DH | Taux d'intérêt : " << tauxInteret << "%" << endl;
    }
};


int main() {
    cout << "=== Début du programme ===" << endl;


    CompteEpargne ce1(1001, 5000.0, 4.5);

    cout << "\n--- Détails du compte ---" << endl;
    ce1.afficher();

    cout << "\n--- Opérations bancaires ---" << endl;
    ce1.deposer(1000.0);
    ce1.retirer(1200.0);
    ce1.calculerInteret();

    cout << "\n--- Situation finale ---" << endl;
    ce1.afficher();

    cout << "=== Fin du programme ===" << endl;
    return 0;
}
