SELECT person_name
FROM (
    SELECT person_id, person_name, weight, SUM(weight) OVER (ORDER BY turn ASC ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS C_SUM
    FROM Queue
) x 
WHERE C_SUM <= 1000
ORDER BY C_SUM DESC
LIMIT 1;
---optimized
SELECT person_name
FROM (
    SELECT 
        person_id, 
        person_name, 
        weight, 
        SUM(weight) OVER (ORDER BY turn ASC) AS C_SUM
    FROM Queue
) x 
WHERE C_SUM <= 1000
ORDER BY C_SUM DESC
LIMIT 1;
