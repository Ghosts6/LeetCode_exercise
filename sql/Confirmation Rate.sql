SELECT a.user_id, ROUND(IFNULL(AVG(action = 'confirmed'), 0), 2) AS confirmation_rate
FROM Signups a
LEFT JOIN Confirmations b ON a.user_id = b.user_id
GROUP BY a.user_id;
---optimize
SELECT 
    a.user_id, 
    ROUND(COALESCE(AVG(b.action = 'confirmed'), 0), 2) AS confirmation_rate
FROM 
    Signups a
LEFT JOIN 
    Confirmations b ON a.user_id = b.user_id
GROUP BY 
    a.user_id;
