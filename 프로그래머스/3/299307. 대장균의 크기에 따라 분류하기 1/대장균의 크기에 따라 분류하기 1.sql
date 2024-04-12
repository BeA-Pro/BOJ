-- 코드를 작성해주세요
SELECT ID,
    CASE
        when SIZE_OF_COLONY <= 100 then 'LOW'
        when size_of_colony <= 1000 then 'MEDIUM'
        else 'HIGH'
    END AS Size
from ecoli_data