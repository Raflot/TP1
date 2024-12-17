On commence ce TP par la création d'un prompt simple capable d'exécuter une commande.
Pour ce faire, on affiche un message de bienvenue grâce à la fonction write.
On lit ensuite la commande qui a été écrite grâce à la fonction read et on la stocke dans input.
On vérifie ensuite si la commande n'est pas "exit" pour quitter le shell ou "fortune" pour effectuer des tests.
On cherche ensuite à exécuter une commande quelconque :

 -Pour ce faire, on utilise une boucle while et strtok afin de séparer le texte en fonction des espaces.
 -On stocke ensuite dans un tableau chaque élément.
 -On crée ensuite un enfant grâce à la fonction fork et il suit la procédure suivante :

                            processus  -->     attend la fin du
                              père    <--      processus fils     <-------------------------
                                |                    /\                                   |
                                |                    ||                                   |
                                |-->   note le temps de départ                            |
                                v                                                         |
                            processus  -->   exécute la commande  --> note le temps de fin--/
                              fils              du prompt                                 |
                               |                    |                                     |
                               |                    v                                     |
                               |        note le processus de sortie------------------------/
                               |           (exit ou interruption)
                               v
                        quitte en cas d'erreur
