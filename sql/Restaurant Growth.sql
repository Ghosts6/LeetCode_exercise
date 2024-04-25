SELECT
    c.visited_on,
    SUM(t.amount) AS amount,
    ROUND(SUM(t.amount) / 7, 2) AS average_amount
FROM
    (SELECT
        visited_on,
        SUM(amount) AS amount
    FROM
        Customer
    GROUP BY
        visited_on) AS c
JOIN
    (SELECT
        visited_on,
        SUM(amount) AS amount
    FROM
        Customer
    GROUP BY
        visited_on) AS t
ON
    c.visited_on >= t.visited_on
    AND DATEDIFF(c.visited_on, t.visited_on) <= 6
GROUP BY
    c.visited_on
HAVING
    COUNT(DISTINCT t.visited_on) = 7;
