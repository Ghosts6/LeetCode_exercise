WITH consecutive_days AS (
    SELECT 
        id,
        visit_date,
        people,
        CASE 
            WHEN people >= 100 THEN 1
            ELSE 0
        END AS is_over_100,
        LAG(people, 1) OVER (ORDER BY visit_date) AS prev_day_people,
        LAG(people, 2) OVER (ORDER BY visit_date) AS prev_prev_day_people,
        LEAD(people, 1) OVER (ORDER BY visit_date) AS next_day_people,
        LEAD(people, 2) OVER (ORDER BY visit_date) AS next_next_day_people
    FROM 
        Stadium
)
SELECT 
    id,
    visit_date,
    people
FROM 
    consecutive_days
WHERE 
    is_over_100 = 1
    AND (
        (people >= 100 AND prev_day_people >= 100 AND next_day_people >= 100)
        OR
        (prev_prev_day_people >= 100 AND prev_day_people >= 100 AND people >= 100)
        OR
        (prev_day_people >= 100 AND people >= 100 AND next_day_people >= 100)
        OR
        (people >= 100 AND next_day_people >= 100 AND next_next_day_people >= 100)
    )