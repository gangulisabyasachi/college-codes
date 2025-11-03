create table supplies(
    s_id int primary key,
    sname varchar(100),
    address varchar(100)

);

create table parts(
    pid int primary key,
    pname varchar(100),
    color varchar(30) not null
);

create table catalog(
    s_id int,
    pid int,
    price numeric(10),
    foreign key(s_id) references supplies(s_id), foreign key(pid) references parts(pid)
);

insert into supplies values (1, 'KE', 'Kolkata');
insert into supplies values (2, 'DE', 'Delhi');
insert into supplies values (3, 'EE', 'Goa');

insert into parts values(1, 'laptop','silver');
insert into parts values(2, 'phone','green');
insert into parts values(3, 'tv','pink');
insert into parts values(4, 'trimmer','black');
insert into parts values(5, 'speaker','blue');
insert into parts values(6, 'alexa','cyan');

insert into catalog values(1,3,10000);
insert into catalog values(1,2,20000);
insert into catalog values(2,1,40000);
insert into catalog values(2,4,70000);
insert into catalog values(3,4,90000);
insert into catalog values(3,5,20000);
insert into catalog values(2,6,20000);
insert into catalog values(1,6,30000);
insert into catalog values(3,2,60000);
insert into catalog values(2,6,6000);

select * from supplies;
select * from parts;
select * from catalog;

select s.sname, max(ca.price), min(ca.price) from catalog ca
join supplies s on ca.s_id=s.s_id
join parts p on ca.pid=p.pid
where ca.pid=6
group by s.sname;

select s.s_id, s.sname, p.pid, p.pname, ca.price, p.color from catalog ca
join supplies s on ca.s_id=s.s_id
join parts p on ca.pid=p.pid
where p.color='black';

select s.sname,p.pname,s.address from supplies s
join catalog ca on s.s_id=ca.s_id
join parts p on ca.pid=p.pid;

select s.s_id, s.sname, p.pid, p.pname, ca.price from catalog ca
join supplies s on ca.s_id=s.s_id
join parts p on ca.pid = p.pid
where ca.price=(select min(ca.price) from catalog cc where cc.pid=ca.pid);