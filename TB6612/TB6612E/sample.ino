/*
   ROBQT Örnek Kod
   TB6612E Örnek Uygulaması
   by DISQET Yazılım Tasarım ve Otomasyon Teknolojileri
   created by: Ömer Necmi KAYHAN
*/

#define PWMA 3
#define AIN1 4

#define PWMB 6
#define BIN1 7

void sur(int motorADegeri, int motorBDegeri) {

    motorADegeri = constrain(motorADegeri, -255, 255);  //Değer Kontrolü değerler -255 ile 255 arasında değilse bu aralığa uyarlanır
    motorBDegeri = constrain(motorBDegeri, -255, 255);  //Değer Kontrolü değerler -255 ile 255 arasında değilse bu aralığa uyarlanır

    digitalWrite(AIN1, motorADegeri > 0);               //A motoru için verilen değer sıfırdan büyükse sürünün birinci girişi HIGH yapılır
    analogWrite(PWMA, abs(motorADegeri));               //A motoru için verilen değerin mutlağı alınarak sürücün PWMA girişine yazılır

    digitalWrite(BIN1, motorBDegeri > 0);               //B motoru için verilen değer sıfırdan büyükse sürünün birinci girişi HIGH yapılır
    analogWrite(PWMB, abs(motorBDegeri));               //B motoru için verilen değerin mutlağı alınarak sürücün PWMB girişine yazılır

}

void setup() {

    //ÇIKIŞLARI AYARLAMA
    pinMode(PWMA, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(BIN1, OUTPUT);

}

void loop() {

    sur(100, 100);      //İKİ MOTOR 100 HIZINDA İLERİ
    delay(2000);        //2 SANİYE BEKLE

    sur(-100, -100);    //İKİ MOTOR 100 HIZINDA GERİ
    delay(2000);        //2 SANİYE BEKLE

    sur(100, -100);     //SOL MOTOR 100 HIZINDA İLERİ, SAĞ MOTOR 100 HIZINDA GERİ
    delay(2000);        //2 SANİYE BEKLE

    sur(-100, 100);     //SAĞ MOTOR 100 HIZINDA İLERİ, SOL MOTOR 100 HIZINDA GERİ
    delay(2000);        //2 SANİYE BEKLE

    sur(0, 0);          //İKİ MOTORU DA DURDUR
    delay(2000);        //2 SANİYE BEKLE

}