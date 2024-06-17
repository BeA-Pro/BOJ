-- 코드를 작성해주세요
with MAXS as(
select max(size_of_colony) as da, year(differentiation_date) as year
from ecoli_data
group by year(differentiation_date)
)
select a.year as YEAR, (a.da - e.size_of_colony) as YEAR_DEV, e.id as ID
from ecoli_data as e
inner join MAXS as a
on a.year = year(e.differentiation_date)
order by YEAR, YEAR_DEV
