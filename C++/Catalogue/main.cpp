using namespace std;
#include <iostream>
#include "Liste.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
#include "Liste.h"

void testTrajetSimple();
void testListe();
void testTrajetCompose();
void testCatalogue();
void application();

int main (){



/////////////////////////////////////////////////
//
//	enlever les include inutiles
//	verifier que les methodes marche avec catalogue vide
//  mettre les char en majuscule dans les caractéristiques des trajets
//  vérifier si un trajet existe déjà quand on le crée
//
/////////////////////////////////////////////////

/////////////////////////////////////////////////
//
//	la saisie n'est pas propre, il faut pointer une nouvelle zone texte à chaque fois !
//
/////////////////////////////////////////////////

//	testTrajetSimple();
//	testListe();
//	testTrajetCompose();
//	testCatalogue();
	application();
	cout<<endl<<"PENSER A FAIRE : valgrind --leak-check=yes ./demo"<<endl;
	return 0;
}


void testCatalogue(){
	cout<<"********** Test Catalogue **********"<<endl<<endl;
	
	Trajet * pt1 = new TrajetSimple("Paris","Strasbourg","Velo");
	cout<<"pt1 => ";
	pt1->Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;
	
	Trajet * pt2 = new TrajetSimple("Strasbourg","Caluire","Velo");
	cout<<"pt2 => ";
	pt2->Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;

	Trajet* ptc = new TrajetCompose(pt1,pt2);
	cout<<"ptc => ";
	ptc->Affiche();
	cout<<endl;
	cout<<endl<<"*****"<<endl<<endl;
	
	Trajet * pt3 = new TrajetSimple("Lyon","Nice","Velo");
	cout<<"pt3 => ";
	pt3->Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;
	
	Trajet * pt4 = new TrajetSimple("Nantes","Moulins","Velo");
	cout<<"pt4 => ";
	pt4->Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;

	Catalogue c;
	c.Add(ptc);
	c.Add(pt3);
	c.Add(pt4);
	c.Affiche();
	
	cout<<endl<<"***** Fin test Catalogue"<<endl<<endl;
}

void testTrajetCompose(){
	cout<<"********** Test TrajetCompose **********"<<endl<<endl;
	
	Trajet * pt1 = new TrajetSimple("Paris","Strasbourg","Velo");
	cout<<"pt1 => ";
	pt1->Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;
	
	Trajet * pt2 = new TrajetSimple("Strasbourg","Caluire","Velo");
	cout<<"pt2 => ";
	pt2->Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;

	TrajetCompose tc(pt1,pt2);
	tc.Affiche();
	tc.Add(pt1);
	tc.Affiche();
	tc.Add(pt2);
	tc.Affiche();
	
	cout<<endl<<"***** Fin test TrajetCompose"<<endl<<endl;
}

void testListe(){
	cout<<"********** Test Liste **********"<<endl<<endl;
	
	Trajet * pt1 = new TrajetSimple("Paris","Strasbourg","Velo");
	cout<<"pt1 => ";
	pt1->Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;
	
	Trajet * pt2 = new TrajetSimple("Perpignan","Caluire","Velo");
	cout<<"pt2 => ";
	pt2->Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;

	Liste l1;
	l1.Affiche("");
	l1.Add(pt1);
	l1.Affiche("");
	l1.Add(pt2);
	l1.Affiche("");
	
	cout<<endl<<"***** Fin test Liste"<<endl<<endl;
}

void testTrajetSimple(){
	cout<<"********** Test TrajetSimple **********"<<endl<<endl;
	
	TrajetSimple t0("", "", "");
	cout<<"t0 = ";
	t0.Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;
	
	TrajetSimple t1("Lyon", "Marseille", "Train");
	cout<<"t1 = ";
	t1.Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;
	
	TrajetSimple * pt1 = new TrajetSimple("Paris","Strasbourg","Velo");
	cout<<"pt1 => ";
	pt1->Affiche();
	cout<<endl;
	delete pt1;
	
	cout<<endl<<"*****"<<endl<<endl;
	
	Trajet * pt2 = new TrajetSimple("Paris","Strasbourg","Velo");
	cout<<"pt2 => ";
	pt2->Affiche();
	cout<<endl;
	delete pt2;
	
	cout<<endl<<"*****"<<endl<<endl;
	
	TrajetSimple t2("Lille","Lyon","Velo");
	cout<<"t2 = ";
	t2.Affiche();
	cout<<endl;
	
	cout<<endl<<"*****"<<endl<<endl;
	
	cout<<"true = "<<true<<"  &  "<<"false = "<<false<<endl;
	cout<<"t2.IsBefore(t1) return "<<t2.IsBefore(t1)<<endl;
	cout<<"t1.IsBefore(t2) return "<<t1.IsBefore(t2)<<endl;
	
	cout<<endl<<"***** Fin test TrajetSimple"<<endl<<endl;
}

void application(){
	//permet de gérer un menu
	const unsigned int NB_MAX_CHAR = 100;

	cout<<endl;
	cout<<"******************************"<<endl;
	cout<<"* Ouverture de l'application *"<<endl;
	cout<<"******************************"<<endl<<endl;
	
	Catalogue catalogue;
	unsigned int saisieMenu;
	do
	{	
		cout<<"Menu :"<<endl;
		cout<<"0) quitter l'application"<<endl;
		cout<<"1) créer un trajet simple"<<endl;
		cout<<"2) créer un trajet composé"<<endl;
		cout<<"3) ajouter un trajet simple à un trajet composé"<<endl;
		cout<<"4) afficher le catalogue"<<endl;
		cout<<"5) recherche de parcours"<<endl;
		cout<<"6) recherche avancée de parcours"<<endl;
		cout<<endl;
		cout <<"Saisissez votre choix : ";
		cin>>saisieMenu;
		cout<<endl;
		switch(saisieMenu)
		{
			case 1:
			{
				cout<<"-- Créer un trajet simple --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char depart[NB_MAX_CHAR];
				cin >> depart;
				cout <<"Saisissez la ville d'arrivée : ";
				char arrivee[NB_MAX_CHAR];
				cin >> arrivee;
				cout <<"Saisissez le moyen de transport : ";
				char moyenTransport[NB_MAX_CHAR];
				cin >> moyenTransport;
				
				Trajet * t = new TrajetSimple(depart,arrivee,moyenTransport);
				catalogue.Add(t);
				
				break;
			}
			
			case 2:
			{
				cout<<"-- Créer un trajet composé --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char depart[NB_MAX_CHAR];
				cin >> depart;
				cout <<"Saisissez le moyen de transport : ";
				char moyenTransport1[NB_MAX_CHAR];
				cin >> moyenTransport1;
				cout <<"Saisissez la ville etape : ";
				char etape[NB_MAX_CHAR];
				cin >> etape;
				cout <<"Saisissez le moyen de transport : ";
				char moyenTransport2[NB_MAX_CHAR];
				cin >> moyenTransport2;
				cout <<"Saisissez la ville d'arrivée : ";
				char arrivee[NB_MAX_CHAR];
				cin >> arrivee;
				
				Trajet * t1 = new TrajetSimple(depart,etape,moyenTransport1);
				Trajet * t2 = new TrajetSimple(etape,arrivee,moyenTransport2);
				Trajet * tc = new TrajetCompose(t1,t2);
				catalogue.Add(tc);
				
				break;
			}
			
			case 4:
				catalogue.Affiche();
				break;
			
			case 5:
			{
				cout<<"-- Recherche de parcours --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char depart[NB_MAX_CHAR];
				cin >> depart;
				cout <<"Saisissez la ville d'arrivée : ";
				char arrivee[NB_MAX_CHAR];
				cin >> arrivee;
				
				catalogue.RechercheParcours(depart,arrivee);
				
				break;
			}
		}
	cout<<endl<<"----------------------------------------------------------"<<endl;
	cout<<endl;
	}
	while(saisieMenu != 0);

	
	cout<<"******************************"<<endl;
	cout<<"* Fermeture de l'application *"<<endl;
	cout<<"******************************"<<endl<<endl;
}
