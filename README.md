# LearningCpp

A clean and simple repository containing all my C++ practice programs created throughout my learning journey.

This repo includes basic to intermediate C++ programs that helped me understand syntax, logic-building, functions, loops, OOP, and more.

---

# 🚀 Introduction

This repository is a collection of my **C++ practice codes**, written as part of my learning path. Each file represents a concept I practiced while improving my logic, debugging skills, and understanding of core C++ fundamentals.

If you're a beginner or someone revising C++, this repo can act as a quick reference for simple, clear examples.

---

# 💻 How to Set Up C++ on Your System

Below are the simplest steps to install everything you need to run C++ programs.

## ✅ 1. Install VS Code

Download from: [https://code.visualstudio.com/](https://code.visualstudio.com/)

Install normally — no special configuration needed.

## ✅ 2. Install MinGW Compiler (for Windows)

1. Download MSYS2 (which includes MinGW) from: [https://www.msys2.org/](https://www.msys2.org/)
2. Install it and open **MSYS2 MinGW 64-bit** terminal.
3. Run the following commands:

```
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc
```

4. Add MinGW to PATH (if needed):

```
C:\msys64\ucrt64\bin
```

## ✅ 3. Install VS Code Extensions

Inside VS Code, install:

* **C/C++ (Microsoft)**
* **Code Runner** (optional but useful)
* **CMake Tools** (optional)

Now you’re ready to compile and run C++!

---

# ▶️ How to Compile & Run C++ Programs

Once the compiler and VS Code are ready, open any `.cpp` file from this repo and use the commands below.

## ✔️ Compile a single file

```
g++ filename.cpp -o output.exe
```

## ✔️ Run the program

```
./output.exe
```

## ✔️ Recommended (compile with warnings)

```
g++ -std=c++17 -Wall -Wextra filename.cpp -o output
```

## ✔️ Using the VS Code Run Button

If you installed **Code Runner**, you can simply press **Run** to execute the program.

---

# 📘 What You’ll Find in This Repo

* Basic syntax examples
* Control flow: if/else, loops, switch
* Functions & recursion
* Arrays and string operations
* Object-Oriented Programming (OOP)
* Small projects (ATM simulator, converters, etc.)
* Learning experiments and logic-building practice

This repository grows as I continue learning.

---

# 📎 Useful Insights While Learning C++

💡 Use floating-point numbers carefully — `9/5` ≠ `9.0/5`

💡 Pre/post increment difference matters: `i++` vs `++i`

💡 Use `-Wall -Wextra` to catch hidden mistakes

💡 Prefer clear variable names and comments while learning

💡 Use `std::vector` and modern C++ instead of raw arrays when possible

---

# 🤝 Contributing

If you want to contribute:

Fork the repo

Create a branch: git checkout -b feature/your-topic

Add your code with clear comments and a short README in the folder

Push and create a PR with a description of what you added

Please follow these rules:

Keep file names descriptive (e.g., arrays_reverse.cpp)

Add comments explaining tricky parts

Prefer simple, educational examples over complex brevity

# 🧾 License

This project is released under the MIT License. See LICENSE for details.

# ✉️ Contact

If you want feedback or help with code, open an issue or reach me at: gopalpinapathuni.@gmafsil.com (optional — add preferred contact)
