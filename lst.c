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
	Element *element = malloc(sizeof(Element));
	
	if (liste == NULL | element == NULL)
	{
		exit(EXIT_FAILURE);
	}
	element->nombre = 0;
	element->suivant = NULL;
	liste->premier = element;

	return liste;
}

void insertion(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(Element));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;

	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
}

void afficherListe(Liste *liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *actuel = liste->premier;

	while (actuel != NULL)
	{
		printf("%d -> ", actuel->nombre);
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
	if (liste->premier != NULL)
	{
		Element *aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
	}
}

int main()
{
	Liste *maListe = initialisation();

	insertion(maListe, 4);
	insertion(maListe, 8);
	insertion(maListe, 15);
	suppression(maListe);

	afficherListe(maListe);
	return 0;
}
