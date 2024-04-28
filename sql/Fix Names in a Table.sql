SELECT user_id, CONCAT(UPPER(substring(name, 1,1)), LOWER(substring(name,2,50))) AS name
FROM users ORDER BY user_id