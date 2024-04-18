SELECT e.name AS name FROM Employee AS e
JOIN
    (SELECT managerId, COUNT(*) AS num_reports
     FROM Employee
     GROUP BY managerId) AS reports ON e.id = reports.managerId
WHERE
    reports.num_reports >= 5;