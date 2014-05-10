/*
-> Min. Priority Queue using Binary heaps
-> Heapify , swim_down , remove_min , swim_up ,decrease_key verified
-> NOTE: Length being 0-based length
-> May not be entirely correct, bugs may still exist
-> len to be declared globally
-> Heap Search using Maps in O(logn)
*/

#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<map>

using namespace std;
map<int,int>m;
int len,pq[100];



void swim_down(int index) { // O(logn)

         int left,right,min_index;
         left = 2*index+1;
         right= 2*index+2;

         if(left>len)
                  return; //Out of index : Base Case
         if(left<=len)
                  min_index =  pq[index] < pq[left]? index:left ;

         if(right<=len)
                  min_index = pq[min_index] < pq[right]? min_index:right ;

         swap(pq[min_index],pq[index]);

         if(min_index != index)
                  swim_down(min_index);   //Recursive
}

void swim_up(int index){
int p_index;
if(index&1)
         p_index = (index-1)/2;
else
         p_index = (index-2)/2;

if(p_index < 0)
         return;

if( pq[p_index] > pq[index]){
         swap(pq[p_index],pq[index]);
         swim_up(p_index);
         }
}


int remove_min(){   //O(logn)
int min;

min = pq[0]; // Min PQ
if(len == 0){
         len = len  - 1;
         return min;
}
if(len == -1)
         return -1;

pq[0] = pq[len];
len = len - 1;
swim_down(0);
return min;
}

int get_min(int len){
if(len>=0)
         return pq[0];
else{
         printf("Array Index Out of Bounds");
         return -1;
         }
}

void decrease_key(int index,int new_val){
         int t;

         t = m.find(pq[index])->second;
         pq[index] = new_val;
         m[ pq[index] ] = t;
         swim_up(index);

}


void heapify( ){
int i;

for(i = len/2 ; i>=0; i--)
         swim_down(i);

}
