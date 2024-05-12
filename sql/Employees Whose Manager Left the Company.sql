SELECT a.employee_id FROM Employees a
WHERE manager_id NOT IN (SELECT e.employee_id FROM Employees e) AND a.salary < 30000
ORDER BY employee_id ASC