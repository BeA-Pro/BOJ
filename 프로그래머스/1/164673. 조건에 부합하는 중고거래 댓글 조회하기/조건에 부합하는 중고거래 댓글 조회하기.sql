-- 코드를 입력하세요
SELECT ugb.title, ugb.board_id, ugr.reply_id, ugr.writer_id, ugr.contents, date_format(ugr.created_date,"%Y-%m-%d") as created_date
from used_goods_board as ugb, used_goods_reply as ugr
where ugb.board_id = ugr.board_id and Year(ugb.created_date) = 2022 and Month(ugb.created_date) = 10
order by ugr.created_date, ugb.title