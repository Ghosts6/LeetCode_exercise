# 📊 Product Sales Analysis I

## 📝 Question
**Title:** Product Sales Analysis I

**Description:** Write a solution to report the product_name, year, and price for each sale_id in the Sales table.

Return the resulting table in any order.

## 💡 Intuition
To find the required details for each sale, we need to join the `sales` table with the `product` table using the `product_id`.

## 🛠️ Approach
1. Use an SQL `JOIN` to combine the `sales` and `product` tables based on the `product_id`.
2. Select the `product_name` from the `product` table and `year` and `price` from the `sales` table.

## 💻 SQL Query
```sql
SELECT p.product_name, s.year, s.price 
FROM sales s
JOIN product p ON s.product_id = p.product_id;
```