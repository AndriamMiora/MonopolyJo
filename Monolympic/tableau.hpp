#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Pion.hpp"
#include "Des.hpp"
#include "Button.hpp"
#include "case.hpp"
#include "casechance.hpp"
#include "casedepart.hpp"
#include "casefermeture.hpp"
#include "casenormale.hpp"
#include "casepropriete.hpp"
#include "casequiz.hpp"
#include "caseservicepublic.hpp"
#include "casetaxe.hpp"
#include "joueur.hpp"

#pragma once
#include <vector>

class Tableau {
    private:
    std::vector<Case*> cases; // Utilisez un vecteur de pointeurs de la classe de base
    std::vector<Joueur*> joueurs; // Utilisez un vecteur de pointeurs de la classe de base

public:
    Tableau() {
        ajouterCaseDepart(0, 0);
        addPropertyCase(1 , 200);
        addQuizCase(2);
        addPropertyCase(3 , 200);
        addTaxCase(4 , 10);
        addNormalCase(5);
        addPropertyCase(6, 200);
        addChanceCase(7);
        addPropertyCase(8 , 200);
        addPropertyCase(9 , 200);
        addNormalCase(10);
        addPropertyCase(11 , 200);
        addServiceCase(12, "Électricité");
        addPropertyCase(13 , 200);
        addPropertyCase(14 , 200);
        addChanceCase(15);
        addPropertyCase(16 , 200);
        addQuizCase(17);
        addPropertyCase(18 , 200);
        addPropertyCase(19 , 200);
        addNormalCase(20);
        addPropertyCase(21 , 200);
        addPropertyCase(22 , 200);
        addChanceCase(23);
        addPropertyCase(24 , 200);
        addPropertyCase(25 , 200);
        addTaxCase(26 , 10);
        addPropertyCase(27 , 200);
        addQuizCase(28);
        addPropertyCase(29 , 200);
        addCloseCityCase(30);
        addPropertyCase(31 , 200);
        addPropertyCase(32 , 200);
        addQuizCase(33);
        addPropertyCase(34 , 200);
        addServiceCase(35, "Main d'œuvre");
        addChanceCase(36);
        addPropertyCase(37 , 200);
        addServiceCase(38, "Eau");
        addPropertyCase(39 , 200);
    }

    std::vector<sf::Vector2f> getPoints();

    std::vector<sf::Sprite> initializeDiceSprites(Des& des, sf::Vector2f buttonPosition, int& position, std::vector<sf::Vector2f> points, Joueur& joueur);
    // Méthodes pour ajouter des instances spécifiques de cases en fonction de leur type
   void addChanceCase(int position) {
        cases.push_back(new CaseChance(position));
    }

    void ajouterCaseDepart(int position, int medailles) {
        cases.push_back(new CaseDepart(medailles, position));
    }

    void addCloseCityCase(int position) {
        cases.push_back(new CaseFermetureVille(position));
    }

    void addNormalCase(int position) {
        cases.push_back(new CaseNormale(position));
    }

    void addPropertyCase(int position, int cout) {
        cases.push_back(new CasePropriete(position, cout));
    }

    void addQuizCase(int position) {
        cases.push_back(new CaseQuiz(position));
    }

    void addServiceCase(int position, const std::string& type) {
        cases.push_back(new CaseServicePublic(position, type));
    }

    void  addTaxCase(int position, int montant) {
        cases.push_back(new CaseTaxe(montant,position));
    }

   // Renvoie la case à une position donnée
    Case* getCaseAtPosition(int pos) const {
        for (Case* c : cases) {
            if (c->getPosition() == pos) {
                return c;
            }
        }
        return nullptr; // Aucune case à cette position
    }

    // Méthode pour effectuer l'action de la case à une position donnée
    void actionAtPosition(int pos) const {
        Case* c = getCaseAtPosition(pos);
        if (c != nullptr) {
            c->action( *joueurs[0]);
            std::cout << "nombre de médailles : " << joueurs[0]->getPoints() << std::endl;
        } else {
            std::cout << "Aucune case à la position " << pos << "." << std::endl;
        }
    }
    // Méthode pour ajouter un joueur au tableau
    void addJoueur(Joueur* joueur) {
        joueurs.push_back(joueur);
    }

    // Méthode pour récupérer tous les joueurs
    std::vector<Joueur*> getJoueurs() const {
        return joueurs;
    }

    // Méthode pour récupérer un joueur par son index dans le vecteur
    Joueur* getJoueurAtIndex(int index) const {
        if (index >= 0 && index < joueurs.size()) {
            return joueurs[index];
        }
        return nullptr; // Index invalide
    }

    // Méthode pour mettre à jour le pion et les points d'un joueur
    void updateJoueur(Joueur* joueur, Pion* pion, int points) {
        joueur->setPion(pion);
        joueur->setPoints(points);
    }

};
