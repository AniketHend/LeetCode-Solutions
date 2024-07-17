select round(avg(if(a.order_date = a.customer_pref_delivery_date,1,0))*100,2) immediate_percentage from Delivery a
where order_date = (
    select b.order_date from Delivery b
    where b.customer_id = a.customer_id
    order by b.order_date
    limit 1
)