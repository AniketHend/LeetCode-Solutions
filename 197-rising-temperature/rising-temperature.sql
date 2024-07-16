# Write your MySQL query statement below
select id from 
(select w1.id,w1.temperature t1,w2.temperature t2 from Weather w1 cross join Weather w2
where DATEDIFF(w1.recordDate,w2.recordDate) = 1) as P
where P.t1 > P.t2;