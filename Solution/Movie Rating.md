# Intuition
🤔 The problem requires finding the user who has rated the greatest number of movies and the movie with the highest average rating in February 2020.

# Approach
💡 To solve the first part, we count the number of movies each user has rated and find the user with the maximum count. In case of a tie, we select the lexicographically smaller user name. For the second part, we calculate the average rating for each movie in February 2020 and select the movie with the highest average rating. Again, in case of a tie, we choose the lexicographically smaller movie name.

# Complexity
- Time complexity:
🕒 The time complexity for both queries is \(O(n \log n)\), where \(n\) is the number of users or movies, respectively.

- Space complexity:
🚀 The space complexity is \(O(n)\), where \(n\) is the number of users or movies, respectively.

# Code
```sql
(
    SELECT name AS results
    FROM (
        SELECT u.name, COUNT(DISTINCT mr.movie_id) AS num_movies
        FROM Users u
        JOIN MovieRating mr ON u.user_id = mr.user_id
        GROUP BY u.name
    ) AS user_movies
    WHERE num_movies = (
        SELECT MAX(num_movies)
        FROM (
            SELECT COUNT(DISTINCT mr.movie_id) AS num_movies
            FROM Users u
            JOIN MovieRating mr ON u.user_id = mr.user_id
            GROUP BY u.name
        ) AS temp
    )
    ORDER BY name ASC
    LIMIT 1
)
UNION ALL
(
    SELECT title AS results
    FROM (
        SELECT m.title, AVG(mr.rating) AS avg_rating
        FROM Movies m
        JOIN MovieRating mr ON m.movie_id = mr.movie_id
        WHERE YEAR(mr.created_at) = 2020 AND MONTH(mr.created_at) = 2
        GROUP BY m.title
    ) AS movies_avg_rating
    ORDER BY avg_rating DESC, title ASC
    LIMIT 1
);
