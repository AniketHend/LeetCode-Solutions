
select E.customer_id,count(*) as count_no_trans from (
select v.customer_id,t.transaction_id from visits v left join Transactions t on v.visit_id = t.visit_id
group by v.visit_id
having t.transaction_id IS null
) as E
group by E.customer_id