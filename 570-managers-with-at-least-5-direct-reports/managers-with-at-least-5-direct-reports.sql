# Write your MySQL query statement below
select name from Employee 
where id in 
(select managerId from
(select ep.managerId,count(ep.managerId)as c from Employee  as ep 
group by ep.managerId) as sp where sp.c>=5)
