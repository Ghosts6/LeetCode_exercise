SELECT
    Request_at AS Day,
    ROUND(SUM(CASE WHEN Status IN ('cancelled_by_driver', 'cancelled_by_client') THEN 1 ELSE 0 END) / COUNT(*), 2) AS 'Cancellation Rate'
FROM
    Trips
WHERE 
    Client_Id NOT IN (SELECT Users_Id FROM Users WHERE Banned ='Yes' AND Role = 'client')
    AND Driver_Id NOT IN (SELECT Users_Id FROM Users WHERE Banned ='Yes' AND Role = 'driver')
    AND Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY
    Request_at;
