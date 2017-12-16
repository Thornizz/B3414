/*************************************************************************
                                  TrajetSimple
                             -------------------
    début                : 15/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Cette classe implémente les trajets simples
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    void Affiche () const;
    // Mode d'emploi : affiche les attributs du contexte appelant
    // Contrat : aucun
    
	bool IsBefore(const Trajet& t) const;
    // Mode d'emploi : retourne true si le départ de t correspond à 
	//     l'arrivée du contexte appelant. Sinon retourne false.
    // Contrat : aucun

	const char* GetDepart() const;
    // Mode d'emploi : renvoi le départ
    // Contrat : aucun
    
	const char* GetArrivee() const;
    // Mode d'emploi : renvoi l'arrivée
    // Contrat : aucun
    
	const char* GetMoyenTransport() const;
    // Mode d'emploi : renvoi le moyen de transport
    // Contrat : aucun
    
	void Save(const ofstream& ofs) const;
    // Mode d'emploi : ecriture du trajet dans un fichier de sauvegarde
    //     via l'ofstream passé en paramêtre
    // Contrat : aucun

//-------------------------------------------- Constructeurs - destructeur
	TrajetSimple (const char* d, const char* a, const char* mT);
    // Mode d'emploi : d le départ du trajet, a l'arrivée du trajet et mT 
	//     le moyen de transport du trajet
    // Contrat : d, a et mT sont non nuls

    virtual ~TrajetSimple ( );
    // Mode d'emploi : aucun
    // Contrat : aucun

//---------------------------------------------------------------- PROTEGE
protected:
//----------------------------------------------------- Attributs protégés
	const char *depart, *arrivee, *moyenTransport;

};

#endif // TrajetSimple_H
