#include <stdio.h>

int main (void)
{
	while (1)
	{
		char str[30];
		scanf ("%s", str);
		if (str[0] == '*')
		  break;
		int i, flag = 0;
		long long int num = 1;
		if (str[0] == 'N')
		  printf ("-1\n");
		else
		{
			for (i = 1; str[i]; i++)
			{
				if (str[i] == 'Y')
				{
					switch (i+1)
					{
					  case 2: case 3: case 5: case 7: case 11: case 13: case 17: case 19:
					    num *= (i+1);
					    break;
					  case 4: if (str[1] == 'N')
						    flag = 1;
						  else
						  {
						      if (num % 4)
							num *= 2;
						  }
						  break;
					  case 6: if (str[1] == 'N' || str[2] == 'N')
						    flag = 1;
						  break;
					  case 8: if (str[1] == 'N' || str[3] == 'N')
						    flag = 1;
						  else
						  {
						    if (num % 8)
						      num *= 2;
						  }
						  break;
					  case 9: if (str[2] == 'N')
						    flag = 1;
						  else
						  {
						      if (num % 9)
							num *= 3;
						  }
						  break;
					  case 10: if (str[1] == 'N' || str[4] == 'N')
						     flag = 1;
						   break;
					  case 12: if (str[1] == 'N' || str[2] == 'N' || str[3] == 'N' || str[5] == 'N')
						     flag = 1;
						   break;
					  case 14: if (str[1] == 'N' || str[6] == 'N')
						      flag = 1;
						   break;
					  case 15: if (str[2] == 'N' || str[4] == 'N')
						      flag = 1;
						   break;
					  case 16: if (str[1] == 'N' || str[3] == 'N' || str[7] == 'N')
						    flag = 1;
						   else
						   {
						      if (num % 16)
							num *= 2;
						   }
						   break;
					  case 18: if (str[1] == 'N' || str[2] == 'N' || str[5] == 'N' || str[8] == 'N')
						     flag = 1;
						   break;
					  case 20: if (str[1] == 'N' || str[3] == 'N' || str[4] == 'N' || str[9] == 'N')
						     flag = 1;
						   break;
					}
				}
				else
				{
					switch (i+1)
					{
					  case 4: if (str[1] == 'Y' && (num % 4 == 0))
						    flag = 1;
						  break;
					  case 6: if (str[1] == 'Y' && str[2] == 'Y')
						    flag = 1;
						  break;
					  case 8: if (str[1] == 'Y' && str[3] == 'Y' && (num % 8 == 0))
						    flag = 1;
						  break;
					  case 9: if (str[2] == 'Y' && (num % 9 == 0))
						    flag = 1;
						  break;
					  case 10: if (str[1] == 'Y' && str[4] == 'Y')
						     flag = 1;
						   break;
					  case 12: if (str[1] == 'Y' && str[2] == 'Y' && str[3] == 'Y' && str[5] == 'Y')
						     flag = 1;
						   break;
					  case 14: if (str[1] == 'Y' && str[6] == 'Y')
						      flag = 1;
						   break;
					  case 15: if (str[2] == 'Y' && str[4] == 'Y')
						      flag = 1;
						   break;
					  case 16: if (str[1] == 'Y' && str[3] == 'Y' && str[7] == 'Y' && (num % 16 == 0))
						    flag = 1;
						   break;
					  case 18: if (str[1] == 'Y' && str[2] == 'Y' && str[5] == 'Y' && str[8] == 'Y')
						     flag = 1;
						   break;
					  case 20: if (str[1] == 'Y' && str[3] == 'Y' && str[4] == 'Y' && str[9] == 'Y')
						     flag = 1;
						   break;
					}
				}
				if (flag)
				  break;
			}
			if (flag)
			  printf ("-1\n");
			else
			  printf ("%lld\n", num);
		}
	}
	return 0;
}