# Projet en Qualité de programmation : gestion des déplacements d'un robot dans un labyrinthe
 
On veut pouvoir déplacer un robot dans un terrain suivant plusieurs algorithmes et suivre ses
déplacements.

# Terrain
Un terrain est représenté par un tableau dont les cases sont soit vides, soit contiennent un mur.
Un terrain peut contenir un robot qui va s’y déplacer et contient aussi deux cases vides spéciales :
une case départ et une case arrivée.
On veut pouvoir sauver le terrain dans un fichier et pouvoir le relire depuis un fichier.

# Robot
Un robot est sur une case du terrain. Il peut détecter s'il y a un obstacle devant lui, sur sa gauche
et sur sa droite. Il peut avancer d'une case, tourner à gauche de 90°,tourner à droite de 90°.
On veut être au courant du moindre de ses déplacements pour faire un certain nombre de choses
(l’afficher, faire des statistiques sur ses déplacements, … ). Pour cela on veut utiliser le modèle de
conception observateur. Un observateur de robot peut être notifié avec les coordonnées (et la
direction de déplacement) d’un robot. Un robot peut enregistrer des observateurs de robot, et à
chaque fois qu’il fait un déplacement, il notifie tous les observateurs de robots enregistrés.

# Algorithme de sortie d’un labyrinthe
On veut programmer le robot pour le faire sortir d’un labyrinthe. Pour cela on veut implémenter
les deux algorithmes de sortie d'un labyrinthe suivants :
– algorithme main droite : se déplacer en ayant toujours un mur à sa droite (si au début il n’y a
pas de mut à droite, aller tout droit jusqu’à rencontrer un mur)
– algorithme de Pledge :
1 aller tout droit jusqu’au mur, passer à l’instruction 2
2 longer le mur par la droite (ou par la gauche, mais toujours dans le même sens) jusqu’à ce
que le décompte des changements de direction atteigne zéro (tourner à gauche = +1,
tourner à droite = -1), passer à l’instruction 1 ;

# Programme à réaliser
Il faut faire un programme en mode texte qui permet à l’utilisateur de lire un terrain (qui
représente un labyrinthe) depuis un fichier, permet de choisir l’algorithme de sortie de labyrinthe,
fait sortir le robot le robot du labyrinthe en visualisant les déplacements du robot et en affichant le
nombre de cases parcourues par le robot.
Le terrain et le robot seront affiché en mode texte. On pourra choisir un mode texte simple ou un
mode texte amélioré, sachant pour pourrait plus tard envisager un affichage graphique.

Mode texte simple :
XXXXXXXXXXXXXXXXXXXX
X......XXXX........X
X..................X
X..X...............X
X..X........X......X
X..X........X......X
X..X........X..>...X
XXXXXXXXXXXXXXXXXXXX

Mode texte amélioré 1 :
+------+##+--------+
|......+--+........|
| .................|
|..|...............|
|..|........|......|
|..|........|......|
|..|........|..>...|
+--+--------+------+

Mode texte amélioré 2 (utilise des caractères unicode de bordure) :
┏━━━━━━┓▄▄┏━━━━━━━━┓
┃......┗━━┛........┃
┃ .................┃
┃..┃...............┃
┃..┃........┃......┃
┃..┃........┃..▷...┃
┗━━┻━━━━━━━━┻━━━━━━┛
