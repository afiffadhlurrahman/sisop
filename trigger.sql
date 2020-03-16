create table sailors ( 
  sid       integer,  
  sname     varchar2(30),
  rating    integer,
  age       float(63)
  type_age 
);

create table boats(
    bid     integer,
    bname   varchar2(30),
    color   varchar2(20)
);

create table reserves(
    sid integer,
    bid integer,      
    day date
);

insert into sailors(sid,sname,rating,age) values (22,'Dustin',7,45.0);
insert into sailors(sid,sname,rating,age) values (29,'Brutus',1,33.0);
insert into sailors(sid,sname,rating,age) values (31,'Lubber',8,55.5);
insert into sailors(sid,sname,rating,age) values (32,'Andy',8,25.5);
insert into sailors(sid,sname,rating,age) values (58,'Rusty',10,35.0);
insert into sailors(sid,sname,rating,age) values (64,'Horatio',7,35.0);
insert into sailors(sid,sname,rating,age) values (71,'Zorba',10,16.0);
insert into sailors(sid,sname,rating,age) values (74,'Horatio',9,35.0);
insert into sailors(sid,sname,rating,age) values (85,'Art',3,25.5);
insert into sailors(sid,sname,rating,age) values (95,'Bob',3,63.5);


insert into boats(bid,bname,color) values (101,'Interlake','blue');
insert into boats(bid,bname,color) values (102,'Interlake','red');
insert into boats(bid,bname,color) values (103,'Clipper','green');
insert into boats(bid,bname,color) values (104,'Marine','red');

insert into reserves(sid,bid,day) values (22,101,TO_DATE('10/10/98','dd/mm/yy'));
insert into reserves(sid,bid,day) values (22,102,TO_DATE('10/10/98','dd/mm/yy'));
insert into reserves(sid,bid,day) values (22,103,TO_DATE('10/08/98','dd/mm/yy'));
insert into reserves(sid,bid,day) values (22,104,TO_DATE('10/07/98','dd/mm/yy'));
insert into reserves(sid,bid,day) values (31,102,TO_DATE('11/10/98','dd/mm/yy'));
insert into reserves(sid,bid,day) values (31,103,TO_DATE('10/06/98','dd/mm/yy'));
insert into reserves(sid,bid,day) values (31,104,TO_DATE('11/12/98','dd/mm/yy'));
insert into reserves(sid,bid,day) values (64,101,TO_DATE('09/05/98','dd/mm/yy'));
insert into reserves(sid,bid,day) values (64,102,TO_DATE('09/08/98','dd/mm/yy'));
insert into reserves(sid,bid,day) values (74,103,TO_DATE('09/08/98','dd/mm/yy'));

create table boatlog(
    blid        integer,
    id_boat     integer,      
    ldate       date,
    changelog   varchar2(20)
);

create sequence seq_log
minvalue 1
maxvalue 9999
start with 1
increment by 1;

create or replace trigger daftar_log
    after insert or update or delete on boats
for each row
declare
    log_action boatlog.changelog%TYPE;
begin
    if inserting then
        log_action :='Insert';
    elsif updating then
        log_action :='Update';
    elsif deleting then
        log_action :='Delete';
    end if;
    
    insert into boatlog (blid,id_boat,ldate,changelog)
    values (seq_log.nextval,bid,SYSDATE,log_action);
end;

-- testing
insert into boats(bid,bname,color) values (105,'Nala','red');
delete from boats where bid = 105;
update boats set bid = 110 where bid = 105;
