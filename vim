https://vi-improved.org/
https://vimcast.org/

Terminal

ctrl-z 		mettre un programme en tache de fond
fg 			relancer le programme

-------------------------------------------------
Motions and operators (motion.txt)

A 			insérer du texte en fin de ligne
a			insérer du texte après le curseur
r 			remplacer
w			jusqu'au début du prochain mot, en EXCLUANT son premier caractère.
e 			jusqu'à la fin du mot courant, en EXCLUANT son dernier caractère.
$			fin de ligne
0			debut de ligne
c			changer (ce efface le mot et rentre en insertion)
ctrl g			affiche les infos du fichier en bas
nb + G			met le curseur sur la ligne nb
/			rechercher
set ic			ignorer la casse (recherche) (set noic)
set hls	is		surligne le résultat (set nohlsearch)
%			trouver des )]}
G			deplace à là fin du fichier
gg			deplace à là premiere ligne
HML			deplace sur l'ecran respectivement high mid low
r			permet de recupérer le contenu d'un fichier
r !ls			permet de récupérer le contenu de ls
o			rentrer en insertion sur la ligne du dessous
O			rentrer en insertion sur la ligne du dessus
R			mode remplacement
di{			supprimer tout ce qui est entre {...}	
da{ 			supprimer tout ce qui est entre {} séparateurs compris	
d%			supprimer tout la ligne et ce qui est entre séparateur
Substitution :
:s/lee/le		seulement sur la prochaine occurence
:s/lee/le/g		seulement pour la ligne
:#,#s/ancien/nouveau/g	de la ligne # à la ligne # 
:%s/ancien/nouveau/g	dans tout le fichier
:%s/ancien/nouveau/gc	avec invite pour confirmer

netrw explorateur de fichier vim
:make lance make et remplis la quickfix list
