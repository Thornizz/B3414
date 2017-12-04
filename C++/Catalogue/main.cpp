using namespace std;
#include <iostream>
#include "TrajetCompose.h"
#include "Catalogue.h"
#include <cstring>

void testTrajetSimple();
void testListe();
void testTrajetCompose();
void testCatalogue();
void application();
void testApplication(Catalogue &catalogue);

int main (){

// Ajout et affichage d'un trajet composé avec valgrind
// Recherche avancée à bien faire

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
	
	const unsigned int NB_MAX_CHAR = 100;

	cout<<endl;
	cout<<"******************************"<<endl;
	cout<<"* Ouverture de l'application *"<<endl;
	cout<<"******************************"<<endl<<endl;
	
	Catalogue catalogue;
	testApplication(catalogue);	
	
	cout<<"----------------------------------------------------------"<<endl;
	cout<<endl;

	unsigned int saisieMenu;
	do
	{	
		cout<<"Menu :"<<endl;
		cout<<"0) quitter l'application"<<endl;
		cout<<"1) ajouter un trajet simple"<<endl;
		cout<<"2) ajouter un trajet composé"<<endl;
		cout<<"3) afficher le catalogue"<<endl;
		cout<<"4) recherche de parcours"<<endl;
		cout<<"5) recherche avancée de parcours"<<endl;
		cout<<endl;
		cout <<"Saisissez votre choix : ";
		cin>>saisieMenu;
		cout<<endl;
		switch(saisieMenu)
		{
			case 1:
			{
				cout<<"-- ajouter un trajet simple --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char * depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> depart;
				cout <<"Saisissez la ville d'arrivée : ";
				char * arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> arrivee;
				cout <<"Saisissez le moyen de transport : ";
				char * moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> moyenTransport;
				
				Trajet * t = new TrajetSimple(depart,arrivee,moyenTransport);
				catalogue.Add(t);
				
				break;
			}
			
			case 2:
			{
				cout<<"-- ajouter un trajet composé --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char * depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> depart;
				cout <<"Saisissez une ville étape : ";
				char * etape = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> etape;
				cout <<"Saisissez le moyen de transport : ";
				char * moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> moyenTransport;
				
				Trajet * td = new TrajetSimple(depart,etape,moyenTransport);
				
				char * etapeCopie = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				strcpy(etapeCopie,etape);
				
				TrajetCompose * tc;
				
				bool creation = true;
				
				bool continuer;
				cout << "--" <<endl;
				cout << "O) Saisir la ville d'arrivee" <<endl;
				cout << "1) Saisir une ville étape" <<endl;
				cout << "Votre choix : "; 
				cin >> continuer;
				cout << "--" <<endl;
					
				while(continuer)
				{
					cout <<"Saisissez une ville étape : ";
					etape = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
					cin >> etape;
					cout <<"Saisissez le moyen de transport : ";
					moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
					cin >> moyenTransport;
					
					Trajet * t = new TrajetSimple(etapeCopie,etape,moyenTransport);
					if(creation)
					{
						tc = new TrajetCompose(td,t);
						creation = false;
					}
					else
					{
						tc->Add(t);
					}
					
					etapeCopie = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
					strcpy(etapeCopie,etape);
					
					cout << "--" <<endl;
					cout << "O) Saisir la ville d'arrivee" <<endl;
					cout << "1) Saisir une ville étape" <<endl;
					cout << "Votre choix : "; 
					cin >> continuer;
					cout << "--" <<endl;
				}
				
				cout <<"Saisissez la ville d'arrivée : ";
				char * arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> arrivee;
				cout <<"Saisissez le moyen de transport : ";
				moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> moyenTransport;
				
				Trajet * ta = new TrajetSimple(etapeCopie,arrivee,moyenTransport);
				if(creation)
				{
					tc = new TrajetCompose(td,ta);
					creation = false;
				}
				else
				{
					tc->Add(ta);
				}
				
				catalogue.Add(tc);
				
				break;
			}
			
			case 3:
				cout<<"-- afficher le catalogue --"<<endl;
				catalogue.Affiche();
				break;
			
			case 4:
			{
				cout<<"-- recherche de parcours --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char * depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> depart;
				cout <<"Saisissez la ville d'arrivée : ";
				char * arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> arrivee;
				
				catalogue.RechercheParcours(depart,arrivee);
				
				free(depart);
				free(arrivee);
				
				break;
			}
			
			case 5:
			{
				cout<<"-- recherche de parcours --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char * depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> depart;
				cout <<"Saisissez la ville d'arrivée : ";
				char * arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
				cin >> arrivee;
				
				catalogue.RechercheParcoursAvancee(depart,arrivee);
				
				free(depart);
				free(arrivee);
				
				break;
			}
		}
	cout<<endl;
	cout<<"----------------------------------------------------------"<<endl;
	cout<<endl;
	}
	while(saisieMenu != 0);

	
	cout<<"******************************"<<endl;
	cout<<"* Fermeture de l'application *"<<endl;
	cout<<"******************************"<<endl<<endl;
}

void testApplication(Catalogue &catalogue)
{
	
	const unsigned int NB_MAX_CHAR = 100;
	
	char * depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	char * arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	char * moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Lyon");
	strcpy(arrivee,"Paris");
	strcpy(moyenTransport,"Train");
	TrajetSimple * t1 = new TrajetSimple(depart,arrivee,moyenTransport);
	catalogue.Add(t1);
	
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Marseille");
	strcpy(arrivee,"Lyon");
	strcpy(moyenTransport,"Voiture");
	TrajetSimple * t3 = new TrajetSimple(depart,arrivee,moyenTransport);
	catalogue.Add(t3);
	
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Lille");
	strcpy(arrivee,"Villeurbanne");
	strcpy(moyenTransport,"Helicopter");
	TrajetSimple * t4 = new TrajetSimple(depart,arrivee,moyenTransport);
	catalogue.Add(t4);
	
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Marseille");
	strcpy(arrivee,"Orange");
	strcpy(moyenTransport,"Helicopter");
	TrajetSimple * tc1e1 = new TrajetSimple(depart,arrivee,moyenTransport);
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Orange");
	strcpy(arrivee,"Montelimar");
	strcpy(moyenTransport,"Train");
	TrajetSimple * tc1e2 = new TrajetSimple(depart,arrivee,moyenTransport);
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Montelimar");
	strcpy(arrivee,"Lyon");
	strcpy(moyenTransport,"Helicopter");
	TrajetSimple * tc1e3 = new TrajetSimple(depart,arrivee,moyenTransport);
	TrajetCompose * tc1 = new TrajetCompose(tc1e1,tc1e2);
	tc1->Add(tc1e3);
	catalogue.Add(tc1);
	
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Biarritz");
	strcpy(arrivee,"Bordeaux");
	strcpy(moyenTransport,"Voiture");
	TrajetSimple * tc2e1 = new TrajetSimple(depart,arrivee,moyenTransport);
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Bordeaux");
	strcpy(arrivee,"Nantes");
	strcpy(moyenTransport,"Train");
	TrajetSimple * tc2e2 = new TrajetSimple(depart,arrivee,moyenTransport);
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Nantes");
	strcpy(arrivee,"Orleans");
	strcpy(moyenTransport,"Voiture");
	TrajetSimple * tc2e3 = new TrajetSimple(depart,arrivee,moyenTransport);
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Orleans");
	strcpy(arrivee,"Paris");
	strcpy(moyenTransport,"Velo");
	TrajetSimple * tc2e4 = new TrajetSimple(depart,arrivee,moyenTransport);
	TrajetCompose * tc2 = new TrajetCompose(tc2e1,tc2e2);
	tc2->Add(tc2e3);
	tc2->Add(tc2e4);
	catalogue.Add(tc2);
	
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Villeurbanne");
	strcpy(arrivee,"Lyon");
	strcpy(moyenTransport,"Pied");
	TrajetSimple * t5 = new TrajetSimple(depart,arrivee,moyenTransport);
	catalogue.Add(t5);
	
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Lille");
	strcpy(arrivee,"Paris");
	strcpy(moyenTransport,"Velo");
	TrajetSimple * t2 = new TrajetSimple(depart,arrivee,moyenTransport);
	catalogue.Add(t2);
	
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Lille");
	strcpy(arrivee,"Bergues");
	strcpy(moyenTransport,"Helicopter");
	TrajetSimple * tc3e1 = new TrajetSimple(depart,arrivee,moyenTransport);
	depart = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	arrivee = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	moyenTransport = (char *) malloc(sizeof(char)*NB_MAX_CHAR);
	strcpy(depart,"Bergues");
	strcpy(arrivee,"Paris");
	strcpy(moyenTransport,"Train");
	TrajetSimple * tc3e2 = new TrajetSimple(depart,arrivee,moyenTransport);
	TrajetCompose * tc3 = new TrajetCompose(tc3e1,tc3e2);
	catalogue.Add(tc3);
}
