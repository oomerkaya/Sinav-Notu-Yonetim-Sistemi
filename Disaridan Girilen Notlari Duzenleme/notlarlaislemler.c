#include <stdio.h>
void main()
{
	int not_sayisi;
	printf("!!UYARI: En Fazla 200 Adet Not Girebilirsiniz\n");
	printf("Toplam Girilecek Not Sayisi: ");
	scanf_s("%d", &not_sayisi);

	int notlar[200], i, A = 0, B = 0, C = 0, D = 0, F = 0, en_kucuk, en_buyuk, fark = 0, Toplam = 0, tek_indis_toplam = 0, cift_indis_toplam = 0;
	float N_O = 0, cift_indis_ortalama = 0, tek_indis_ortalama = 0;

	printf("\nGirilen not degerleri 0-100 arasinda olmalidir.\n\n");

	for (i = 0; i <= not_sayisi-1; i++)
	{
		printf("%d. Ogrencinin Notu: ", i + 1);
		scanf_s("%d", &notlar[i]);
	}
hesap:
	for (i = 0; i <= not_sayisi - 1; i++)
	{
		if (notlar[i] <= 100 && notlar[i] >= 91)
		{
			A = A + 1;
		}
		if (notlar[i] <= 89 && notlar[i] >= 76)
		{
			B = B + 1;

		}
		if (notlar[i] <= 74 && notlar[i] >= 50)
		{
			C = C + 1;
		}
		if (notlar[i] <= 49 && notlar[i] >= 45)
		{
			D = D + 1;
		}
		if (notlar[i] <= 44 && notlar[i] >= 0)
		{
			F = F + 1;
		}
		
		
		Toplam = Toplam + notlar[i];
	}
	en_buyuk = notlar[0];
		en_kucuk = notlar[0];
	for (i = 0; i <= not_sayisi - 1; i++)
	{
		if (notlar[i] < en_kucuk)
		{
			en_kucuk = notlar[i];
		}
		else if (notlar[i] > en_buyuk)
		{
			en_buyuk = notlar[i];
		}
	}

	for (i = 0; i <= not_sayisi - 1; i++)
	{
		if (i == 0 || i % 2 == 0)
		{
			cift_indis_toplam = cift_indis_toplam + notlar[i];
		}
		else
		{
			tek_indis_toplam = tek_indis_toplam + notlar[i];
		}
	}

	N_O = (float)Toplam / not_sayisi;
	cift_indis_ortalama = (float)cift_indis_toplam / not_sayisi;
	tek_indis_ortalama = (float)tek_indis_toplam / not_sayisi;
	fark = en_buyuk - en_kucuk;

	printf("\n");
	int secim, temp, eklenecek_puan;//temp gecici saklama alani
devam:
	printf("\n\n1. Butun Notlari Goruntule\n");
	printf("2. En Dusuk Not\n");
	printf("3. En Yuksek Not\n");
	printf("4. En Yuksek Not Ile En Dusuk Not Arasindaki Fark\n");
	printf("5. Not Ortalamasi\n");
	printf("6. Cift Indisli Notlarin Ortalamasi\n");
	printf("7. Tek Indisli Notlarin Ortalamasi\n");
	printf("8. Harf Notlarinin Dagilimi\n");
	printf("9. Notlari Kucukten Buyuge Dogru Sirala\n");
	printf("10. Notlari Buyukten Kucuge Dogru Sirala\n");
	printf("11. Notlara Puan Ekle\n");
	printf("12. Cikis\n\n");

	printf("Seciminiz: ");
	scanf_s("%d", &secim);
	printf("\n");

	if (secim == 12)
	{
		goto kapat;
	}

	switch (secim)
	{

	case 1:
	{
		for (int i = 0; i <= not_sayisi - 1; i++)
		{
			printf("%d. Ogrencinin Notu: %d\n", i + 1, notlar[i]);

		}
		goto devam;
		break;
	}
	case 2:
	{
		printf("En Dusuk Not: %d\n", en_kucuk);
		goto devam;
		break;
	}
	case 3:
	{
		printf("En Yuksek Not: %d\n", en_buyuk);
		goto devam;
		break;
	}
	case 4:
	{
		printf("En Yuksek Not Ile En Dusuk Not Arasindaki Fark: %d\n", fark);
		goto devam;
		break;
	}
	case 5:
	{
		printf("Not Ortalamasi: %.2f\n", N_O);
		if (N_O < 50)
		{
		
			printf("Not ortalamasi 50'den kucuk, butun notlara 5'er puan ekleyip tekrardan hesaplanmasini ister misiniz?\n");
			printf("1. Evet\n");
			printf("2. Hayir\n");
			printf("Secminiz: ");
			scanf_s("%d", &secim);
			
		}
		if (secim == 1)
		{
			for (i = 0; i <= not_sayisi - 1; i++)
			{
				notlar[i] = notlar[i] + 5;
				if (notlar[i] > 100)
				{
					notlar[i] = 100;
				}
			}
			A = 0;
			B = 0;
			C = 0;
			D = 0;
			F = 0;
			Toplam = 0;
			N_O = 0;
			cift_indis_ortalama = 0;
			tek_indis_ortalama = 0;
			tek_indis_toplam = 0;
			cift_indis_toplam = 0;
			fark = 0;
			en_buyuk = 0;
			en_kucuk = 0;
			goto hesap;
		}
		if (secim == 2)
		{
			goto devam;
		}
		goto devam;
		break;
	}
	case 6:
	{
		printf("Cift Indisli Notlarin Ortalamasi: %.2f", cift_indis_ortalama);
		goto devam;
		break;
	}
	case 7:
	{
		printf("Tek Indisli Notlarin Ortalamasi: %.2f", tek_indis_ortalama);
		goto devam;
		break;
	}
	case 8:
	{
		printf("Harf Notlarinin Dagilimi:\n\n");
		printf("A: %d\n", A);
		printf("B: %d\n", B);
		printf("C: %d\n", C);
		printf("D: %d\n", D);
		printf("F: %d\n\n", F);

		if (F >= 5)
		{
			printf("F harf notunun dagilimi 5'den buyuk esit, notlara 10'ar puan ekleyip tekrardan hesaplamak ister misiniz?\n");
			printf("1. Evet\n");
			printf("2. Hayir\n");
			printf("Seciminiz: ");
			scanf_s("%d", &secim);
		}
		if (secim == 1)
		{
			for (i = 0; i <= not_sayisi - 1; i++)
			{
				notlar[i] = notlar[i] + 10;
				if (notlar[i] > 100)
				{
					notlar[i] = 100;
				}
			}
			A = 0;
			B = 0;
			C = 0;
			D = 0;
			F = 0;
			Toplam = 0;
			N_O = 0;
			cift_indis_ortalama = 0;
			tek_indis_ortalama = 0;
			tek_indis_toplam = 0;
			cift_indis_toplam = 0;
			fark = 0;
			en_buyuk = 0;
			en_kucuk = 0;
			goto hesap;

		}
		if (secim == 2)
		{
			goto devam;
		}
		break;
	}
	case 9:
	{
		printf("Notlarin Kucukten Buyuge Dogru Siralanisi: ");
		for (i = 0; i <= not_sayisi - 1; i++)
		{

			for (int j = i + 1; j <= not_sayisi - 1; j++)
			{
				if (notlar[i] > notlar[j])
				{
					temp = notlar[i];
					notlar[i] = notlar[j];
					notlar[j] = temp;
				}
			}
			printf("%d ", notlar[i]);
		}
		goto devam;
		break;
	}
	case 10:
	{
		printf("Notlarin Buyukten Kucuge Dogru Siralanisi: ");
		for (i = 0; i <= not_sayisi - 1; i++)
		{

			for (int j = i + 1; j <= not_sayisi - 1; j++)
			{
				if (notlar[i] < notlar[j])
				{
					temp = notlar[i];
					notlar[i] = notlar[j];
					notlar[j] = temp;
				}
			}
			printf("%d ", notlar[i]);
		}
		goto devam;
		break;
	}
	case 11:
	{
		printf("Butun Notlara Kac Puan Eklemek Istiyorsunuz: ");
		scanf_s("%d", &eklenecek_puan);
		for (i = 0; i <= not_sayisi - 1; i++)
		{
			notlar[i] = notlar[i] + eklenecek_puan;
			if (notlar[i] > 100)
			{
				notlar[i] = 100;
			}
		}
		A = 0;
		B = 0;
		C = 0;
		D = 0;
		F = 0;
		Toplam = 0;
		N_O = 0;
		cift_indis_ortalama = 0;
		tek_indis_ortalama = 0;
		tek_indis_toplam = 0;
		cift_indis_toplam = 0;
		fark = 0;
		en_buyuk = 0;
		en_kucuk = 0;
		goto hesap;
		break;
	}
	default:
	{
		printf("***Hatali Secim***\n\n");
		goto devam;
	}

	}
kapat:

	getch();

}