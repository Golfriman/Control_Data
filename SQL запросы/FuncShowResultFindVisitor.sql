CREATE OR REPLACE FUNCTION showResultFindVisitor(PHONE_FIND TEXT)
RETURNS TEXT 
AS $body$
DECLARE result_find INT;
BEGIN
	PHONE_FIND:=PHONE_FIND || '%';
	SELECT COUNT(*) INTO result_find FROM visitor WHERE phone LIKE PHONE_FIND;
	RETURN 'Найдены похожие результаты '||result_find;
	--DEBUG: raise notice '%', result_find;
END;
$body$ LANGUAGE PLPGSQL;
SELECT showResultFindVisitor('8');