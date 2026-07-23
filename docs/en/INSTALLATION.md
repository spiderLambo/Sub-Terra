# Installation

Read in: [English](INSTALLATION.md) | [Français](../fr/INSTALLATION.md)

## Software Prerequisites

Before starting, make sure you have installed the core tools on your machine:

- **Git**: to clone the project sources.
- **A C/C++ compiler** (`gcc`/`g++` on Linux, `Clang` / `Xcode Tools` on macOS).
- **CMake** (version 3.10 or higher recommended).

## Step-by-Step Installation

<details>
<summary>Linux (Debian / Ubuntu)</summary>

### 1. Update packages and install dependencies

```bash
sudo apt update
sudo apt install build-essential cmake git
```

### 2. Clone the repository

```bash
git clone https://github.com/spiderLambo/Sub-Terra.git
cd Sub-Terra
```

### 3. Compile the project

```bash
chmod +x newbuild.sh
./newbuild.sh
```

### 4. Run the application

```bash
./build/subterra.out
```

</details>

<details>
<summary>macOS</summary>

### 1. Install command-line tools and Homebrew

```bash
xcode-select --install
brew install cmake git
```

### 2. Clone the repository

```bash
git clone https://github.com/spiderLambo/Sub-Terra.git
cd Sub-Terra
```

### 3. Compile the project

```bash
chmod +x newbuild.sh
./newbuild.sh
```

### 4. Run the application

```bash
./build/subterra.out
```

</details>

## Manual Compilation (without newbuild.sh)

If you prefer to build the project manually without using the script:

### 1. Compilation

```bash
mkdir -p build && cd build
cmake ..
make
```

### 2. Launch

```bash
./subterra.out
```

## Troubleshooting Common Issues

- **Permission denied on `newbuild.sh`:**  
  Run `chmod +x newbuild.sh` in your terminal to grant execution rights.
- **CMake not found (`command not found`):**  
  Ensure CMake is properly installed and accessible in your `$PATH` environment variable.
- **Compilation errors after switching branches:**  
  Clean up previously generated files with `./newbuild.sh -clean` and then recompile.
