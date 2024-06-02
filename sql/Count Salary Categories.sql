SELECT 
    'High Salary' AS category,
    SUM(IF(income > 50000, 1, 0)) AS accounts_count
FROM 
    Accounts
UNION
SELECT 
    'Low Salary' AS category,
    SUM(IF(income < 20000, 1, 0)) AS accounts_count
FROM 
    Accounts
UNION
SELECT 
    'Average Salary' AS category,
    SUM(IF(income >= 20000 AND income <= 50000, 1, 0)) AS accounts_count  
FROM 
    Accounts;
---optimized
SELECT 
    'High Salary' AS category,
    SUM(CASE WHEN income > 50000 THEN 1 ELSE 0 END) AS accounts_count
FROM 
    Accounts
UNION ALL
SELECT 
    'Low Salary' AS category,
    SUM(CASE WHEN income < 20000 THEN 1 ELSE 0 END) AS accounts_count
FROM 
    Accounts
UNION ALL
SELECT 
    'Average Salary' AS category,
    SUM(CASE WHEN income >= 20000 AND income <= 50000 THEN 1 ELSE 0 END) AS accounts_count
FROM 
    Accounts;
