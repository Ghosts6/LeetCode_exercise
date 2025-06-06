SELECT
    id,
    SUM(revenue) FILTER (WHERE month = 'Jan') AS jan_revenue,
    SUM(revenue) FILTER (WHERE month = 'Feb') AS feb_revenue,
    SUM(revenue) FILTER (WHERE month = 'Mar') AS mar_revenue,
    SUM(revenue) FILTER (WHERE month = 'Apr') AS apr_revenue,
    SUM(revenue) FILTER (WHERE month = 'May') AS may_revenue,
    SUM(revenue) FILTER (WHERE month = 'Jun') AS jun_revenue,
    SUM(revenue) FILTER (WHERE month = 'Jul') AS jul_revenue,
    SUM(revenue) FILTER (WHERE month = 'Aug') AS aug_revenue,
    SUM(revenue) FILTER (WHERE month = 'Sep') AS sep_revenue,
    SUM(revenue) FILTER (WHERE month = 'Oct') AS oct_revenue,
    SUM(revenue) FILTER (WHERE month = 'Nov') AS nov_revenue,
    SUM(revenue) FILTER (WHERE month = 'Dec') AS dec_revenue
FROM department
GROUP BY id;
