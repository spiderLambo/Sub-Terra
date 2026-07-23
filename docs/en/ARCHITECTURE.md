# Architecture

Read in: [English](ARCHITECTURE.md) | [Français](../fr/ARCHITECTURE.md)

## Project Structure

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
| [`display/`]()           | Handle rendering                      |
| [`utils/`]()             | Handle global events                  |

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
