#include <bits/stdc++.h>
using namespace std;


class minHeap{
    vector<int> nums;
    public:
        minHeap(){
            this->nums={};
        }
    
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
                int parent=getParentIndex(i);
                if(nums[parent]>nums[i]){
                    swap(nums[i],nums[parent]);
                    i=parent;
                }
                else return;
            }
        }
        
        int deleteElement(){
            if(nums.size()<1) return -1;
            int val=nums[0];
            swap(nums[0],nums[nums.size()-1]);
            nums.pop_back();
            
            int i=0;
            while(i<nums.size()){
                int left=getLeftChildIndex(i);
                int right=getRightChildIndex(i);
                int smallest=i;
                if(left<nums.size() && nums[left]<nums[smallest]) smallest=left;
                if(right<nums.size() && nums[right]<nums[smallest]) smallest=right;
                
                if(smallest!=i){
                    swap(nums[i],nums[smallest]);
                    i=smallest;
                }
                else return val;
                
            }
            return val;
        }
        int peek(){
            if(nums.size()<1) return 0;
            return nums[0];
        }
    
};


int main() {
	
	minHeap heap;
	heap.insert(5);
	heap.insert(20);
	heap.insert(4);
	heap.insert(10);
	heap.insert(1);
	heap.insert(0);
	heap.showNums();
    cout<<heap.peek()<<endl;
	cout<<heap.deleteElement()<<endl;
	cout<<heap.deleteElement()<<endl;
	heap.insert(7);
	heap.showNums();
	
	
	

}
