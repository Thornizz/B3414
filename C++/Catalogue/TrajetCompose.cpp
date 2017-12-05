/*************************************************************************
                                 TrajetCompose
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 void TrajetCompose::Affiche() const
// Algorithme : aucun
//
{
	if(liste->first == NULL)
	{
		cout << "Erreur : TrajetCompose vide"<<endl;
		return;
	}

	Trajet::Affiche();
	cout << endl;
	liste->Affiche("            ");
	 
} //----- Fin de Affiche

 bool TrajetCompose::Add(const Trajet* t) const
// Algorithme : aucun
//
 {
 	if(liste->first == NULL){
		cout<<"Erreur TrajetCompose::Add"<<endl;
		return false;
	}
	
	ElementListe* cur = liste->first;
	ElementListe* next = cur->suivant;
	while(next!=NULL){
		cur = next;
		next = cur->suivant;
	}
	
	if(cur->trajet->IsBefore(*t)) {
		liste->Add(t);
		return true;
	}
	else {
		cout<<"Erreur: Les trajets ne se suivent pas"<<endl;
		return false;
	}
 } //----- Fin de Add

 bool TrajetCompose::IsBefore(const Trajet& t) const
// Algorithme : aucun
//
 {
	 return Trajet::IsBefore(t);

 } //----- Fin de IsBefore

 const char* TrajetCompose::GetDepart() const
// Algorithme : aucun
//
 {
	if(liste->first == NULL){
		cout<<"Erreur TrajetCompose::GetDepart"<<endl;
		return "";
	}
	return liste->first->trajet->GetDepart();

 } //----- Fin de GetDepart


 const char* TrajetCompose::GetArrivee() const
// Algorithme : aucun
//
 {

	if(liste->first == NULL){
		cout<<"Erreur TrajetCompose::GetArrivee"<<endl;
		return "";
	}
	ElementListe* cur = liste->first;
	ElementListe* next = cur->suivant;
	while(next!=NULL){
		cur = next;
		next = cur->suivant;
	}
	return cur->trajet->GetArrivee();

 } //----- Fin de GetArrivee

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (const Trajet* t1, const Trajet* t2)
// Algorithme : aucun
//
{
	if(t1->IsBefore(*t2)) {
		liste = new Liste();
		liste->Add(t1);
		liste->Add(t2);
	}
	else {
		liste = NULL;
		cout<<"Erreur: Les trajets ne se suivent pas"<<endl;
	}
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme : aucun
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	delete liste;
} //----- Fin de ~TrajetCompose
