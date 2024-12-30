# Constraints

There are two types of Constraints.
- Data Constraints
- Edit Constraints

## Data Constraints
- Constraints are the **rules enforced on data columns** on table.
- Used to **limit the type of data** that can go into a table.
- Ensures the **accuracy and reliability** of the data in the database.
- Could be **column level or table level.**
- **Column level** constraints are applied only to **one column.**
- **Table level** constraints are applied to the **whole table.**

## Types of Constraints:
1. **NOT NULL:**
- Ensures that a column cannot have a `NULL` value. This guarantees that a field always contains data.
- Example:
```sql
<col><datatype>(size) not null
```
```sql
CREATE TABLE employees (
    id INT NOT NULL,
    name VARCHAR(50) NOT NULL
);
```
2. **UNIQUE:**
- Ensures that all values in a column are unique, meaning no duplicate values are allowed.
- Example:
```sql
<col><datatype>(size) unique
```
```sql
CREATE TABLE employees (
    id INT UNIQUE,
    email VARCHAR(50) UNIQUE
);
```

3. **PRIMARY KEY:**
- Combines the `NOT NULL` and `UNIQUE` constraints, ensuring that each row in the table has a unique and non-null identifier. A table can only have `one` `PRIMARY KEY`.
- Example:
```sql
<col><datatype>(size) primary key
```
```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(50)
);
```

4. **FOREIGN KEY:**
- Establishes a relationship between two tables by linking a column in one table to the PRIMARY KEY of another table.
```sql
CREATE TABLE departments (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50)
);

CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    dept_id INT,
    FOREIGN KEY (dept_id) REFERENCES departments(dept_id)
);
```

5. **CHECK:**
- Ensures that all values in a column meet a specific condition.
- Example:
```sql
Syntax: 
<col><datatype>(size) check(<logical expression>)
Or,
constraint <constraint_name> check <col> (<logical expression>)
```
```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    salary DECIMAL(10, 2),
    age INT,
    CONSTRAINT chk_salary_age CHECK (salary > 0 AND age > 18) -- Logical condition applied to multiple columns
);
```

6. **DEFAULT:**
- Sets a default value for a column if no value is specified during insertion.
- Example:
```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    status VARCHAR(20) DEFAULT 'Active'
);
```

7. **INDEX:**
- Improves the speed of data retrieval but does not enforce uniqueness (unless used with UNIQUE).
- Example:
```sql
CREATE INDEX idx_name ON employees(name);
```

---

## Edit Constraints

Constraints can also be added or removed from an existing table using the `ALTER TABLE` command.

- **Adding Constraints**

For foreign key:
```sql
alter table <table>add constraint<constraint_name> foreign key(<current table col>) references <reference table name>(<reference col>);
```
```sql
ALTER TABLE employees
ADD CONSTRAINT chk_salary CHECK (salary > 0);
```

- **Drop Constraints**
```sql
alter table <table> drop constraint <constraint_name>;
```
```sql
ALTER TABLE employees
DROP CONSTRAINT chk_salary;
```

- Disable Constraints
```sql
alter table <table> disable  constraint <constraint_name>;
```
```sql
INSERT INTO employees (id, name, salary, age) 
VALUES (1, 'John Doe', -500, 25); -- This will succeed because the constraint is disabled

```

- Enable Constraints
```sql
alter table <table> enable constraint <constraint_name>;
```
```sql
ALTER TABLE employees ENABLE CONSTRAINT chk_salary;
```
