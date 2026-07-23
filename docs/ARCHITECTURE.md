# Architecture

## Structure du projet

```
Sub-Terra
├─ CMakeLists.txt
├─ README.md
├─ docs
│  └─ ARCHITECTURE.md
├─ includes
│  ├─ entities
│  │  └─ player.h
│  └─ main.h
├─ newbuild.sh
└─ src
   ├─ entities
   │  └─ player.cpp
   └─ main.cpp

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
| [`display/`]()           | Gérer l'affichage                    |
| [`utils/`]()             | Gérer les événements globaux         |

### entities

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

  | nom                         | visibilité | utilité                        |
  | --------------------------- | ---------- | ------------------------------ |
  | subirDegats(`degats`)       | public     | Inflige `degats` dégâts        |
  | recupererPv                 | public     | Ajoute 1 pv                    |
  | setConscient                | public     | Change l'attribut `conscient`  |
  | setCache                    | public     | Change l'attribut `cache`      |
  | resetActions                | public     | MMet le nombre d'actions à `2` |
  | ajouterActions(`nbActions`) | public     | Ajoute `nbActions` actions     |
  | utiliserActions(`action`)   | public     | Effectue l'action `action`     |

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
