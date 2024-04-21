SELECT u.user_id AS buyer_id,u.join_date,COUNT(CASE WHEN YEAR(o.order_date) = 2019 THEN o.order_id END) AS orders_in_2019
FROM Users u
LEFT JOIN Orders o ON u.user_id = o.buyer_id
GROUP BY u.user_id, u.join_date;

