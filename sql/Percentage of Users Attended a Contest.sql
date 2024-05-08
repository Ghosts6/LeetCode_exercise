SELECT r.contest_id, 
       ROUND(COUNT(r.user_id) * 100.0 / (SELECT COUNT(DISTINCT user_id) FROM Users), 2) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER By percentage DESC,r.contest_id;