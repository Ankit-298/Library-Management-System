<div align="center">

# 📚 Library Management System

A modern **Console-Based Library Management System** built with **C++17**, **Object-Oriented Programming**, **STL**, and **File Handling**.

<p>

![C++](https://img.shields.io/badge/C++17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![OOP](https://img.shields.io/badge/OOP-Object--Oriented-4CAF50?style=for-the-badge)
![STL](https://img.shields.io/badge/STL-Containers-FF9800?style=for-the-badge)
![File Handling](https://img.shields.io/badge/File%20Handling-Persistent-E91E63?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-blueviolet?style=for-the-badge)

</p>

> Manage books, members, book issuing, returns, due dates, and fines with automatic file-based data persistence.

</div>

---

# 📑 Table of Contents

- ✨ Features
- 🛠 Tech Stack
- 📂 Project Structure
- ⚡ Getting Started
- 📸 Screenshots
- 💾 Data Storage
- 🧠 OOP Concepts
- 🚀 Future Improvements
- 👨‍💻 Author

---

# ✨ Features

| 📚 Library | 👤 Members | 📋 Transactions |
|------------|-----------|----------------|
| ✅ Add Book | ✅ Register Member | ✅ Issue Book |
| ✅ Remove Book | ✅ Remove Member | ✅ Return Book |
| ✅ Update Book | ✅ View Members | ✅ Due Date Tracking |
| ✅ Search Book | | ✅ Fine Calculation |
| ✅ Display Books | | ✅ Issued Books |

### Extra Features

- 💾 Automatic Data Saving
- 📂 Automatic Data Loading
- 🚫 Duplicate Book Validation
- 📖 Search by ID, Title & Author
- 🖥 Menu Driven Interface

---

# 🛠 Tech Stack

| Technology | Purpose |
|------------|---------|
| C++17 | Programming Language |
| OOP | Application Design |
| STL | Data Structures |
| File Handling | Persistent Storage |
| CMake | Build System |
| VS Code | Development |

---

# 📂 Project Structure

```text
Library-Management-System
│
├── data/
│   ├── books.txt
│   ├── members.txt
│   └── issues.txt
│
├── include/
│   ├── Book.h
│   ├── Library.h
│   ├── Member.h
│   └── Utility.h
│
├── src/
│   ├── Book.cpp
│   ├── Library.cpp
│   ├── Member.cpp
│   ├── Utility.cpp
│   └── main.cpp
│
├── screenshots/
│
├── .gitignore
├── LICENSE
├── CMakeLists.txt
└── README.md
```

---

# ⚡ Getting Started

## Compile

```bash
g++ -std=c++17 -Iinclude src/main.cpp src/Book.cpp src/Member.cpp src/Library.cpp src/Utility.cpp -o library.exe
```

## Run

```bash
./library.exe
```

---

# 📸 Screenshots

## 🏠 Main Menu

![Main Menu](screenshots/menu.png)

---

## 📖 Add Book

![Add Book](screenshots/add_book.png)

---

## 📚 Display Books

![Display Books](screenshots/display_books.png)

---

## 👤 Register Member

![Register Member](screenshots/register_member.png)

---

## 📕 Issue Book

![Issue Book](screenshots/issue_book.png)

---

## 📗 Return Book

![Return Book](screenshots/return_book.png)

---

## 🔍 Search Book

![Search Book](screenshots/search_title.png)

---

## 💾 Data Persistence

![Data Persistence](screenshots/data_loaded.png)

---

# 💾 Data Storage

All records are stored automatically in text files.

```text
books.txt
members.txt
issues.txt
```

The application loads the data at startup and saves every change automatically.

---

# 🧠 OOP Concepts Demonstrated

- Classes & Objects
- Encapsulation
- Constructors & Destructors
- STL Vector
- STL Map
- STL Unordered Map
- File Handling
- Data Persistence
- Modular Programming

---

# 🚀 Future Improvements

- 🔐 Login System
- 🖥 GUI Version
- 🗄 MySQL Integration
- 📱 QR Code Based Issue
- 📷 Barcode Scanner
- ☁ Cloud Database
- 📊 Reports & Analytics

---

# 👨‍💻 Author

**Ankit**

🎓 Computer Science Engineering Student

---

<div align="center">

### ⭐ If you like this project, don't forget to Star the repository!

Made with ❤️ using C++.

</div>
