/*************************************************************************
                                  Catalogue
                             -------------------
    début                : 18/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/

//------ Interface de la classe <Catalogue> (fichier Catalogue.h) --------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "Liste.h"

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Cette classe permet de gérer de stocker des trajets et effectuer des 
// recherches
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
	void Affiche() const;
    // Mode d'emploi : affiche les trajets du contexte appelant
    // Contrat : aucun
    
	bool Add(const Trajet* t) const;
    // Mode d'emploi : retourne false et ne fait rien si le trajet et 
	//      déjà présent, sinon ajoute le trajet et retourne true
    // Contrat : aucun

	unsigned int RechercheParcours(const char* depart,
											const char* arrivee ) const;
    // Mode d'emploi : recherche de trajets qui vont de depart à arrivee 	 //      et renvoie le nombre de solution
    // Contrat : depart et arrivee sont non nulls
    
	void RechercheParcoursAvancee(const char* depart,
											const char* arrivee ) const;
    // Mode d'emploi : recherche les compositions de trajets qui vont de 	 //     depart à arrivee et affiche toutes les solutions
    // Contrat : depart et arrivee sont non nulls

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( );
    // Mode d'emploi : aucun
    // Contrat : aucun

    virtual ~Catalogue ( );
    // Mode d'emploi : aucun
    // Contrat : aucun

//---------------------------------------------------------------- PROTEGE
protected:
//----------------------------------------------------- Attributs protégés
	Liste* liste;

//------------------------------------------------------------------ PRIVE
private:
//------------------------------------------------------- Methodes privées
	void rechercheRecursive (const char* depart, const char* arrivee, 
					 	unsigned int* tab,const unsigned int lengthTab, 						const unsigned int position) const;
    // Mode d'emploi : sous methode de RechercheParcoursAvancee qui
	//     recherche les compositions de trajets qui vont de depart à 
	//     arrivee et affiche toutes les solutions. Tab est un tableau de 
	//     même longueur que le nombre de trajets du catalogue. Il est 
	//     remplit de 0 pour les trajets qui ne sont pas utilisés et de 
	//     nombres strictement positifs représentant l'ordre 
	//     d'utilisation pour les trajets utilisés. Position est alors la 
	//     position qui va être occupée par le prochain trajet qui 
	//     satisfait la recherche.
    // Contrat : depart, arrivee, tab et position sont non nulls et 
	//     lengthTab est la longueur du tableau tab

};

#endif // Catalogue_H
