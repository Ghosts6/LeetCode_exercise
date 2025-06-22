-- my sql
SELECT 
    e1.name AS Employee
FROM 
    Employee e1
JOIN 
    Employee e2 ON e1.managerId = e2.id
WHERE 
    e1.salary > e2.salary;

-- psql
SELECT e1.name AS employee
FROM employee e1
JOIN employee e2 ON e1.managerid = e2.id
WHERE e1.salary > e2.salary;

