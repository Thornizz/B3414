/*************************************************************************
                                  TrajetSimple
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---vopi- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Cette classe permet d'implémenter les trajets simples
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Affiche () const;
    // Mode d'emploi : affiche les caractéristiques du trajet
    //
    // Contrat : aucun
    //
    
	virtual bool IsBefore(Trajet& t) const;
    // Mode d'emploi : retourne true si le départ de t correspond à l'arrivée du contexte appelant. Sinon retourne false.
    //
    // Contrat : aucun
    //

//-------------------------------------------- Constructeurs - destructeur
	TrajetSimple (const char* d, const char* a, const char* mT);
    // Mode d'emploi : d le départ du trajet, a l'arrivée du trajet et mT le moyen de transport du trajet
    //
    // Contrat : aucun
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //

	const char* GetDepart() const;
    // Mode d'emploi : renvoie le départ du trajet
    //
    // Contrat : aucun
    //
    
	const char* GetArrivee() const;
    // Mode d'emploi : renvoie l'arrivée du trajet
    //
    // Contrat : aucun
    //

//---------------------------------------------------------------- PROTEGE

protected:

//----------------------------------------------------- Attributs protégés
const char *depart, *arrivee, *moyenTransport;

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H

