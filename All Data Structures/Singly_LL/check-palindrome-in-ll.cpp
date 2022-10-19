#include<iostream>
#include<vector>
//#include<bit/stdc++.h>

using namespace std;

class ListNode{

 public:
    int data;
    ListNode* next;
    
    ListNode(int data){
      this->data=data;
      this->next=NULL;
    }
};

bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head != NULL) {
            arr.push_back(head->data);
            head = head->next;
        }
        
        for(int i=0;i<arr.size()/2;i++) 
            if(arr[i] != arr[arr.size()-i-1]) 
                return false;
        
        
        return true;
    }
    
