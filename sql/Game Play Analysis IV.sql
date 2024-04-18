SELECT 
    ROUND(
        SUM(CASE WHEN DATEDIFF(a.event_date, f.first_login_date) = 1 THEN 1 ELSE 0 END) 
        / COUNT(DISTINCT a.player_id), 
    2) AS fraction
FROM 
    Activity AS a
JOIN (
    SELECT 
        player_id, 
        MIN(event_date) AS first_login_date
    FROM 
        Activity
    GROUP BY 
        player_id
) AS f ON a.player_id = f.player_id;
