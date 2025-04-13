#include <stdio.h>

int ocjene[10];
int brojStudenata = 0;

    void unosOcjena()
{
    if (brojStudenata >= 10)
    {
        printf("Unijeli ste maksimalan broj studenata!\n");
        return;
    }
    printf("Koliko studenata zelite unijeti? (max %d): ", 10 - brojStudenata);
    int n;
    scanf("%d", &n);
    if (n <= 0 || n > 10 - brojStudenata)
    {
        printf("Pogresan unos! \n");
        return;
    }
    printf("Unesite ocjene (5-10): \n");
    for (int i = 0; i < n; i++)
    {
        int ocjena;
        do
        {
            printf("Ocjena studenta %d: ", i + 1);
            scanf("%d", &ocjena);
            if (ocjena < 5 || ocjena > 10)
                printf("Ocjena mora biti 5-10!\n");
        } while (ocjena < 5 || ocjena > 10);
        ocjene[brojStudenata++] = ocjena;
    }
}
    
    void prosjek()
    {
        if (brojStudenata == 0)
        {
            printf("Nema unesenih studenata.\n");
            return;
        }
        
        float suma = 0;
        for (int i= 0; i < brojStudenata; i++)
        suma += ocjene[i];
        printf("Prosjek ocjena: %.2f\n", suma / brojStudenata);
    }

    void najbolja_najlosija()
    {
        if (brojStudenata == 0)
        {
            printf("Nema unesenih studenata!\n");
            return;
        }
        int najbolja= ocjene[0] , najlosija= ocjene[0];
        for (int i = 1; i < brojStudenata; i++)
        {
            if (ocjene[i] > najbolja)
            najbolja = ocjene[i];
            if (ocjene[i] < najlosija)
            najlosija = ocjene[i];  
        }

        printf ("Najbolja ocjena: %d\n ", najbolja);
        printf ("Najlosija ocjena: %d\n ", najlosija);
        
    }

    void meni()
    {
        printf("\n********************************\n");
        printf("       Sistem ocjenjivanja\n");
        printf("********************************\n");
        printf("1. Unos ocjena studenata \n");
        printf("2. Prikaz prosjecne ocjene\n");
        printf("3. Prikaz najbolje i najlosije ocjene\n");
        printf("0. Izlaz\n");
        printf("********************************\n");
        printf("Izbor: ");
    }

    int main()
    {
        int izbor;
        do
        {
            meni();
            while (scanf("%d", &izbor) !=1 || izbor<0 || izbor > 3) {
                while (getchar() != '\n');
            printf("Pogresan unos! Unesite broj izmedju 0 i 3: ");
            
                
            }

            switch (izbor)
            {
            case 1:
                unosOcjena();
                break;
            case 2:
                prosjek();
                break;
            case 3:
                najbolja_najlosija();
                break;
            case 0:
                printf("Kraj programa. \n");
                break;
            default:
                printf("Pogresan izbor! \n");
            }
            
        } while (izbor!= 0);
        return 0;
        
    }