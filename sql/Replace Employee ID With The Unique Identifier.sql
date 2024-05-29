SELECT u.unique_id,e.name FROM employees e
LEFT JOIN employeeUNI u ON e.id = u.id;
---optimized
SELECT u.unique_id, e.name 
FROM employees e
LEFT JOIN employeeUNI u ON e.id = u.id;
