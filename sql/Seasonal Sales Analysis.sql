WITH CategorySeasonStats AS (
    -- Aggregate data by season and category
    SELECT 
        CASE 
            WHEN MONTH(s.sale_date) IN (12, 1, 2) THEN 'Winter'
            WHEN MONTH(s.sale_date) IN (3, 4, 5) THEN 'Spring'
            WHEN MONTH(s.sale_date) IN (6, 7, 8) THEN 'Summer'
            WHEN MONTH(s.sale_date) IN (9, 10, 11) THEN 'Fall'
        END AS season,
        p.category,
        SUM(s.quantity) AS total_quantity,
        SUM(s.quantity * s.price) AS total_revenue
    FROM sales s
    JOIN products p ON s.product_id = p.product_id
    GROUP BY 
        CASE 
            WHEN MONTH(s.sale_date) IN (12, 1, 2) THEN 'Winter'
            WHEN MONTH(s.sale_date) IN (3, 4, 5) THEN 'Spring'
            WHEN MONTH(s.sale_date) IN (6, 7, 8) THEN 'Summer'
            WHEN MONTH(s.sale_date) IN (9, 10, 11) THEN 'Fall'
        END,
        p.category
),
RankedCategories AS (
    -- Rank categories within each season based on requirements
    SELECT 
        season,
        category,
        total_quantity,
        total_revenue,
        ROW_NUMBER() OVER (
            PARTITION BY season 
            ORDER BY total_quantity DESC, total_revenue DESC, category ASC
        ) as rn
    FROM CategorySeasonStats
)
-- Final selection of the top-ranked category per season
SELECT 
    season,
    category,
    total_quantity,
    total_revenue
FROM RankedCategories
WHERE rn = 1
ORDER BY season ASC;
