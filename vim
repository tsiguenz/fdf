https://vi-improved.org/
https://vimcast.org/

Terminal

ctrl-z 		mettre un programme en tache de fond
fg 			relancer le programme

-------------------------------------------------
Opérateurs de déplacement :

w			au début du mot suivant	
e 			a la fin du mot courant
b			au début du mot courant
^			au premier caractère non blanc
$			fin de ligne
0			debut de ligne
G			deplace à là fin du fichier
gg			deplace à là premiere ligne
nb + G		met le curseur sur la ligne nb
H			haut de la fenetre
M			milieu de la fenetre
L			bas de la fenetre

Opérateurs de déplacement et d'insersion :

i			insersion avant le curseur
I 			insérer du texte en début de ligne
a			insersion après le curseur
A 			insérer du texte en fin de ligne
o			insertion sur la ligne du dessous
O			insertion sur la ligne du dessus
s			supprime le caractère
S			supprime la ligne
r 			remplacer

c			changer 
C			changer jusqu'a la fin de la ligne
ctrl g		affiche les infos du fichier en bas
/			rechercher
J			fusionne la ligne en cours et celle en dessous
<>			indent
set ic		ignorer la casse (recherche) (set noic)
set hls	is	surligne le résultat (set nohlsearch)
%			trouver des )]}
HML			deplace sur l'ecran respectivement high mid low
r			permet de recupérer le contenu d'un fichier
r !ls		permet de récupérer le contenu de ls
R			mode remplacement
di{			supprimer tout ce qui est entre {...}	
da{ 		supprimer tout ce qui est entre {} séparateurs compris	
d%			supprimer tout la ligne et ce qui est entre séparateur

Substitution :
:s/lee/le		seulement sur la prochaine occurence
:s/lee/le/g		seulement pour la ligne
:#,#s/ancien/nouveau/g	de la ligne # à la ligne # 
:%s/ancien/nouveau/g	dans tout le fichier
:%s/ancien/nouveau/gc	avec invite pour confirmer


netrw explorateur de fichier vim
:make lance make et remplis la quickfix list
