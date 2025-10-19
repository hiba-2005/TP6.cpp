#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Produit {
protected:
    string nom;
    double prix;

public:
    Produit(const string& n, double p) : nom(n), prix(p) {}
    virtual ~Produit() = default;

    virtual void afficherInfos() const {
        cout << "Produit : " << nom << " | Prix : " << prix << " DH\n";
    }
};


class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;

public:
    ProduitAlimentaire(const string& n, double p, const string& dateExp)
        : Produit(n, p), dateExpiration(dateExp) {}

    void afficherInfos() const override {
        cout << "Produit Alimentaire : " << nom
             << " | Prix : " << prix << " DH"
             << " | Date d'expiration : " << dateExpiration << "\n";
    }
};


class ProduitElectronique : public Produit {
private:
    int garantieMois;
public:
    ProduitElectronique(const string& n, double p, int garantie)
        : Produit(n, p), garantieMois(garantie) {}

    void afficherInfos() const override {
        cout << "Produit Electronique : " << nom
             << " | Prix : " << prix << " DH"
             << " | Garantie : " << garantieMois << " mois\n";
    }
};


int main() {
    cout << "=== Début du programme ===\n";


    vector<unique_ptr<Produit>> catalogue;
    catalogue.push_back(make_unique<ProduitAlimentaire>("Lait UHT", 10.5, "2026-03-15"));
    catalogue.push_back(make_unique<ProduitElectronique>("Casque Bluetooth", 499.0, 24));
    catalogue.push_back(make_unique<ProduitAlimentaire>("Yaourt Fraise", 4.2, "2025-11-30"));
    catalogue.push_back(make_unique<ProduitElectronique>("Laptop i7", 12999.0, 12));

    cout << "\n--- Catalogue ---\n";
    for (const auto& p : catalogue) {
        p->afficherInfos();
    }

    cout << "=== Fin du programme ===\n";
    return 0;
}
