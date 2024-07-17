select query_name, round(avg(rating / position), 2) quality,
round((avg(coalesce(rating < 3, 0))) * 100, 2) poor_query_percentage
from Queries
group by query_name
having !(query_name is null)