select P.machine_id,round(avg(P.t2-P.t1),3) processing_time from (
select a.machine_id,a.timestamp t1,b.timestamp t2  from Activity a left join Activity b on a.machine_id = b.machine_id and a.process_id = b.process_id
where a.activity_type = "start" and b.activity_type = "end") as P
group by P.machine_id