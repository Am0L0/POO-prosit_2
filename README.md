# Prosit 2
*Par Amaury, Samy, Pablo*

## A propos 
Le but de est de faire un programme capable de chiffrer et dechiffrer un fichier texte.

### Le Chiffrement 
Notre programme dispose de 3 methodes de chiffrement 

#### 1. Methode CESAR
Cette methode consiste a deplacer le lettre de l'alphabet d'un certain nombre de lettre

*Mettre un exemple ici (une image par exemple)*

C'est une methode regaltivement facile a **BrutFroce** car il suffit de traduire le fichier en 25 cobinaison diffrente (etant donné que ca ne peux pas etre dechiffré de base)

#### 2. Methode XOR

Voici la table de verité de la table `XOR` :
| A | B | (A XOR B) |
| :---: | :---: | :---: |
| Faux | Faux | Faux |
| Faux | Vrai | Vrai |
| Vrai | Faux | Vrai |
| Vrai | Vrai | Faux |

<br>
<br>

Prenons un exemple avec le message **`CESI`**:
| **Lettre** | **C** | **E** | **S** | **I** |
| :---:      | :---: | :---: | :---: | :---: |
| **ASCII**  | 67 | 69 | 83 | 73 |
| **Binaire** | 01000011 | 01000101 | 01010011 | 01001001 |

<br>

Le mot **`CLE`** en binaire est lui représenté par 01000011 - 01001100 - 01000101 .

<br>
<br>

| Élément | Octet 1 | Octet 2 | Octet 3 | Octet 4 |
| :--- | :---: | :---: | :---: | :---: |
| **Message en binaire** | 01000011 | 01000101 | 01010011 | 01001001 |
| **Clé en binaire<br>(répétée si nécessaire)** | 01000011 | 01001100 | 01000101 | 01000011 |
| **Message crypté en binaire** | **00001110** | **00001001** | **00010110** | **00010000** |

#### 3. Methode CESAR + XOR

Celle est plutot transparante il s'agit d'apliquer les methodes vu precedamment l'une a la suite de l'autre.