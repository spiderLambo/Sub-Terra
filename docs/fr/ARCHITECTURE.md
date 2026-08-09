# Architecture

Lire en: [English](../en/ARCHITECTURE.md) | [Français](ARCHITECTURE.md)

## Structure du projet

```
Sub-Terra
├─ CHANGELOG.md
├─ CMakeLists.txt
├─ README.fr.md
├─ README.md
├─ docs
│  ├─ en
│  │  ├─ ARCHITECTURE.md
│  │  ├─ DEVELOPEMENT.md
│  │  └─ INSTALLATION.md
│  └─ fr
│     ├─ ARCHITECTURE.md
│     ├─ DEVELOPPEMENT.md
│     └─ INSTALLATION.md
├─ includes
│  ├─ display
│  │  ├─ engine
│  │  │  ├─ geometry.h
│  │  │  └─ window.h
│  │  ├─ entities
│  │  │  ├─ plateau.h
│  │  │  └─ player.h
│  │  ├─ render.h
│  │  └─ scenes
│  │     ├─ game.h
│  │     └─ scene.h
│  ├─ entities
│  │  └─ player.h
│  ├─ main.h
│  ├─ plateau.h
│  ├─ tuiles
│  │  └─ tuile.h
│  └─ utils
│     └─ Str_to_color.h
├─ newbuild.sh
└─ src
   ├─ display
   │  ├─ engine
   │  │  ├─ geometry.cpp
   │  │  └─ window.cpp
   │  ├─ entities
   │  │  ├─ plateau.cpp
   │  │  └─ player.cpp
   │  ├─ render.cpp
   │  └─ scenes
   │     ├─ game.cpp
   │     └─ scene.cpp
   ├─ entities
   │  └─ player.cpp
   ├─ main.cpp
   ├─ plateau.cpp
   ├─ tuiles
   │  ├─ tuile.cpp
   │  ├─ tuile_corde.cpp
   │  ├─ tuile_depart.cpp
   │  ├─ tuile_effondrement.cpp
   │  ├─ tuile_emanation.cpp
   │  ├─ tuile_horreur.cpp
   │  ├─ tuile_inondable.cpp
   │  ├─ tuile_ordinaire.cpp
   │  ├─ tuile_retrecissement.cpp
   │  ├─ tuile_sortie.cpp
   │  └─ tuile_terrain_accidente.cpp
   └─ utils
      └─ Str_to_color.cpp

```

## Organisation du code

Pour maintenir une base de code propre, modulaire et facile à maintenir, le projet suit ces règles d'organisation :

- **Miroir `includes/` et `src/`** : À chaque fichier source `.cpp` dans `src/` correspond un fichier d'en-tête `.h` situé dans le dossier équivalent sous `includes/`.
  - _Exemple :_ `src/entities/player.cpp` inclut `entities/player.h`.
- **Includes relatifs au dossier racine** : Dans le code, les inclusions se font à partir de la racine du dossier `includes/` (ex: `#include "entities/player.h"`).

### Description des fichiers et dossiers

| Dossier                  | Fonction                             |
| ------------------------ | ------------------------------------ |
| `main.cpp`               | Instancier et démarrer l'application |
| [`entities/`](#entities) | Modéliser les données                |
| [`core/`]()              | Gérer la logique du jeu              |
| [`display/`](#display)   | Gérer l'affichage                    |
| [`utils/`](#utils)       | Gérer les événements globaux         |

### entities/

- <details>
    <summary><code>player.cpp</code></summary>

  ## Player

  Cette classe abstraite sert de parent pour touts les autres types de joueurs

  ### Attributs

  | nom       | visibilité | utilité                                |
  | --------- | ---------- | -------------------------------------- |
  | pv        | protected  | indiquer les pv restants               |
  | rang      | protected  | indiquer le rang du joueur             |
  | couleur   | protected  | indiquer la couleur du joueur          |
  | conscient | protected  | indiquer si le joueur est conscient    |
  | cache     | protected  | indiquer si le joueur est caché        |
  | actions   | protected  | indiquer le nombre d'actions restantes |
  | maxPv()   | protected  | indiquer le nombre de pv maximum       |

  ### Getters

  | nom          | visibilité |
  | ------------ | ---------- |
  | getPv        | public     |
  | getRang      | public     |
  | getCouleur   | public     |
  | estConscient | public     |
  | estCache     | public     |
  | getActions   | public     |

  ### Autres méthodes

  | nom                         | visibilité | utilité                       |
  | --------------------------- | ---------- | ----------------------------- |
  | subirDegats(`degats`)       | public     | Inflige `degats` dégâts       |
  | recupererPv                 | public     | Ajoute 1 pv                   |
  | setConscient                | public     | Change l'attribut `conscient` |
  | setCache                    | public     | Change l'attribut `cache`     |
  | resetActions                | public     | Met le nombre d'actions à `2` |
  | ajouterActions(`nbActions`) | public     | Ajoute `nbActions` actions    |
  | utiliserActions(`action`)   | public     | Effectue l'action `action`    |

  ## Plongeur

  Hérite de [Player](#player), a pour rang `1` et couleur `#FFFF00`<span style="color:#FFFF00;">■</span>.

  ## Eclaireur

  Hérite de [Player](#player), a pour rang `2`, pour couleur `#000000`<span style="color:#000000;">■</span> et reste constamment caché.

  ## Geologue

  Hérite de [Player](#player), a pour rang `3` et pour couleur `#886644`<span style="color:#886644;">■</span>.

  ## Ingenieur

  Hérite de [Player](#player), a pour rang `4` et pour couleur `#0000FF`<span style="color:#0000FF;">■</span>.

  ## Grimpeur

  Hérite de [Player](#player), a pour rang `5` et pour couleur `#551166`<span style="color:#551166;">■</span>.

  ## Medecin

  Hérite de [Player](#player), a pour rang `6` et pour couleur `#FFFFFF`<span style="color:#FFFFFF;">■</span>.

  ## Garde du corps

  Hérite de [Player](#player), a pour rang `7`, pour couleur `#FF0000`<span style="color:#FF0000;">■</span>.

  ## Chef

  Hérite de [Player](#player), a pour rang `8` et pour couleur `#002200`<span style="color:#002200;">■</span>.

  </details>

### display/

- <details>
  <summary><code>engine/</code></summary>

  Ce dossier a pour but de s'occuper de tout ce qui va être relatif à l'affichage.
  - <details>
    <summary><code>window.cpp</code></summary>

    # Window

    Cette classe a pour but de représenter la fenêtre courante.

    ## Attributs

    | `nom`  | `visibilité` | `utilité`                        |
    | ------ | ------------ | -------------------------------- |
    | height | private      | Obtenir la hauteur de la fenêtre |
    | width  | private      | Obtenir la largeur de la fenêtre |

    ## Getters

    | `nom`  | `visibilité` |
    | ------ | ------------ |
    | Height | public       |
    | Width  | public       |

    </details>

  - <details>
    <summary><code>geometry.cpp</code></summary>

    Ce fichier sert à simplifier l'utilisation des formes.

    # Rectangle (Hérite de sf::RectangleShape)

    Cette classe représente un rectangle.

    ## Attributs

    | `nom`  | `visibilité` | `utilité`                                                |
    | ------ | ------------ | -------------------------------------------------------- |
    | window | protected    | Faire référence à la fenêtre sur laquelle il est affiché |

    ## Méthodes

    | `nom`   | `visibilité` | `utilité`             |
    | ------- | ------------ | --------------------- |
    | Display | public       | Afficher le rectangle |

    # Circle (Hérite de sf::CircleShape)

    Cette classe représente un cercle.

    ## Attributs

    | `nom`  | `visibilité` | `utilité`                                                |
    | ------ | ------------ | -------------------------------------------------------- |
    | window | protected    | Faire référence à la fenêtre sur laquelle il est affiché |

    ## Méthodes

    | `nom`   | `visibilité` | `utilité`          |
    | ------- | ------------ | ------------------ |
    | Display | public       | Afficher le cercle |

    </details>

  </details>

- <details>
  <summary><code>entities/</code></summary>

  Ce dossier a pour but de s'occuper des représentations des éléments correspondants à la du jeu.
  - <details>
    <summary><code>player.cpp</code></summary>

    Ce fichier sert à représenter les joueurs.

    # PlayerDisplay (Hérite de Circle)

    Cette classe représente un joueur.

    ## Attributs

    | `nom`  | `visibilité` | `utilité`                 |
    | ------ | ------------ | ------------------------- |
    | player | private      | Faire référence au joueur |

    # PlayerList (Hérite de std::array<Player\*,6>)

    Cette classe représente une liste de joueurs.

    ## Méthodes

    | `nom`            | `visibilité` | `utilité`                                                                        |
    | ---------------- | ------------ | -------------------------------------------------------------------------------- |
    | Display(`x`,`y`) | public       | Affiche la liste de joueurs en fonction de leur nombre aux coordonnées (`x`,`y`) |

    </details>

  - <details>
      <summary><code>plateau.cpp</code></summary>

    Ce fichier sert à représenter tout ce qui est relatif au plateau.

    # TuileDisplay (Hérite de Rectangle)

    Sert à représenter une tuile.

    ## Attributs

    | `nom` | `visibilité` | `utilité`                                                 |
    | ----- | ------------ | --------------------------------------------------------- |
    | tuile | private      | Faire référence à la tuile                                |
    | size  | private      | Indiquer la largeur du rectangle correspondant à la tuile |

    ## Méthodes

    | `nom`   | `visibilité` | `utilité`                                     |
    | ------- | ------------ | --------------------------------------------- |
    | Display | public       | Faire du polymorphisme en affichant les coins |

    # PlateauDisplay

    Sert à représenter un plateau.

    ## Attributs

    | `nom`   | `visibilité` | `utilité`                    |
    | ------- | ------------ | ---------------------------- |
    | plateau | private      | Faire référence à un plateau |

    ## Méthodes

    | `nom`            | `visibilité` | `utilité`                                    |
    | ---------------- | ------------ | -------------------------------------------- |
    | Display(`x`,`y`) | public       | Affiche le plateau aux coordonnées (`x`,`y`) |

    </details>

  </details>

  </details>

- <details>
  <summary><code>scene/</code></summary>

  Ce dossier sert à représenter une scène.
  - <details>
    <summary><code>scene.cpp</code></summary>

    # Scene

    Cette classe sert à afficher une scène

    ## Attributs

    | `nom`        | `visibilité` | `utilité`                                                   |
    | ------------ | ------------ | ----------------------------------------------------------- |
    | window       | private      | Fait référence à la fenêtre sur laquelle la scène s'affiche |
    | event        | protected    | Correspond aux événements de la fenêtre                     |
    | windowWidth  | protected    | Correspond à la largeur de la fenêtre                       |
    | windowHeight | protected    | Correspond à la hauteur de la fenêtre                       |

    ## Méthodes

    | `nom`                | `visibilité` | `utilité`                                   |
    | -------------------- | ------------ | ------------------------------------------- |
    | afficher (abstraite) | private      | Correspond aux éléments qui seront affichés |
    | events (abstraite)   | protected    | Correspond aux événements de la scène       |
    | Display              | public       | Affiche et gère les événements de la scène  |

    </details>

  - <details>
    <summary><code>Game.cpp</code></summary>

    Sert à gérer la scène de jeu principale.

    # Game (Hérite de Scene)

    Cette classe sert à représenter la scène de jeu principale.

    ## Attributs

    | `nom`       | `visibilité` | `utilité`                                             |
    | ----------- | ------------ | ----------------------------------------------------- |
    | plateauData | private      | Correspond au plateau du jeu représenté               |
    | plateau     | private      | Correspond à l'affichage du plateau du jeu représenté |

    ## Méthodes

    | `nom`            | `visibilité` | `utilité`                                        |
    | ---------------- | ------------ | ------------------------------------------------ |
    | dessinerContours | private      | Dessine les contours de tous les éléments de jeu |

    </details>

  </details>

- <details>
  <summary><code>render.cpp</code></summary>

  Ce fichier sert à gérer l'affichage des scènes.

  # render()

  Cette procédure sert à gérer l'affichage des scènes.

  </details>

### utils/

- <details>
  <summary><code>Str_to_color.cpp</code></summary>

  Ce fichier contient la fonction `Str_to_color(hex)` qui convertit la chaîne de caractères hex représentant une couleur en hexadécimal (ex: `#FFFFFF`, `#000000`) en une couleur utilisable par SFML.

  </details>
