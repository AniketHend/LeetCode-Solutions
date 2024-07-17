
select a.contest_id,round((count(a.user_id)/(select count(distinct(p.user_id)) from Users p))*100,2) percentage from Register a left join Users b on a.user_id = b.user_id
group by a.contest_id
order by percentage desc,a.contest_id ASC
