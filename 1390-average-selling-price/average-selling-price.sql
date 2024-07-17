select a.product_id, if(round(sum(a.price*b.units) / (select sum(u.units) from UnitsSold u group by u.product_id having u.product_id = a.product_id), 2),round(sum(a.price*b.units) / (select sum(u.units) from UnitsSold u group by u.product_id having u.product_id = a.product_id), 2),0) average_price from Prices a left join UnitsSold b
on a.product_id = b.product_id and b.purchase_date >= a.start_date and b.purchase_date <= a.end_date
group by a.product_id
