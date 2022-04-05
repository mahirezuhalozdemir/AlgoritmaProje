# AlgoritmaProje
Kullanıcıdan alınan metnin dilini belirleme:
Algoritmalar ve programlama projemizin konusu “C    Programlama” dilinde ve bu programlama diline uygun bir IDE ortamında kullanıcı tarafından girilen 
bir metnin İngilizce dilinde mi yoksa Almanca dilinde mi yazıldığını otomatik olarak belirlemektir.

Bu projeyi hazırlamadaki amacımız ise I. Yarıyıl dönemi konularından ;
1. Fonksiyon yapılarının öğrenilmesi ve uygulanması,
2. Döngülerin öğrenilmesi ve uygulanması,
3. Char dizileri üzerinde çeşitli işlemlerin gerçekleştiriminin öğrenilmesi ve öğrenilen bu bilgilerin uygulanmasıdır.

Projeyi hazırlarken takip ettiğimiz adımlar sırasıyla şöyle belirtilmiştir :
1.Kullanıcıdan bir metin alınacaktır. Kullanıcıdan alınan metinde yer alan yabancı karakterler temizlenmelidir.
(A-Z karakterleri ve boşluk karakterleri dışındaki karakterler boşluk karakteri ile değiştirilmelidir.)
2.Daha sonra yabancı karakterlerden arındırılan bu metin “strings” diye bir diziye atılacak ve bu dizi üzerinden for ile dolaşıp if koşulu ile bigram ve 
trigram kelimelerden kaç adet geçtiği bulunacaktır. (Frekans matris hesaplaması)
3.İkinci adımdaki frekans hesaplaması yapıldıktan sonra elde ettiğimiz frekans matrisi ile bize daha önceden verilmiş İngilizce ve Almanca dillerinin 
frekans değerlerinin bulunduğu matris karşılaştırılacaktır. 
4.“Öklid Uzaklığı“ kullanılarak taslak kodda verilmiş frekans matrisi ile bizim elde ettiğimiz frekans matrisleri arasında uzaklık hesabı yapılacaktır.
5.Hangi dilde daha küçük uzaklık değeri elde edildiyse, metnin yazıldığı dil olarak o dil tahmin edilecektir.

Yukarıdaki adımları gerçekleştirmek için kullanılabilecek fonksiyonlar aşağıdaki tabloda verilmiştir:



Amaç:	                              Kullanılacak fonksiyon:
Metni temizleme	                      void filter_str(char str[])
Bigram hesaplama	              void calculate_frequencies_bi(char str[])
Trigram hesaplama	              Void calculate_frequencies_tri(char str[])
Uzaklık hesaplaması	              Void calculate_distances(const float distances[2][20]
Kullanılan dilin tahmin edilmesi      Void detect_lang()
