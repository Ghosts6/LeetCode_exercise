WITH cte AS (
    SELECT 
        customer_id, 
        MIN(order_date) AS first_order_date 
    FROM 
        Delivery 
    GROUP BY 
        customer_id
)
SELECT 
    ROUND(
        SUM(CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 1 ELSE 0 END) * 100.0 / COUNT(*),
        2
    ) AS immediate_percentage 
FROM 
    Delivery d
JOIN 
    cte c ON d.customer_id = c.customer_id AND d.order_date = c.first_order_date;
