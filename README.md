# SUB TERRA

Read in: [English](README.md) | [Français](README.fr.md)

The goal of this project is to adapt the board game [Sub Terra](https://www.nutspublishing.com/eshop/sub-terra-en) into a video game.

## Quick Start

- <details>
  <summary>Linux (Ubuntu / Debian)</summary>

  ```bash
  sudo apt update
  sudo apt install build-essential cmake libsfml-dev
  git clone https://github.com/spiderLambo/Sub-Terra.git
  cd Sub-Terra
  ./newbuild.sh
  ./build/subterra.out
  ```

</details>

- <details>
  <summary>MacOs</summary>

  ```bash
  xcode-select --install
  brew install cmake sfml
  git clone https://github.com/spiderLambo/Sub-Terra.git
  cd Sub-Terra
  chmod +x newbuild.sh
  ./newbuild.sh
  ./build/subterra.out
  ```

</details>

## Ressources

- [Architecture](/docs/en/ARCHITECTURE.md)
- [Installation](/docs/en/INSTALLATION.md)
- [Development](/docs/en/DEVELOPEMENT.md)
- [Changelog](CHANGELOG.md)
