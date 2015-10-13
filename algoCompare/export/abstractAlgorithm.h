/*****************************************************************
*
* Abstract class.
* To be used by the sorting algorithms.
*
*****************************************************************/
class SortAlgorithm
{
	public:
		/*****************************************************************
		*
		* This function should sort the array it gets as its argument.
		*
		*****************************************************************/
		virtual int* sort(int[], int size) = 0;
		
		/*****************************************************************
		*
		* This function should return the time it took (in seconds) for
		* the sort function to complete.
		*
		*****************************************************************/
		virtual std::chrono::duration<double> getTime() = 0;

	private:
		/*****************************************************************
		*
		*	This function should be called immediately when 'sort' is called.
		* It should start a timer to keep track of the running time of sort. 
		*
		*****************************************************************/
		virtual void startTimer() = 0;
		
		/*****************************************************************
		*
		* This function should be called at the end of 'sort' and stop
		* the timer that is running.
		*
		*****************************************************************/
		virtual void stopTimer() = 0;
};
