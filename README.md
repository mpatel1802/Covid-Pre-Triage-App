# 🏥 COVID Pre-Triage App

A **C++-based COVID-19 pre-triage application** designed to simulate the process of registering patients, collecting patient information, assigning triage priorities, and managing patients through a structured pre-triage workflow.

The project uses object-oriented programming principles, file handling, CSV data processing, and modular class design to model a healthcare pre-triage system.

## 📌 Overview

The **COVID Pre-Triage App** is a command-line application that simulates a pre-triage workflow for patients.

The system organizes patient information and uses different patient and triage classes to manage the flow of patients through the application.

The project was developed to demonstrate practical **C++ object-oriented programming**, including inheritance, encapsulation, polymorphism, operator overloading, file I/O, and modular software design.

## ✨ Features

* 🏥 Patient registration and management
* 🦠 COVID-related patient information handling
* 📋 Pre-triage workflow
* 🚨 Patient triage prioritization
* 🎫 Ticket management
* ⏱️ Time tracking
* 💾 CSV-based data storage
* 📂 File input/output
* 🔍 Patient data processing
* 🧩 Object-oriented class architecture
* 💻 Command-line interface
* 📊 Support for small and large datasets

## 🛠️ Technologies Used

| Technology                      | Purpose                                             |
| ------------------------------- | --------------------------------------------------- |
| **C++**                         | Core application development                        |
| **Object-Oriented Programming** | Modeling patients, triage, tickets, menus, and time |
| **CSV**                         | Patient/data storage                                |
| **File I/O**                    | Reading and writing application data                |
| **STL**                         | Data structures and utility functionality           |
| **Command Line**                | User interface                                      |
| **C++ Header Files**            | Class and interface definitions                     |

## 🏗️ Object-Oriented Design

The application is organized into multiple C++ classes, each responsible for a specific part of the system.

### Core Classes

| Class           | Responsibility                                  |
| --------------- | ----------------------------------------------- |
| `Patient`       | Represents general patient information          |
| `CovidPatient`  | Represents COVID-specific patient information   |
| `TriagePatient` | Handles patients involved in the triage process |
| `PreTriage`     | Manages the pre-triage workflow                 |
| `Ticket`        | Represents and manages patient tickets          |
| `Time`          | Handles time-related information                |
| `Menu`          | Controls the application's menu interface       |
| `IOAble`        | Provides input/output-related functionality     |
| `utils`         | Provides supporting utility functions           |

The repository contains separate `.h` and `.cpp` files for these classes, allowing the application to maintain a modular structure.

## 🧠 Application Workflow

A simplified workflow of the application is:

```text
Patient
   │
   ▼
Patient Registration
   │
   ▼
Patient Information
   │
   ▼
Pre-Triage Assessment
   │
   ▼
Triage Classification
   │
   ▼
Ticket Assignment
   │
   ▼
Patient Queue / Processing
   │
   ▼
Updated Patient Records
```

## 📂 Project Structure

```text
Covid-Pre-Triage-App/
│
├── CovidPatient.cpp
├── CovidPatient.h
│
├── IOAble.cpp
├── IOAble.h
│
├── Menu.cpp
├── Menu.h
│
├── Patient.cpp
├── Patient.h
│
├── PreTriage.cpp
├── PreTriage.h
│
├── Ticket.cpp
├── Ticket.h
│
├── Time.cpp
├── Time.h
│
├── TriagePatient.cpp
├── TriagePatient.h
│
├── utils.cpp
├── utils.h
│
├── fpTester.cpp
│
├── data.csv
├── smalldata.csv
├── bigdata.csv
│
├── smalldata.csv.bak
├── bigdata.csv.bak
├── Theseinputs.txt
├── reflect.txt
│
└── README.md
```

The repository currently contains the C++ source/header files, CSV datasets, input data, and testing-related files listed above.

## ⚙️ Getting Started

### Prerequisites

You need a C++ compiler capable of compiling modern C++ code.

Recommended options include:

* GCC
* Clang
* Microsoft Visual C++
* Xcode Command Line Tools

You can verify that a compiler is installed with:

```bash
g++ --version
```

## 📥 Installation

Clone the repository:

```bash
git clone https://github.com/mpatel1802/Covid-Pre-Triage-App.git
```

Navigate into the project:

```bash
cd Covid-Pre-Triage-App
```

## 🔨 Compilation

Compile the project using a C++ compiler.

For example:

```bash
g++ -std=c++11 *.cpp -o covid-triage
```

If compilation succeeds, an executable named `covid-triage` will be created.

> The exact compilation command may need to be adjusted depending on the compiler and environment being used.

## ▶️ Running the Application

On macOS or Linux:

```bash
./covid-triage
```

On Windows:

```text
covid-triage.exe
```

The application runs through the command line and provides an interactive workflow for managing patient and triage information.

## 💾 Data Management

The application uses CSV files to store and process patient-related data.

The repository includes:

* `data.csv`
* `smalldata.csv`
* `bigdata.csv`

as well as backup versions of the datasets.

This provides an opportunity to work with datasets of different sizes while testing the application's data-processing functionality.

## 🧪 Testing

The repository includes:

```text
fpTester.cpp
```

along with input and reflection files that support testing and evaluation of the application.

Example input data is also provided through:

```text
Theseinputs.txt
```

## 🧠 Key C++ Concepts Demonstrated

This project demonstrates practical experience with:

* Object-oriented programming
* Classes and objects
* Inheritance
* Encapsulation
* Polymorphism
* Header/source file separation
* Operator overloading
* File input/output
* CSV data processing
* Dynamic data management
* Modular program design
* Command-line interfaces
* Error handling
* Data validation
* Testing and debugging

## 🎯 Project Goals

The primary goals of this project were to:

1. Apply object-oriented programming to a real-world problem.
2. Model a healthcare pre-triage workflow using C++ classes.
3. Practice inheritance and polymorphism.
4. Implement modular and reusable C++ components.
5. Work with persistent CSV data.
6. Build a functional command-line application.
7. Process and manage patient information efficiently.
8. Develop experience with larger multi-file C++ projects.

## 📚 What I Learned

Through this project, I strengthened my understanding of:

* C++ object-oriented programming
* Software architecture
* Class relationships
* Inheritance and polymorphism
* File handling
* Data parsing
* CSV processing
* Modular programming
* Testing and debugging
* Command-line application development
* Designing software around real-world workflows

## 🔮 Future Improvements

Potential improvements for future versions include:

* [ ] Add a graphical user interface
* [ ] Add a database instead of CSV storage
* [ ] Add user authentication
* [ ] Add role-based access for healthcare workers
* [ ] Add more detailed triage reporting
* [ ] Add patient search functionality
* [ ] Add automated unit testing
* [ ] Add comprehensive logging
* [ ] Improve error handling and input validation
* [ ] Add data export functionality
* [ ] Add configurable triage rules
* [ ] Improve scalability for larger datasets

## ⚠️ Disclaimer

This project is an **educational software project** demonstrating a simulated COVID-19 pre-triage workflow.

It is **not a medical diagnostic tool** and should not be used to make real-world medical decisions or determine actual patient treatment.

## 👨‍💻 Author

**Mann Patel**

GitHub: [@mpatel1802](https://github.com/mpatel1802)

## 📄 License

This project was created for educational and portfolio purposes.
