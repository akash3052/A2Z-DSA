class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int firstLargest = arr[0], secondLargest = INT_MIN;
	    for(int i = 1; i < n; i++){
	        if(arr[i] > firstLargest){
	            firstLargest = arr[i];
	        }
	    }
	    for(int i = 0; i < n; i++){
	        if(arr[i] > secondLargest && arr[i] < firstLargest){
	            secondLargest = arr[i];
	        }
	    }
	    return secondLargest == INT_MIN ? -1 : secondLargest;
	}
};


TC = O(n)


  
