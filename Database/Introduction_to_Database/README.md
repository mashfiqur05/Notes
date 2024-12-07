# Introduction to Database

## Basic Concepts of Database

### What is Database?
Database is a collection of ineterrelated data stored together to serve multiple applications. A generic approch is used to add new data, edit or retrive data within the database.

### Purpose of Database
- **Centralized Data Repisotory:**  A database serves as a centralized repository to store and manage information required by various applications within an organization.

- **Data Accessibility:** Allows efficient retrieval and continuous modification of data for operational and planning purposes.

- **Enhanced Query Capabilities:** Provides the ability to search and query the database to answer specific questions or support decision-making. 

- **Improved Data Management:** Addresses limitations of file-processing systems, such as `data Redundancy` (Eliminates duplicate data storage), `Data Inconsistency`(Ensures uniform data across applications.), `Data Security`, `Error Mitigation` etc.
- **Database Management System (DBMS):** Provides centralized control and management of data, resolving key issues present in traditional file-based systems. 

### Database Abstraction
A major purpose of database is to provide the user with only as much information as is required of them that means the system does not disclose all the details of the data, rather it hides some details of how the data is stored and maintained. The complexity of databases is abstracted through multiple levels, enabling easier user interaction.

**Three Levels of Database Abstraction**

1. *Internal Level (Physical Level)*
    - Closest to physical storage.
    - Describes how data is stored on storage media.
    - describes complex low-level data structures in detail.

2. *Conceptual Level (Logical Level)*
    - Defines what data is stored in the database and what relationships exist between them.
    - Uses logical structures, abstracting physical implementation details.

3. *External Level (View Level)*
    - The highest level of abstraction.
    - Closest to users.
    - Defines how data is viewed by individual users, tailored to their needs.
    - Even though the logical level uses simpler structures, complexity remains because of the variety of information stored in a large database.

#### Data Abstraction and Independence

**Data Abstraction:**
- Changes at one level (e.g., storage) should not impact other levels.
- Promotes flexibility by isolating users from system complexities.

**Data Independence:**
- Prevents redesign or re-implementation when the database changes.
- Ensures smooth scaling and adaptability as the database grows or evolves.

