#include <iostream>

int main()
{
	int a_res = 0;
	int b_res = 0;
	int c_res = 0;

	for(int a = 0; a < 1000; a++)
	{
		for(int b = a; b < 1000; b++)
		{
			for(int c = b; c < 1000; c++)
			{
				int sum = a + b + c;
				if (sum == 1000)
				{	
					int left = a*a + b*b;
					int right = c*c;
					if(left == right)
					{
						a_res = a;
						b_res = b;
						c_res = c;
					}
				}

				if (sum > 1000)
					break;
			}
		}
	}
  std::cout << "Result is " << a_res << " " << b_res << " " << c_res << std::endl;
}

