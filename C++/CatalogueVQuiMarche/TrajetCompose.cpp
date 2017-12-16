/*************************************************************************
                                 TrajetCompose
                             -------------------
    début                : 15/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

    
void TrajetCompose::Save(fstream& fs) const
// Algorithme : aucun
{
	fs << "TCD" << endl;
	fs << GetDepart() << endl;
	fs << GetArrivee() << endl;
	ElementListe* cur = liste->first;
	while(cur!=nullptr)
	{
		cur->trajet->Save(fs);
		cur = cur->suivant;
	}
 	fs << "TCF" <<endl;
} //----- Fin de Save

 void TrajetCompose::Affiche() const
// Algorithme : aucun
{
	if(liste->first == nullptr)
	{
		cout << "Erreur : TrajetCompose vide"<<endl;
		return;
	}
	Trajet::Affiche();
	cout << endl;
	liste->Affiche("            ");
	 
} //----- Fin de Affiche

 bool TrajetCompose::Add(const Trajet* t) const
// Algorithme : on ajoute le trajet *t en fin de liste
 {
 	if(liste->first == nullptr)
	{
		cout<<"Erreur : TrajetCompose vide"<<endl;
		return false;
	}
	ElementListe* cur = liste->first;
	ElementListe* next = cur->suivant;
	while(next!=nullptr)
	{
		cur = next;
		next = cur->suivant;
	}
	if(cur->trajet->IsBefore(*t))
	{
		liste->Add(t);
		return true;
	}
	else
	{
		cout<<"Erreur: Les trajets ne se suivent pas"<<endl;
		return false;
	}
 } //----- Fin de Add

 bool TrajetCompose::IsBefore(const Trajet& t) const
// Algorithme : aucun
 {
	 return Trajet::IsBefore(t);
 } //----- Fin de IsBefore

 const char* TrajetCompose::GetDepart() const
// Algorithme : aucun
 {
	if(liste->first == nullptr)
	{
		cout<<"Erreur TrajetCompose::GetDepart"<<endl;
		return "";
	}
	return liste->first->trajet->GetDepart();
} //----- Fin de GetDepart

const char* TrajetCompose::GetArrivee() const
// Algorithme : aucun
 {
	if(liste->first == nullptr)
	{
		cout<<"Erreur TrajetCompose::GetArrivee"<<endl;
		return "";
	}
	ElementListe* cur = liste->first;
	ElementListe* next = cur->suivant;
	while(next!=nullptr)
	{
		cur = next;
		next = cur->suivant;
	}
	return cur->trajet->GetArrivee();
 } //----- Fin de GetArrivee

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (const Trajet* t1, const Trajet* t2)
// Algorithme : aucun
{
	if(t1->IsBefore(*t2)) {
		liste = new Liste();
		liste->Add(t1);
		liste->Add(t2);
	}
	else {
		liste = nullptr;
		cout<<"Erreur: Les trajets ne se suivent pas"<<endl;
	}
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	delete liste;
} //----- Fin de ~TrajetCompose
