# Projet GetNextLine

<a href="https://github.com/RaphyStoll/Get_next_line/blob/main/README.md" style="text-decoration:none;">
  <button style="background-color:#e0f7fa; border:none; cursor:pointer;">
    🇫🇷 Français
  </button>
</a>
&nbsp;&nbsp;
<a href="https://github.com/RaphyStoll/Get_next_line/blob/main/README.eng.md" style="text-decoration:none;">
  <button style="border:none; cursor:pointer;">
    🇬🇧 English
  </button>
</a>

## Aperçu

Le projet `GetNextLine` vise à développer une fonction permettant de lire une ligne à partir d'un
descripteur de fichier. Ce projet introduit le concept des variables statiques en programmation C et
fournit une fonction pratique pour lire des lignes à partir de fichiers ou de l'entrée standard.

## Table des matières

- [Projet GetNextLine](#projet-getnextline)
	- [Aperçu](#aperçu)
	- [Table des matières](#table-des-matières)
	- [Objectifs](#objectifs)
	- [Règles](#règles)
	- [Partie obligatoire](#partie-obligatoire)
		- [Fonction : `get_next_line`](#fonction--get_next_line)
		- [Exigences :](#exigences-)
		- [Restrictions :](#restrictions-)
	- [Partie Bonus](#partie-bonus)
		- [Fichiers Bonus :](#fichiers-bonus-)
	- [Structure des répertoires](#structure-des-répertoires)
	- [Compilation](#compilation)
	- [Tests](#tests)

## Objectifs

- Développer une fonction pour lire des lignes à partir d'un descripteur de fichier.
- Explorer l'utilisation des variables statiques en C.
- Assurer la conformité avec les normes de codage et une gestion correcte de la mémoire.

## Règles

- Le projet doit être écrit en C.
- Le code doit respecter les normes de codage de 42.
- Les fonctions ne doivent pas se terminer de manière inattendue (par exemple, segmentation fault).
- Toute mémoire allouée dynamiquement doit être correctement libérée.

## Partie obligatoire

### Fonction : `get_next_line`

- **Prototype :** `char *get_next_line(int fd);`
- **Fichiers :** `get_next_line.h`, `get_next_line.c`, `get_next_line_utils.c`
- **Paramètres :** `fd` - descripteur de fichier à lire.
- **Valeur de retour :** Le contenu de la ligne lue ou `NULL` s'il n'y a plus rien à lire ou en cas
  d'erreur.
- **Fonctions externes autorisées :** `read`, `malloc`, `free`

### Exigences :

- Les appels successifs à `get_next_line()` doivent permettre de lire le fichier texte entier ligne
  par ligne.
- La fonction doit retourner la ligne lue, y compris le caractère de nouvelle ligne (`\n`), sauf si
  la fin du fichier est atteinte sans nouvelle ligne.
- La fonction doit fonctionner correctement pour les fichiers et l'entrée standard.
- Le projet doit se compiler avec l'option `-D BUFFER_SIZE=n`, permettant de spécifier la taille du
  tampon.

### Restrictions :

- La bibliothèque `libft` n'est pas autorisée.
- La fonction `lseek()` est interdite.
- Les variables globales ne sont pas autorisées.

## Partie Bonus

- Implémentez `get_next_line()` en utilisant une seule variable statique.
- Étendez `get_next_line()` pour gérer plusieurs descripteurs de fichiers simultanément.

### Fichiers Bonus :

- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

## Structure des répertoires

```plaintext
header/
  get_next_line.h
  get_next_line_bonus.h
objects/
  bonus/
    get_next_line_bonus.o
    get_next_line_utils_bonus.o
    main_bonus.o
  main/
    get_next_line.o
    get_next_line_utils.o
    main.o
source/
  bonus/
    get_next_line_bonus.c
    get_next_line_utils_bonus.c
    main_bonus.c
  main/
    get_next_line.c
    get_next_line_utils.c
    main.c
test/
  txt/
    empty.txt
    file_with_null_bytes.txt
    infinite_line.txt
    lines_with_only_spaces.txt
    long_line.txt
    long_line_with_newline.txt
    mixed_line_lengths.txt
    multiple_consecutive_newlines.txt
    multiple_lines.txt
    no_newline_at_end.txt
    non_printable_characters.txt
    one_line_no_newline.txt
    one_line_with_newline.txt
    only_newlines.txt
    text.txt
    unicode_characters.txt
output/
  gnl
  gnl_bonus
```

## Compilation

Pour compiler le projet, utilisez le Makefile fourni :

```sh
make
```

Pour nettoyer les fichiers de compilation, utilisez :

```sh
make clean
```

## Tests

- Le répertoire `test/txt` contient divers fichiers de test pour valider le fonctionnement de
  `get_next_line()`.
