# Mathbender

## Inleiding
Dit project is gemaakt door Both Maikel en Geelen Joachim.
Het project is gemaakt voor het vak Softwareontwerp met C/C++ en Qt voor de richting 3de Bachelor Elektronica-ICT aan de faculteit Industriële Ingenieurswetenschappen aan de UHasselt.

## Doel
Het doel van het spel is om vaak mogelijk de vijand te doden. Elke keer dat de vijand dood gaat, komt er een nieuwe die meer levenspunten heeft.
De speler heeft de keuze tussen twee verschillende aanvallen. De eerste aanval is een vuurbal die recht naar boven wordt afgevuurd. De tweede aanval is een waterstraal die met een boog naar boven wordt gewaterd. 
De vijand schiet terug met kogels. 

Wanneer de speler geen levenspunten meer heeft, stopt het spel en wordt een eindscherm getoond met de score die behaald werd. Het spel kan dan herstart worden door op de start knop te drukken.

## Domain Class Diagram

![Image of Domain Class Diagram](https://github.com/maikelboth/cpp-project/blob/master/mathbender/MathbenderUML.png)

We vertrekken vanuit de Main waarin een eerste scene wordt opgeroepen met een instantie van de GBA-Engine. Er zijn 3 scenes waarvan MainScreen als default wordt opgeroepen in de Main. De gebruiker doorloopt het spel en zal zo tussen de 3 scenes wisselen. Level1Screen is de scene waar het spelen gebeurt. Deze heeft namelijk. een Boss als vijand, een Speler en verschillende rondvliegende, zowel vriendelijke als vijandige, Attacks. Er zijn 3 soorten attacks (Fireball, Water, Bullet) die allemaal erven van de hoofdklasse Attack.

## Gebruikte Sprites
De sprite van de Boss is een aangepaste versie van 'buff alligator' van Nuclear Throne van de studio Vlambeer. Voor het ontwerpen van de tilemap voor de backgrounds is vertrokken van onderstaande tileset van 'OddPotatoGift'.

https://oddpotatogift.itch.io/16x16-dungeon-tileset
https://nuclear-throne.fandom.com/wiki/Buff_Alligator
