SELECT 
    employee_id,
    CASE 
        WHEN COUNT(employee_id) = 1 THEN MIN(department_id) 
        WHEN SUM(primary_flag = 'Y') > 0 THEN MIN(CASE WHEN primary_flag = 'Y' THEN department_id ELSE NULL END) 
        ELSE NULL
    END AS department_id
FROM 
    Employee 
GROUP BY 
    employee_id;