select product_id,year first_year,quantity,price from Sales
where (product_id,year) in
(
select p.product_id,min(p.year) year from Sales p
group by 1
)