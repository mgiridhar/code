/** Solution: 
    * use two heaps - one max heap and one min heap 
    * say when you have received "n" items from your data stream, balance the heaps in such a way that
    *   1) if n is even and k, k+1 are medians , both max heap should contain k smaller elements and min heap should contain k larger elements of the data stream. Median is the average of the top values of both heaps.
    *   2) if n is odd and k'th element is median, then maintain the difference between the size of both heaps s.t it is <= 1 .ie. one heap has k elements  and other has k-1 elements. Median is the top element of heap with higher elements.
    * Time complexity - O(n * log n)
    * * * n - number of elements in data stream, log n - for every insert/delete operation in heap which is done for every element in stream
    **/
class MedianFinder {
    
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // base case: first element
        if(!maxHeap.size() && !minHeap.size()) {
            maxHeap.push(num);
            return;
        }
        
        // insert the element in the corresponding heap
        if(maxHeap.size() && maxHeap.top() < num) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
        //cout << maxHeap.top() << " " << maxHeap.size() << " " << minHeap.top() << " " << minHeap.size() << endl;
        // maintain the size of both the heaps with difference <= 1
        if(maxHeap.size() > minHeap.size() + 1) {
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        else if(minHeap.size() > maxHeap.size() + 1) {
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        //cout << maxHeap.top() << " " << maxHeap.size() << " " << minHeap.top() << " " << minHeap.size() << endl;
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */