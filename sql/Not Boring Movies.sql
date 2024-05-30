SELECT * 
FROM Cinema 
WHERE (id % 2 = 1) AND TRIM(description) != 'boring' 
ORDER BY rating DESC;
