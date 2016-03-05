#include <vector>
#include <iostream>

template <class T, int size> class SortedVector
{
	private:
		int noElements;	

	public:
		T vec[size];

		SortedVector()
		{
			noElements = 0;
		}
		
		~SortedVector()
		{
		}

		bool add(const T& v)
		{
			if(noElements < (size) )
			{
				for(int i = 0; i < noElements; i++)
				{
					if(vec[i] > v)
					{
						T tmp = vec[i];
						T tmp2;
						vec[i] = v;
						for(int j = i; j < noElements-1; j++)
						{
							tmp2 = vec[j+1];
							vec[j+1] = tmp;
							tmp = tmp2;
						}
						vec[noElements] = tmp;
						noElements++;
						return true;				
					}
				}
				
				vec[noElements] = v;
				noElements++;
				return true;
			}
			return false;
		}

		T& median()
		{
			int index = noElements / 2;
			return vec[index];
		}
		
		void removeLarger(const T& v)
		{
			for(int i = 0; i < noElements; i++)
			{
				if(vec[i] > v)
					vec[i] = 0;
					noElements--;
			}
		}
	
		void print(ostream &os)
		{
			for(int i = 0; i < noElements; i++)
			{	
				os << vec[i] << std::endl;
			}
		}
};
