# Architecture

Read in: [English](ARCHITECTURE.md) | [Français](../fr/ARCHITECTURE.md)

## Project Structure

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

## Code Organization

To maintain a clean, modular, and easy-to-maintain codebase, the project follows these organization rules:

- **Mirroring `includes/` and `src/`**: Each `.cpp` source file in `src/` corresponds to a `.h` header file located in the equivalent directory under `includes/`.
  - _Example:_ `src/entities/player.cpp` includes `entities/player.h`.
- **Root-relative inclusions**: In the code, `#include` paths are defined relative to the root of the `includes/` directory (e.g., `#include "entities/player.h"`).

### Files and Directories Description

| Directory                | Function                              |
| ------------------------ | ------------------------------------- |
| `main.cpp`               | Instantiate and start the application |
| [`entities/`](#entities) | Model game data                       |
| [`core/`]()              | Handle game logic                     |
| [`display/`](#display)   | Handle rendering                      |
| [`utils/`](#utils)       | Handle global events                  |

### entities/

- <details>
    <summary><code>player.cpp</code></summary>

  ## Player

  This abstract class serves as the parent class for all other player types.

  ### Attributs

  | name      | visibility | purpose                              |
  | --------- | ---------- | ------------------------------------ |
  | pv        | protected  | indicates remaining health points    |
  | rang      | protected  | indicates the player's rank          |
  | couleur   | protected  | indicates the player's color         |
  | conscient | protected  | indicates if the player is conscious |
  | cache     | protected  | inndicates if the player is hidden   |
  | actions   | protected  | indicates remaining action points    |
  | maxPv()   | protected  | indicates maximum health points      |

  ### Getters

  | name         | visibility |
  | ------------ | ---------- |
  | getPv        | public     |
  | getRang      | public     |
  | getCouleur   | public     |
  | estConscient | public     |
  | estCache     | public     |
  | getActions   | public     |

  ### Other Methods

  | name                        | visibility | purpose                           |
  | --------------------------- | ---------- | --------------------------------- |
  | subirDegats(`degats`)       | public     | Deals `degats` damage             |
  | recupererPv                 | public     | Restores 1 hp                     |
  | setConscient                | public     | Updates the `conscient` attribute |
  | setCache                    | public     | Updates the `cache` attribute     |
  | resetActions                | public     | Resets the action count to `2`    |
  | ajouterActions(`nbActions`) | public     | Adds `nbActions` actions          |
  | utiliserActions(`action`)   | public     | Performs the action `action`      |

  ## Diver (Plongeur)

  Inherits from [Player](#player), has rank `1` and color `#FFFF00`<span style="color:#FFFF00;">■</span>.

  ## Scout (Eclaireur)

  Inherits from [Player](#player), has rank `2`, color `#000000`<span style="color:#000000;">■</span>, and remains permanently hidden.

  ## Geologist (Geologue)

  Inherits from [Player](#player), has rank `3` and color `#886644`<span style="color:#886644;">■</span>.

  ## Engineer (Ingenieur)

  Inherits from [Player](#player), has rank `4` and color `#0000FF`<span style="color:#0000FF;">■</span>.

  ## Climber (Grimpeur)

  Inherits from [Player](#player), has rank `5` and color `#551166`<span style="color:#551166;">■</span>.

  ## Medic (Medecin)

  Inherits from [Player](#player), has rank `6` and color `#FFFFFF`<span style="color:#FFFFFF;">■</span>.

  ## Bodyguard (Garde du corps)

  Inherits from [Player](#player), has rank `7` and color `#FF0000`<span style="color:#FF0000;">■</span>.

  ## Leader (Chef)

  Inherits from [Player](#player), has rank `8` and color `#002200`<span style="color:#002200;">■</span>.

  </details>

### display/

- <details>
  <summary><code>engine/</code></summary>

  This folder is meant to handle everything related to the display.
  - <details>
    <summary><code>window.cpp</code></summary>

    # Window

    This class is meant to represent the current window.

    ## Attributes

    | `name` | `visibility` | `purpose`                    |
    | ------ | ------------ | ---------------------------- |
    | height | private      | Get the height of the window |
    | width  | private      | Get the width of the window  |

    ## Getters

    | `name` | `visibility` |
    | ------ | ------------ |
    | Height | public       |
    | Width  | public       |

    </details>

  - <details>
    <summary><code>geometry.cpp</code></summary>

    This file is used to simplify the use of shapes.

    # Rectangle (Inherits from sf::RectangleShape)

    This class represents a rectangle.

    ## Attributes

    | `name` | `visibility` | `purpose`                                     |
    | ------ | ------------ | --------------------------------------------- |
    | window | protected    | Reference the window on which it is displayed |

    ## Methods

    | `name`  | `visibility` | `purpose`             |
    | ------- | ------------ | --------------------- |
    | Display | public       | Display the rectangle |

    # Circle (Inherits from sf::CircleShape)

    This class represents a circle.

    ## Attributes

    | `name` | `visibility` | `purpose`                                     |
    | ------ | ------------ | --------------------------------------------- |
    | window | protected    | Reference the window on which it is displayed |

    ## Methods

    | `name`  | `visibility` | `purpose`          |
    | ------- | ------------ | ------------------ |
    | Display | public       | Display the circle |

    </details>

  </details>

- <details>
  <summary><code>entities/</code></summary>

  This folder is meant to handle the representations of elements corresponding to the game.
  - <details>
    <summary><code>player.cpp</code></summary>

    This file is used to represent players.

    # PlayerDisplay (Inherits from Circle)

    This class represents a player.

    ## Attributes

    | `name` | `visibility` | `purpose`            |
    | ------ | ------------ | -------------------- |
    | player | private      | Reference the player |

    # PlayerList (Inherits from std::array<Player\*,6>)

    This class represents a list of players.

    ## Methods

    | `name`           | `visibility` | `purpose`                                                                   |
    | ---------------- | ------------ | --------------------------------------------------------------------------- |
    | Display(`x`,`y`) | public       | Displays the list of players based on their number at coordinates (`x`,`y`) |

    </details>

  - <details>
      <summary><code>plateau.cpp</code></summary>

    This file is used to represent everything relative to the board.

    # TuileDisplay (Inherits from Rectangle)

    Used to represent a tile.

    ## Attributes

    | `name` | `visibility` | `purpose`                                                     |
    | ------ | ------------ | ------------------------------------------------------------- |
    | tuile  | private      | Reference the tile                                            |
    | size   | private      | Indicate the width of the rectangle corresponding to the tile |

    ## Methods

    | `name`  | `visibility` | `purpose`                                      |
    | ------- | ------------ | ---------------------------------------------- |
    | Display | public       | Perform polymorphism by displaying the corners |

    # PlateauDisplay

    Used to represent a board.

    ## Attributes

    | `name`  | `visibility` | `purpose`         |
    | ------- | ------------ | ----------------- |
    | plateau | private      | Reference a board |

    ## Methods

    | `name`           | `visibility` | `purpose`                                   |
    | ---------------- | ------------ | ------------------------------------------- |
    | Display(`x`,`y`) | public       | Displays the board at coordinates (`x`,`y`) |

    </details>

  </details>

  </details>

- <details>
  <summary><code>scene/</code></summary>

  This folder is used to represent a scene.
  - <details>
    <summary><code>scene.cpp</code></summary>

    # Scene

    This class is used to display a scene

    ## Attributes

    | `name`       | `visibility` | `purpose`                                             |
    | ------------ | ------------ | ----------------------------------------------------- |
    | window       | private      | References the window on which the scene is displayed |
    | event        | protected    | Corresponds to the window events                      |
    | windowWidth  | protected    | Corresponds to the window width                       |
    | windowHeight | protected    | Corresponds to the window height                      |

    ## Methods

    | `name`              | `visibility` | `purpose`                                      |
    | ------------------- | ------------ | ---------------------------------------------- |
    | afficher (abstract) | private      | Corresponds to elements that will be displayed |
    | events (abstract)   | protected    | Corresponds to scene events                    |
    | Display             | public       | Displays and handles scene events              |

    </details>

  - <details>
    <summary><code>Game.cpp</code></summary>

    Used to manage the main game scene.

    # Game (Inherits from Scene)

    This class is used to represent the main game scene.

    ## Attributes

    | `name`      | `visibility` | `purpose`                                                |
    | ----------- | ------------ | -------------------------------------------------------- |
    | plateauData | private      | Corresponds to the represented game board                |
    | plateau     | private      | Corresponds to the display of the represented game board |

    ## Methods

    | `name`           | `visibility` | `purpose`                               |
    | ---------------- | ------------ | --------------------------------------- |
    | dessinerContours | private      | Draws the outlines of all game elements |

    </details>

  </details>

- <details>
  <summary><code>render.cpp</code></summary>

  This file is used to manage the display of scenes.

  # render()

  This procedure is used to manage the display of scenes.

  </details>

### utils/

- <details>
  <summary><code>Str_to_color.cpp</code></summary>

  This file contains the `Str_to_color(hex)` function which converts the `hex` character string representing a color in hexadecimal (ex: `#FFFFFF`, `#000000`) into a color usable by SFML.

  </details>
