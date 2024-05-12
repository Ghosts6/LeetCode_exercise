# 📜 Employees Whose Manager Left the Company

## 💡 Intuition
When tackling this problem, our initial thoughts are to identify employees whose managers have left the company and whose salaries are below ```$30,000```.

## 🛠️ Approach
To solve this problem, we'll:
1. Select all employees (`a`) from the `Employees` table.
2. Filter out employees whose manager IDs are not present in the list of employee IDs.
3. Further filter out employees whose salaries are below $30,000.
4. Finally, sort the resulting list of employee IDs in ascending order.

## 💻 Code
```sql
# Write your MySQL query statement below
SELECT a.employee_id FROM Employees a
WHERE manager_id NOT IN (SELECT e.employee_id FROM Employees e) AND a.salary < 30000
ORDER BY employee_id ASC
```