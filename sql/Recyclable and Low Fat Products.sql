SELECT product_id 
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y'

---optimized
SELECT product_id 
FROM Products
WHERE low_fats = 'Y' 
  AND recyclable = 'Y';