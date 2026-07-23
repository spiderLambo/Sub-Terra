# Installation

## Prérequis logiciels

Avant de commencer, assurez-vous d'avoir installé les outils fondamentaux sur votre machine :

- **Git** : pour récupérer les sources du projet.
- **Un compilateur C/C++** (`gcc`/`g++` sous Linux, `Clang` / `Xcode Tools` sous macOS).
- **CMake** (version 3.10 ou supérieure recommandée).

## Installation pas-à-pas

<details>
<summary>Linux (Debian / Ubuntu)</summary>

### 1. Mettre à jour les paquets et installer les dépendances

```bash
sudo apt update
sudo apt install build-essential cmake git
```

### 2. Cloner le dépôt

```bash
git clone https://github.com/spiderLambo/Sub-Terra.git
cd Sub-Terra
```

### 3. Compiler le projet

```bash
chmod +x newbuild.sh
./newbuild.sh
```

### 4. Lancer l'application

```bash
./build/subterra.out
```

</details>

<details>
<summary>macOS</summary>

### 1. Installer les outils de ligne de commande et Homebrew

```bash
xcode-select --install
brew install cmake git
```

### 2. Cloner le dépôt

```bash
git clone https://github.com/spiderLambo/Sub-Terra.git
cd Sub-Terra
```

### 3. Compiler le projet

```bash
chmod +x newbuild.sh
./newbuild.sh
```

### 4. Lancer l'application

```bash
./build/subterra.out
```

</details>

---

## Compilation manuelle (sans newbuild.sh)

Si vous préférez compiler le projet manuellement sans passer par le script :

### 1. Compilation

```bash
mkdir -p build && cd build
cmake ..
make
```

### 2. Lancement

```bash
./subterra.out
```

---

## Résolution des problèmes courants

- **Permission refusée sur `newbuild.sh` :**  
  Exécutez `chmod +x newbuild.sh` dans votre terminal pour accorder les droits d'exécution.
- **CMake introuvable (`command not found`) :**  
  Vérifiez que CMake est bien installé et accessible dans votre variable d'environnement `$PATH`.
- **Erreurs de compilation lors d'un changement de branche :**  
  Nettoyez les anciens fichiers générés avec `./newbuild.sh -clean` puis recompilez.
