# Write your MySQL query statement below
SELECT v.customer_id, Count(v.visit_id) as count_no_trans
FROM Visits as v
LEFT JOIN Transactions as t on v.visit_id = t.visit_id
where t.transaction_id is NULL
Group by v.customer_id