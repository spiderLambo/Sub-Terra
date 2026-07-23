# SUB TERRA

L'objectif est ici d'adapter le jeu de société [Sub Terra](https://www.nutspublishing.com/eshop/sub-terra-fr) en jeu vidéo.

## Installation rapide

- <details>
  <summary>Linux (Ubuntu / Debian)</summary>

  ```bash
  sudo apt update
  sudo apt install build-essential cmake
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
  brew install cmake
  git clone https://github.com/spiderLambo/Sub-Terra.git
  cd Sub-Terra
  chmod +x newbuild.sh
  ./newbuild.sh
  ./build/subterra.out
  ```

</details>

## Ressources

- [Architecture](/docs/ARCHITECTURE.md)
- [Installation](/docs/INSTALLATION.md)
- [Developpement](/docs/DEVELOPPEMENT.md)
- [Changelog](./CHANGELOG.md)
