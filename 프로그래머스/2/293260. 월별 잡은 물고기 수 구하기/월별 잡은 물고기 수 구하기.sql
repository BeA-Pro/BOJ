-- 코드를 작성해주세요
select COUNT(*) as FISH_COUNT, MONTH(fi.time) as MONTH
from fish_info fi
group by MONTH(fi.time)
having COUNT(*) > 0
order by MONTH(fi.time)
