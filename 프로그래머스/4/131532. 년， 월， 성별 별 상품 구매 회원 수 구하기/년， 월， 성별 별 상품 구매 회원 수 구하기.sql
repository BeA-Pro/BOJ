-- 코드를 입력하세요
SELECT YEAR(os.sales_date) as YEAR,
    MONTH(os.sales_date) as MONTH,
    ui.gender as GENDER,
    COUNT(distinct ui.user_id) as USERS
from online_sale os
left join user_info ui on os.user_id= ui.user_id
where ui.gender is not null
group by YEAR(os.sales_date), MONTH(os.sales_date), ui.gender
order by 1,2,3