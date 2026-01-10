--- base
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016 FROM Insurance
WHERE
    tiv_2015 IN (
        SELECT tiv_2015
        FROM Insurance
        GROUP BY tiv_2015
        HAVING COUNT(*) > 1
    )
    AND (lat, lon) NOT IN (
        SELECT lat, lon
        FROM Insurance
        GROUP BY lat, lon
        HAVING COUNT(*) > 1
    );

--- optimize
SELECT
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM (
    SELECT
        tiv_2016,
        COUNT(*) OVER(PARTITION BY tiv_2015) AS tiv_count,
        COUNT(*) OVER(PARTITION BY lat, lon) AS loc_count
    FROM Insurance
) AS sub
WHERE tiv_count > 1 AND loc_count = 1;
