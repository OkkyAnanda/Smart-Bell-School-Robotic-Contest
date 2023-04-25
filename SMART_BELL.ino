fandi12#include <DS3231.h>
DS3231  rtc(SDA, SCL);

Time waktu;
 int RelayBell=12;
void setup()
{
  Serial.begin(9600);  
  rtc.begin();
  pinMode(RelayBell,OUTPUT);
  digitalWrite(RelayBell,LOW);
  Serial.begin(9600);  
  rtc.begin();
  // Seting waktu saat pertama kali RTC digunakan
// rtc.setDOW(MINGGU);   // Set Hari
 //rtc.setTime(14,56,00);    // Set waktu JJ:MM:DD (24hr format)
 //rtc.setDate(6,8,2017);     // Set tanggal 20 September 2016

} 
 
void loop()
{
  if (Serial.available()>0){
  char data=Serial.read();
  if (data==1){
  NYALA(); // alarm nyala
  }else if(data==2){
  MATI(); // alarm mati
}
  }
  //tampilkan hari
 // Serial.println(rtc.getDOWStr(FORMAT_LONG));
 
  //ambil waktu
  waktu = rtc.getTime();
  char* dataHari=rtc.getDOWStr(FORMAT_LONG);
  int dataJam = waktu.hour;     
  int dataMenit = waktu.min;
  int dataDetik = waktu.sec;
  //Menampilkan Waktu di Serial monitor
 /*
  Serial.print(dataHari);
  Serial.print(',');
  Serial.print(dataJam);
  Serial.print(':');
  Serial.print(dataMenit);
  Serial.print(':');
  Serial.println(dataDetik);
  delay(1000);
 // */
 
//Bel HARI SENIN
if(dataHari=="Senin" && dataJam==6 && dataMenit==50 && dataDetik==0) { // Peringatan Upacara
  BellMasukDanBellIstirahat();
  Serial.println(13);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==7 && dataMenit==0 && dataDetik==0) { // Upacara
  BellMasukDanBellIstirahat();
  Serial.println(14);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==8 && dataMenit==0 && dataDetik==0) { //Bell Mapel 1
  BellPergantianDanMulaiMapel();
  Serial.println(1);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==9 && dataMenit==20 && dataDetik==0) { //Bell Mapel 2
  BellPergantianDanMulaiMapel();
  Serial.println(2);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==10 && dataMenit==0 && dataDetik==0) { //Bell Istirahat 1
  BellMasukDanBellIstirahat();
  Serial.println(6);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==10 && dataMenit==35 && dataDetik==0) { //Bell Masuk Istirahat 1
  BellPergantianDanMulaiMapel();
  Serial.println(7);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==10 && dataMenit==40 && dataDetik==0) { //Bell Mapel 2
  BellPergantianDanMulaiMapel();
  Serial.println(2);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==11 && dataMenit==20 && dataDetik==0) { //Bell Mapel 3
  BellPergantianDanMulaiMapel();
  Serial.println(3);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==12 && dataMenit==40 && dataDetik==0) { //Bell Istirahat 2
  BellMasukDanBellIstirahat();
  Serial.println(8);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==13 && dataMenit==15 && dataDetik==0) { //Bell Masuk Istirahat 2
  BellPergantianDanMulaiMapel();
  Serial.println(9);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==13 && dataMenit==20 && dataDetik==0) { //Bell Mapel 4
  BellPergantianDanMulaiMapel();
  Serial.println(4);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==14 && dataMenit==40 && dataDetik==0) { //Bell Mapel 5
  BellPergantianDanMulaiMapel();
  Serial.println(5);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==16 && dataMenit==0 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(15);
  delay(1000);
  Serial.println("");
}

// Bell Hari Selasa
if(dataHari=="Selasa" && dataJam==6 && dataMenit==50 && dataDetik==0) { // Peringatan Apel
  BellMasukDanBellIstirahat();
  Serial.println(11);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==7 && dataMenit==0 && dataDetik==0) { //Bell Apel
  BellPergantianDanMulaiMapel();
  Serial.println(12);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==7 && dataMenit==20 && dataDetik==0) { //Bell Mapel 1
  BellPergantianDanMulaiMapel();
  Serial.println(1);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==8 && dataMenit==40 && dataDetik==0) { //Bell Mapel 2
  BellPergantianDanMulaiMapel();
  Serial.println(2);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==10 && dataMenit==0 && dataDetik==0) { //Bell Istirahat 1
  BellMasukDanBellIstirahat();
  Serial.println(6);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==10 && dataMenit==35 && dataDetik==0) { //Bell Masuk Istirahat 1
  BellPergantianDanMulaiMapel();
  Serial.println(7);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==10 && dataMenit==40 && dataDetik==0) { //Bell Mapel 3
  BellPergantianDanMulaiMapel();
  Serial.println(3);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==12 && dataMenit==0 && dataDetik==0) { //Bell Mapel 4
  BellPergantianDanMulaiMapel();
  Serial.println(4);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==12 && dataMenit==40 && dataDetik==0) { //Bell Istirahat 2
  BellMasukDanBellIstirahat();
  Serial.println(8);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==13 && dataMenit==19 && dataDetik==0) { //Bell Masuk Istirahat 2
  BellPergantianDanMulaiMapel();
  Serial.println(9);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==13 && dataMenit==20 && dataDetik==0) { //Bell Mapel 4
  BellPergantianDanMulaiMapel();
  Serial.println(4);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==14 && dataMenit==0 && dataDetik==0) { //Bell Mapel 5
  BellPergantianDanMulaiMapel();
  Serial.println(5);
  delay(1000);
  Serial.println("");
}if(dataHari=="Selasa" && dataJam==15 && dataMenit==20 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(15);
  delay(1000);
  Serial.println("");
}

// Hari Rabu
if(dataHari=="Rabu" && dataJam==6 && dataMenit==50 && dataDetik==0) { // Peringatan Apel
  BellMasukDanBellIstirahat();
  Serial.println(11);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==7 && dataMenit==0 && dataDetik==0) { //Bell Apel
  BellPergantianDanMulaiMapel();
  Serial.println(12);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==7 && dataMenit==20 && dataDetik==0) { //Bell Mapel 1
  BellPergantianDanMulaiMapel();
  Serial.println(1);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==8 && dataMenit==40 && dataDetik==0) { //Bell Mapel 2
  BellPergantianDanMulaiMapel();
  Serial.println(2);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==10 && dataMenit==0 && dataDetik==0) { //Bell Istirahat 1
  BellMasukDanBellIstirahat();
  Serial.println(6);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==10 && dataMenit==35 && dataDetik==0) { //Bell Masuk Istirahat 1
  BellPergantianDanMulaiMapel();
  Serial.println(7);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==10 && dataMenit==40 && dataDetik==0) { //Bell Mapel 3
  BellPergantianDanMulaiMapel();
  Serial.println(3);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==12 && dataMenit==0 && dataDetik==0) { //Bell Mapel 4
  BellPergantianDanMulaiMapel();
  Serial.println(4);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==12 && dataMenit==40 && dataDetik==0) { //Bell Istirahat 2
  BellMasukDanBellIstirahat();
  Serial.println(8);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==13 && dataMenit==19 && dataDetik==0) { //Bell Masuk Istirahat 2
  BellPergantianDanMulaiMapel();
  Serial.println(9);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==13 && dataMenit==20 && dataDetik==0) { //Bell Mapel 4
  BellPergantianDanMulaiMapel();
  Serial.println(4);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==14 && dataMenit==0 && dataDetik==0) { //Bell Mapel 5
  BellPergantianDanMulaiMapel();
  Serial.println(5);
  delay(1000);
  Serial.println("");
}if(dataHari=="Rabu" && dataJam==15 && dataMenit==20 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(15);
  delay(1000);
  Serial.println("");
}


// Bell Hari Kamis
if(dataHari=="Kamis" && dataJam==6 && dataMenit==50 && dataDetik==0) { // Peringatan Apel
  BellMasukDanBellIstirahat();
  Serial.println(11);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==7 && dataMenit==0 && dataDetik==0) { //Bell Senam
  BellPergantianDanMulaiMapel();
  Serial.println(12);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis"  && dataJam==8 && dataMenit==0 && dataDetik==0) { // Bell Mapel 1
  BellMasukDanBellIstirahat();
  Serial.println(1);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==9 && dataMenit==20 && dataDetik==0) { //Bell Mapel 2
  BellPergantianDanMulaiMapel();
  Serial.println(2);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==10 && dataMenit==0 && dataDetik==0) { //Bell Istirahat 1
  BellPergantianDanMulaiMapel();
  Serial.println(6);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==10 && dataMenit==39 && dataDetik==0) { //Bell Masuk Istirahat 1
  BellMasukDanBellIstirahat();
  Serial.println(7);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==10 && dataMenit==40 && dataDetik==0) { //Bell Mapel 2
  BellPergantianDanMulaiMapel();
  Serial.println(2);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==11 && dataMenit==20 && dataDetik==0) { //Bell Mapel 3
  BellPergantianDanMulaiMapel();
  Serial.println(3);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==12 && dataMenit==40 && dataDetik==0) { //Bell Istirahat 2
  BellPergantianDanMulaiMapel();
  Serial.println(8);
  delay(1000);
  Serial.println("");
}if(dataHari  =="Kamis" && dataJam==13 && dataMenit==19 && dataDetik==0) { //Bell Masuk Istirahat 2
  BellMasukDanBellIstirahat();
  Serial.println(9);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==13 && dataMenit==20 && dataDetik==0) { //Bell Mapel 4
  BellPergantianDanMulaiMapel();
  Serial.println(4);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==14 && dataMenit==40 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(15);
  delay(1000);
  Serial.println("");
}

// Bell Hari Jumat
if(dataHari=="Jumat" && dataJam==6 && dataMenit==50 && dataDetik==0) { // Peringatan Apel
  BellMasukDanBellIstirahat();
  Serial.println(11);
  delay(1000);
  Serial.println("");
}if(dataHari=="Jumat" && dataJam==7 && dataMenit==0 && dataDetik==0) { //Bell Apel
  BellPergantianDanMulaiMapel();
  Serial.println(12);
  delay(1000);
  Serial.println("");
}if(dataHari=="Jumat"  && dataJam==7 && dataMenit==20 && dataDetik==0) { //Bell Mapel 1
  BellMasukDanBellIstirahat();
  Serial.println(1);
  delay(1000);
  Serial.println("");
}if(dataHari=="Jumat" && dataJam==8 && dataMenit==30 && dataDetik==0) { //Bell Mapel 2
  BellPergantianDanMulaiMapel();
  Serial.println(2);
  delay(1000);
  Serial.println("");
}if(dataHari=="Jumat" && dataJam==9 && dataMenit==40 && dataDetik==0) { //Bell Istirahat 1
  BellPergantianDanMulaiMapel();
  Serial.println(6);
  delay(1000);
  Serial.println("");
}if(dataHari=="Jumat" && dataJam==10 && dataMenit==19 && dataDetik==0) { //Bell Masuk Istirahat 1
  BellMasukDanBellIstirahat();
  Serial.println(7);
  delay(1000);
  Serial.println("");
}if(dataHari=="Jumat" && dataJam==10 && dataMenit==20 && dataDetik==0) { //Bell Mapel 3
  BellPergantianDanMulaiMapel();
  Serial.println(3);
  delay(1000);
  Serial.println("");
}if(dataHari=="Jumat" && dataJam==11 && dataMenit==30 && dataDetik==0) { //Bell Pulang
  BellPergantianDanMulaiMapel();
  Serial.println(16);
  delay(1000);
  Serial.println("");


// codding uji coba
}if(dataHari=="Senin" && dataJam==15 && dataMenit==16 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(13);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==15 && dataMenit==17 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(14);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==15 && dataMenit==18 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(1);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==15 && dataMenit==19 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(2);
  delay(1000);
  Serial.println("");
}if(dataHari=="Senin" && dataJam==15 && dataMenit==48 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(3);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==13 && dataMenit==26 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(6);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==13 && dataMenit==18 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(7);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==13 && dataMenit==19 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(4);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==13 && dataMenit==20 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(5);
  delay(1000);
  Serial.println("");
}if(dataHari=="Kamis" && dataJam==13 && dataMenit==21 && dataDetik==0) { //Bell Pulang
  BellPulang();
  Serial.println(15);
  delay(1000);
  Serial.println("");
}else {
  digitalWrite(RelayBell,LOW);
}

}

void BellMasukDanBellIstirahat(){
  digitalWrite(RelayBell,HIGH);
  delay(1000);
  digitalWrite(RelayBell,LOW);
  delay(500);
  digitalWrite(RelayBell,HIGH);
  delay(1000);
  digitalWrite(RelayBell,LOW);
  delay(500);
}

void BellPergantianDanMulaiMapel(){
  digitalWrite(RelayBell,HIGH);
  delay(1000);
  digitalWrite(RelayBell,LOW);
  delay(500);
}
void BellPulang(){
  digitalWrite(RelayBell,HIGH);
  delay(1000);
  digitalWrite(RelayBell,LOW);
  delay(500);
  digitalWrite(RelayBell,HIGH);
  delay(1000);
  digitalWrite(RelayBell,LOW);
  delay(500);
  digitalWrite(RelayBell,HIGH);
  delay(1000);
  digitalWrite(RelayBell,LOW);
  delay(500);
  
}

void NYALA(){
digitalWrite (RelayBell,HIGH);
}
void MATI(){
digitalWrite (RelayBell,LOW);
}
