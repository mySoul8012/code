start transaction;
update sc
set grade = grade + 1

rollback;

start transaction;
delete from sc

select *
from sc

rollback

start transaction;
delete from sc

rollback;

select *
from sc

start transaction;
delete from sc;

rollback;

select grade,sno,cno;
from sc;

select *
from sc

start transaction; 
delete from sc;

rollback;

select *
from sc;

start transaction; 
delete from sc

rollback;

start transaction;
delete from sc;

rollback;

-- 将sc表删除；
start transaction;
delete from sc;


rollback;

start transaction;
delete from sc;
delete from c;
commit;

rollback;

select *
from sc;

select *
from c;

start transaction;
insert sc(sno, cno, grade)
values ('01', '01', '90');
savepoint insert01;
insert sc(sno, cno, grade)
values ('02', '02', '92');
savepoint insert02;
insert sc(sno, cno, grade)
values ('03', '03', '93');
commit;

rollback to insert01;

select *
from sc

delete from sc
where sno in ('01', '02', '03');

select *
from sc

start transaction;
insert sc(sno, cno, grade)
values ('01', '01', '92');
savepoint a01;
insert sc(sno, cno, grade)
values ('02', '02', '93');
savepoint a02;
insert sc(sno, cno, grade)
values ('03', '03', '94');
savepoint a03;

rollback  a01;

start transaction;
insert sc(sno, cno, grade)
values ('21', '01', '92');
savepoint a01;
insert sc(sno, cno, grade)
values ('22', '02', '93');
savepoint a02;
insert sc(sno, cno, grade)
values ('23', '03', '94');
savepoint a03;

rollback to a02;

select *
from sc
where sno = '23';

select *
from sc
where sno = '22';

commit;

rollback to a02;
