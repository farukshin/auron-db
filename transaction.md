# Поддержка транзакций

## Побочные действия

* Потерянное обновление / Lost Update

Когда данные меняются в разных транзакциях и одно из изменений теряется.

|Транзакция 1| Транзакция 2|
|--|--|
|status = db.get("key1", value)|status = db.get("key1", value)|
|status = db.insert("key1", value + 10)||
||status = db.insert("key1", value+20)|

* Грязное чтение / Dirty Read

Когда происходит чтение данных, которые не были зафиксированы другой ранзакцией (которая может откатиться).

|Транзакция 1| Транзакция 2|
|--|--|
|status = db.get("key1", value)||
|status = db.insert("key1", value + 10)||
||status = db.get("key1", value)|
|db.ROLLBACK()||

* Неповторяющееся чтение / Non-Repeatable Read

При повторном чтении в рамках одной транзакции ранее прочитанные данные оказываются изменёнными.

|Транзакция 1| Транзакция 2|
|--|--|
||status = db.get("key1", value)|
|status = db.get("key1", value)||
|status = db.insert("key1", value + 10)||
|db.Commit()||
||status = db.get("key1", value)|


* Фантомное чтение / Phantom Reads

При повторном чтении в рамках одной транзакции одна и та же выборка дает разные множества строк.

Неактуально для KV. Будет актуально для колоночной БД.

## Уровни изоляции

|  Isolation level | Phantom Reads | Non-Repeatable Read |	Dirty Read | Lost Update |
| --------	| --- |	--- | --- | ---	|
|SERIALIZABLE |-|	-|	-|	-|
|REPEATABLE READ | + | -	| -	| - |
|READ COMMITTED | +	| +	| -	| - |
|READ UNCOMMITTED |+ | + | + | - |


## Совместимость блокировок auronDB

Различные типы блокировок могут по-разному взаимодействовать между собой. Таблица совместимости блокировок в auronDB:

|  | S| X|
|--|--|--|
| S| +| -|
| X| -| -|
