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
UNION
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
---optimize
(
    SELECT name AS results
    FROM (
        SELECT u.name, COUNT(DISTINCT mr.movie_id) AS num_movies
        FROM Users u
        JOIN MovieRating mr ON u.user_id = mr.user_id
        GROUP BY u.name
        ORDER BY num_movies DESC, u.name ASC
        LIMIT 1
    ) AS user_movies
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
        ORDER BY avg_rating DESC, m.title ASC
        LIMIT 1
    ) AS movies_avg_rating
);

