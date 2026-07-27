# 📚 Library Management System

<p align="center">

![C++](https://img.shields.io/badge/C++-17-blue?style=for-the-badge&logo=c%2B%2B)
![OOP](https://img.shields.io/badge/OOP-Object%20Oriented-success?style=for-the-badge)
![STL](https://img.shields.io/badge/STL-Containers-orange?style=for-the-badge)
![File Handling](https://img.shields.io/badge/File%20Handling-Persistent-red?style=for-the-badge)
![CMake](https://img.shields.io/badge/CMake-Build-blueviolet?style=for-the-badge)

</p>

A **console-based Library Management System** built using **C++17**, **Object-Oriented Programming (OOP)**, **STL Containers**, and **File Handling**.

This project enables efficient management of books and library members with persistent data storage. It demonstrates core C++ concepts including classes, encapsulation, STL, file handling, and modular project architecture.

---

# ✨ Features

| Feature | Status |
|---------|:------:|
| Add Book | ✅ |
| Remove Book | ✅ |
| Update Book | ✅ |
| Search by ID | ✅ |
| Search by Title | ✅ |
| Search by Author | ✅ |
| Display Books | ✅ |
| Register Member | ✅ |
| Remove Member | ✅ |
| Display Members | ✅ |
| Issue Book | ✅ |
| Return Book | ✅ |
| Due Date Tracking | ✅ |
| Fine Calculation | ✅ |
| Show Issued Books | ✅ |
| Automatic Save | ✅ |
| Automatic Load | ✅ |

---

# 🛠 Tech Stack

- C++17
- Object-Oriented Programming
- Standard Template Library (STL)
- File Handling
- CMake
- VS Code

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
│   ├── Member.h
│   ├── Library.h
│   └── Utility.h
│
├── src/
│   ├── Book.cpp
│   ├── Member.cpp
│   ├── Library.cpp
│   ├── Utility.cpp
│   └── main.cpp
│
├── screenshots/
│
├── .gitignore
├── CMakeLists.txt
├── LICENSE
└── README.md
```

---

# 🧠 OOP Concepts Used

- Classes & Objects
- Encapsulation
- Constructors
- Destructors
- Abstraction
- STL Vector
- STL Map
- STL Unordered Map
- File Handling
- Data Persistence
- Menu Driven Programming

---

# 🚀 Build & Run

## Compile

```bash
g++ -std=c++17 -Iinclude src/main.cpp src/Book.cpp src/Member.cpp src/Library.cpp src/Utility.cpp -o library.exe
```

## Run

```bash
./library.exe
```

---

# 📸 Application Screenshots

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

## 👥 Display Members

![Display Members](screenshots/display_members.png)

---

## 📕 Issue Book

![Issue Book](screenshots/issue_book.png)

---

## 📋 Issued Books

![Issued Books](screenshots/issued_books.png)

---

## 📗 Return Book

![Return Book](screenshots/return_book.png)

---

## 🔍 Search Book

![Search Book](screenshots/search_title.png)

---

## 🚫 Duplicate Book Validation

![Duplicate Book](screenshots/duplicate_book.png)

---

## 💾 Data Persistence

![Data Persistence](screenshots/data_loaded.png)

---

# 💾 Data Storage

The application stores all records in plain text files.

```text
data/
├── books.txt
├── members.txt
└── issues.txt
```

Data is automatically loaded when the application starts and saved whenever changes are made.

---

# 🎯 Future Enhancements

- 🔐 Admin Login
- 🔑 Authentication System
- 🖥 GUI Version
- 🗄 MySQL Database Integration
- 📱 QR Code Based Book Issue
- 📷 Barcode Scanner Support
- 📅 Book Reservation System

---

# 👨‍💻 Author

**Ankit**

Computer Science Engineering Student

---

# ⭐ Support

If you found this project useful, consider giving it a ⭐ on GitHub.
