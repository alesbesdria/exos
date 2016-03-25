#include <stdio.h>
#include <stdlib.h>

typedef struct TElement Element;
struct TElement
{
	int nombre;
	Element *suivant;
};

typedef struct TListe Liste;
struct TListe
{
	Element *premier;
};

Liste *initialisation()
{
	Liste *liste = malloc(sizeof(Liste));
//	Element *element = malloc(sizeof(Element));
	
	if (liste == NULL/* | element == NULL*/)
	{
		exit(EXIT_FAILURE);
	}
//	element->nombre = 0;
//	element->suivant = NULL;
//	liste->premier = element;
	liste->premier = NULL;
//1//ON NE CREE PAS DE PREMIER ELEMENT.
	return liste;
}

void insertion(Liste *liste, int nvNombre)
{
//2//DANS LA STRUCTURE LISTE ON RAJOUTE UN ELEMENT *NOUVEAU.
	Element *nouveau = malloc(sizeof(Element));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
//3//ON MET nvNombre DANS NOMBRE.
	nouveau->nombre = nvNombre;
//4//PREMIER EST MAINTENANT DEVENU LE SUIVANT.
	nouveau->suivant = liste->premier;
//5//ON REPLACE LE NOUVEAU EN PREMIER.
	liste->premier = nouveau;
}

void afficherListe(Liste *liste)
{
//6//ON CREE UN ACTUEL POUR AFFICHER CHAQUE ELEMENTS JUSQU A NULL.
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *actuel = liste->premier;

	while (actuel != NULL)
	{
		printf("nombre actuel : %d - adresse : %x - champs : %s ->\n"/*- contenu : %s ->\n "*/, actuel->nombre, &actuel->nombre, actuel->nombre/*, *actuel->nombre*/);
		actuel = actuel->suivant;
	}
	printf("NULL\n");
}

void suppression(Liste *liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while (liste->premier != NULL)
	{
//7//ON BOUCLE POUR SUPPRIMER CHAQUE ELEMENT JUSQUAU DERNIER.
		Element *aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
		afficherListe(liste);
	}
//***LIBERATION DE LISTE***//
	free(liste);
}

int main()
{
	Liste *maListe = initialisation();

	insertion(maListe, 4);
	insertion(maListe, 8);
	insertion(maListe, 15);
	insertion(maListe, 6);
	insertion(maListe, 9);
	insertion(maListe, 18);
	suppression(maListe);

	afficherListe(maListe);

	return 0;
}
