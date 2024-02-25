
/* `#include <Arduino.h>` est une directive de préprocesseur qui inclut la bibliothèque principale
Arduino dans le code C++.
Cette bibliothèque fournit des fonctions et des définitions essentielles pour travailler avec les
cartes et périphériques Arduino. Il vous permet d'accéder aux fonctions et fonctionnalités
spécifiques à Arduino dans votre programme. */
#include <Arduino.h>

/* `#define DUREE_BLINK 500` est une directive de préprocesseur utilisée pour représenter la durée
(en millisecondes) pendant laquelle une LED clignotera alternativement dans la fonction « FCTBlink »
*/
#define DUREE_BLINK 500

/*
  --------------------------------------------------------------------------------------------------
  -- Déclararion des fonctions personnelles (*.h)
  --------------------------------------------------------------------------------------------------
*/

void FCTBlink(uint8_t, uint16_t);

/*
  --------------------------------------------------------------------------------------------------
  -- Fonction Générale d'Initialisation
  --------------------------------------------------------------------------------------------------
*/

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

/*
  --------------------------------------------------------------------------------------------------
  -- Fonction Générale Répétée en Boucle indéfiniment
  --------------------------------------------------------------------------------------------------
*/

void loop()
{
	FCTBlink(LED_BUILTIN, DUREE_BLINK);
}

/*
  --------------------------------------------------------------------------------------------------
  -- Définition des fonctions personnelles (*.cpp)
  --------------------------------------------------------------------------------------------------
*/

/**
 * La fonction `FCTBlink` fait clignoter une LED connectée à une broche spécifiée à un intervalle
 * spécifié.
 *
 * @param _pinLED _pinLED est le numéro de broche auquel la LED est connectée.
 * @param _duree Le paramètre `_duree` représente la durée en millisecondes pendant laquelle la LED
 * doit clignoter alternativement.
 */
void FCTBlink(uint8_t _pinLED, uint16_t _duree)
{
	static ulong timelastblink = 0;
	static ulong timenow = millis();
	static bool etat = HIGH;
	long long delta = timenow - timelastblink;
	if (delta > _duree || delta < 0)
	{
		digitalWrite(_pinLED, etat);
		etat = !etat;
		timelastblink = timenow;
	}
}
