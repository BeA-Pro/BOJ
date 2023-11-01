-- 코드를 입력하세요
# select * from first_half

select flavor from (
    select flavor , sum(total_order) as total_order from  (
        select a.flavor, sum(a.total_order) as total_order
        from first_half as a
        group by a.flavor
        union all
        select b.flavor, sum(b.total_order) as total_order
        from july as b
        group by b.flavor
    ) x
    group by flavor
) xx
order by total_order desc limit 3