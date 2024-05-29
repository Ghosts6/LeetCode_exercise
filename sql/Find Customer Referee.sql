SELECT name FROM Customer WHERE referee_id IS NULL OR referee_id != 2;
---optimized
SELECT name 
FROM Customer 
WHERE referee_id IS NULL OR referee_id <> 2;
