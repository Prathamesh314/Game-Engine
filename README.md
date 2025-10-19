# 🎮 Game Engine

A high-performance game engine built for creating immersive gaming experiences.

## 📋 Prerequisites

Before you begin, ensure you have the following installed:
- **C++ Compiler** (GCC, Clang, or MSVC)
- **Git** for version control
- **Make** or equivalent build tool for your platform

## 🚀 Quick Start

### 1. Download Premake

First, you'll need to download Premake5 for your operating system:

- **Windows**: Download `premake-5.0.0-windows.zip` from [Premake Releases](https://github.com/premake/premake-core/releases)
- **macOS**: Download `premake-5.0.0-macosx.tar.gz` from [Premake Releases](https://github.com/premake/premake-core/releases)
- **Linux**: Download `premake-5.0.0-linux.tar.gz` from [Premake Releases](https://github.com/premake/premake-core/releases)

### 2. Install Premake

Once downloaded, extract the executable and place it in the following directory:

```
vendor/bin/premake/
```

The directory structure should look like this:
```
project-root/
├── vendor/
│   └── bin/
│       └── premake/
│           └── premake5.exe (Windows)
│           └── premake5 (macOS/Linux)
├── run.sh
└── ...
```

### 3. Build the Project

#### For Unix-based systems (Linux/macOS):
```bash
# Make the script executable (first time only)
chmod +x run.sh

# Run the build script
./run.sh
```

#### For Windows:
```bash
# If using Git Bash or WSL
./run.sh

# Or create a run.bat file with equivalent commands
```

## 🛠️ Build Configuration

The `run.sh` script will:
1. Generate project files using Premake
2. Compile the game engine
3. Build all dependencies

## 📁 Project Structure

```
game-engine/
├── vendor/          # Third-party dependencies
│   └── bin/        
│       └── premake/ # Premake executable location
├── src/            # Source code
├── include/        # Header files
├── assets/         # Game assets (textures, models, etc.)
├── build/          # Build output (generated)
└── run.sh          # Build script
```
