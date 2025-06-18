WITH RankedSalaries AS (
    SELECT 
        d.name AS department,
        e.name AS employee,
        e.salary,
        RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rank
    FROM 
        Employee e
    JOIN 
        Department d ON e.departmentId = d.id
)
SELECT  
    department,
    employee,
    salary
FROM 
    RankedSalaries
WHERE 
    rank = 1;

