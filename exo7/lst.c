#include <stdio.h>
#include <stdlib.h>

typedef struct TElement Element;
struct TElement
{
	int nombre;
	int count;
	Element *suivant;
	Element *precedent;
};

typedef struct TListe Liste;
struct TListe
{
	Element *premier;
	Element *dernier;
	Element *courant;
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
	liste->dernier = NULL;
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
	if (liste->premier == NULL)
	{
		liste->dernier = nouveau;
		liste->courant = nouveau;
	}
//3//ON MET nvNombre DANS NOMBRE.
	nouveau->nombre = nvNombre;
//4//PREMIER EST MAINTENANT DEVENU LE SUIVANT.
	nouveau->suivant = liste->premier;
	nouveau->precedent = NULL;
	if (liste->premier != NULL)
	{
		liste->premier->precedent = nouveau;
	}
	nouveau->precedent = NULL;
//5//ON REPLACE LE NOUVEAU EN PREMIER.
	liste->premier = nouveau;
//	nouveau->precedent = liste->premier;;
//5//ON REPLACE LE NOUVEAU EN PREMIER.
//	liste->premier = nouveau;
//	liste->dernier = nouveau;
//	nouveau = liste->dernier;
//	liste->premier->precedent = liste->dernier;
//	liste->dernier = nouveau->precedent;
//	nouveau->precedent = nouveau;
//	nouveau->precedent = liste->dernier;
//	nouveau->precedent = liste->premier;
//	liste->premier = nouveau;
}

void courantavant(Liste *liste)
{
	if (liste->courant->suivant != NULL)
	{
		liste->courant = liste->courant->suivant;
	}
}

void courantarriere(Liste *liste)
{
	if (liste->courant->precedent != NULL)
	{
		liste->courant = liste->courant->precedent;
	}
}

void insertdebut(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(Element));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;

	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
	nouveau->suivant->precedent = nouveau;
	nouveau->precedent = NULL;
}

void insertfin(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(Element));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;

	nouveau->precedent = liste->dernier;
	liste->dernier = nouveau;
	nouveau->precedent->suivant = nouveau;
	nouveau->suivant = NULL;
}

void insertcourav(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(Element));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;
	if (liste->courant->precedent != NULL)
	{
/*	nouveau->precedent = liste->courant->precedent;
	liste->courant = nouveau;
	nouveau->suivant->precedent = nouveau;
	nouveau->precedent = nouveau->suivant;
	*/
	nouveau->precedent = liste->courant->precedent;
	liste->courant->precedent->suivant = nouveau;
	nouveau->suivant = liste->courant;
	liste->courant->precedent = nouveau;
	}
}

void insertcourar(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(Element));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;
	if (liste->courant->suivant != NULL)
	{
	nouveau->suivant = liste->courant->suivant;
/*	liste->courant = nouveau;
	nouveau->precedent->suivant = nouveau;
	nouveau->suivant = nouveau->precedent;
*/
	liste->courant->suivant->precedent = nouveau;
	nouveau->precedent = liste->courant;
	liste->courant->suivant = nouveau;
	}
}

void remplcourav(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(Element));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;
	if (liste->courant->precedent != NULL)
	{
	nouveau->precedent = liste->courant->precedent;
	liste->courant = nouveau;
	}
}

void remplcourar(Liste *liste, int nvNombre)
{
	Element *nouveau = malloc(sizeof(Element));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;
	if (liste->courant->suivant != NULL)
	{
	nouveau->suivant = liste->courant->suivant;
	liste->courant->suivant = nouveau;
	}
}

void afficherListeAvant(Liste *liste)
{
//6//ON CREE UN ACTUEL POUR AFFICHER CHAQUE ELEMENTS JUSQU A NULL.
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *actuel = liste->premier;

	while (actuel != NULL)
	{
//		printf("nombre actuel : %d - adresse : %p - addrliste : %p - addrliste.premier : %p - liste.premier : %p->\n ", actuel->nombre, &actuel->nombre, &liste, &liste->premier, liste->premier);
		printf("nombre actuel : %d -  ", actuel->nombre);
		actuel = actuel->suivant;
	}
	printf("NULL\n");
}

void afficherListeArriere(Liste *liste)
{
//6//ON CREE UN ACTUEL POUR AFFICHER CHAQUE ELEMENTS JUSQU A NULL.
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *courant = liste->dernier;

	while (courant != NULL)
	{
//		printf("nombre courant : %d - adresse : %p - addrliste : %p - addrliste.dernier : %p - liste.dernier : %p->\n ", courant->nombre, &courant->nombre, &liste, &liste->dernier, liste->dernier);
		printf("nombre courant : %d -  ", courant->nombre);
		courant = courant->precedent;
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
//		afficherListe(liste);
	}
/*	while (liste->dernier != 0)
	{
//7'//ON BOUCLE POUR SUPPRIMER CHAQUE ELEMENT JUSQUAU PREMIER.
		Element *aSupprimer = liste->dernier;
		liste->dernier = liste->dernier->precedent;
		free(aSupprimer);
//		afficherListe(liste);
	}
*/
//***LIBERATION DE LISTE***//
	free(liste);
}

int	compteur(Liste *liste)
{
	Element *cpt;
	int count = 0;
	cpt = liste->premier;
	if (cpt)
	{
		while (cpt->suivant != NULL)
		{
			cpt = cpt->suivant;
			count++;
		}
		count++;
	}
	else
		count = 0;
	return (count);
}

void	supprdebut(Liste *liste)
{
	Element *aSupprimer;
	if (liste->premier)
	{
		aSupprimer = liste->premier;
		liste->premier->suivant->precedent = NULL;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
	}
}

void	supprfin(Liste *liste)
{
	Element *aSupprimer;
	if (liste->dernier)
	{
		aSupprimer = liste->dernier;
		liste->dernier->precedent->suivant = NULL;
		liste->dernier = liste->dernier->precedent;
		free(aSupprimer);
	}
}

void	supprcour(Liste *liste)
{
	Element *aSupprimer;
	if (liste->courant == liste->premier)
		supprdebut(liste);
		else if (liste->courant == liste->dernier)
			supprfin(liste);
			else
			{
				aSupprimer = liste->courant;
				liste->courant->suivant->precedent = liste->courant->precedent;
				liste->courant->precedent->suivant = liste->courant->suivant;
				free(aSupprimer);
			}
}

void deplacecourprec(Liste *liste)
{
	if (liste->courant->precedent)
		liste->courant = liste->courant->precedent;
}

void deplacecoursuiv(Liste *liste)
{
	if (liste->courant->suivant)
		liste->courant = liste->courant->suivant;
}

int main()
{
	Liste *maListe = initialisation();
	
	printf("%d\n", compteur(maListe));

	insertion(maListe, 4);
	insertion(maListe, 8);
	insertion(maListe, 15);
	insertion(maListe, 6);
	insertion(maListe, 9);
	insertion(maListe, 18);
//	suppression(maListe);
	afficherListeAvant(maListe);
	afficherListeArriere(maListe);
	deplacecourprec(maListe);
	deplacecourprec(maListe);
	supprcour(maListe);
	afficherListeAvant(maListe);
	afficherListeArriere(maListe);
	return 0;
	supprfin(maListe);
	printf("%d\n", compteur(maListe));

	insertdebut(maListe,1);
	supprcour(maListe);
	insertfin(maListe, 99);

	afficherListeAvant(maListe);
	printf("===\n");
	afficherListeArriere(maListe);

	courantavant(maListe);
	printf("%d-", maListe->courant->nombre);
	courantarriere(maListe);
	printf("%d-", maListe->courant->nombre);
	courantarriere(maListe);
	
	remplcourav(maListe, 666);
	insertcourav(maListe, 888);
	
	printf("%d-", maListe->courant->nombre);
	courantarriere(maListe);
	printf("%d-", maListe->courant->nombre);
	courantarriere(maListe);

	remplcourar(maListe, 999);
	insertcourar(maListe, 777);

	printf("%d-", maListe->courant->nombre);
	courantavant(maListe);
	printf("%d-", maListe->courant->nombre);
	courantavant(maListe);
	printf("%d\n\n", maListe->courant->nombre);

	afficherListeAvant(maListe);
	printf("%d\n", compteur(maListe));

	return 0;
}
