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

int main (){
	testTrajetSimple();
	testListe();
	testTrajetCompose();
	testCatalogue();
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
	l1.Affiche();
	l1.Add(pt1);
	l1.Affiche();
	l1.Add(pt2);
	l1.Affiche();
	
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
