Pour ce second TP, l'objectif est d'établir une communication avec un serveur en utilisant le protocole TFTP. Pour ce faire, nous devons développer deux fonctions : gettftp pour télécharger des fichiers depuis le serveur et puttftp pour envoyer des fichiers vers le serveur.

Dans un premier temps, nous demandons à l'utilisateur le nom du serveur ainsi que le nom du fichier à transférer. Grâce à ces informations et à la fonction getaddrinfo, qui nous fournit l'adresse du serveur, le type d'IP (IPv4 ou IPv6), et d'autres paramètres, nous pouvons configurer un socket qui permettra la communication avec le serveur.

Ensuite, nous avons créé une fonction pour construire une trame conforme au format attendu par le protocole TFTP. Cette trame respecte la convention suivante :
            2 bytes     string    1 byte     string   1 byte
            ------------------------------------------------
           | Opcode |  Filename  |   0  |    Mode    |   0  |
            ------------------------------------------------
Enfin, nous avons pu envoyer une requête de lecture (Read Request, ou RRQ) correctement formée, comme illustré par l'image dans le fichier du TP2.
