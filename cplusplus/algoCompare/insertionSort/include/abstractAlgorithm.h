#include <chrono>
/*****************************************************************
*
* Abstract class.
* To be used by the sorting algorithms.
*
*****************************************************************/
class SortAlgorithm
{
	private:
		std::chrono::high_resolution_clock::time_point start;
		std::chrono::high_resolution_clock::time_point stop;	

	public:
		/*****************************************************************
		*
		* This function should sort the array it gets as its argument.
		*
		*****************************************************************/
		virtual void sort(int[], int size) = 0;
		
		/*****************************************************************
		*
		* This function should return the time it took (in seconds) for
		* the sort function to complete.
		*
		*****************************************************************/
		std::chrono::duration<double> getTime()
		{
			std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double> > (stop - start);
			return time_span;
		}

		/*****************************************************************
		*
		*	This function should be called immediately when 'sort' is called.
		* It should start a timer to keep track of the running time of sort. 
		*
		*****************************************************************/
		void startTimer()
		{
			start = std::chrono::high_resolution_clock::now();
		}
		
		/*****************************************************************
		*
		* This function should be called at the end of 'sort' and stop
		* the timer that is running.
		*
		*****************************************************************/
		void stopTimer()
		{
			stop = std::chrono::high_resolution_clock::now();
		}
};
