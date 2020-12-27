#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>


const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};

const char languages[2][8]={"english", "german"};

//Ýngilizce dilinin frekans deðerleri
 const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
 //Almanca dilinin frekans deðerleri
 const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];
float distances [2]={0,0};


void filter_str(char str[])
{
    int i=0;
    for(;i<strlen(str);i++)
    {
        if(str[i]==' ')
            continue;
        else if(str[i]<='z' && str[i]>='a')
            continue;
        else
            str[i]=' ';
    }
    puts(str);
}
//ustteki fonksiyon alinan metindeki yabanci karakterleri temizler.

void small_filter(char text[])
{
    int m=0;
    for(;m<strlen(text);m++)
    {
        text[m]=tolower(text[m]);
    }
}
//ustteki fonksiyon alinan metindeki buyuk harfleri kucultur.


void calculate_frequencies_bi(char str[])
{
    for(int j=0;j<10;j++)
    {
        for(int m=0;m<strlen(str)-1;m++)
        {
            if (strcmp(matrix_bigram_strings[j][3],str[m]&&str[m+1]) == 0)
                calculated_frequencies[j]+=1;
        }

        printf("%s - %f\n", matrix_bigram_strings[j][3], calculated_frequencies[j]);



    }

}
//ustteki fonksiyonda alinan metindeki bigramlarin oranini bulmaya calistik.

void calculate_frequencies_tri(char str[])
{

    for (int j = 0; j < 10; j++)
    {
        for(int e=0;e<strlen(str)-1;e++)
        {
            if (strcmp(matrix_trigram_strings[j][4],str[e]&&str[e+1]) == 0)
                calculated_frequencies[10+j]+=1;

        }
        printf("%s - %f \n", matrix_trigram_strings[j][4], calculated_frequencies[10+j]);
    }



}


//ustteki fonksiyonla alinan metindeki trgramlari hesaplamaya calistik.

void calculate_distances()
{
    float frekans,frekans2;
    float distances [2]={0,0};
    float frequency_eng[20];
    float frequency_germ[20];
    calculated_frequencies[20];
    for(int i=0;i<20;i++)
    {
       float a=sqrt(pow(calculated_frequencies[i],2)+ pow(frequency_eng[i],2));
       frekans+=a;
    }
    distances[0]=frekans;
    printf("frequency difference in english:  %f",distances[0]);
    for(int i=0;i<20;i++)
    {
        float b=sqrt(pow(calculated_frequencies[i],2)+ pow(frequency_germ[i],2));
        frekans2+=b;
    }
    distances[1]=frekans2;
    printf("frequency difference in german:  %f",distances[1]);
}
//ustteki fonksiyonla,hesaplanan bigram ve trigramlara gore iki dil arasindaki frekans farkini bulmaya calistim.

void detect_lang()
{
    float distances [2];
    if(distances[0]>distances[1])
        printf("almanca dilinde yazilmistir.");
    else
        printf("ingilizce dilinde yazilmistir.");
}
//hesapladigim frekans oranlarına gore metnin hangi dilde yazıldıgına karar verdim.

int main()
{
    char metin[200];
    printf("metin girin:  ");
    gets(metin);
    small_filter(metin);
    filter_str(metin);
    calculate_frequencies_bi(metin);
    calculate_frequencies_tri(metin);
    calculate_distances();
    detect_lang();






    return 0;
}
