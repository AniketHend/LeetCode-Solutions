select e.name , b.bonus from Employee e left join Bonus b 
on e.empId = b.empId
where if(b.bonus,b.bonus,0)<1000