#include <iostream>
using namespace std;

// Étape 1: Définition de la classe Noeud
class Noeud {
public:
    int valeur;
    Noeud* suivant;
    
    // Constructeur pour faciliter la création
    Noeud(int val) : valeur(val), suivant(nullptr) {}
    
    // Destructeur (optionnel, mais bonne pratique)
    ~Noeud() {}
};

// Étape 2: Fonction d'affichage
void afficherListe(Noeud* tete) {
    if (tete == nullptr) {
        cout << "(liste vide)" << endl;
        return;
    }
    
    Noeud* courant = tete;
    while (courant != nullptr) {
        cout << courant->valeur;
        if (courant->suivant != nullptr) {
            cout << " -> ";
        }
        courant = courant->suivant;
    }
    cout << " -> NULL" << endl;
}

// Étape 2: Fonction d'ajout au début
void ajouterDebut(Noeud*& tete, int valeur) {
    Noeud* nouveauNoeud = new Noeud(valeur);
    nouveauNoeud->suivant = tete;
    tete = nouveauNoeud;
}

// Étape 3: Fonction d'ajout à la fin
void ajouterFin(Noeud*& tete, int valeur) {
    Noeud* nouveauNoeud = new Noeud(valeur);
    
    // Cas liste vide
    if (tete == nullptr) {
        tete = nouveauNoeud;
        return;
    }
    
    // Parcourir jusqu'au dernier nœud
    Noeud* courant = tete;
    while (courant->suivant != nullptr) {
        courant = courant->suivant;
    }
    
    // Ajouter le nouveau nœud à la fin
    courant->suivant = nouveauNoeud;
}

// Étape 4: Fonction de recherche
bool rechercher(Noeud* tete, int valeur) {
    Noeud* courant = tete;
    while (courant != nullptr) {
        if (courant->valeur == valeur) {
            return true;
        }
        courant = courant->suivant;
    }
    return false;
}

// Étape 4: Fonction pour obtenir la position
int obtenirPosition(Noeud* tete, int valeur) {
    Noeud* courant = tete;
    int position = 0;
    
    while (courant != nullptr) {
        if (courant->valeur == valeur) {
            return position;
        }
        courant = courant->suivant;
        position++;
    }
    
    return -1; // Non trouvé
}

// Étape 5: Fonction de suppression
bool supprimerElement(Noeud*& tete, int valeur) {
    // Liste vide
    if (tete == nullptr) {
        return false;
    }
    
    // Suppression en tête
    if (tete->valeur == valeur) {
        Noeud* aSupprimer = tete;
        tete = tete->suivant;
        delete aSupprimer;
        return true;
    }
    
    // Suppression ailleurs dans la liste
    Noeud* courant = tete;
    while (courant->suivant != nullptr) {
        if (courant->suivant->valeur == valeur) {
            Noeud* aSupprimer = courant->suivant;
            courant->suivant = aSupprimer->suivant;
            delete aSupprimer;
            return true;
        }
        courant = courant->suivant;
    }
    
    return false; // Élément non trouvé
}

// Étape 6: Compter les éléments
int compterElements(Noeud* tete) {
    int compteur = 0;
    Noeud* courant = tete;
    
    while (courant != nullptr) {
        compteur++;
        courant = courant->suivant;
    }
    
    return compteur;
}

// Étape 6: Vider la liste
void viderListe(Noeud*& tete) {
    while (tete != nullptr) {
        Noeud* aSupprimer = tete;
        tete = tete->suivant;
        delete aSupprimer;
    }
    cout << "Liste vidée avec succès." << endl;
}

// Étape 6: Inverser la liste
void inverserListe(Noeud*& tete) {
    if (tete == nullptr || tete->suivant == nullptr) {
        return; // Liste vide ou un seul élément
    }
    
    Noeud* precedent = nullptr;
    Noeud* courant = tete;
    Noeud* suivant = nullptr;
    
    while (courant != nullptr) {
        suivant = courant->suivant;
        courant->suivant = precedent;
        precedent = courant;
        courant = suivant;
    }
    
    tete = precedent;
}

// Fonction pour insérer à une position donnée (Défi bonus)
bool insererPosition(Noeud*& tete, int position, int valeur) {
    if (position < 0) {
        return false;
    }
    
    // Insertion en position 0 (début)
    if (position == 0) {
        ajouterDebut(tete, valeur);
        return true;
    }
    
    // Trouver la position d'insertion
    Noeud* courant = tete;
    for (int i = 0; i < position - 1 && courant != nullptr; i++) {
        courant = courant->suivant;
    }
    
    // Position invalide
    if (courant == nullptr) {
        return false;
    }
    
    // Insérer le nouveau nœud
    Noeud* nouveauNoeud = new Noeud(valeur);
    nouveauNoeud->suivant = courant->suivant;
    courant->suivant = nouveauNoeud;
    
    return true;
}

// Fonction de tri (tri à bulles simple) - Défi bonus
void trierListe(Noeud*& tete) {
    if (tete == nullptr || tete->suivant == nullptr) {
        return; // Liste vide ou un seul élément
    }
    
    bool echange = true;
    while (echange) {
        echange = false;
        Noeud* courant = tete;
        
        while (courant->suivant != nullptr) {
            if (courant->valeur > courant->suivant->valeur) {
                // Échanger les valeurs
                int temp = courant->valeur;
                courant->valeur = courant->suivant->valeur;
                courant->suivant->valeur = temp;
                echange = true;
            }
            courant = courant->suivant;
        }
    }
}

// Fonction d'affichage du menu
void afficherMenu() {
    cout << "\n=== GESTIONNAIRE DE LISTE CHAÎNÉE ===" << endl;
    cout << "1. Ajouter au début" << endl;
    cout << "2. Ajouter à la fin" << endl;
    cout << "3. Rechercher élément" << endl;
    cout << "4. Supprimer élément" << endl;
    cout << "5. Afficher liste" << endl;
    cout << "6. Compter éléments" << endl;
    cout << "7. Inverser liste" << endl;
    cout << "8. Insérer à position" << endl;
    cout << "9. Trier liste" << endl;
    cout << "10. Vider liste" << endl;
    cout << "11. Quitter" << endl;
    cout << "Votre choix : ";
}

// Fonction de test pour démontrer chaque étape
void demonstrationEtapes() {
    cout << "=== DÉMONSTRATION DES ÉTAPES ===" << endl;
    
    // Étape 1: Création manuelle de nœuds
    cout << "\nÉtape 1: Création manuelle de 3 nœuds (avec classe)" << endl;
    Noeud* noeud1 = new Noeud(10);
    Noeud* noeud2 = new Noeud(20);
    Noeud* noeud3 = new Noeud(30);
    
    noeud1->suivant = noeud2;
    noeud2->suivant = noeud3;
    
    cout << "Liste manuelle: ";
    afficherListe(noeud1);
    
    // Nettoyer
    delete noeud1;
    delete noeud2;
    delete noeud3;
    
    // Étape 2: Test ajout au début
    cout << "\nÉtape 2: Ajout au début" << endl;
    Noeud* liste = nullptr;
    
    ajouterDebut(liste, 30);
    cout << "Après ajout de 30: ";
    afficherListe(liste);
    
    ajouterDebut(liste, 20);
    cout << "Après ajout de 20: ";
    afficherListe(liste);
    
    ajouterDebut(liste, 10);
    cout << "Après ajout de 10: ";
    afficherListe(liste);
    
    // Étape 3: Test ajout à la fin
    cout << "\nÉtape 3: Ajout à la fin" << endl;
    ajouterFin(liste, 40);
    cout << "Après ajout de 40: ";
    afficherListe(liste);
    
    ajouterFin(liste, 50);
    cout << "Après ajout de 50: ";
    afficherListe(liste);
    
    // Étape 4: Test recherche
    cout << "\nÉtape 4: Recherche d'éléments" << endl;
    int valeursRecherche[] = {30, 60, 10};
    for (int val : valeursRecherche) {
        bool trouve = rechercher(liste, val);
        int position = obtenirPosition(liste, val);
        cout << "Recherche de " << val << ": ";
        if (trouve) {
            cout << "Trouvé à la position " << position << endl;
        } else {
            cout << "Non trouvé (position -1)" << endl;
        }
    }
    
    // Étape 5: Test suppression
    cout << "\nÉtape 5: Suppression d'éléments" << endl;
    cout << "Liste avant suppression: ";
    afficherListe(liste);
    
    bool succes = supprimerElement(liste, 30);
    cout << "Suppression de 30: ";
    afficherListe(liste);
    cout << (succes ? "(Réussi)" : "(Échec)") << endl;
    
    succes = supprimerElement(liste, 60);
    cout << "Suppression de 60: ";
    afficherListe(liste);
    cout << (succes ? "(Réussi)" : "(Échec - élément non trouvé)") << endl;
    
    // Étape 6: Test fonctions utilitaires
    cout << "\nÉtape 6: Fonctions utilitaires" << endl;
    cout << "Nombre d'éléments: " << compterElements(liste) << endl;
    
    cout << "Liste avant inversion: ";
    afficherListe(liste);
    
    inverserListe(liste);
    cout << "Liste après inversion: ";
    afficherListe(liste);
    
    // Test tri
    cout << "\nTest de tri:" << endl;
    ajouterDebut(liste, 5);
    ajouterFin(liste, 25);
    cout << "Liste avant tri: ";
    afficherListe(liste);
    
    trierListe(liste);
    cout << "Liste après tri: ";
    afficherListe(liste);
    
    viderListe(liste);
}

// Programme principal avec menu interactif
int main() {
    // Démonstration des étapes
    demonstrationEtapes();
    
    // Menu interactif
    Noeud* liste = nullptr;
    int choix;
    
    do {
        afficherMenu();
        cin >> choix;
        
        switch (choix) {
            case 1: {
                int valeur;
                cout << "Valeur à ajouter au début : ";
                cin >> valeur;
                ajouterDebut(liste, valeur);
                cout << "Élément ajouté avec succès." << endl;
                break;
            }
            
            case 2: {
                int valeur;
                cout << "Valeur à ajouter à la fin : ";
                cin >> valeur;
                ajouterFin(liste, valeur);
                cout << "Élément ajouté avec succès." << endl;
                break;
            }
            
            case 3: {
                int valeur;
                cout << "Valeur à rechercher : ";
                cin >> valeur;
                int position = obtenirPosition(liste, valeur);
                if (position != -1) {
                    cout << "Élément trouvé à la position " << position << endl;
                } else {
                    cout << "Élément non trouvé." << endl;
                }
                break;
            }
            
            case 4: {
                int valeur;
                cout << "Valeur à supprimer : ";
                cin >> valeur;
                bool succes = supprimerElement(liste, valeur);
                if (succes) {
                    cout << "Élément supprimé avec succès." << endl;
                } else {
                    cout << "Élément non trouvé." << endl;
                }
                break;
            }
            
            case 5: {
                cout << "Liste actuelle: ";
                afficherListe(liste);
                break;
            }
            
            case 6: {
                int nombre = compterElements(liste);
                cout << "Nombre d'éléments: " << nombre << endl;
                break;
            }
            
            case 7: {
                inverserListe(liste);
                cout << "Liste inversée avec succès." << endl;
                break;
            }
            
            case 8: {
                int position, valeur;
                cout << "Position d'insertion : ";
                cin >> position;
                cout << "Valeur à insérer : ";
                cin >> valeur;
                bool succes = insererPosition(liste, position, valeur);
                if (succes) {
                    cout << "Élément inséré avec succès." << endl;
                } else {
                    cout << "Position invalide." << endl;
                }
                break;
            }
            
            case 9: {
                trierListe(liste);
                cout << "Liste triée avec succès." << endl;
                break;
            }
            
            case 10: {
                viderListe(liste);
                break;
            }
            
            case 11: {
                cout << "Au revoir!" << endl;
                break;
            }
            
            default: {
                cout << "Choix invalide. Veuillez réessayer." << endl;
                break;
            }
        }
        
    } while (choix != 11);
    
    // Nettoyer la mémoire avant de quitter
    if (liste != nullptr) {
        viderListe(liste);
    }
    
    return 0;
}