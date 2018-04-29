## Installation
Prendre note que cette application n'est pas utilisable sur Mac et linux. Elle fonctionne uniquement sur Windows Vista et plus.
 Pour pull le projet vous devez faire les étapes suivantes :
1. Avoir les librairies d'openframeWorks sur votre ordinateur.

2. Faire un clone du projet dans ...\of_v0.9.8_vs_release\apps\myApps, ou faire un pull si vous avez déjà le repo sur votre ordinateur à cet endroit.

3. Modifier le chemin d'importation du of_v0.9.8_vs_release. Pour ce faire, ouvrir visual studio 2015, faites un clique droit sur le projet Tp1 dans le Solution Explorer, puis cliquer sur "edit".

4. Ensuite, mettre le projet Tp1 comme projet par defaut en faisant clique droit puis "Set as startUp project".

5. Ré-importer les addons d'openframeworks. Pour cela, vous devez faire clique droit sur Tp1, puis selectionner "openFrameworks Addons" Décochez les addons puis enregistrer. Refaire la même maneuvre que sitée plus haut mais en rechochant les addons précèdement décochés.

6. Modifier le chemin des dépendances additionelles. Faire un clique droit sur le projet dans le Solution Explorer et aller dans Properties -> Linker -> Input. Cliquer sur le chemin de Additional Dependencies, puis <Edit...>. Effacer les premiers caractères au début du chemin "%3b" et s'assurer que le chemin n'est pas écrit en double. Appliquer les changements.

7. (Cette étape est optionnelle si elle a déja été faite) Aller à la page suivante: https://github.com/braitsch/ofxDatGui. Copiez l'url du repo et le cloner dans of_v0.9.8_vs_release\addons. Ensuite, ouvrir le dossier ofxDatGui nouvellement créé dans addons et copier le dossier ofxbraitsch. Coller ce dossier dans of_v0.9.8_vs_release\apps\myApps\infographie-tp1\tp1\bin\data. L'option d'ajout de ce addon sera dans la section community addons.

8. (Cette étape est optionnelle si elle a déja été faite) Aller à la page suivante: https://github.com/charlesveasey/ofxBezierSurface. Copiez l'url du repo et le cloner dans of_v0.9.8_vs_release\addons. Cocher l'option d'ajout de ce addon dans la section community addons en cliquant droit sur le projet et en allant dans openFrameworks addons.

9. (Cette étape est optionnelle si elle a déja été faite) Aller à la page suivante: https://github.com/neilmendoza/ofxPostProcessing. Copiez l'url du repo et le cloner dans of_v0.9.8_vs_release\addons. Cocher l'option d'ajout de ce addon dans la section community addons en cliquant droit sur le projet et en allant dans openFrameworks addons.

## Exécution
Exécuter tp1/bin/tp1_debug.exe ou compiler et exécuter le projet dans Visual Studio 2015.

## Construit avec

* [OpenframeWorks](http://openframeworks.cc/)

## Auteurs

* **Rémy Tremblay**
* **Marcel Samson-Morasse**
* **Damien Arroyo**
* **Marc-André Tremblay**

Voir la liste des [contributeurs](https://github.com/RETRE208/infographie-tp1/graphs/contributors) qui ont participés au projet.
