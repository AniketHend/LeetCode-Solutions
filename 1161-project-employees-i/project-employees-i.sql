
select a.project_id,round(avg(b.experience_years),2) average_years from Project a left join Employee b on a.employee_id=b.employee_id
group by a.project_id