SELECT s.product_id, 
       s.year AS first_year,
       s.quantity,
       s.price
FROM Sales s
JOIN (
    SELECT product_id, 
           MIN(year) AS min_year
    FROM Sales
    GROUP BY product_id
) min_years ON s.product_id = min_years.product_id AND s.year = min_years.min_year
JOIN Product p ON s.product_id = p.product_id
