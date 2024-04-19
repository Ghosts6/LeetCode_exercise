SELECT s.name
FROM salesPerson AS s
LEFT JOIN orders AS o ON s.sales_id = o.sales_id
LEFT JOIN company AS c ON o.com_id = c.com_id AND c.name = 'RED'
WHERE c.com_id IS NULL;