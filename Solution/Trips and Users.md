# 🚖 Trips and Users Cancellation Rate

## 📋 Problem Description
The cancellation rate is computed by dividing the number of canceled requests (by client or driver) with unbanned users by the total number of requests with unbanned users on that day.

Write a solution to find the cancellation rate of requests with unbanned users (both client and driver must not be banned) each day between "2013-10-01" and "2013-10-03". Round the Cancellation Rate to two decimal points.

Return the result table in any order.

## 💡 Intuition
To determine the cancellation rate, we need to count the number of canceled requests by unbanned users (both clients and drivers) and divide it by the total number of requests made by unbanned users for each day.


## 🛠️ Approach
1. **Filter out banned users**: Select only those trips where both the client and driver are not banned.
2. **Date Range Filtering**: Focus on the date range from '2013-10-01' to '2013-10-03'.
3. **Group and Calculate**: Group the results by day and calculate the cancellation rate for each day. Use `CASE` statements to count the number of canceled trips and divide by the total number of trips, rounding the result to two decimal places.


## 🧮 Complexity
- Time complexity:
O(n), where n is the number of records in the Trips table within the specified date range. The query iterates through these records to apply filters and aggregations.

- Space complexity:
O(n), where n is the number of records that match the query conditions. The space is used to store the intermediate results of the filtered and grouped data.

# 💻 Code
### Query
```sql
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
```

🔍 Explanation

1.  Filtering Unbanned Users:
        The subqueries (SELECT Users_Id FROM Users WHERE Banned ='Yes' AND Role = 'client') and (SELECT Users_Id FROM Users WHERE Banned ='Yes' AND Role = 'driver') retrieve the IDs of banned clients and drivers, respectively.
        The main query ensures that only trips involving unbanned clients and drivers are selected by using NOT IN with these subqueries.

2.  Date Filtering:
        AND Request_at BETWEEN '2013-10-01' AND '2013-10-03' restricts the results to the specified date range.

3.  Grouping and Aggregation:
        GROUP BY Request_at groups the results by each day within the specified range.
        The CASE statement within the SUM function counts the number of canceled trips.
        ROUND(SUM(CASE WHEN Status IN ('cancelled_by_driver', 'cancelled_by_client') THEN 1 ELSE 0 END) / COUNT(*), 2) calculates the cancellation rate by dividing the number of canceled trips by the total number of trips and rounding the result to two decimal places.