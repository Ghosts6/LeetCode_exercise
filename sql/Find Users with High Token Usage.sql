SELECT
    user_id,
    COUNT(*) AS prompt_count,
    CAST(ROUND(AVG(CAST(tokens AS decimal(10,2))), 2) AS decimal(10,2)) AS avg_tokens
FROM prompts
GROUP BY user_id
HAVING
    COUNT(*) >= 3
    AND MAX(tokens) > AVG(tokens)
ORDER BY
    avg_tokens DESC,
    user_id ASC;

