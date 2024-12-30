
## Database Languages
- Data Definition Language
- Data Manipulation Language
- Data Control Language
- Transactional Control Language
---

## DDL
DDL stands for Data Defination Language. 
DDL commands operate on schemas and metadata, ensuring the database's structure is organized.

### Commands in DDL:
1. **CREATE:** 
- Used to create new database objects such as tables, indexes, views, stored procedures, and triggers.
- Example: 
```sql
Create table <table name> (<col1><datatype>(<size>),<col2><datatype>(<size>));
```
```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR2(50),
    position VARCHAR2(50)
);
```

2. **ALTER:**
- Modifies the structure of existing database objects.
- Example:

```sql
Add new columns:
Syntax: 
Alter table <tablename> add(<new col> <datatype(size), <newcol> datatype(size));

Dropping a column from a table
Syntax: 
Alter table <tablename> drop column <col>;

Renaming existing columns
Syntax: 
Alter table <tablename> rename column <old_col>to<new_col>;

Modifying existing columns datatype
Syntax: 
Alter table <tablename> modify<col><newdatatype>(<newsize>));
```
```sql
ALTER TABLE employees ADD COLUMN salary DECIMAL(10, 2);
```

3. **DROP:**
- Deletes database objects like tables or views permanently.
- Example: 
```sql
Drop table <tablename>;  (deletes a table in the database)
```
```sql
DROP TABLE employees;
```

4. **TRUNCATE:**
- Removes all records from a table and reclaims the allocated storage space. Unlike DELETE, it cannot be rolled back.
- Example:
```sql
Truncate table <tablename>; (deletes the data inside a table, but not the table itself)
```
```sql
TRUNCATE TABLE employees;
```

5. **RENAME:**
- Renames an existing database object.
- Example:
```sql
Rename <oldtable> to <new table>;
```
```sql
RENAME employees TO staff;
```

###  Table Checking
To see all the tables which are accessible to the current user
```sql
SELECT table_name
FROM all_tables
```

To see all the tables which are created by the current user
```sql
SELECT table_name
FROM user_tables
```

## Data Manipulation Language (DML):
DML commands deal with the actual data in a database, allowing users to insert, update, delete, or retrieve records.

### Commands in DML:
1. **SELECT (DQL - Data Query Language):**

- Retrieves data from one or more tables without modifying them.
- Example:
```sql
SELECT * FROM employees WHERE position = 'Manager';
```

2. **INSERT:**
- Adds new records to a table.
- Example:
```sql
Syntax 1:
insert into <tablename> (<col1>,<col2>…..<col n>) values(<val 1>,<val 2>…….<val n>); 

Syntax 2:
insert into <tablename> values(<val 1>,<val 2>…….,<val n>);
```
```sql
INSERT INTO employees (id, name, position, salary)
VALUES (1, 'John Doe', 'Manager', 80000);
```

3. **UPDATE:**
- Modifies existing records in a table.
- Example:
```sql
a) Updating all rows:
Syntax: 
Update <tablename> set <col>=<exp>,<col>=<exp>;
b) Updating selected records:
Syntax: 
Update <tablename> set <col>=<exp>,<col>=<exp> where<condition>;
```
```sql
UPDATE employees
SET salary = 85000
WHERE position = 'Manager';
```

4. **DELETE:**
- Removes specific records from a table. Unlike TRUNCATE, it can be rolled back.
- Example:
```sql
a) Remove all rows:
Syntax: 
delete from <tablename>;
b) Removal of a specified row/s:
Syntax: 
delete from <tablename> where <condition>;
```
```sql
DELETE FROM employees WHERE position = 'Intern';
```

5. **MERGE:**
- Combines INSERT and UPDATE operations (UPSERT).
- Example:
```sql
MERGE INTO employees AS target
USING new_employees AS source
ON target.id = source.id
WHEN MATCHED THEN UPDATE SET target.salary = source.salary
WHEN NOT MATCHED THEN INSERT (id, name, position, salary)
VALUES (source.id, source.name, source.position, source.salary);
```
6. **CALL:**

- Executes a stored procedure or subprogram.
- Example:
```sql
CALL calculate_bonus();
```

7. EXPLAIN PLAN:
- Shows the query execution plan, helping optimize SQL performance.
- Example:
```sql
EXPLAIN PLAN FOR
SELECT * FROM employees;
```

8. **LOCK TABLE:**
- Provides concurrency control by locking a table to prevent conflicting updates.
- Example:
```sql
LOCK TABLE employees IN EXCLUSIVE MODE;
```
