#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rehber{
    char ad_soyad[80];
    double tel_no;
    struct rehber *gosterici;
};

struct rehber *ilk=NULL;
struct rehber *temp;
struct rehber *yeni_ilk=NULL;

int sayac=1;

int ekle_islemi()
{

    char ad_soyad[80];
    double tel_no;
    struct rehber *ata=(struct rehber*)malloc(sizeof(struct rehber));
    printf("Ad soyad gir= ");
    scanf("%s",&ata->ad_soyad);
    printf("Tel gir= ");
    scanf("%lf",&ata->tel_no);


    if(ilk==NULL)
    {
        ata->gosterici=ata;
        ilk=ata;
    }

    else
    {
        temp=ilk;
        while(temp->gosterici!=ilk)
        {
            printf("*-*-");
            sayac+=1;
            temp=temp->gosterici;

        }
        sayac+=1;
        temp->gosterici=ata;
        ata->gosterici=ilk;
        ilk=ata;
    }
}


int listele()
{
    temp=ilk;
    while(temp->gosterici!=ilk)
    {
        printf("%s->%lf\n",temp->ad_soyad,temp->tel_no);
        temp=temp->gosterici;
    }
    printf("%s->%lf\n",temp->ad_soyad,temp->tel_no);


}

int sirala()
{
    printf("Yetismedi :(");
}




int sil()
{
temp=ilk;
if(temp==NULL)
    {
        printf("Rehber bos\n");
    }

else
    {
        while(temp->gosterici!=ilk)
        {
            temp=temp->gosterici;
        }
        yeni_ilk=ilk->gosterici;
        free(ilk);
        temp->gosterici=yeni_ilk;
        ilk=yeni_ilk;
        printf("En bastaki silinmistir.\n");


}

}





int ara()
{
    temp=ilk;
    int tercih,i,aranacak_ad,dogruluk=0;
    double aranacak_no;
    printf("Tel no ile (1)-Isim ile (2)\n");
    scanf("%d",&tercih);
    if (tercih==1)
    {
        printf("Tel no giriniz \n");
        scanf("%lf",&aranacak_no);
        if (ilk==NULL)
        {
            printf("Rehber Bos");

        }
        else
        {
            while(temp->gosterici!=ilk)
            {

                if (aranacak_no==temp->tel_no)
                {
                    printf("%s->%lf\n",temp->ad_soyad,temp->tel_no);
                }
                temp=temp->gosterici;
            }



        }
    }
    else
    {
        printf("Isim giriniz \n");
        scanf("%s",&aranacak_ad);
        if (ilk==NULL)
        {
            printf("Rehber Bos");

        }
        else
        {
            while(temp->gosterici!=ilk)
            {

                if (strcmp(aranacak_ad,temp->ad_soyad)==0)
                {
                    printf("%s->%lf\n",temp->ad_soyad,temp->tel_no);
                }
                temp=temp->gosterici;

            }
        }
    }

}





int main()
{

    while(1==1)
    {


        int tercih;
        long int numara;
        char ad[80];
        printf("Ekleme(1)\nArama(2)\nListele(3)\nSoyada gore sirala(4)\nEn bastaki kisiyi sil(5)\nCikis(6)");
        scanf("%d",&tercih);

        switch(tercih)
        {
        case 1:
            ekle_islemi();
            break;
        case 2:
           ara();
            break;
        case 3:
            listele();
            break;
        case 4:
            sirala();
            break;
        case 5:
            sil();
            break;
        case 6:
            return 0;
            break;

        }
    }



}

