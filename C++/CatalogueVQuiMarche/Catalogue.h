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
    // Mode d'emploi : recherche de trajets qui vont de depart à arrivee 	 
    //      et renvoie le nombre de solution
    // Contrat : depart et arrivee sont non nuls

	void RechercheParcoursAvancee(const char* depart,
											const char* arrivee ) const;
    // Mode d'emploi : recherche les compositions de trajets qui vont de 	 
    //     depart à arrivee et affiche toutes les solutions
    // Contrat : depart et arrivee sont non nuls

	void GetSauvegarde() const;
	// Mode d'emploi : ajoute tous les trajets sauvegardés
	// Contrat : aucun

	void GetSauvegardeTypeTrajet(bool simple) const;
	// Mode d'emploi : ajoute les trajets simples (type=true) ou composés
	//      (type=false) sauvegardés
	// Contrat : aucun

	void GetSauvegardeDepartArrivee(string depart, string arrivee) const;
	// Mode d'emploi : ajoute les trajets sauvegardés selon la ville de
	//     depart et/ou d'arrivee
	// Contrat : aucun
	
	int GetNbTotalDeTrajet() const;
	// Mode d'emploi : renvoie le nombre total de trajets sauvegardés dans
	//     le fichier de sauvegarde
	// Contrat : le fichier de sauvegarde est renseigné

	void GetSauvegardeDelta(int min, int max) const;
	// Mode d'emploi : ajoute les trajets sauvegardés entre les indices
	//     min et max
	// Contrat : min < max <= nombre total de trajet dans la sauvegarde et
	//     le fichier de sauvegarde est renseigné

	void SetFichierSauvegarde(string fichier);
	// Mode d'emploi : modifie le fichier de sauvegarde
	// Contrat : aucun
	
	void Save() const;
	// Mode d'emploi : ajoute tous les trajets au fichier de sauvegarde,
	//     si le fichier fichierSauvegarde n'existe pas il est créé
	// Contrat : aucun

	void SaveTypeTrajet(bool simple) const;
	// Mode d'emploi : ajoute les trajets simples (type=true) ou composés
	//     (type=false) au fichier de sauvegarde, si le fichier
	//     fichierSauvegarde n'existe pas il est créé
	// Contrat : aucun

	void SaveDepartArrivee(string depart, string arrivee) const;
	// Mode d'emploi : ajoute les trajets au fichier de sauvegarde selon
	//     la ville de depart et/ou d'arrivee, si le fichier
	//     fichierSauvegarde n'existe pas il est créé
	// Contrat : aucun

	void SaveInterval(unsigned int start, unsigned int end) const;
	// Mode d'emploi : ajoute les trajets au fichier de sauvegarde qui
	//     se situent dans l'interval [start,end]. Si fichierSauvegarde
	//     n'existe pas il est créé
	// Contrat : start est inférieur à end

	unsigned int GetNbTrajet() const;
	// Mode d'emploi : renvoit le nombre de trajets présents dans le
	//     catalogue
	// Contrat : aucun

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
	string fichierSauvegarde;

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
		const unsigned int NB_MAX_CHAR = 100;
//------------------------------------------------------- Methodes privées
	void rechercheRecursive (const char* depart, const char* arrivee,
					 	unsigned int* tab,const unsigned int lengthTab,
			 						const unsigned int position) const;
    // Mode d'emploi : sous methode de RechercheParcoursAvancee qui
	//     recherche les compositions de trajets qui vont de depart à
	//     arrivee et affiche toutes les solutions. Tab est un tableau de
	//     même longueur que le nombre de trajets du catalogue. Il est
	//     remplit de 0 pour les trajets qui ne sont pas utilisés et de
	//     nombres strictement positifs représentant l'ordre
	//     d'utilisation pour les trajets utilisés. Position est alors la
	//     position qui va être occupée par le prochain trajet qui
	//     satisfait la recherche.
    // Contrat : depart, arrivee, tab et position sont non nuls et
	//     lengthTab est la longueur du tableau tab

};

#endif // Catalogue_H
