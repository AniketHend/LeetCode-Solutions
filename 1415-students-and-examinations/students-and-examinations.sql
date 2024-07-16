select s.student_id,s.student_name,m.subject_name,count(e.student_id) attended_exams from Students s
cross join Subjects m left join Examinations e
on s.student_id = e.student_id and e.subject_name = m.subject_name
group by s.student_id ,m.subject_name, s.student_name
order by s.student_id , m.subject_name; 
