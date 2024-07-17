select a.product_id, COALESCE(round(sum(a.price*b.units)/sum(b.units),2),0)  average_price from Prices a left join UnitsSold b
on a.product_id = b.product_id and b.purchase_date >= a.start_date and b.purchase_date <= a.end_date
group by a.product_id
