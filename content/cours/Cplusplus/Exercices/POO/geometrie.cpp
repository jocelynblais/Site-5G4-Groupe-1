#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cmath>
#include <iomanip>

// Classe de base abstraite
class Forme {
protected:
    std::string nom;
    std::string couleur;

public:
    // Constructeur
    Forme(const std::string& nom, const std::string& couleur) 
        : nom(nom), couleur(couleur) {}
    
    // Destructeur virtuel
    virtual ~Forme() = default;
    
    // Méthodes virtuelles pures
    virtual double calculerAire() const = 0;
    virtual double calculerPerimetre() const = 0;
    
    // Méthode virtuelle
    virtual void afficher() const {
        std::cout << nom << " (" << couleur << ")" << std::endl;
    }
    
    // Getters
    std::string getNom() const { return nom; }
    std::string getCouleur() const { return couleur; }
};

// Classe Rectangle
class Rectangle : public Forme {
private:
    double largeur;
    double hauteur;

public:
    Rectangle(const std::string& nom, const std::string& couleur, 
             double largeur, double hauteur)
        : Forme(nom, couleur), largeur(largeur), hauteur(hauteur) {}
    
    double calculerAire() const override {
        return largeur * hauteur;
    }
    
    double calculerPerimetre() const override {
        return 2 * (largeur + hauteur);
    }
    
    void afficher() const override {
        std::cout << "Rectangle ";
        Forme::afficher();
        std::cout << "  Largeur: " << largeur 
                  << ", Hauteur: " << hauteur << std::endl;
        std::cout << "  Aire: " << calculerAire() 
                  << ", Périmètre: " << calculerPerimetre() << std::endl;
    }
    
    // Getters
    double getLargeur() const { return largeur; }
    double getHauteur() const { return hauteur; }
};

// Classe Cercle
class Cercle : public Forme {
private:
    double rayon;
    static constexpr double PI = 3.14159265359;

public:
    Cercle(const std::string& nom, const std::string& couleur, double rayon)
        : Forme(nom, couleur), rayon(rayon) {}
    
    double calculerAire() const override {
        return PI * rayon * rayon;
    }
    
    double calculerPerimetre() const override {
        return 2 * PI * rayon;
    }
    
    void afficher() const override {
        std::cout << "Cercle ";
        Forme::afficher();
        std::cout << "  Rayon: " << rayon << std::endl;
        std::cout << "  Aire: " << std::fixed << std::setprecision(4) 
                  << calculerAire() << ", Périmètre: " 
                  << calculerPerimetre() << std::endl;
    }
    
    double getRayon() const { return rayon; }
};

// Classe Triangle
class Triangle : public Forme {
private:
    double base;
    double hauteur;
    double cote1, cote2; // pour le calcul du périmètre

public:
    Triangle(const std::string& nom, const std::string& couleur, 
            double base, double hauteur, double cote1 = 0, double cote2 = 0)
        : Forme(nom, couleur), base(base), hauteur(hauteur), 
          cote1(cote1), cote2(cote2) {
        // Si les côtés ne sont pas fournis, on calcule pour un triangle isocèle
        if (cote1 == 0 || cote2 == 0) {
            // Triangle isocèle : calcul des côtés égaux
            double demi_base = base / 2.0;
            this->cote1 = this->cote2 = std::sqrt(demi_base * demi_base + hauteur * hauteur);
        }
    }
    
    double calculerAire() const override {
        return (base * hauteur) / 2.0;
    }
    
    double calculerPerimetre() const override {
        return base + cote1 + cote2;
    }
    
    void afficher() const override {
        std::cout << "Triangle ";
        Forme::afficher();
        std::cout << "  Base: " << base << ", Hauteur: " << hauteur << std::endl;
        std::cout << "  Aire: " << calculerAire() 
                  << ", Périmètre: " << std::fixed << std::setprecision(4) 
                  << calculerPerimetre() << std::endl;
    }
    
    double getBase() const { return base; }
    double getHauteur() const { return hauteur; }
};

// Classe GestionnaireFormes
class GestionnaireFormes {
private:
    std::vector<std::unique_ptr<Forme>> formes;

public:
    // Destructeur par défaut (les unique_ptr se détruisent automatiquement)
    ~GestionnaireFormes() = default;
    
    void ajouterForme(std::unique_ptr<Forme> forme) {
        formes.push_back(std::move(forme));
    }
    
    void afficherToutesLesFormes() const {
        std::cout << "=== Affichage de toutes les formes ===" << std::endl;
        for (const auto& forme : formes) {
            forme->afficher();
            std::cout << std::endl;
        }
    }
    
    double calculerAireTotale() const {
        double aireTotal = 0.0;
        for (const auto& forme : formes) {
            aireTotal += forme->calculerAire();
        }
        return aireTotal;
    }
    
    size_t getNombreFormes() const {
        return formes.size();
    }
    
    // Méthode bonus : trouver la forme avec la plus grande aire
    const Forme* trouverPlusGrandeAire() const {
        if (formes.empty()) return nullptr;
        
        const Forme* plusGrande = formes[0].get();
        double aireMax = plusGrande->calculerAire();
        
        for (const auto& forme : formes) {
            double aire = forme->calculerAire();
            if (aire > aireMax) {
                aireMax = aire;
                plusGrande = forme.get();
            }
        }
        return plusGrande;
    }
};

// Opérateur << pour l'affichage des formes
std::ostream& operator<<(std::ostream& os, const Forme& forme) {
    forme.afficher();
    return os;
}

// Programme principal
int main() {
    // Création du gestionnaire
    GestionnaireFormes gestionnaire;
    
    std::cout << "=== Création des formes ===" << std::endl;
    
    // Création des formes avec des pointeurs intelligents
    auto rectangle = std::make_unique<Rectangle>("Mon Rectangle", "Rouge", 5.0, 3.0);
    auto cercle = std::make_unique<Cercle>("Mon Cercle", "Bleu", 4.0);
    auto triangle = std::make_unique<Triangle>("Mon Triangle", "Vert", 6.0, 4.0);
    
    // Démonstration du polymorphisme avant d'ajouter au gestionnaire
    std::vector<std::unique_ptr<Forme>> formesDemo;
    formesDemo.push_back(std::make_unique<Rectangle>("Rectangle Demo", "Jaune", 2.0, 8.0));
    formesDemo.push_back(std::make_unique<Cercle>("Cercle Demo", "Violet", 3.0));
    
    std::cout << "Démonstration du polymorphisme:" << std::endl;
    for (const auto& forme : formesDemo) {
        std::cout << "Aire de " << forme->getNom() << ": " 
                  << forme->calculerAire() << std::endl;
    }
    std::cout << std::endl;
    
    // Ajout des formes au gestionnaire
    gestionnaire.ajouterForme(std::move(rectangle));
    gestionnaire.ajouterForme(std::move(cercle));
    gestionnaire.ajouterForme(std::move(triangle));
    
    // Ajout des formes de démonstration
    for (auto& forme : formesDemo) {
        gestionnaire.ajouterForme(std::move(forme));
    }
    
    // Affichage de toutes les formes
    gestionnaire.afficherToutesLesFormes();
    
    // Calcul et affichage des statistiques
    std::cout << "=== Statistiques ===" << std::endl;
    std::cout << "Nombre total de formes: " << gestionnaire.getNombreFormes() << std::endl;
    std::cout << "Aire totale de toutes les formes: " 
              << std::fixed << std::setprecision(4) 
              << gestionnaire.calculerAireTotale() << std::endl;
    
    // Bonus : forme avec la plus grande aire
    const Forme* plusGrande = gestionnaire.trouverPlusGrandeAire();
    if (plusGrande) {
        std::cout << "Forme avec la plus grande aire: " << plusGrande->getNom() 
                  << " (Aire: " << plusGrande->calculerAire() << ")" << std::endl;
    }
    
    return 0;
}
