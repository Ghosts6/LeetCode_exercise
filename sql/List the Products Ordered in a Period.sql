SELECT 
    p.product_name,
    o.total_units AS unit
FROM 
    Products p
JOIN (
    SELECT 
        product_id,
        SUM(unit) AS total_units
    FROM 
        Orders
    WHERE 
        MONTH(order_date) = 2 AND YEAR(order_date) = 2020
    GROUP BY 
        product_id
    HAVING 
        total_units >= 100
) AS o ON p.product_id = o.product_id;
