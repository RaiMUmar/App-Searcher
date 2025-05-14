# App-Searcher for macOS

A C-based command-line utility that scans your entire macOS filesystem for a specified application or file by name, and optionally executes it if found.

## 🔍 Overview

This tool performs a recursive file system search starting from the root (`/`) directory to locate a file of a given name. When it locates one, it prints the path to the application, and if executable, runs the file using the macOS `open` command.

> ⚠️ Only use this tool for development or personal use. Do not run recursive root file searches because it is slow and resource-hungry.

## 🛠️ Features

- Recursive directory travel
- Avoids system-sensitive or redundant directories for performance and safety
- Automatically executes the file if it is executable
- Terminal-friendly output for debugging or monitoring progress

## 📁 Skipped Directories

To avoid permission issues and irrelevant content, the program avoids directories like:

```
Volumes, Library, System, bin, dev, etc, opt, private, sbin, tmp, usr, var, Movies, Music, Pictures, Public
```

These can be altered in the code inside `findFile()` to suit your use.

## 🖥️ How to Compile

Use `gcc` to compile the code:
```bash
gcc -o appsearcher appsearcher.c
```

## ▶️ Usage

```bash
./appsearcher <filename>
```

**Example:**
```bash
./appsearcher Notes.app
```

If the file is found and executable, it will be launched automatically. Otherwise, the program will notify you.

## 🧠 How It Works

1. Starts at `/` and recursively searches subdirectories.
2. Checks each file against the target filename.
3. If there is a match:
  - The whole path is printed.
  - If the file is executable, it is opened through `open <filepath>`.

## ⚠️ Important Notes

- Requires execution privileges and may ask for elevated access on some systems.
- Not designed for extremely large file systems or SSD wear; use with caution.
- Current version is macOS-specific due to `open` usage.

## 📄 License

This project is open source and free to use or modify under the MIT License.
