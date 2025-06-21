-- mysql version
SELECT id,
    CASE 
        WHEN id % 2 = 0 THEN LAG(student, 1, student) OVER (ORDER BY id)
        ELSE COALESCE(LEAD(student, 1, student) OVER (ORDER BY id), student)
    END AS student
FROM Seat;


-- psql version (optimized)
WITH SeatWithLeadLag AS (
    SELECT
        id,
        student,
        LEAD(student) OVER (ORDER BY id) AS next_student,
        LAG(student) OVER (ORDER BY id) AS prev_student
    FROM Seat
)
SELECT
    id,
    CASE 
        WHEN id % 2 = 0 THEN prev_student
        ELSE COALESCE(next_student, student)
    END AS student
FROM SeatWithLeadLag
ORDER BY id;

