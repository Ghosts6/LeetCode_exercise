SELECT 
    user_id, 
    email
FROM 
    Users
WHERE 
    email LIKE '%.com'
    AND email LIKE '%@%' 
    AND email NOT LIKE '%@%@%'
    AND LEFT(email, CHARINDEX('@', email) - 1) NOT LIKE '%[^a-zA-Z0-9_]%'
    AND LEN(LEFT(email, CHARINDEX('@', email) - 1)) > 0
    AND SUBSTRING(
            email, 
            CHARINDEX('@', email) + 1, 
            LEN(email) - CHARINDEX('@', email) - 4
        ) NOT LIKE '%[^a-zA-Z]%'
    AND LEN(SUBSTRING(email, CHARINDEX('@', email) + 1, LEN(email) - CHARINDEX('@', email) - 4)) > 0
ORDER BY 
    user_id ASC;
