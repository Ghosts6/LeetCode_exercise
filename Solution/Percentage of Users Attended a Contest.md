# 📊 Percentage of Users Attended a Contest 📊

## Intuition
🤔 Counting the percentage of users registered in each contest seems like a straightforward task. 

## Approach
💡 We can achieve this by dividing the count of users registered in each contest by the total number of distinct users and rounding the result to two decimal places. Then, we order the results by percentage in descending order. In case of a tie, we sort the contests by their IDs in ascending order.

### code 
```sql
SELECT r.contest_id, 
       ROUND(COUNT(r.user_id) * 100.0 / (SELECT COUNT(DISTINCT user_id) FROM Users), 2) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER By percentage DESC,r.contest_id;
```