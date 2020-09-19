#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
void all(double*, double);
void substractFT(double*, double);
void substractVAT(double*);
void substractservice(double*);




int main()
{
	double bill,ft{};
	int month;
	double a[3] = {-0.1160,-0.1160,-0.1243};
	printf("PS. service in this year is 38.22 BAHT\n\n");
	printf("Enter your bill : ");
	scanf_s("%lf", &bill);
	printf("Enter your number of months that you want to calculate ex. January = 1 , September = 9 : ");
	scanf_s("%d", &month);
	if (month>=1 && month<=4)
	{
		ft = a[0];
	}
	else if (month >= 5 && month <= 8)
	{
		ft = a[1];
	}
	else if (month >= 9 && month <= 12)
	{
		ft = a[2];
	}

	if (bill>0)
	{
		all(&bill, ft);
		printf("\nYour electricity bill that not include VAT and FT = %.2f BAHT\n", bill);
		printf("Your FT = %.4f BAHT\n", ft);
	}
	else if(bill == 0 )
	{
		substractservice(&bill);
		printf("\nYour electricity bill that not include VAT and FT = %.2f BAHT\n", -bill);
		printf("Your FT = %.4f BAHT\n", ft);
		printf("Your service  = %.2f BAHT\n", 38.22);
	}
	else
	{
		printf("\nError");
	}

	
	return 0;
}

void all(double* bill, double ft)
{
	substractservice(bill);
	substractVAT(bill);
	substractFT(bill, ft);
	
}

void substractFT(double* bill, double ft)
{
	*bill += *bill * ft;
}

void substractVAT(double* bill)
{
	*bill = *bill * 0.93;
}

void substractservice(double* bill)
{
	*bill -= 38.22;
}

