SELECT product_id,year first_year,quantity,price FROM Sales
WHERE (product_id,year) IN
(
    SELECT p.product_id,min(p.year) year FROM Sales p
    GROUP BY 1
)