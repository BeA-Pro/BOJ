-- 코드를 입력하세요
SELECT animal_type, COUNT(*) as count
from animal_ins
group by animal_type
order by animal_type