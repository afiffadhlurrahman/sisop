CREATE TABLE data_pasien(
    id_pasien char(7) PRIMARY KEY,
    no_ktp varchar(20),
    nama_pasien varchar(75),
    alamat_pasien varchar(100),
    jenis_kelamin char(1),
    gol_darah varchar(2),
    tgl_lahir date,
    telp varchar(14)
);

CREATE TABLE dokter(
    nid_d char(4) PRIMARY KEY,
    kode_poli char(3),
    nama varchar(70),
    jenis_kelamin char(1),
    alamat_dokter varchar(150),
    telp_dokter varchar(14),
    tgl_mulai_praktek date
);

CREATE TABLE pemeriksaan(
    id_periksa char(4) PRIMARY KEY, 
    nid char(4),
    id_pasien_p char(7),
    tgl_periksa date,
    diagnosa varchar(100),
    biaya numeric,
    catatan varchar(80)
);

alter table pemeriksaan 
    add foreign key (nid) references dokter(nid_d);

alter table pemeriksaan 
    add foreign key (id_pasien_p) references data_pasien(id_pasien);


insert into  data_pasien values ('PS00001','3506031602880001','Izdihar Farahdina','Perumdos ITS Blok IF No.13','P','O','1994/07/27','081234777888');
insert into  data_pasien values('PS00002','3606031002890003','Biandina Meidyani','Perumdos ITS Blok BM No.4','P','B','1994/05/04','085700885577');
insert into  data_pasien values('PS00003','3101092000060004','Aranda Rizki Soedjono','Perumdos ITS Blok ARS-7','L','O','1994/02/24','081654321000');
insert into  data_pasien values('PS00004','3171092910770002','Ratih Ayu Indaswari','Wisma Nyempil W-8','P','O','1994/09/19','089845680800');
insert into  data_pasien values('PS00005','3224071910850005','Hafidh Azmi','Keputih Gang Buntu UC-100','L','AB','1994/09/07','085987654321');


insert into dokter values('D001','P04','dr.Iskandar','L','Jl.Meranti 37 Sidoarjo','081234500500','2001/03/22');
insert into dokter values('D002','P04','dr.Mumi Sasmita','P','Jl.Rambutan 22 Surabaya','081233567567','2007/01/10');
insert into dokter values('D003','P01','dr.Angga Kusuma','L','Jl.Diponegoro 23 Sidoarjo','081246555789','2008/04/21');
insert into dokter values('D004','P02','dr.Charles Sungkono','L','Jl.Majapahit 89 Surabaya','08564682277','2010/06/14');
insert into dokter values('D005','P03','dr.Melani Andini','P','Jl.Jalak Gg.III/15 Pasuruan','089845477000','2011/03/02');
insert into dokter values('D006','P04','dr.Sri Wedari','P','Jl.Kenjeran 200 Surabaya','081331454000','2010/06/22');


insert into pemeriksaan values('PR01','D003','PS00001','2014/11/05','Demam Berdarah Dengue',150000,'PembayaranKredit');
insert into pemeriksaan values('PR02','D006','PS00002','2014/11/08','Sakit Gigi',85000,'PembayaranTunai');
insert into pemeriksaan values('PR03','D003','PS00003','2014/11/10','Maag Kronis',250000,'PembayaranKredit');
insert into pemeriksaan values('PR04','D004','PS00004','2014/11/10','Infeksi Mata',50000,'PembayaranTunai');
insert into pemeriksaan values('PR05','D005','PS00005','2014/11/29','Influenza',30000,'PembayaranTunai');
insert into pemeriksaan values('PR06','D005','PS00002','2014/12/30','Influenza',30000,'PembayaranTunai');
insert into pemeriksaan values('PR07','D001','PS00001','2014/12/30','Radang Gusi',35000,'PembayaranTunai');


SELECT dp.nama_pasien as nama_pasien
FROM data_pasien dp,pemeriksaan p
WHERE dp.id_pasien=p.id_pasien_p AND p.diagnosa LIKE  '%Influenza%'
UNION
SELECT dp.nama_pasien as nama_pasien
FROM data_pasien dp,pemeriksaan p
WHERE dp.id_pasien=p.id_pasien_p AND p.diagnosa LIKE  '%Sakit Gigi%'


SELECT dp.nama_pasien as nama_pasien,p.tgl_periksa,p.diagnosa
FROM data_pasien dp,pemeriksaan p
WHERE dp.id_pasien=p.id_pasien_p AND p.diagnosa LIKE  '%Influenza%' AND dp.id_pasien IN
(SELECT dp.id_pasien
FROM data_pasien dp,pemeriksaan p
WHERE dp.id_pasien=p.id_pasien_p AND p.tgl_periksa BETWEEN '2014/12/01' AND '2014/12/31')


SELECT dp.nama_pasien as nama_pasien,p.tgl_periksa,p.diagnosa
FROM data_pasien dp,pemeriksaan p, dokter d
WHERE dp.id_pasien=p.id_pasien_p AND d.nid_d = p.nid AND d.nama LIKE  '%dr.Angga%' AND dp.id_pasien NOT IN
(SELECT dp.id_pasien
FROM data_pasien dp,pemeriksaan p
WHERE dp.id_pasien=p.id_pasien_p AND p.diagnosa LIKE  '%Radang Gusi%' )

SELECT d.nama,p.biaya
FROM pemeriksaan p, dokter d
WHERE d.nid_d = p.nid
GROUP BY d.nama

SELECT p.biaya,p.catatan
FROM pemeriksaan p
WHERE p.catatan LIKE "%Kredit%"

SELECT min(p.biaya) as minimum_check_fees,max(p.biaya) as maximum_check_fees
FROM pemeriksaan p
WHERE p.tgl_periksa BETWEEN '2014/11/01' AND '2014/11/31'
UNION
SELECT min(p.biaya) as minimum_check_fees,max(p.biaya) as maximum_check_fees
FROM pemeriksaan p
WHERE p.tgl_periksa BETWEEN '2014/12/01' AND '2014/12/31'

