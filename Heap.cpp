#include <bits/stdc++.h>
using namespace std;


class minHeap{
    vector<int> &nums;
    public:
        minHeap(vector<int> &nums):nums(nums){}
    
        void showNums(){
            for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
            cout<<endl;
        }
        
        int getLeftChildIndex(int i){
            return (2*i+1);
        }
        
        int getRightChildIndex(int i){
            return (2*i+2);
        }
        
        int getParentIndex(int i){
            return (i-1)/2;
        }
        
        void insert(int val){
            nums.push_back(val);
            int i=nums.size()-1;
            while(i!=0){
                int parent=(i-1)/2;
                if(nums[parent]>nums[i]){
                    swap(nums[i],nums[parent]);
                    i=parent;
                }
                else return;
            }
        }
    
};


int main() {
	
	vector<int> arr={5,10,20,30};
	minHeap heap(arr);
	heap.showNums();
	heap.insert(1);
	heap.showNums();
	heap.insert(0);
	heap.showNums();
	for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
	
	
	

}
